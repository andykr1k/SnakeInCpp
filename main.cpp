#include <iostream>
using namespace std;

void input(int &x, int &y, bool &gameover){
    char move;
    cin >> move;
    if (move != 'q'){
        if (move == 'w') {
            y--;
        } else if (move == 's') {
            y++;
        } else if (move == 'a') {
            x--;
        } else if (move == 'd') {
            x++;
        }
    } else {
            gameover = true;
        }
}

void logic(int h, int w, int pX, int pY, int &foodX, int &foodY, int &Score, bool &gameover) {
    if (pX == foodX && pY == foodY) {
        Score++;
        foodX = rand() % w;
        if (foodX == 0) {
            foodX = 1;
        }
        if (foodX == w - 1) {
            foodX = w - 2;
        }
        foodY = rand() % h;
        if (foodY == 0) {
            foodY = 1;
        }
        if (foodY == h - 1) {
            foodY = h - 2;
        }
    }

    if (pX < 1) {
        gameover = true;
    } else if (pX >= w -1) {
        gameover = true;
    } else if (pY < 1) {
        gameover = true;
    } else if (pY >= h -1) {
        gameover = true;
    }
}

void draw(int h, int w, int pX, int pY, int foodX, int foodY, int Score) {
    system("clear");
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
        cout << endl;
    }
    cout << "Score: " << Score << endl;
    cout << "Press q to quit" << endl;
    cout << "W = UP - S = DOWN \nA = LEFT - S = RIGHT \nCONFIRM - ENTER" << endl;
}

int main() {
        bool gameover = false;
        int height = 20, width = 20, score = 0;
        int pX = 3, pY =  7, foodX = 5, foodY = 5;

        while (!gameover){
            draw(height, width, pX, pY, foodX, foodY, score);
            input(pX, pY, gameover);
            logic(height, width, pX, pY, foodX, foodY, score, gameover);
        }

        system("clear");
        cout << "Game over" << endl;
        cout << "Score: " << score << endl;
        cout << "Thank you for playing" << endl;
        return 0;
}