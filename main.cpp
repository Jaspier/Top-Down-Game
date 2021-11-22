#include "raylib.h"
#include "raymath.h"

int main()
{
    const int windowWidth{384};
    const int windowHeight{384};
    InitWindow(windowWidth, windowHeight, "Jaspier Monster Slayer!");

    Texture2D map = LoadTexture("./nature_tileset/WorldMap.png");
    Vector2 mapPos{0.0, 0.0};
    float speed{4.0};

    Texture2D Knight = LoadTexture("./characters/knight_idle_spritesheet.png");
    Vector2 KnightPos{
        (float)windowWidth/2.0f - 4.0f * (0.5f * (float)Knight.width/6.0),
        (float)windowHeight/2.0f - 4.0f * (0.5f *  (float)Knight.height)
    };

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;
        if (Vector2Length(direction) != 0.0)
        {
            // set mapPos = mapPos - direction
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
        }
        
        // draw the map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        // draw the character
        Rectangle source{0.f, 0.f, (float)Knight.width/6, (float)Knight.height};
        Rectangle dest{KnightPos.x, KnightPos.y, 4.0f * (float)Knight.width/6.0f, 4.0f * (float)Knight.height};

        DrawTexturePro(Knight, source, dest, Vector2{}, 0.f, WHITE);

        EndDrawing();
    }
    CloseWindow();
}