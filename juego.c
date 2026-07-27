#include "juego.h"
#include <ncurses.h>

int columnsRows;
int level[3]={8,10,12};



void startGame(int dificult){
    

    startUserTable(dificult);
    drawTable();


    while (1) {
        int ch = getch();
        if (ch == 'q') break; 
    }

    
}

void startUserTable(int dificult){
    
    columnsRows=level[dificult-1];
    clear();
    

}
void drawTable(){
    clear();
    for (size_t i = 0; i < columnsRows; i++)
    {   
        for (size_t j = 0; j < columnsRows; j++)
        {
            mvprintw(i,j,"~");
        }
        
    } 
    refresh();
}