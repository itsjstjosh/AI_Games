#include "openai-helper.hpp"
#include "raylib-cpp.hpp"

int main()
{
  aipfg::openai_helper oai_help;

  float screenWidth = 800;
  float screenHeight = 600;
  raylib::Window window(screenWidth, screenHeight, "Raylib Chatbot");

  SetTargetFPS(60);

  float rotation{0};

  while (!window.ShouldClose()) // Detect window close button or ESC key
  {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    std::string s{"Hello Text!"};
    DrawText(s.c_str(), 240, 140, 40, GRAY); // This c_str *is* needed.

    DrawPoly({600,400}, 5, 80, rotation, { 255,0,0,255 });

    rotation+=4;

    EndDrawing();
  }

  return 0;
}
