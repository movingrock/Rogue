// #include "map.h"
#include <ncurses.h>

int px = 22;
int py = 40;

void map() {
    WINDOW *window1;
    WINDOW *player;
    initscr();
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    refresh();

    window1 = newwin(24, 80, 0, 0);
    player = newwin(1, 1, px, py);
    wbkgd(window1, COLOR_PAIR(1));
    wbkgd(player, COLOR_PAIR(2));
    wborder(window1, '|', '|', '-', '-', '+', '+', '+', '+');
    wprintw(player, "@");
    wrefresh(window1);
    wrefresh(player);

    getch();

    mvwin(player, py, px);
    touchwin(player);
    wrefresh(window1);
    wrefresh(player);
}

// void map() {
//     WINDOW *window1;
//     WINDOW *player;
//     initscr();
//     keypad(stdscr, TRUE);
//     start_color();
//     init_pair(1, COLOR_WHITE, COLOR_BLACK);
//     init_pair(2, COLOR_YELLOW, COLOR_BLACK);
//     refresh();
//     int x, y;
//     x = 15;
//     y = 30;
//     window1 = newwin(24, 80, 0, 0);
//     player = newwin(1, 1, x, y);
//     wbkgd(window1, COLOR_PAIR(1));
//     wbkgd(player, COLOR_PAIR(2));
//     wborder(window1, '|', '|', '-', '-', '+', '+', '+', '+');
//     wprintw(player, "@");
//     wrefresh(window1);
//     wrefresh(player);

//     mvwin(player, 22, 40);
//     int key;

//     getch();
//     x = x - 1;
//     y = y - 1;
//     mvwin(player, y, x);
//     wrefresh(window1);
//     wrefresh(player);

//     getch();
//     endwin();
// }

// char textToGraphic(Text text) {
//     char graphic = ' ';
//     switch (text) {
//     case Text::ARMOR:
//         graphic = 'A';
//         break;
//     case Text::Ground:
//         graphic = '.';
//         break;
//     case Text::Portion:
//         graphic = 'P';
//         break;
//     case Text::Gold:
//         graphic = 'G';
//         break;
//     case Text::Road_V:
//         graphic = '|';
//         break;
//     case Text::Road_H:
//         graphic = '_';
//         break;
//     }
//     return graphic;
// }
