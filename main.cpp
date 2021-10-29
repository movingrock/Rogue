#include "exit.cpp"
#include "info.cpp"
#include "input.cpp"
#include "menu.cpp"

int main(void) {
    while (1) {
        clear;
        if (window == "menu_w") {
            menu();
        } else if (window == "info_w") {
            info();
        } else if (window == "exit_w") {
            exit();
        }
        getKey();
    }

    return 0;
}
