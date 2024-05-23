#include <cmath>
#include <cstdlib>
#include <fmt/core.h>
#include <raygui.h>
#include <raylib.h>
#include <sorts.hpp>
#include <thread>
#include <vector>

#define SIZE 1000

struct State {
  std::string algoName;
  bool is_randomizing;
  bool is_running;
} SortState;

void sortAnimations(std::vector<int> &values) {
  using namespace std::chrono_literals;

  std::this_thread::sleep_for(2s);
  randomize(values);

  std::this_thread::sleep_for(2s);
  radixSort(values);

  std::this_thread::sleep_for(2s);
  randomize(values);

  std::this_thread::sleep_for(2s);
  bubbleSort(values);

  std::this_thread::sleep_for(2s);
  randomize(values);

  std::this_thread::sleep_for(2s);
  selectionSort(values);

  sortAnimations(values);
}

void renderValues(std::vector<int> &values, RenderTexture &tex) {

  BeginTextureMode(tex);
  ClearBackground(BLACK);
  for (int i = 0; i < values.size(); i++) {
    DrawRectangle(i, 0, (int)(tex.texture.width / values.size()), values[i],
                  RED);
  }
  EndTextureMode();
}

int main() {

  InitWindow(1500, 1500, "Sort Visuals");
  SetWindowState(FLAG_WINDOW_RESIZABLE);

  RenderTexture2D texture = LoadRenderTexture(SIZE, SIZE);

  int x = 40000;
  std::vector<int> arr = {};
  for (int i = 0; i < SIZE; i++) {

    arr.push_back(i);
  }
  std::thread mythread([&]() { sortAnimations(arr); });
  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_Q)) {
      break;
    }

    renderValues(arr, texture);

    // Draw Call
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexturePro(
        texture.texture,
        Rectangle{0, 0, (float)texture.texture.width,
                  (float)texture.texture.height},
        (Rectangle){0, 0, (float)GetScreenWidth(), (float)GetScreenWidth()},
        {0}, 0, WHITE);

    EndDrawing();
  }
  CloseWindow();
}
