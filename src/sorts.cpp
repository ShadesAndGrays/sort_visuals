#include <cmath>
#include <fmt/core.h>
#include <sorts.hpp>
#include <thread>
#include <vector>

void printArray(std::vector<int> &arr) {
  fmt::print("[");
  for (int i = 0; i < arr.size(); i++) {

    fmt::print("{}", arr[i]);
    if (i != arr.size() - 1)
      fmt::print(", ");
  }
  fmt::println("]");
}

void bubbleSort(std::vector<int> &values) {
  using namespace std::chrono_literals;
  for (int i = values.size() - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {

      if (values[j] > values[j + 1]) {
        int temp = values[j + 1];
        values[j + 1] = values[j];
        values[j] = temp;
      }
    }
    std::this_thread::sleep_for(20ms);
  }
}
void selectionSort(std::vector<int> &values) {
  using namespace std::chrono_literals;
  for (int i = 0; i < values.size(); i++) {
    int smallest = i;
    for (int j = i; j < values.size(); j++) {
      if (values[smallest] > values[j]) {
        smallest = j;
      }
    }
    int temp = values[i];
    values[i] = values[smallest];
    values[smallest] = temp;

    std::this_thread::sleep_for(2ms);
  }
}

void radixSort(std::vector<int> &values) {
  using namespace std::chrono_literals;

  int max = values[0];

  for (int i = 0; i < values.size(); i++) {
    if (values[i] > max)
      max = values[i];
  }

  for (int exp = 1; exp < max; exp *= 10) {
    countSort(values, exp);
    std::this_thread::sleep_for(1s);
  }
}
void countSort(std::vector<int> &values, int exp) {
  using namespace std::chrono_literals;

  std::vector<int> frequency(10);
  std::vector<int> output(values.size());

  for (int i = 0; i < values.size(); i++) {
    output[i] = values[i];
  }

  for (int value : output) {
    int index = (value / exp) % 10;
    frequency[index]++;
  }

  for (int i = 1; i < frequency.size(); i++) {
    frequency[i] += frequency[i - 1];
  }

  for (int i = output.size() - 1; i >= 0; i--) {
    values[frequency[(output[i] / exp) % 10] - 1] = output[i];
    frequency[(output[i] / exp) % 10]--;
    std::this_thread::sleep_for(2ms);
  }
}
void randomize(std::vector<int> &values) {
  using namespace std::chrono_literals;
  for (int i = 0; i < values.size(); i++) {

    int randPos = rand() % values.size();
    int temp = values[i];
    values[i] = values[randPos];
    values[randPos] = temp;
    std::this_thread::sleep_for(2ms);
  }
}
