#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ncurses.h>

using namespace std;

class control {
  private:
    string cursor = "start";
    string window = "menu_win";
    string player = "alive";
    int px = 22;
    int py = 40;
    WINDOW *TREE[30];

  public:
    control(string cursor, string window);
    string getCursor();
    string getWindow();
    string getPlayer();
    void getKey();
    void info();
    void exit();
    void status();
    void inven();
    void map();
    void menu();
    void dead(double result);
};

control::control(string cursor, string window) {
    this->cursor = cursor;
    this->window = window;
}

string control::getCursor() { return cursor; }
string control::getWindow() { return window; }
string control::getPlayer() { return player; }

void control::getKey() {
    int key = getch();
    if (key == 'w' || key == 'W' || key == KEY_UP) {
        if (cursor == "info") {
            cursor = "start";
        } else if (cursor == "exit") {
            cursor = "info";
        } else if (window == "map_win") {
            px -= 1;
        }
    } else if (key == 'a' || key == 'A' || key == KEY_LEFT) {
        if (window == "map_win") {
            py -= 1;
        }
    } else if (key == 's' || key == 'S' || key == KEY_DOWN) {
        if (cursor == "start") {
            cursor = "info";
        } else if (cursor == "info") {
            cursor = "exit";
        } else if (window == "map_win") {
            px += 1;
        }
    } else if (key == 'd' || key == 'D' || key == KEY_RIGHT) {
        if (window == "map_win") {
            py += 1;
        }
    } else if (key == 'z' || key == 'Z' || key == KEY_ENTER) {
        if (cursor == "start") {
            window = "map_win";
        } else if (cursor == "info") {
            window = "info_win";
        } else if (cursor == "exit") {
            window = "exit_win";
        }
    } else if (key == 'x' || key == 'X') {
        if (window == "info_win") {
            window = "menu_win";
        } else if (window == "inv_win") {
            window = "map_win";
        }
    } else if (key == 'c' || key == 'C') {
        if (window == "map_win") {
            window = "inv_win";
        } else if (window == "inv_win") {
            window = "map_win";
        }
    } else if (key == 'r' || key == 'R') {
        if (window == "map_win") {
            window = "menu_win";
        }
    }
}

void control::info() {
    WINDOW *info_name;
    WINDOW *info_1;
    WINDOW *info_2;

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    refresh();

    info_name = newwin(9, 80, 0, 0);
    info_1 = newwin(15, 40, 9, 0);
    info_2 = newwin(15, 40, 9, 40);

    wbkgd(info_name, COLOR_PAIR(1));
    wbkgd(info_1, COLOR_PAIR(1));
    wbkgd(info_2, COLOR_PAIR(1));

    wprintw(info_name,
            "     __o__       o          o        o__ __o__/_           "
            "o__ __o      \n");
    wprintw(info_name,
            "       |        <|\\        <|>      <|    v               "
            "/v     v\\     \n");
    wprintw(info_name,
            "      / \\       / \\o       / \\      < >                  "
            "/>       <\\    \n");
    wprintw(info_name,
            "      \\o/       \\o/ v\\     \\o/       |                 "
            "o/           \\o  \n");
    wprintw(info_name,
            "       |         |   <\\     |        o__/_            <|    "
            "         |> \n");
    wprintw(info_name,
            "      < >       / \\    \\o  / \\       |                 \\  "
            "         //  \n");
    wprintw(info_name,
            "       |        \\o/     v\\ \\o/      <o>                  "
            "\\         /    \n");
    wprintw(info_name,
            "       o         |       <\\ |        |                    o "
            "      o     \n");
    wprintw(info_name,
            "     __|>_      / \\        < \\      / \\                   "
            "<\\__ __/>     \n");

    wprintw(info_1, "\n");
    wprintw(info_1, "W     Move UP\n");
    wprintw(info_1, "A     Move LEFT\n");
    wprintw(info_1, "S     Move DOWN\n");
    wprintw(info_1, "D     Move RIGHT\n\n");
    wprintw(info_1, "Z     Confirm\n");
    wprintw(info_1, "X     Cancel\n");
    wprintw(info_1, "C     Inventory\n");
    wprintw(info_2, "\n");
    wprintw(info_2, "1     ITEM 1\n");
    wprintw(info_2, "2     ITEM 2\n");
    wprintw(info_2, "3     ITEM 3\n");
    wprintw(info_2, "4     ITEM 4\n");
    wprintw(info_2, "5     ITEM 5\n");
    wprintw(info_2, "6     ITEM 6\n");

    wrefresh(info_name);
    wrefresh(info_1);
    wrefresh(info_2);
}

void control::exit() {
    WINDOW *exit_win;
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    refresh();

    exit_win = newwin(24, 80, 0, 0);

    wbkgd(exit_win, COLOR_PAIR(1));

    wprintw(exit_win, "        .----------------.  .----------------.  "
                      ".----------------. \n");
    wprintw(exit_win, "       | .--------------. || .--------------. || "
                      ".--------------. |\n");
    wprintw(exit_win, "       | |   ______     | || |  ____  ____  | || |  "
                      "_________   | |\n");
    wprintw(exit_win,
            "       | |  |_   _ \\    | || | |_  _||_  _| | || | |_   "
            "___  |  | |\n");
    wprintw(exit_win,
            "       | |    | |_) |   | || |   \\ \\  / /   | || |   | "
            "|_  \\_|  | |\n");
    wprintw(exit_win,
            "       | |    |  __'.   | || |    \\ \\/ /    | || |   |  "
            "_|  _   | |\n");
    wprintw(exit_win, "       | |   _| |__) |  | || |    _|  |_    | || |  _| "
                      "|___/ |  | |\n");
    wprintw(exit_win, "       | |  |_______/   | || |   |______|   | || | "
                      "|_________|  | |\n");
    wprintw(exit_win,
            "       | |              | || |              | || |       "
            "       | |\n");
    wprintw(exit_win, "       | '--------------' || '--------------' || "
                      "'--------------' |\n");
    wprintw(
        exit_win,
        "        '----------------'  '----------------'  '----------------'\n");

    wprintw(exit_win, "\n\n\n\n\n\t\t\t === press any key to exit ===");
    wrefresh(exit_win);
    getch();
    endwin();
}

