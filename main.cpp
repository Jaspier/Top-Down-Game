#include "raylib.h"
int main()
{
    // Window dimensions
    const int windowWidth{384};
    const int windowHeight{384};

    // Initialize the window
    InitWindow(384, 384, "Jaspier Monster Slayer!");
    
    Texture2D map = LoadTexture("./nature_tileset/WorldMap.png");

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // draw the map
        Vector2 mapPos{0.0, 0.0};
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        // stop drawing
        EndDrawing();
    }

    UnloadTexture(map);
    CloseWindow();
}