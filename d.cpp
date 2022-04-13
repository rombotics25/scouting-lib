/*******************************************************************************************
*
*   raylib [core] example - Basic 3d example
*
*   Welcome to raylib!
*
*   To compile example, just press F5.
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

/*#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;

class Button{
    public:
        float width;
        float height;
        float x;
        float y;
        Color color;
        Rectangle rec;
        bool isClicked;
        int numberOfClicks;
    
        Button(){
            width = 100;
            height = 50;
            x = 0;
            y = 0;
            color = RED;
            isClicked = false;
            numberOfClicks = 0;
        }
};

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    Button button;
    button.x = (screenWidth / 2) - (button.width / 2);
    button.y = (screenHeight / 2) - (button.height / 2);
    button.rec = {button.x, button.y, button.width, button.height};
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            DrawRectangle(button.rec.x, button.rec.y, button.rec.width, button.rec.height, button.color);
            button.onClick();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
*/

