
#include "map_setup.h"
#include <ncurses.h>

/*Function: initmap
 *creates points at positions min(x,y) &&
 *max(x,y), incremnts min[x] and min[y] &&
 *decrements max[x] and max[y] so they they both
 *create half of a square and meets in the middle
 *to create a full one like so:
 * 
 *             ^ <___.max(x,y) 
 *             |     |
 *     min(x,y).____>v
 */
void initmap(int x, int y){

  int min[XY] = {1,1};
  int max[XY] = {x,y};
  int min_y = min[Y];
  int min_x = min[X];
  mvprintw(min[Y],min[X],"0");
  while(min[Y]++ != max[Y]){
    mvprintw(min[Y], min[X],"0");
    if(min[Y] == max[Y]){
      while(min[X]++ != max[X]){
        mvprintw(max[Y],min[X],"0");
      }        
    }
  }
  while(min[Y]-- != min_y){
    mvprintw(min[Y],max[X],"0");
    if(min[Y] == min_y){
      while(min[X]-- != min_x){
        mvprintw(min[Y], min[X], "0");
      }
    }
  }
  min[Y] = min_y;
  min[X] = min_x;
}

void pick_ups(){

}
