#include "sprite.hpp"
#include "raylib-cpp.hpp"
#include <vector>

int main(int argc, char *argv[])
{
  int screen_width{ 800 };
  int screen_height{ 600 };
  raylib::Window window(screen_width, screen_height, "Raylib Sprites");

  SetTargetFPS(60);            // Set our game to run at 60 frames-per-second

  const std::string rlcpp_dir = CMAKE_RLCPP;     // Defined in CMakeLists.txt
  const std::string res_dir   = CMAKE_RESOURCES; // ""

  raylib::AudioDevice audio{}; // necessary: initialises the audio
  raylib::Sound coin_sound{ rlcpp_dir + "/examples/audio/resources/coin.wav" };

  raylib::Texture tex1{ rlcpp_dir + "/examples/textures/resources/scarfy.png" };
  std::map<std::string, std::vector<int>> frame_ids;
  frame_ids["run"] = { 0, 1, 2, 3, 4, 5 };

  aipfg::Sprite scarfy1{ tex1, 6, 1, { 120, 300 }, frame_ids, 6 };
  aipfg::Sprite scarfy2{ tex1, 6, 1, { 520, 300 }, frame_ids, 6 };
  float delta{ -2.0f };
  scarfy2.rotation_ = delta;
  scarfy2.centre_ = { 0.5f, 0.5f };

  raylib::Texture tex2{ res_dir + "/time_fantasy/reaper_blade_3.png" };
  std::map<std::string, std::vector<int>> frame_ids2;
  frame_ids2["run"] = { 0, 1, 2 };
  aipfg::Sprite reaper{ tex2, 3, 4, { window.GetSize() / 3.0f }, frame_ids2 };

  raylib::Texture tex3{ res_dir + "/time_fantasy/knights_3x.png" };

  int ncols = 12, nrows = 8;   // 8? ... the png file contains 4 empty rows
  std::map<std::string, std::vector<int>> all_frame_ids;
  all_frame_ids["down"]  = {  3,  4,  5,  4 };
  all_frame_ids["left"]  = { 15, 16, 17, 16 };
  all_frame_ids["right"] = { 27, 28, 29, 28 };
  all_frame_ids["up"]    = { 39, 40, 41, 40 };
  aipfg::Sprite grey_knight { tex3, ncols, nrows, { 40, 200 }, all_frame_ids, 6 };

  const float grey_speed = 2.5f;

  bool reaper_collision = false; // currently colliding with the reaper?

  while (!window.ShouldClose()) // Detect window close button or ESC key
  {
    grey_knight.animation_on_ = false;

    if (IsKeyDown(KEY_DOWN))
    {
      grey_knight.posn_.y += grey_speed;
      grey_knight.set_state("down");
      grey_knight.animation_on_ = true;
    }

    if (Vector2Distance(grey_knight.posn_, reaper.posn_) < 30.0f)
    {
      if (!reaper_collision)
      {
        reaper_collision = true;
        //
      }
    }
    else
    {
      reaper_collision = false;
    }

    scarfy1.update();
    scarfy2.update();
    reaper.update();
    grey_knight.update();

    BeginDrawing();

    ClearBackground(RAYWHITE);

    // these should be drawn from back (-ve y coord) to front (+ve y coord)
    scarfy1.draw();
    scarfy2.draw();
    reaper.draw();
    grey_knight.draw();

    EndDrawing();
  }

  return 0;
}
