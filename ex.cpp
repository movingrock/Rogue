#include <ncurses.h>

// 받는 글자 확인하기
int main(void) {
    initscr();
    int c;
    while ((c = getch()) != 27) {
        move(10, 0);
        printw("Keycode: %d, and the character: %c", c, c);
        move(0, 0);
        printw("ESC to escape: ");
        refresh();
    }
    endwin();
}
