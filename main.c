// 2018113528 심재헌
// main code file
#include <stdio.h>
#include <curses.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h> 
#include <stdlib.h>
#include <sys/wait.h>
#include "game.h"

int score=0;							// score variable

int main(){
	int pid = fork();					//start init_screen
	int right;
	int type=-1;
	signal(SIGINT,SIG_IGN);
	switch (pid) {					
	case -1:							// error
		perror("fork failed");
		exit(1);
	case 0:								// run init_screen process
		init_screen();
	default:							
		break;
	}
	wait(NULL);				
	clear();
	
	type=type_input();					// choose type
	if(type==-1){						// wrong input
		error_screen();					// go to error_screen
	}
	go_condition();
	
	for(int i=0;i<Q_NUMBER;i++){				// 10 questions			
		 right=question(i,score,type);
		if(right==0){ 					// if wrong
			game_over(score);			// go to game_over
		}else{							// if correct
			score++;					// plus score
			if(score==Q_NUMBER){				// if all correct	
				all();		
			}else{						
				correct(score);
			}
		}
	}
	signal(SIGINT,SIG_DFL);
}

