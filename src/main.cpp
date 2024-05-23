#include <cmath>
#include <cstdlib>
#include <fmt/core.h>
#include <raygui.h>
#include <raylib.h>
#include <thread>
#include <vector>

#define SIZE 100

void bubbleSort(std::vector<int> &values) {
  using namespace std::chrono_literals;
  for (int i = values.size(); i > 0; i--) {
    for (int j = 0; j < i; j++) {

      if (values[j] > values[j + 1]) {
        int temp = values[j + 1];
        values[j + 1] = values[j];
        values[j] = temp;
      }
    }
    std::this_thread::sleep_for(2ms);
  }
}
void selectionSort(std::vector<int> &values) {
  using namespace std::chrono_literals;
  for (int i = values.size(); i > 0; i--) {
    int largest = 0;
    for (int j = 0; j < i; j++) {
      if (values[largest] < values[j]) {
        largest = j;
      }
    }
    int temp = values[i];
    values[i] = values[largest];
    values[largest] = temp;

    std::this_thread::sleep_for(2ms);
  }
}
void randomize(std::vector<int> &values) {
  using namespace std::chrono_literals;
  for (int i = 0; i < values.size(); i++) {

    int randPos = rand() % values.size() - 1;
    int temp = values[i];
    values[i] = values[randPos];
    values[randPos] = temp;
    std::this_thread::sleep_for(2ms);
  }
}

void sortAnimations(std::vector<int> &values) {
  using namespace std::chrono_literals;
  std::this_thread::sleep_for(2s);
  randomize(values);

  std::this_thread::sleep_for(2s);
  bubbleSort(values);

  std::this_thread::sleep_for(2s);
  randomize(values);

  std::this_thread::sleep_for(2s);
  selectionSort(values);
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

  fmt::println("Hello world");

  InitWindow(1500, 1500, "Sort Visuals");
  SetWindowState(FLAG_WINDOW_RESIZABLE);

  RenderTexture2D texture = LoadRenderTexture(SIZE, SIZE);

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
