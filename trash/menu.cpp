#include "menu.h"
#include "input.h"

#include <ncurses.h>

void menu() {
    WINDOW *window1;
    WINDOW *window2;
    WINDOW *window3;
    WINDOW *window4;
    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_WHITE);
    init_pair(3, COLOR_WHITE, COLOR_BLUE);
    refresh();
    window1 = newwin(19, 80, 0, 0);
    window2 = newwin(1, 20, 19, 30);
    window3 = newwin(1, 20, 20, 30);
    window4 = newwin(1, 20, 21, 30);
    wbkgd(window1, COLOR_PAIR(1));
    wbkgd(window2, COLOR_PAIR(2));
    wbkgd(window3, COLOR_PAIR(2));
    wbkgd(window4, COLOR_PAIR(2));
    wprintw(window1, "\n\n\n\n\n");
    wprintw(
        window1,
        "          |======      =======     =======      ==    ==      ====\n");

    wprintw(window1,
            "          |  __  \\    /  ___  \\   / ______\\    |  |  |  "
            "|    |   _|\n");

    wprintw(window1, "        __| |__| |____| |___| |___| |__________|  |__|  "
                     "|____|  |____\n");

    wprintw(window1, "       / _| |__| |____| |___| |___| |_ ____ ___|  |__|  "
                     "|___ |     | |\n");

    wprintw(window1,
            "       \\__| ____ \\____| |___| |___| |_|_  _|___|  |__|  "
            "|____|   __|_|\n");

    wprintw(window1, "          | |   \\ \\   | |___| |   | |___| |    |  |__| "
                     " |    |  |_\n");

    wprintw(window1, "          |_|   |_|   \\_______/   \\_______/    "
                     "\\________/    |____|\n");

    wprintw(window1, "LIKE");

    wrefresh(window1);
    if (cursor == "start") {
        wbkgd(window2, COLOR_PAIR(3));
    }
    if (cursor == "info") {
        wbkgd(window3, COLOR_PAIR(3));
    }
    if (cursor == "exit") {
        wbkgd(window4, COLOR_PAIR(3));
    }

    wprintw(window2, "\tSTART");
    wprintw(window3, "\tINFO");
    wprintw(window4, "\tEXIT");

    wrefresh(window2);
    wrefresh(window3);
    wrefresh(window4);
}
