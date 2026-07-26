#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include "juego.h"
#include "menu.h"

static void finish(int sig);

int
main(int argc, char *argv[])
{
    int num = 0;

    /* initialize your non-curses data structures here */

    (void) signal(SIGINT, finish);      /* arrange interrupts to terminate */

    (void) initscr();      /* initialize the curses library */
    keypad(stdscr, TRUE);  /* enable keyboard mapping */
    (void) nonl();         /* tell curses not to do NL->CR/NL on output */
    (void) cbreak();       /* take input chars one at a time, no wait for \n */
    (void) noecho();         /* echo input - in color */

  

    for (;;)// ,, its means a infinity loop
    {
        int option= selectOption();

        if(option==1){
            int dificult=selectDificulty();
          
        }else{
            break;
        }

        
        
    }

    finish(0);               /* we are done */
}



static void finish(int sig)
{
    endwin();

    /* do your non-curses wrapup here */

    exit(0);
}

