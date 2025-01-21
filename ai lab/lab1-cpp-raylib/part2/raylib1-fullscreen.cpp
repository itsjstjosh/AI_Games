#include "raylib-cpp.hpp"
#include <string> // std::string, std::to_string

// C++ Documentation is at https://robloach.github.io/raylib-cpp/index.html
// ... and https://www.raylib.com/cheatsheet/cheatsheet.html

// 1. Uncomment the three rotation value increments within the while loop
// 2. Change the colour or position of the rectange "rect"
// 3. Change the second (source) parameter of DrawRectanglePro to {0,0}
//    It then rotates around one of its corners rather than its centre.
// 4. What does the "5" in the DrawPoly function call do?

int main(int argc, char *argv[])
{
  raylib::Window window{ 800, 600, "Raylib Lab 1 (Resizable)" };
  window.SetState(FLAG_WINDOW_RESIZABLE);

  raylib::RenderTexture rt{ GetScreenWidth(), GetScreenHeight() };

  const std::string version = std::string{ RAYLIB_VERSION } + '.' + std::to_string(RAYLIB_VERSION_PATCH); // e.g. "5.5.0"
  const std::string logo_path = std::string{ "../../../raylib-cpp-" } + version + "/examples/textures/resources/raylib_logo.png";
  raylib::Texture logo{ logo_path };

  raylib::Rectangle rect{ 150, 150, 140, 50 };

  SetTargetFPS(60);

  float rotation1{ 0 }, rotation2{ 0 }, rotation3{ 0 };

  float rw = rect.GetWidth();
  float rh = rect.GetHeight();
  float w = logo.GetWidth();
  float h = logo.GetHeight();

  // Source rectangle (part of the texture to use for drawing)
  Rectangle sourceRec{ 0, 0, w, h };

  // Destination rectangle (screen rectangle where drawing part of texture)
  Rectangle destRec{ GetScreenWidth()/2.0f, GetScreenHeight()/2.0f, w*2, w*2 };

  // Origin of the texture (rotation/scale point),
  // it's relative to destination rectangle size
  Vector2 origin{ w, h };

  while (!window.ShouldClose()) // Detect window close button or ESC key
  {
    BeginTextureMode(rt);

    ClearBackground(RAYWHITE);

    DrawRectanglePro(rect, { rw/2, rh/2 }, rotation1, GREEN);

    DrawTexturePro(logo, sourceRec, destRec, origin, rotation2, WHITE);

    DrawPoly({ 600, 400 }, 5, 80, rotation3, { 255, 0, 0, 255 });

    //rotation1+=3;
    //rotation2-=2;
    //rotation3+=4;

    EndTextureMode();

    BeginDrawing();
    DrawTexturePro(
      rt.texture,
      Rectangle{ 0, 0, static_cast<float>(rt.texture.width), static_cast<float>(-rt.texture.height) },
      Rectangle{ 0, 0, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) },
      Vector2{ 0, 0 },
      0,
      WHITE);
    EndDrawing();
  }

  return 0;
}
