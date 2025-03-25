#include "sprite.hpp"
#include "raylib-cpp.hpp"
#include <iostream>   // std::cout, std::endl
#include <future>     // std::async
#include <functional> // std::ref
#include <thread>     // std::this_thread::sleep_for
#include <chrono>     // std::chrono::seconds

void internet_request(const int &input, int &output)
{
  std::this_thread::sleep_for(std::chrono::seconds(5));
  output = input * 2 + output;
}

int main(int argc, char *argv[])
{
  using namespace aipfg;

  raylib::Window window(1024, 576, "Raylib Llama2 NPCs");

  const std::string res_dir   = CMAKE_RESOURCES; // Defined in CMakeLists.txt
  SetTargetFPS(60);            // Set our game to run at 60 frames-per-second

  raylib::AudioDevice audio{}; // necessary: initialises the audio
  raylib::Music music{ res_dir + "/audio/Magic-Clock-Shop.mp3" };
  music.Play();

  raylib::Texture tex{ res_dir + "/time_fantasy/knights_3x.png" };
  const int ncols = 12, nrows = 8;
  Vector2 posn{ 150.0f, 100.0f };
  std::map<std::string, std::vector<int>> all_frame_ids;
  all_frame_ids["left"] = { 21, 22, 23, 22 };
  Sprite green_knight { tex, ncols, nrows, posn, all_frame_ids, 6 };
  green_knight.set_state("left");
  const float speed = 2.5f;
  int internet_result = -1;
  const float sprite_width = tex.width / ncols;

  std::future<void> future_handle{};

  while (!window.ShouldClose()) // Detect window close button or ESC key
  {
    music.Update();

    green_knight.posn_.x -= speed;

    if (green_knight.posn_.x < (-sprite_width))
    {
      green_knight.posn_.x = window.GetWidth();
    }

    // check the handle is valid AND future::wait_for returns std::future_status::ready
    if (false)  // change this from false
    {
      future_handle.get(); // invalidates the future
      std::cout << "internet_result is now " << internet_result << std::endl;
    }

    green_knight.update(); // update animation

    switch (GetKeyPressed())
    {
      case KEY_ENTER:
      {
        std::cout << "internet_result: " << internet_result << std::endl;
        internet_request(21, internet_result); // use async here
      }
        break;

      default:
        break;
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    green_knight.draw();
    DrawText("Press Enter to pretend a slow llama.cpp request", 20, 20, 20, RED);

    EndDrawing();
  }

  return 0;
}
