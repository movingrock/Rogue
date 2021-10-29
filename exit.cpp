#include "input.cpp"

#include <ncurses.h>

void exit() {
    WINDOW *window1;
    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    refresh();

    window1 = newwin(24, 80, 0, 0);

    wbkgd(window1, COLOR_PAIR(1));

    wprintw(window1, "        .----------------.  .----------------.  "
                     ".----------------. \n");
    wprintw(window1, "       | .--------------. || .--------------. || "
                     ".--------------. |\n");
    wprintw(window1, "       | |   ______     | || |  ____  ____  | || |  "
                     "_________   | |\n");
    wprintw(window1, "       | |  |_   _ \\    | || | |_  _||_  _| | || | |_   "
                     "___  |  | |\n");
    wprintw(window1, "       | |    | |_) |   | || |   \\ \\  / /   | || |   | "
                     "|_  \\_|  | |\n");
    wprintw(window1,
            "       | |    |  __'.   | || |    \\ \\/ /    | || |   |  "
            "_|  _   | |\n");
    wprintw(window1, "       | |   _| |__) |  | || |    _|  |_    | || |  _| "
                     "|___/ |  | |\n");
    wprintw(window1, "       | |  |_______/   | || |   |______|   | || | "
                     "|_________|  | |\n");
    wprintw(window1, "       | |              | || |              | || |       "
                     "       | |\n");
    wprintw(window1, "       | '--------------' || '--------------' || "
                     "'--------------' |\n");
    wprintw(
        window1,
        "        '----------------'  '----------------'  '----------------'\n");

    wprintw(window1, "\n\n\n\n\n\t\t\t === press any key to exit ===");
    wrefresh(window1);
    getch();
    endwin();
}
