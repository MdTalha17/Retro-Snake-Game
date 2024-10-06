#include <iostream>
#include <raylib.h>
#include <deque>
using namespace std;

Color white = {255, 255, 255, 255};
Color black = {0, 0, 0, 255};

int cellsize = 30;
int cellcount = 25;

class Snake{
    public:
        deque<Vector2> body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};

        void Draw(){
            for(unsigned i=0; i<body.size(); i++){
                float x = body[i].x;
                float y = body[i].y;
                Rectangle segment = Rectangle{x*cellsize, y*cellsize, (float)cellsize, (float)cellsize};
                DrawRectangleRounded(segment, 0.5, 6, black);
            }
        }
};

class Food{
    public:
        Vector2 position;
        Texture2D texture;

        Food(){
            Image image = LoadImage("graphics/food.png");
            texture = LoadTextureFromImage(image);
            UnloadImage(image);
            position = GenerateRandomPos();
        }

        ~Food(){
            UnloadTexture(texture);
        }

        void Draw(){
            DrawTexture(texture, position.x * cellsize, position.y * cellsize, BLACK);
        }

        Vector2 GenerateRandomPos(){
            float x = GetRandomValue(0, cellcount - 1);
            float y = GetRandomValue(0, cellcount - 1);
            return Vector2{x,y};
        }
};

int main () {

    cout<<"Starting the game....";
    InitWindow(cellsize*cellcount, cellsize*cellcount, "Retro Snake");
    SetTargetFPS(144);

    Food food = Food();
    Snake snake = Snake();

    while(WindowShouldClose() == false){
        BeginDrawing();

        //Drawing
        ClearBackground(white);
        food.Draw();
        snake.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}