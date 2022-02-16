2018113528 심재헌 시스템프로그래밍 프로젝트

Description

	- 시스템 프로그래밍 과목에서 배운 용어들과 Linux Command를 복습하는 게임 프로그램이다. 자신이 놓친 부분을 확인하기 좋은 프로그램이다.

Environment

	-groomIDE를 사용했고, Ubuntu 18.04 LTS에서 구현을 진행하였다.

Prerequisite

	-curses library를 사용해야한다.

Files
	
	game.h
		- 프로그램의 헤더파일이다.
	main.c
		- 시작화면을 불러오고, type 선택화면, question을 푸는 화면을 실행시킨다.
	question.c
		- 문제를 띄우고 사용자의 입력을 받는다.
	screen.c
		- 프로그램의 여러 화면을 나타내는 파일이다.
	start.c
		- 프로그램이 시작되고 시작화면과 게임
	state.c
		- 프로그램의 여러 상태를 나타내는 파일이다.
	start.sh
		- 프로그램을 컴파일하고 실행하는 쉘 스크립트이다.

Usage

	시스템 작동 방법
		- start 쉘 스크립트를 작동시키면 된다  sh start.sh

