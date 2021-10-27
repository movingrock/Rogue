#include "menu.h"
#include <ncurses.h>

int main(int argc, char const *argv[]) {
    WINDOW *window1;
    WINDOW *window2;
    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_WHITE);
    refresh();
    window1 = newwin(19, 80, 0, 0);
    window2 = newwin(3, 20, 19, 30);
    wbkgd(window1, COLOR_PAIR(1));
    wbkgd(window2, COLOR_PAIR(2));
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

    wprintw(window2, "\tSTART\n");
    wprintw(window2, "\tINFO\n");
    wprintw(window2, "\tEXIT");
    wrefresh(window1);
    wrefresh(window2);

    getch();
    endwin();
    return 0;
}
