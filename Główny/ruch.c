//plik źródłowy "ruch.c" 
#include<ncurses.h>
#include <math.h>

#define A 11

void delay(int p)
{	
	p = p*10000000;
	for (int i = 0; i < p; ++i)
	{}
	refresh();
} //funkcja powodująca opóźnienie w programie

void drybling(int *wysokosc, int height, int width, int start1_x, int start1_y, WINDOW *win1, WINDOW *win2)
{
	mvwprintw(win2, ++(*wysokosc), 1, "drybling");
 	for (int k = start1_x; k < width-15; ++k){
		mvwprintw(win1, height-7, k+2, "  00 / ");
 		mvwprintw(win1, height-6, k+2, " /[]/ ");
  		mvwprintw(win1, height-5, k+2, "  /\\ "); 
  		mvwprintw(win1, height-5, k+2,"_");	
  		mvwprintw(win1, height-10, 5+k,"  oo ");
		mvwprintw(win1, height-9, 5+k, " o  o ");
		mvwprintw(win1, height-8,  5+k,"  oo ");
  			
  		delay(2);
  		wrefresh(win1);
  		wrefresh(win2);
 	}
}
 	
void powrot(int *wysokosc, int height, int width, int start1_x, int start1_y, WINDOW *win1, WINDOW *win2)
{
	mvwprintw(win2,++(*wysokosc), 1, "powrot");
	 for (int j = width - 15; j >0 ; --j){
		mvwprintw(win1, height-7, j, "  00 / ");
	 	mvwprintw(win1, height-6, j, " /[]/ ");
	  	mvwprintw(win1, height-5, j, "  /\\ "); 

	  	mvwprintw(win1, height-5, j+5,"_");

	  	mvwprintw(win1, height-10, 5+j,"  oo ");
		mvwprintw(win1, height-9,  5+j," o  o ");
		mvwprintw(win1, height-8,  5+j,"  oo  ");	
	  			
	  	delay(2);
	  	wrefresh(win1);
	  	wrefresh(win2);
 	}
}
 	
void rzut(int *wysokosc, int height, int width, int start1_x, int start1_y, WINDOW *win1, WINDOW *win2)
{
	mvwprintw(win2, ++(*wysokosc), 1, "RZUT");
 	for ( int i = 1; i < (width-12); ++i){	
 		mvwprintw(win1, height-6, 1, " \\[]/ ");

	  	mvwprintw(win1, height-sqrt(A*i)-6, 5+i,"  oo ");
		mvwprintw(win1, height-sqrt(A*i)-5, 5+i," o  o ");
		mvwprintw(win1, height-sqrt(A*i)-4, 5+i,"  oo ");

		wrefresh(win2);
 		wrefresh(win1);
	  	delay(1+i/10);

		mvwprintw(win1, height-sqrt(A*i)-6, 5+i,"     ");
		mvwprintw(win1, height-sqrt(A*i)-5, 5+i,"     ");
		mvwprintw(win1, height-sqrt(A*i)-4, 5+i,"     ");

		wrefresh(win2);
 		wrefresh(win1);
	} 

 	for(int j = 0; j<2; ++j){
	  	mvwprintw(win1, height-sqrt(A*(width-11))+j-4, width-7-j, " oo " );
	  	mvwprintw(win1, height-sqrt(A*(width-11))+j-3, width-7-j, "o  o ");
	  	mvwprintw(win1, height-sqrt(A*(width-11))+j-2, width-7-j, " oo ");

	  	wrefresh(win2);
 		wrefresh(win1);
	  	delay(4);

	  	mvwprintw(win1, height-sqrt(A*(width-11))+j-2, width-7-j, "    ");
	  	mvwprintw(win1, height-sqrt(A*(width-11))+j-3, width-7-j, "    ");
	  	mvwprintw(win1, height-sqrt(A*(width-11))+j-4, width-7-j, "    ");

	  	wrefresh(win2);
 		wrefresh(win1);
	}
 	wrefresh(win2);
 	wrefresh(win1);

}
void punkt(int *wysokosc, int height, int width, int start1_x, int start1_y, WINDOW *win1, WINDOW *win2)
{
	  	mvwprintw(win1, height/3, width/3, "KAMIL ZA 3 PKT!!!");
	  	mvwprintw(win2, ++(*wysokosc), 1, "PUNKT");
	  	wrefresh(win1);
	  	wrefresh(win2);
	  	refresh();
}