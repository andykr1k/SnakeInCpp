#include <iostream>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

int main() {
        bool gameover = false;
        int height = 20, width = 20, score = 0;
        int pX, pY, foodX, foodY;

        while (!gameover){
            draw(height, width, pX, pY, foodX, foodY, score);
            input(pX, pY);
            logic(height, width, pX, pY, foodX, foodY, score);
        }
}

void input(int x, int y){
    if (!getch()){
        char c = getch();
        if (c == 'w') {
            y--;
        } else if (c == 's') {
            y++;
        } else if (c == 'a') {
            x--;
        } else if (c == 'd') {
            x++;
        } else if (c == 'q') {
            exit(0);
        }
    }
}

void logic(int h, int w, int pX, int pY, int foodX, int foodY, int Score) {

}

void draw(int h, int w, int pX, int pY, int foodX, int foodY, int Score) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                cout << "#";
            } else if (i == pY && j == pX) {
               cout << "O";
            } else if (i == foodY && j == foodX) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
    }
    cout << "Score: " << Score << endl;
    cout << "Press q to quit" << endl;
}