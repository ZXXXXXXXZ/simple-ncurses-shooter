#include "player_setup.h"
#include "map_setup.h"
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{ 
  initscr();
  
  char input;
  int x_dimensions = 60;
  int y_dimensions = 40;
	Player * new_player = player_setup();
  while((input = getch())!= 'q'){ 
    player_border(new_player,x_dimensions,y_dimensions);
    initmap(x_dimensions,y_dimensions);
    controls(new_player, input);
    

  }

  noecho();
  refresh();
  endwin();
	return(0);
}
