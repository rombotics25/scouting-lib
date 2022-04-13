#pragma once
#include "raygui.h"
#include "raylib.h"
#include <string>

class Button{
    public:
        float width;
        float height;
        float x;
        float y;
        Color color;
        Rectangle bounds;
        bool isClicked;
        int numberOfClicks;
        const char *numOfClicks;
    
        Button(){
            width = 100;
            height = 50;
            x = 0;
            y = 0;
            isClicked = false;
            numberOfClicks = 0;
        }   

        void draw(){
            numOfClicks = std::to_string(numberOfClicks).c_str();
            DrawText(numOfClicks, x + width / 2, y + height / 2, 20, BLACK);
        }

        void hangarDraw(){
            DrawText(numOfClicks, x + width / 2, y + height / 2, 20, BLACK);
        }

};