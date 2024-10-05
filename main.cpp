#include <iostream>
#include <raylib.h>

using namespace std;

int main () {

    cout<<"Starting the game....";
    InitWindow(1000, 750, "Retro Snake");

    while(WindowShouldClose()==false){
        BeginDrawing();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}