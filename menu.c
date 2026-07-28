#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include "menu.h"


void printCentered(int row_target, const char *cadena) {
    int row, col;
    getmaxyx(stdscr, row, col);
    int x_ideal = (col / 2) - (strlen(cadena) / 2);
    mvprintw(row_target, x_ideal, "%s", cadena);
}

void expandMenu(int seleccion) {
    int row, col; 
    getmaxyx(stdscr, row, col); 
    clear();

   
    printCentered(row / 2 - 2, "|========= BATTELSHIP IN TERMINAL =========|");
    printCentered(row / 2,     "SELECT OPTION WITH ARROWS + SPACE");


    if (seleccion == 1) attron(A_REVERSE);
    printCentered(row / 2 + 2, "1- PARTIDA NUEVA");
    if (seleccion == 1) attroff(A_REVERSE);

    if (seleccion == 2) attron(A_REVERSE);
    printCentered(row / 2 + 4, "2- SALIR");
    if (seleccion == 2) attroff(A_REVERSE);
    
    refresh(); 
}

int selectOption(void) {
    int option = 1;
    expandMenu(option);

    while (1) {
        int tecla = getch();
        switch (tecla) {
            case KEY_UP:
                if (option > 1) { option--; expandMenu(option); }
                break;
            case KEY_DOWN:
                if (option < 2) { option++; expandMenu(option); }
                break;
            case ' ': 
                return option;
        }
    } 
}

int selectDificulty(void) {
    int row, col;
    getmaxyx(stdscr, row, col);
    clear();
    
    printCentered(row / 2 - 4, "|========= SELECT DIFFICULTY =========|");
    printCentered(row / 2 - 2, "1 = EASY | 2 = MEDIUM | 3 = HARD");
    printCentered(row / 2,     "PRESS 1, 2 OR 3: ");
    refresh();
    
    while (1) {
        int tecla = getch();
        if (tecla >= '1' && tecla <= '3') {
            int dificultad = tecla - '0'; 
            
            clear();
            // Reutilizamos el formateador directamente con printCentered usando buffers temporales si fuera necesario,
            // o imprimiendo de forma estática y limpia:
            char msg_status[50];
            sprintf(msg_status, "Dificultad seleccionada: %d", dificultad);
            printCentered(row / 2, msg_status);
            printCentered(row / 2 + 2, "Presiona cualquier tecla para empezar el juego...");
            refresh();
            
            getch(); 
            return dificultad;
        } else {
            printCentered(row / 2 + 4, "[!] Opción inválida. Presiona 1, 2 o 3.   ");
            refresh(); 
        }
    }
}