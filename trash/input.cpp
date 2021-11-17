#include "input.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

string cursor = "start";
string window = "menu_w";

extern int px;
extern int py;

void getKey() {
    int key = getch();
    if (key == 'w' || key == 'W' || key == KEY_UP) {
        if (cursor == "info") {
            cursor = "start";
        } else if (cursor == "exit") {
            cursor = "info";
        } else if (window == "map_w") {
            px += 1;
        }
    } else if (key == 'a' || key == 'A' || key == KEY_LEFT) {
        if (window == "map_w") {
            py -= 1;
        }
    } else if (key == 's' || key == 'S' || key == KEY_DOWN) {
        if (cursor == "start") {
            cursor = "info";
        } else if (cursor == "info") {
            cursor = "exit";
        } else if (window == "map_w") {
            px -= 1;
        }
    } else if (key == 'd' || key == 'D' || key == KEY_RIGHT) {
        if (window == "map_w") {
            py += 1;
        }
    } else if (key == 'z' || key == 'Z' || key == KEY_ENTER) {
        if (cursor == "start") {
            window = "map_w";
        } else if (cursor == "info") {
            window = "info_w";
        } else if (cursor == "exit") {
            window = "exit_w";
        }
    } else if (key == 'x' || key == 'X') {
        if (window == "info_w") {
            window = "menu_w";
        } else if (window == "inv_w") {
            window = "map_w";
        }
    } else if (key == 'c' || key == 'C') {
        if (window == "map_w") {
            window = "inv_w";
        } else if (window == "inv_w") {
            window = "map_w";
        }
    }
}
