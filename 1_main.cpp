#include "romanLib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <string>
#include <iostream>



int main(){
    GuiEnable();
    const int screenWidth = 800;
    const int screenHeight = 450;


    Button upperHub;
    upperHub.x = (screenWidth / 2) - (upperHub.width / 2);
    upperHub.y = (screenHeight / 2) - (upperHub.height / 2);
    upperHub.bounds = {upperHub.x, upperHub.y, upperHub.width, upperHub.height};
    upperHub.color = ORANGE;


    Button lowerHub;
    lowerHub.x = (screenWidth / 3) - (lowerHub.width / 3);
    lowerHub.y = (screenHeight / 3) - (lowerHub.height / 3);
    lowerHub.bounds = {lowerHub.x, lowerHub.y, lowerHub.width, lowerHub.height};
    lowerHub.color = LIME;

    Button hangar;
    hangar.x = (screenWidth / 4) - (hangar.width / 4);
    hangar.y = (screenHeight / 4) - (hangar.height / 4);
    hangar.bounds = {hangar.x, hangar.y, hangar.width, hangar.height};
    hangar.color = RED;


    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose())    // Detect window close upperHub or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        BeginDrawing();

            

            ClearBackground(RAYWHITE);
            DrawRectangle(upperHub.bounds.x, upperHub.bounds.y, upperHub.bounds.width, upperHub.bounds.height, upperHub.color);
            DrawRectangle(lowerHub.bounds.x, lowerHub.bounds.y, lowerHub.bounds.width, lowerHub.bounds.height, lowerHub.color);
            DrawRectangle(hangar.bounds.x, hangar.bounds.y, hangar.bounds.width, hangar.bounds.height, hangar.color);
            upperHub.draw();
            lowerHub.draw();
            hangar.hangarDraw();
            //GuiButton((Rectangle){upperHub.x, upperHub.y, upperHub.width, upperHub.height}, "Upper Hub");
            
                    if(IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_ENTER)){
                        lowerHub.numberOfClicks++;
                        lowerHub.numOfClicks = std::to_string(lowerHub.numberOfClicks).c_str();
                    }
                    else if(IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_BACKSPACE)){
                        lowerHub.numberOfClicks--;
                        if(lowerHub.numberOfClicks < 0){
                            lowerHub.numberOfClicks = 0;
                        }
                        lowerHub.numOfClicks = std::to_string(lowerHub.numberOfClicks).c_str();
                    }
                    else if(!IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_ENTER)){
                        upperHub.numberOfClicks++;
                        upperHub.numOfClicks = std::to_string(upperHub.numberOfClicks).c_str();
                    }
                    else if(!IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_BACKSPACE)){
                        upperHub.numberOfClicks--;
                        if(upperHub.numberOfClicks < 0){
                            upperHub.numberOfClicks = 0;
                        }
                        upperHub.numOfClicks = std::to_string(upperHub.numberOfClicks).c_str();
                    }
                    else if(GuiButton((Rectangle){upperHub.bounds.x, upperHub.bounds.y, upperHub.bounds.width, upperHub.bounds.height}, "Upper Hub")){
                        upperHub.numberOfClicks++;
                        upperHub.numOfClicks = std::to_string(upperHub.numberOfClicks).c_str();
                    }

                    if(IsKeyDown(KEY_ONE)){
                        hangar.numberOfClicks = 1;
                    
                    }
                    else if(IsKeyPressed(KEY_TWO)){
                        hangar.numberOfClicks = 2;
                        //hangar.color = {178, 130, 0, 255};
                        hangar.color = BLUE;
                        WaitTime(600);
                        hangar.color = RED;
                    }
                    else if(IsKeyDown(KEY_THREE)){
                        hangar.numberOfClicks = 3;
                        //hangar.color = {178, 130, 0, 255};
                        //hangar.color = ORANGE;
                    }
                    else if(IsKeyDown(KEY_FOUR)){
                        hangar.numberOfClicks = 4;
                        //hangar.color = {178, 130, 0, 255};
                        //hangar.color = ORANGE;
                    }
                    else if(IsKeyDown(KEY_ZERO)){
                        hangar.numberOfClicks = 0;
                        //hangar.color = {178, 130, 0, 255};
                        //hangar.color = ORANGE;
                    }

                    if(hangar.numberOfClicks == 1){
                        hangar.numOfClicks = "Low Bar";
                    }
                    else if(hangar.numberOfClicks == 2){
                        hangar.numOfClicks = "Mid Bar";
                    }
                    else if(hangar.numberOfClicks == 3){
                        hangar.numOfClicks = "High Bar";
                    }
                    else if(hangar.numberOfClicks == 4){
                        hangar.numOfClicks = "Transversal";
                    }
                    else if(hangar.numberOfClicks == 0){
                        hangar.numOfClicks = "No Climb";
                    }

            
        EndDrawing();

        
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    
}

