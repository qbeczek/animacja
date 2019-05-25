//plik główny programu ANIMACJI ASCII Jakub Szymański E102 300387
//kompilacja gcc -Wall -o grafika main.c boisko.c ruch.c -lm -lncurses
// ./grafika

#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<math.h> //dołączenie standardowych bibliotek potrzebnych do grafiki

#include"boisko.h" //dołączenie pliku nagłówkowego "boisko.h" w którym znajdują się funkcje do wyrysowania boiska
#include"ruch.h" //dołączenie pliku nagłówkowego "ruch.h" w którym znajdują się funckje ruchu animacji

#define A 11 //stała do równania parametrycznego y = A*sqrt(x);

int main(void)
{	
	initscr();
	raw();
	noecho();

	int wysokosc = 0;
	int x, y;
	int height, width, start1_y, start1_x, start2_x, start2_y;

 	getmaxyx(stdscr, y, x);
 	clear();
 	
	height  = y;
	width = x/2;
	start1_x = start1_y = 0;
	start2_x = x/2;
	start2_y = 0;

	WINDOW * win1= newwin(height, width, start1_y, start1_x);
	WINDOW * win2= newwin(height, width, start2_y, start2_x);

	refresh();
 	box(win1, 0, 0);
 	box(win2, 0, 0);

 	wrefresh(win1);
 	wrefresh(win2);

 	getch();

 	boisko(&wysokosc, height, width, win1, win2);
 	
 	wrefresh(win1);
 	wrefresh(win2);
 	getch();

 	drybling(&wysokosc, height, width, start1_x, start1_y, win1, win2);

 	powrot(&wysokosc, height, width, start1_x, start1_y, win1, win2);

 	rzut(&wysokosc, height, width, start1_x, start1_y, win1, win2);

 	punkt(&wysokosc, height, width, start1_x, start1_y, win1, win2);

	wrefresh(win1);
	wrefresh(win2);
	refresh();
	getch();
	endwin();

	return 0;
}	