#include <iostream>
#include <raylib.h>
using namespace std;

Color white = {255, 255, 255, 255};
Color black = {0, 0, 0, 255};

int main () {

    cout<<"Starting the game....";
    InitWindow(1000, 750, "Retro Snake");
    SetTargetFPS(144);

    while(WindowShouldClose() == false){
        BeginDrawing();
        
        //Drawing
        ClearBackground(white);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}