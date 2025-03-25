#include "raylib-cpp.hpp"
#include <cstdlib> // std::getenv
#include <string>

// Scarfy sprite by Eiden Marsal
// Found in both raylib & raylib-cpp repos
// 768x128 - 6 square sprites - each 128x128

int main(void)
{
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Scarfy raylib animation example.");

  const std::string rlcpp_dir = CMAKE_RLCPP; // A dir defined in CMakeLists.txt
  const std::string scarfy_png =
                      rlcpp_dir + "/examples/textures/resources/scarfy.png";
  Texture2D scarfy = LoadTexture(scarfy_png.c_str()); // Texture loading

  Vector2 position = { 350.0f, 280.0f };
  Rectangle frameRec = { 0.0f, 0.0f, (float)scarfy.width/6, (float)scarfy.height };
  int currentFrame = 0;

  int framesCounter = 0;
  int framesSpeed = 8;          // Number of spritesheet frames shown by second

  SetTargetFPS(60);             // Set our game to run at 60 frames-per-second

  while (!WindowShouldClose())  // Detect window close button or ESC key
  {
    framesCounter++;

    if (framesCounter >= (60/framesSpeed))
    {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 5) currentFrame = 0;

      frameRec.x = (float)currentFrame*(float)scarfy.width/6;
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawTextureRec(scarfy, frameRec, position, WHITE);  // Draw part of the texture

    DrawText("(c) Scarfy sprite by Eiden Marsal", screenWidth - 200, screenHeight - 20, 10, GRAY);

    EndDrawing();
  }

  UnloadTexture(scarfy);       // Texture unloading

  CloseWindow();               // Close window and OpenGL context

  return 0;
}
