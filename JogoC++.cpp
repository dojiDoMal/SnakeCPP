#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;

enum DIRECTION{
    STOP = 0;
    LEFT,
    UP,
    RIGHT,
    DOWN
};

DIRECTION DIR;

void Settings(){
    gameOver = false;
    DIR = STOP;
    x = width/2;
    y = height/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Visual(){
    system("cls");
    for (int i = 0; i < width + 2; i++){
        cout<< "#"
    }
    cout<< endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if(j==0 || j==width-1){
                cout<< "#";
            }
            else{
                cout<< " ";
            }
        }
        cout<< endl;
        
    }
    
    for (int i = 0; i < width + 2; i++){
        cout<< "#"
    }
    cout<< endl;
}

void Logic(){

}

void Input(){

}

int main() {
    Settings();

    while(!gameOver){
        Visual();
        Input();
        Logic();
        Sleep(10);
    }

    return 0;
}