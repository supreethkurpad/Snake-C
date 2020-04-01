# Snake -C
A mini project implementing the classical 'Snake' game using C.

# Instructions

The following contains instructions as to how to complete the project.
Due to technical difficulties in implementing certain features, we are now going to use a C module named **ncurses**.
**ncurses** will help us deploy the terminal GUI as we intended it to work. It offers great flexibilty in taking inputs from keyboard,

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

## Intro:
Before we split work and start coding, let's understand how the program needs to work.

##
