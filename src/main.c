#include "raylib.h"

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 600;
  const char *screenTitle = "Conway's Game of life";
  Color slightGreenColor = {.r = 41, .g = 196, .b = 60, .a = 1};

  InitWindow(screenWidth, screenHeight, screenTitle);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(slightGreenColor);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
