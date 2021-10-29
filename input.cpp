#ifndef __INPUT_CPP__
#define __INPUT_CPP__

#include <iostream>
#include <ncurses.h>

using namespace std;

static string cursor = "start";
static string window = "menu_w";

void getKey() {
    int key = getch();
    if (key == 'w' || key == 'W') {
        if (cursor == "info") {
            cursor = "start";
        } else if (cursor == "exit") {
            cursor = "info";
        }
    } else if (key == 'a' || key == 'A') {
        printf("LEFT");
    } else if (key == 's' || key == 'S') {
        if (cursor == "start") {
            cursor = "info";
        } else if (cursor == "info") {
            cursor = "exit";
        }
    } else if (key == 'd' || key == 'D') {
        printf("RIGHT");
    } else if (key == 'z' || key == 'Z') {
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
        }
    }
}

#endif
