// #include <cstdlib>
// #include <ctime>
// #include <iostream>
// #include <ncurses.h>

// using namespace std;

// class maping {
//   private:
//     int px;
//     int py;

//   public:
//     maping(int px, int py);
//     void drawmap();
// };

// maping::maping(int px, int py) {
//     this->px = px;
//     this->py = py;
// }

// void maping::drawmap() {
//     WINDOW *map_win;
//     WINDOW *player;
//     WINDOW *tree;
//     initscr();
//     keypad(stdscr, TRUE);
//     start_color();
//     init_pair(1, COLOR_WHITE, COLOR_BLACK);
//     init_pair(2, COLOR_YELLOW, COLOR_BLACK);
//     init_pair(3, COLOR_GREEN, COLOR_BLACK);
//     refresh();

//     srand((unsigned int)time(NULL));
//     int tx = rand();
//     int ty = rand();

//     map_win = newwin(24, 80, 0, 0);
//     player = newwin(1, 1, px, py);
//     tree = newwin(1, 1, tx % 22, ty % 78);
//     wbkgd(map_win, COLOR_PAIR(1));
//     wbkgd(player, COLOR_PAIR(2));
//     wbkgd(tree, COLOR_PAIR(3));
//     wborder(map_win, '|', '|', '-', '-', '+', '+', '+', '+');
//     wprintw(player, "@");
//     wprintw(tree, "T");

//     for (int i = 0; i < 20; ++i) {
//         tree = newwin(1, 1, tx % 22, ty % 78);
//         wrefresh(tree);
//     }

//     wrefresh(map_win);
//     wrefresh(player);
//     wrefresh(tree);

//     mvwin(player, py, px);
//     touchwin(player);
//     wrefresh(map_win);
//     wrefresh(player);
//     wrefresh(tree);
// }

// int main(void) {
//     maping *map = new maping(22, 40);
//     map->drawmap();
// }
