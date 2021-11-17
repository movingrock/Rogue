#include "control.cpp"
#include <time.h>

int main(void) {
    control *ctrl = new control("start", "menu_win");
    time_t start, end;
    double result;
    start = time(NULL);
    while (1) {
        ctrl->getKey();
        if (ctrl->getWindow() == "menu_win") {
            ctrl->menu();
        } else if (ctrl->getWindow() == "map_win") {
            ctrl->map();
        } else if (ctrl->getWindow() == "info_win") {
            ctrl->info();
        } else if (ctrl->getWindow() == "exit_win") {
            ctrl->exit();
        }
    }
    return 0;
}
