#include<ncurses.h>
#include<math.h>

#define A 11 //stała do równania parametrycznego y = A*sqrt(x);

void boisko(int *wysokosc, int y, int x, WINDOW *win1, WINDOW *win2)
{
	int p = 1;
	while(p!=(x-1)){
 		mvwprintw(win1, y-5, p, "_");
 		++p;
 	}

  	mvwprintw(win1, y-3, 2, "x %d  y %d, animacja ASCII boisko do koszykowki", x, y);

  	mvwprintw(win1, y-7, 3, "00");
 	  mvwprintw(win1, y-6, 2, "/[]\\");
  	mvwprintw(win1, y-5, 3, "/\\"); // ludzik gotowy do rzutu

  	for(int i = -3; i<7; ++i) //wypisanie kosza
  		mvprintw(y-sqrt(A*(x-11))-i, x-2, "|");
  	for(int k = 0; k<11; ++k){
  		mvprintw(y-sqrt(A*(x-11)), x-k-3, "_");
  		mvprintw(y-sqrt(A*(x-11))+1, x-k-3, "_");
  	}
  	mvwprintw(win1, y-sqrt(A*(x-11))+1, x-14,   "|");
  	mvwprintw(win1, y-sqrt(A*(x-11))+2, x-13, "\\/\\/\\/\\/\\/");
  	mvwprintw(win1, y-sqrt(A*(x-11))+3, x-12, "\\/\\/\\/\\/");
  	mvwprintw(win1, y-sqrt(A*(x-11))+4, x-11, "\\/\\/\\/");
  	mvwprintw(win1, y-sqrt(A*(x-11))+5, x-10, "\\/\\/");

    mvwprintw(win2, ++(*wysokosc), 1, "WYRYSOWANIE BOISKA, gracz gotowy, nacisnij przycisk!");

  	wrefresh(win1);
    wrefresh(win2);
}