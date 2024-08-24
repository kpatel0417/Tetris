#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>


double lastUpdateTime = 0;

bool EventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(500,620, "Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();
    
    while(WindowShouldClose() == false) {
        game.HandleInput();
        if (EventTriggered(0.2)) {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(babyPink);
        DrawTextEx(font, "Score", {360,15}, 38, 2, BLACK);
        DrawTextEx(font, "Next", {370,175}, 38, 2, BLACK);
        if (game.gameOver) {
            DrawTextEx(font, "GAME OVER", {320, 450}, 30, 2, BLACK);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, grey);

        char scoreText[10];
        snprintf(scoreText, sizeof(scoreText), "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        
        DrawTextEx(font, scoreText, {320 + (170-textSize.x)/2,65}, 38, 2, BLACK);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, grey);
        game.Draw(); 
        EndDrawing();
    }

    CloseWindow();
}