void control::status() {}

void control::inven() {
    WINDOW *inven_name;
    WINDOW *inven_1;

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    refresh();

    inven_name = newwin(2, 30, 0, 50);
    inven_1 = newwin(22, 30, 2, 50);
    wbkgd(inven_name, COLOR_PAIR(1));
    wbkgd(inven_1, COLOR_PAIR(1));

    wprintw(inven_name, "\tINVENTORY");
    wprintw(inven_1, "portion");

    wrefresh(inven_name);
    wrefresh(inven_1);
}

void control::map() {
    WINDOW *map_win;
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    refresh();

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 30; i++) {
        int tx = rand();
        int ty = rand();
        TREE[i] = newwin(1, 1, (ty % 20) + 1, (tx % 45) + 1);
        wbkgd(TREE[i], COLOR_PAIR(3));
        wprintw(TREE[i], "T");
    }
    map_win = newwin(24, 50, 0, 0);

    wbkgd(map_win, COLOR_PAIR(1));

    wborder(map_win, '*', '*', '*', '*', '+', '+', '+', '+');

    wrefresh(map_win);
    for (int i = 0; i < 30; i++) {
        wrefresh(TREE[i]);
    }
    inven();
}

void control::menu() {
    WINDOW *menu_win;
    WINDOW *start_but;
    WINDOW *info_but;
    WINDOW *exit_but;
    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_WHITE);
    init_pair(3, COLOR_WHITE, COLOR_BLUE);
    refresh();
    menu_win = newwin(19, 80, 0, 0);
    start_but = newwin(1, 20, 19, 30);
    info_but = newwin(1, 20, 20, 30);
    exit_but = newwin(1, 20, 21, 30);
    wbkgd(menu_win, COLOR_PAIR(1));
    wbkgd(start_but, COLOR_PAIR(2));
    wbkgd(info_but, COLOR_PAIR(2));
    wbkgd(exit_but, COLOR_PAIR(2));
    wprintw(menu_win, "\n\n\n\n\n");
    wprintw(
        menu_win,
        "          |======      =======     =======      ==    ==      ====\n");

    wprintw(menu_win,
            "          |  __  \\    /  ___  \\   / ______\\    |  |  |  "
            "|    |   _|\n");

    wprintw(menu_win, "        __| |__| |____| |___| |___| |__________|  |__|  "
                      "|____|  |____\n");

    wprintw(menu_win, "       / _| |__| |____| |___| |___| |_ ____ ___|  |__|  "
                      "|___ |     | |\n");

    wprintw(menu_win,
            "       \\__| ____ \\____| |___| |___| |_|_  _|___|  |__|  "
            "|____|   __|_|\n");

    wprintw(menu_win,
            "          | |   \\ \\   | |___| |   | |___| |    |  |__| "
            " |    |  |_\n");

    wprintw(menu_win, "          |_|   |_|   \\_______/   \\_______/    "
                      "\\________/    |____|\n");

    wprintw(menu_win, "\t\t\t\t\t\t\t\tLIKE");

    wrefresh(menu_win);
    if (cursor == "start") {
        wbkgd(start_but, COLOR_PAIR(3));
    }
    if (cursor == "info") {
        wbkgd(info_but, COLOR_PAIR(3));
    }
    if (cursor == "exit") {
        wbkgd(exit_but, COLOR_PAIR(3));
    }

    wprintw(start_but, "\tSTART");
    wprintw(info_but, "\tINFO");
    wprintw(exit_but, "\tEXIT");

    wrefresh(start_but);
    wrefresh(info_but);
    wrefresh(exit_but);
}

void control::dead(double result) {
    WINDOW *dead_win;
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    refresh();

    dead_win = newwin(24, 80, 0, 0);
    wprintw(dead_win, " .----------------. .----------------. "
                      ".----------------. .----------------. \n");
    wprintw(dead_win, "| .--------------. | .--------------. | "
                      ".--------------. | .--------------. |\n");
    wprintw(dead_win, "| |  ________    | | |  _________   | | |      __      "
                      "| | |  ________    | |\n");
    wprintw(dead_win, "| | |_   ___ `.  | | | |_   ___  |  | | |     /  \\     "
                      "| | | |_   ___ `.  | |\n");
    wprintw(dead_win,
            "| |   | |   `. \\ | | |   | |_  \\_|  | | |    / /\\ \\    "
            "| | |   | |   `. \\ | |\n");
    wprintw(dead_win, "| |   | |    | | | | |   |  _|  _   | | |   / ____ \\   "
                      "| | |   | |    | | | |\n");
    wprintw(dead_win,
            "| |  _| |___.' / | | |  _| |___/ |  | | | _/ /    \\ \\_ "
            "| | |  _| |___.' / | |\n");
    wprintw(dead_win, "| | |________.'  | | | |_________|  | | ||____|  "
                      "|____|| | | |________.'  | |\n");
    wprintw(dead_win, "| |              | | |              | | |              "
                      "| | |              | |\n");
    wprintw(dead_win, "| '--------------' | '--------------' | "
                      "'--------------' | '--------------' |\n");
    wprintw(dead_win, " '----------------' '----------------' "
                      "'----------------' '----------------' \n\n\n");

    wprintw(dead_win, "Survive Time:");

    wrefresh(dead_win);
}
