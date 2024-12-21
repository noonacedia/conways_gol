#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

void zoomMouseWheel(Camera2D *camera) {
  float wheel = GetMouseWheelMove();
  if (wheel != 0) {
    Vector2 mouseWordPos = GetScreenToWorld2D(GetMousePosition(), *camera);
    camera->offset = GetMousePosition();
    camera->target = mouseWordPos;
    float scaleFactor = 1.0f + (0.25 * fabs(wheel));
    if (wheel < 0)
      scaleFactor = 1.0f / scaleFactor;
    camera->zoom = Clamp(camera->zoom * scaleFactor, 0.125f, 64.0f);
  }
}

void moveCameraWithMouse(Camera2D *camera) {
  if (IsMouseButtonDown(0)) {
    Vector2 newVectorOffset = {
        GetMouseX(),
        GetMouseY(),
    };
    camera->offset = newVectorOffset;
    camera->target = newVectorOffset;
  }
}

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 600;
  const char *screenTitle = "Conway's Game of life";
  const int fps = 100;

  InitWindow(screenWidth, screenHeight, screenTitle);
  Vector2 cameraVectorOffset = {0, 0};
  Vector2 cameraVectorTarget = {0, 0};
  Camera2D camera = {cameraVectorOffset};
  camera.zoom = 1.0f;
  SetTargetFPS(fps);

  while (!WindowShouldClose()) {
    zoomMouseWheel(&camera);
    moveCameraWithMouse(&camera);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode2D(camera);
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
