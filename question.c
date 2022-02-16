// 2018113528 심재헌
// question code file

#include <stdio.h>
#include <curses.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h> 
#include <termio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include "game.h"

int time; 					//time use for print
void print_time();			
char* removegap(char* st);
void bigtosmall(char* user_answer);

char cmd_questions[Q_NUMBER][100] = {										 // commmand questions
							"Change the working directory", //cd
							 "List directory contents",//ls
							 "Show who is logged on",//who
							 "Change file mode bits",// chmod
							 "Copy files and directories", // cp
							 "Make directories", // mkdir
							 "Display a line of text",//echo
							 "Compares two sorted files line by line",//comm
							 "Print name of current/working directory",// pwd
							 "Make links between files"//ln
							};
char terminologies_questions[Q_NUMBER][100] = {							// terminology questions
							"Program complete control over everything in the system.",//kernal
							 "A kind of file, that contains a list of names of files and directories",// directory
							 "That is a bits are used to activate special properties of a file",//special bits
							 "The dir to which the subtree is attached",// mount point
							 "That is a mode Buffering and editing is turned off", // crmode
							 "One-word messsage from kernal to process", // signal
							 "A section of code that modifies a data structure",//Critical Sections
							 "The memory space and setting with which the program runs",//process
							 "A file that contains a batch of commands",// shll script
							 "A one-way data channel"//pipe
							};
	
char cmd_answer[Q_NUMBER][10] ={											// command answers
						"cd",
					  "ls",
					  "who",
					  "chmod",
					  "cp",
					  "mkdir",
					  "echo",
					  "comm",
					  "pwd",
					  "ln"};

char terminologies_answer[Q_NUMBER][20] ={								// terminology answers
						"kernal",
					  "directory",
					  "specialbits",
					  "mountpoint",
					  "crmode",
					  "signal",
					  "criticalsection",
					  "process",
					  "shellscript",
					  "pipe"};

int question(int num,int score,int type){
	
	int correct=0;		
	time = ENDTIME;		
	
	char user_answer[100];
	
	initscr();
	clear();
	signal(SIGALRM, print_time);
	
	grid_screen();
	
	move(row_start+3,col_start+10);
	if(type==0){								//type 0 == command
		addstr(" C O M M A N D ");
	}else{										//type 1 == terminologies
		addstr(" T E R M I N O L O G Y ");
	}
	
	move(row_start+2,col_last-10);
	printw("score = %d",score);					//print current score
	
	if(type==1){
		move(row_start+row_last/3, col_start+col_last/6);	
		if(num==1){
			move(row_start+row_last/3, col_start+10);	
			printw("%s\n",terminologies_questions[num]);	
		}else{
			printw("%s\n",terminologies_questions[num]);	
		}
	}else{
		move(row_start+row_last/3, col_start+col_last/3);	
		printw("%s\n",cmd_questions[num]);	
	}
	
	move(LINES, 0);
	refresh();
	
	for(int i=0;i<6;i++){								// alarm signal
		alarm(1);
		pause();	
	}
	
	move(row_last-5, col_start);
	addstr("                                                                                                                    ");
	move(row_start+row_last/3, col_start);
	addstr("                                                                                                                    ");
	int time_row= (row_last+row_start+row_last/3)/2;
	int time_col=(col_start+col_last)/2;
	move(time_row, col_start+col_last/3);
	addstr("                                                                                                                    ");
	standout();
	move(row_start+row_last/4+1, col_start+col_last/3);
	addstr("INPUT ANSWER!!!");
	rewind(stdin);
		
	move(row_start+row_last/4, col_start+col_last/3);
	addstr("What is the answer???");
	
	move(row_start+row_last/4+5, col_start+col_last/3);	
	addstr("The input value is less than 20 characters.");
	
	move(LINES,0);
	refresh();
	
	standend();
	echo();
	move(row_start+row_last/4+3, col_start+col_last/3);	
	scanw("%[^\n]s",user_answer);								//input answer
	
	noecho();
	
	bigtosmall(user_answer);									// replace big to small
	char* replace = removegap(user_answer);						// remove " "
	if(type==1){												// terminologies
		if(strcmp(replace,terminologies_answer[num])==0){		// if correct
			correct=1; 
		}	
	}else{														// if correct 
		if(strcmp(replace,cmd_answer[num])==0){
			correct=1; 
		}
	}	
	endwin();
	return correct;	
}

void print_time(){							 // print remain time
	int time_row= (row_last+row_start+row_last/3)/2;
	int time_col=(col_start+col_last)/2;
	move(time_row, col_start+col_last/3);
	printw("%d.....\n",time--);
	move(LINES,0);
	refresh();	
}

void bigtosmall(char* user_answer){			// Change uppercase to lowercase.
	for(int i=0;i<strlen(user_answer);i++){
		user_answer[i]=tolower(user_answer[i]);	
	}
}

char* removegap(char* st){					// remove the gap
	char* str = (char*)malloc(sizeof(st));
	int k = 0;
	for (int i = 0; i < strlen(st); i++) {
		if (st[i] != ' ') {					// if meet gap
			str[k++] = st[i];				// pass
		}
	}
	str[k] = '\0';							// input null
	return  str;
}
