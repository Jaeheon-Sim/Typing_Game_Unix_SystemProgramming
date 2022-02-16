// 2018113528 심재헌
// start code file

#include <stdio.h>
#include <curses.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h> 
#include <stdlib.h>
#include <sys/wait.h>
#include "game.h"

void init_screen(){
	int pid = fork();					/* make new process */
	switch (pid) {
	case -1:
		perror("fork failed");
		exit(1);
	case 0:
		start_screen();
	default:	
		wait(NULL);
		clear();
	}
	
	pid = fork();					/* make new process */
	switch (pid) {
	case -1:
		perror("fork failed");
		exit(1);
	case 0:
		explain_rules();
	default:	
		wait(NULL);
		clear();
	}
	exit(0);
}

