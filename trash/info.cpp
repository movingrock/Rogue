#include "info.h"
#include <ncurses.h>
void info() {
    WINDOW *window1;
    WINDOW *window2;
    WINDOW *window3;

    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    refresh();

    window1 = newwin(9, 80, 0, 0);
    window2 = newwin(15, 40, 9, 0);
    window3 = newwin(15, 40, 9, 40);

    wbkgd(window1, COLOR_PAIR(1));
    wbkgd(window2, COLOR_PAIR(1));
    wbkgd(window3, COLOR_PAIR(1));

    wprintw(window1,
            "     __o__       o          o        o__ __o__/_           "
            "o__ __o      \n");
    wprintw(window1,
            "       |        <|\\        <|>      <|    v               "
            "/v     v\\     \n");
    wprintw(window1,
            "      / \\       / \\o       / \\      < >                  "
            "/>       <\\    \n");
    wprintw(window1,
            "      \\o/       \\o/ v\\     \\o/       |                 "
            "o/           \\o  \n");
    wprintw(window1,
            "       |         |   <\\     |        o__/_            <|    "
            "         |> \n");
    wprintw(window1,
            "      < >       / \\    \\o  / \\       |                 \\  "
            "         //  \n");
    wprintw(window1,
            "       |        \\o/     v\\ \\o/      <o>                  "
            "\\         /    \n");
    wprintw(window1,
            "       o         |       <\\ |        |                    o "
            "      o     \n");
    wprintw(window1,
            "     __|>_      / \\        < \\      / \\                   "
            "<\\__ __/>     \n");

    wprintw(window2, "\n");
    wprintw(window2, "W     Move UP\n");
    wprintw(window2, "A     Move LEFT\n");
    wprintw(window2, "S     Move DOWN\n");
    wprintw(window2, "D     Move RIGHT\n\n");
    wprintw(window2, "Z     Confirm\n");
    wprintw(window2, "X     Cancel\n");
    wprintw(window2, "C     Inventory\n");
    wprintw(window3, "\n");
    wprintw(window3, "1     ITEM 1\n");
    wprintw(window3, "2     ITEM 2\n");
    wprintw(window3, "3     ITEM 3\n");
    wprintw(window3, "4     ITEM 4\n");
    wprintw(window3, "5     ITEM 5\n");
    wprintw(window3, "6     ITEM 6\n");

    wrefresh(window1);
    wrefresh(window2);
    wrefresh(window3);
}
