# Snake -C
A mini project implementing the classical 'Snake' game using C.

# Instructions

The following contains instructions as to how to complete the project.

## Current problem
The current problem we faced was input. Imagine our game worked such that, it drew a new board on the screen every second(effectively animating it). But, if we needed the snake to move as the user wants it to, we need to take user command using *getchar()* method. But when getchar is used, the program stops all process till a chracter is entered, which means no more drawing the game board on the screen, and our snake wont move until a key is pressed, which is clearly now what we want.

## How to tackle this
As discussed above, we will be using **ncurses** module for C
### Here is a guide to install ncurses on Ubuntu
https://www.cyberciti.biz/faq/linux-install-ncurses-library-headers-on-debian-ubuntu-centos-fedora/
### Documentation for ncurses
1. http://www.cs.ukzn.ac.za/~hughm/os/notes/ncurses.html#init
2. http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/helloworld.html
In the second link, just learn up to the module named Windows

### NOTE: Please compile and make all the programs on a Linux-based distro. Use Virtual Box if necessary. Windows is for noobs.(Also because ncurses doesnt work that well on windows)

# Program structure

## Basics:
The **board** is the arena where the game occurs, the snake is displayed on the board. The dimensions of the board is 50x50.
In the program the board is represented as 50x50 2D character array. 
The snake, which is the main part is represented by a *linked list*. Every element of the snake contains {positions x,y, direction, pointer to next body, pointer to prev body}
## Game flow
Initially, the snake moves is the upward direction at speed, 1 line per second. When a key is captured, based on the key, the snake changes the direction and continues in that direction.
## How the snake moves.
Every item in the *linked list* snake is a body. Ex: if the snake was AAAAAAA. That means, there are 7 elements in the *linked list* snake.
The topmost element is called head.
Let's consider the movemnet of snake with two elements, the movement of the second element is dependadnt on the first. 
Case 1: If, the direction of head is same as tail, then any increase is position of head is applied for tail
Case 2: If the direction of the head is different, then we must move one unit in the same direction and then change the direction of the tail to equal the head.

