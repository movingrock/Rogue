#include <ncurses.h>

void inven() {
    WINDOW *window1;
    WINDOW *window2;
    WINDOW *window3;

    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    refresh();

    window1 = newwin(2, 80, 0, 0);
    window2 = newwin(22, 40, 2, 0);
    window3 = newwin(22, 40, 2, 40);
    wbkgd(window1, COLOR_PAIR(1));
    wbkgd(window2, COLOR_PAIR(1));
    wbkgd(window3, COLOR_PAIR(1));

    wprintw(window1, "\t\t\t\tINVENTORY");
    wprintw(window2, "portion");
    wprintw(window3, "sword");

    wrefresh(window1);
    wrefresh(window2);
    wrefresh(window3);
}
