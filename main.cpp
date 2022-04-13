#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <string>
#include <iostream>
#define MAX_INPUT_CHARS     150


const int screenWidth = 1280;
const int screenHeight = 720;



bool upperHub(){
        return GuiButton((Rectangle){100, 100, 75, 75}, "Upper Hub");
    }
bool lowerHub(){
    return GuiButton((Rectangle){100, 200, 75, 75}, "Lower Hub");
    }
bool hangar(){
    return GuiButton((Rectangle){100, 300, 75, 75}, "Hangar");
    }

int commentsBox(){
    return GuiTextInputBox((Rectangle){100, 400, 300, 100}, "Comments", "", "100", "Text");
}

bool GTB(){
    return GuiTextBox((Rectangle){100, 500, 300, 100}, "", 100, "Text");
}
 

 class buttonValueDraw{
     public:
            void draw(int value, const char *text, int x, int y, Color color){
                text = std::to_string(value).c_str();
                DrawText(text, x, y, 20, color);
            }
 };


int main(){
    

    //bool upperHub = GuiButton((Rectangle){100, 100, 200, 50}, "Upper Hub");
    //bool lowerHub = GuiButton((Rectangle){100, 200, 200, 50}, "Lower Hub");
    //bool hangar = GuiButton((Rectangle){100, 300, 200, 50}, "Hangar");

    
    /*char name[MAX_INPUT_CHARS + 1] = "\0";      // NOTE: One extra space required for null terminator char '\0'
    int letterCount = 0;

    Rectangle textBox = { screenWidth/2.0f - 100, 180, 225, 50 };
    bool mouseOnText = false;

    int framesCounter = 0;*/

    int upperHubClicks = 0;
    int lowerHubClicks = 0;
    int hangarClicks = 0;

    const char *upperHubClicksChar = "";
    const char *lowerHubClicksChar = "";
    const char *hangarClicksChar = "";
    char *comments = "";

    buttonValueDraw upper;
    buttonValueDraw lower;
    buttonValueDraw hang;

    char name[MAX_INPUT_CHARS + 1] = "\0";      // NOTE: One extra space required for null terminator char '\0'
    int letterCount = 0;

    Rectangle textBox = { screenWidth/2.0f - 100, 180, 225, 50 };
    bool mouseOnText = false;

    int framesCounter = 0;

    GuiEnable();
    int editMode = GuiGetState();

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    // Main game loop
    while(!WindowShouldClose()){


        // Update
        //----------------------------------------------------------------------------------   
        if(upperHub() == true && IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)){
            upperHubClicks--;
            if(upperHubClicks < 0){
                upperHubClicks = 0;
            }
            upperHubClicksChar = std::to_string(upperHubClicks).c_str();
        }
        
        if(upperHub() == true && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
            upperHubClicks++;
            upperHubClicksChar = std::to_string(upperHubClicks).c_str();
        }

        if(lowerHub() == true && IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)){
            lowerHubClicks--;
            if(lowerHubClicks < 0){
                lowerHubClicks = 0;
            }
            lowerHubClicksChar = std::to_string(lowerHubClicks).c_str();
        }
        
        if(lowerHub() == true && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
            lowerHubClicks++;
            lowerHubClicksChar = std::to_string(lowerHubClicks).c_str();
        } //

        if(hangar() == true && IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)){
            hangarClicks--;
            if(hangarClicks < 0){
                hangarClicks = 0;
            }
            hangarClicksChar = std::to_string(hangarClicks).c_str();
        }

        if(hangar() == true && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
            hangarClicks++;
            hangarClicksChar = std::to_string(hangarClicks).c_str();
        }

        if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
        else mouseOnText = false;

        if (mouseOnText)
        {
            // Set the window's cursor to the I-Beam
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            // Get char pressed (unicode character) on the queue
            int key = GetCharPressed();

            // Check if more characters have been pressed on the same frame
            while (key > 0)
            {
                // NOTE: Only allow keys in range [32..125]
                if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
                {
                    name[letterCount] = (char)key;
                    name[letterCount+1] = '\0'; // Add null terminator at the end of the string.
                    letterCount++;
                }

                key = GetCharPressed();  // Check next character in the queue
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                name[letterCount] = '\0';
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (mouseOnText) framesCounter++;
        else framesCounter = 0;
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);
         DrawText("PLACE MOUSE OVER INPUT BOX!", 240, 140, 20, GRAY);

            DrawRectangleRec(textBox, LIGHTGRAY);
            if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
            else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

            DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 10, MAROON);

            DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), 315, 250, 20, DARKGRAY);

            if (mouseOnText)
            {
                if (letterCount < MAX_INPUT_CHARS)
                {
                    // Draw blinking underscore char
                    if (((framesCounter/20)%2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 20, MAROON);
                }
                else DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
            }
        upperHub();
        lowerHub();
        hangar();
        //commentsBox();
        //GTB();

        GuiTextBox((Rectangle){100, 400, 400, 50}, comments, 200, editMode);
        //GuiTextInputBox((Rectangle){100, 400, 300, 100}, "Comments", "", "100", "Text");

        //DrawText(upperHubClicksChar, 100, 100, 20, BLACK);
        upper.draw(upperHubClicks, upperHubClicksChar, 100, 100, BLACK);
        //DrawText(lowerHubClicksChar, 100, 200, 20, BLACK);
        lower.draw(lowerHubClicks, lowerHubClicksChar, 100, 200, BLACK);
        //DrawText(hangarClicksChar, 100, 300, 20, BLACK);
        hang.draw(hangarClicks, hangarClicksChar, 100, 300, BLACK);



                
        EndDrawing();
        

        std::cout << name << std::endl;
    }
}

bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}