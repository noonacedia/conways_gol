#include "raylib.h"
#include "rlgl.h"

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 600;
  const char *screenTitle = "Conway's Game of life";
  // Color slightGreenColor = {.r = 206, .g = 169, .b = 188, .a = 1};

  InitWindow(screenWidth, screenHeight, screenTitle);
  // Camera2D camera = {0};
  // camera.zoom = 1.0f;
  // int zoomMode = 0;

  SetTargetFPS(65);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    // BeginMode2D(camera);
    rlPushMatrix();
    rlTranslatef(0, 25 * 50, 0);
    rlRotatef(90, 1, 0, 0);
    DrawGrid(100, 50);
    rlPopMatrix();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
