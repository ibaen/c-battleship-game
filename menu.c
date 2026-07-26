#include <ncurses.h>
#include "menu.h"
#include <stdio.h>
// Nota: Para usar colores en curses es mejor usar init_pair(), 
// pero mantenemos tus definiciones si solo las usas en prints normales.
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

void expandMenu(int seleccion){
    
    clear();
    mvprintw(2, 5, "|========= BATTELSHIP IN TERMINAL =========| ");
    mvprintw(4, 5, "SELECT OPTION WITH ARROWS + SPACE");

    // Primera opción: PARTIDA NUEVA
    if (seleccion == 1) {
        attron(A_REVERSE);
        mvprintw(7, 8, "1- PARTIDA NUEVA");
        attroff(A_REVERSE); // ¡Crucial desactivarlo!
    } else {
        mvprintw(7, 8, "1- PARTIDA NUEVA");
    }

    // Segunda opción: SALIR (Corregido el texto que estaba repetido)
    if (seleccion == 2) {
        attron(A_REVERSE);
        mvprintw(9, 8, "2- SALIR");
        attroff(A_REVERSE); // ¡Crucial desactivarlo!
    } else {
        mvprintw(9, 8, "2- SALIR");
    }
    
    refresh(); // Muestra los cambios en la pantalla
}

int selectOption(void){
    int option = 1;
    int tecla;

    expandMenu(option);

    while (1)
    {
        tecla = getch();
        switch (tecla)
        {
            case KEY_UP:
                option = 1;
                expandMenu(option); 
                break;
                
            case KEY_DOWN:
                option = 2;
                expandMenu(option); 
                break;

            case ' ': 
                return option;
            
        }
    } 

}
/*
En el lenguaje C, cuando pones un carácter entre comillas simples (como '1'), el compilador lo traduce automáticamente a su valor numérico de la tabla ASCII (que es 49);
*/

/*
in the lenguage C, when you put a character in single quotes(like '1'), the compiler automaticlly translate  it to its numeric value from the ACCII table(wich is 49);
*/

int selectDificulty(void) {
    clear();
    
    mvprintw(2, 5, "|========= SELECT DIFFICULTY =========|");
    mvprintw(4, 5, "1 = EASY | 2 = MEDIUM | 3 = HARD");
    mvprintw(6, 5, "PRESS 1, 2 OR 3: ");
    refresh();
    
    int tecla = 0;
    int dificultad = 0;

    while (1) {
        tecla = getch();
        if (tecla == '1' || tecla == '2' || tecla == '3') {
            // Convertimos el carácter ASCII ('1'..'3') a número entero (1..3)
            dificultad = tecla - '0'; 
            
            mvprintw(8, 5, "Dificultad seleccionada: %d \n", dificultad);
            mvprintw(10, 5, "Presiona cualquier tecla para empezar el juego...");
            refresh();
            
            getch(); // Espera una tecla para que el usuario pueda leer el mensaje
            break;
        } else {
            mvprintw(8, 5, "[!] Opción inválida. Presiona 1, 2 o 3.   ");
            refresh(); 
        }
    }

    return dificultad;
}