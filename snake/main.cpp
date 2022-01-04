#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

bool gameOver;
int tailX[50], tailY[50];
int tail;
const int width = 10;
const int height = 10;
int x, y, fruitX, fruitY, score;

enum DIRECTION{
    STOP = 0,
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
        cout<< "#";
    }
    cout<< endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if(j==0 || j==width-1){
                cout<< "#";
            }
            if(i==y && j==x){
                cout<<"O";
            }
            else if(i==fruitY && j == fruitX){
                cout<< "*";
            }
            else{
                bool printTail = false;
                for (int k = 0; k < tail; i++)
                {
                    if(tailX[k] == j && tailY[k] == y){
                        cout << "o";
                        printTail=true;
                    }
                }
                
                cout<< " ";
            }
        }
        cout<< endl;
        cout<< "Score: " << score << endl;
        
    }
    
    for (int i = 0; i < width + 2; i++){
        cout<< "#";
    }
    cout<< endl;
}

void Logic(){
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < tail; i++)
    {
        prev2X = tailX[1];
        prev2Y = tailY[1];
        tailX[1] = prevX;
        tailY[1] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    

    switch(DIR){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    if(x>=width){
        x=0;
    }
    else if(x<0){
        x=width-1;
    }

    if(y>=height){
        y=0;
    }
    else if(y<0){
        y=height-1;
    }

    for (int i = 0; i < tail; i++)
    {
        if(tailX[i] == x && tailY[i] == y) gameOver = true;
    }

    if(x==fruitX && y==fruitY){
        score++;
        fruitX = rand() % width;
        fruitY = rand() % height;
        tail++;
    }
}

void Input(){
    if(_kbhit()){
        switch(_getch()){
            case 'a':
                DIR = LEFT;
                break;
            case 's':
                DIR = DOWN;
                break;
            case 'w':
                DIR = UP;
                break;
            case 'd':
                DIR = RIGHT;
                break;
            case 'x':
                gameOver = true;   
                break;
        }
    }
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