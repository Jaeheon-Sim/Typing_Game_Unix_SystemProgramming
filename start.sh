# 2018113528 JaeHeon-Sim
# Create an executable file and execute the file.

#!/bin/bash
cc main.c question.c screen.c start.c state.c -lcurses -o main
./main
