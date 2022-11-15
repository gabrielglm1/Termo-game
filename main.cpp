#include <iostream> 
#include <stdlib.h>
#include <string>
#include <curses.h>

using namespace std;

int main(){

    initscr();
    noecho();
    curs_set(0);

        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);

        WINDOW *win = newwin(yMax/2, xMax/2, yMax/4, xMax/4);
        box(win, 0, 0);

    mvwprintw(win, 0, 10, "Game");

    char ch;
    while(ch = wgetch(win)){
        switch(ch){
            case 'w':
            wattron(win, A_STANDOUT); 
            mvwprintw(win, 0, 2, "Termo");
            wattroff(win, A_STANDOUT);
            break;
            case 'a':

            break;
            case 's':

            break;
            case 'd':

            break;
        }
    }

endwin();
return 0;
}
