// 2018113528 심재헌
// screen code file

#include <stdio.h>
#include <curses.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h> 
#include <stdlib.h>
#include "game.h"

void grid_screen();	

int value;

void start_screen()								// print start screen
{
	
	initscr();
	clear();
	
	grid_screen();
	
	move(row_value+2, col_start+col_last/6);	
	addstr("========   ==========       =        =======    ==========");
	move(row_value+3, col_start+col_last/6);	
	addstr("=              ==          = =       =      =       ==");
	move(row_value+4, col_start+col_last/6);	
	addstr("========       ==         =====      =======        ==");
	move(row_value+5, col_start+col_last/6);	
	addstr("       =       ==        =     =     =     =        ==");
	move(row_value+6, col_start+col_last/6);	
	addstr("========       ==       =       =    =      =       ==");
	move(row_last-3, col_start+col_last/3.3);	
	addstr("press any button!!!!\n");
	
	move(LINES, 0);
	
	refresh();
	getch();
	out_condition();			
}

void explain_rules(){
	initscr();
	clear();
	
	// grid
	grid_screen();
	
	// explain about game
	move(row_value, col_value);	
	addstr("SYSTEM PROGRAMMING TEST!!!!!!!!!!!!!!!!!!!");
	move(row_value+1, col_value);	
	addstr("There are two types of problems and each has a 10 Question...");
	move(row_value+4, col_value);	
	addstr("-------------------------------game rules------------------------------------");
	move(row_value+6, col_value);	
	addstr("A sentence explaining the term will be printed for 5 seconds...");
	move(row_value+7, col_value);	
	addstr("You can enter the term after 5 seconds.");
	move(row_value+8, col_value);	
	addstr("If it's correct, you'll get points and move on to the next question...");
	move(row_value+9, col_value);	
	addstr("If it's incorrect, the game will end...");
	move(row_value+12, col_value);
	standout();
	addstr("If you're ready, press any button!!!!!!");
	standend();
	
	move(LINES, 0);
	
	refresh();
	getch();
	out_condition();
}

int type_input(){
	int value=-1;
	
	initscr();
	crmode();
	noecho();
	clear();
	grid_screen();
	fflush(stdout);
	
	move(row_start+row_last/3, col_start+col_last/4+1);
	standout();
	addstr("Choose Question Type!!!");
	move(row_start+row_last/3+1, col_start+col_last/4+1);
	addstr("Input 0 or 1.");
	standend();
	rewind(stdin);
	move(row_start+row_last/3+3, col_start+col_last/4+1);
	addstr("0. Command 1. Terminology");
	
	move(row_start+row_last/3+5, col_start+col_last/4+3);
	refresh();	
	
	int c = getch();		/* grab the char */	
	
	if(c == '1'){ // 종료조건 처리하기
		value=1;
	}else if( c == '0'){
		value=0;
	}else{
		value=-1;
	}	
	
	return value;
}

void error_screen(){
	int row_middle = (row_start+row_last)/2;
	clear();
	grid_screen();
	move(row_middle, col_start+col_last/4);
	standout();
	addstr("ONLY INPUT 1 OR 2!!!!!!!!!!!!!!!");
	standend();
	refresh();
	
	sleep(5);
	out_condition();
}

void grid_screen(){
	move(row_start,col_start);
	for(int i=col_start;i<=col_last;i++){
		addstr("*");	
	}
	move(row_last,col_start);
	for(int i=col_start;i<=col_last;i++){
		addstr("*");	
	} 
}


