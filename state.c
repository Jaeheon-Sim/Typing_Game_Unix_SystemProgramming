// 2018113528 심재헌
// state code file

#include <stdio.h>
#include <curses.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h> 
#include <stdlib.h>
#include <sys/wait.h>
#include "game.h"

int atime;

void game_over(int score){							// game_over screen
	atime=OOPSTIME;
	noecho();
	initscr();
	clear();
	signal(SIGALRM,oops_time);
	
	grid_screen();
	
	move(row_value, col_value);
	standout();
	addstr("OOPS...");
	standend();
	move(row_value+1, col_value);
	addstr("Go study more....");
	move(row_value+4, col_value);
	printw("The total score is %d.\n",score);
	move(row_value+7, col_value);
	addstr("The system will be shut down in 4 seconds...");
	
	move(LINES, 0);
	refresh();
	
	for(int i=0;i<4;i++){							//alarm signal for 4secs
		alarm(1);
		pause();	
	}

	out_condition();								
}

void correct(int score){							// correct
	atime=CORRECTTIME;
	noecho();
	initscr();
	clear();
	signal(SIGALRM,correct_time);
	
	grid_screen();
	
	move(row_value, col_value);
	standout();
	addstr("CORRECT!!!!!!");
	standend();
	move(row_value+2, col_value);
	addstr("We'll move on to the next question in 3 seconds.");
	move(row_value+4, col_value);
	printw("The current score is %d.\n",score);
	
	move(LINES, 0);
	refresh();
	
	for(int i=0;i<3;i++){								// alarm signal for 3 secs
		alarm(1);
		pause();	
	}
	
	refresh();
	go_condition();
}

void all(){
	noecho();
	initscr();
	clear();
	signal(SIGALRM,out_condition);

	grid_screen();
		
	move(row_value, col_value);
	standout();
	addstr("WOW!!!! ALL CLEAR!!!");
	standend();
	move(row_value+1, col_value);
	addstr("You did a great job...");
	move(row_value+3, col_value);
	
	addstr("The system will be shut down in 5 seconds...");
	
	move(LINES, 0);
	refresh();
	
	alarm(5);			// 5secs alarm
	pause();
}

void out_condition(){				// make out out_condition
	echo();							// echo on
	nocrmode();						// no crmode
	clear();						// clear tty
	endwin();						// end curses
	exit(0);						// end
}

void go_condition(){				
	echo();							// echo on
	nocrmode();						// no crmode
	clear();						// clear tty
	endwin();						// end curses
}

void correct_time(){				// correct timer
	move(row_value+2, col_value);		
	printw("We'll move on to the next question in %d seconds.",atime--);
	move(LINES,0);
	refresh();
}

void oops_time(){					// oops timer
	move(row_value+7, col_value);
	printw("The system will be shut down in %d seconds...",atime--);
	move(LINES,0);
	refresh();
}