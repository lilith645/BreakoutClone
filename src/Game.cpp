#include "../include/Game.h"

Game::Game() {
  level = 1;
  printf("Game setup\n");
}

void Game::draw() {
  drawBorder();
  paddle.draw();
}

void Game::update(float delta, unsigned char* keyState, unsigned char* prevKeyState) {
  paddle.update(delta, keyState, prevKeyState);
}

void Game::drawBorder() {
  glColor3f(1.0f, 1.0f, 1.0f);
  //Left border
  drawQuad(GAME_PANEL_MIN_X, SPACE_Y_RESOLUTION/2.5, 20, SPACE_Y_RESOLUTION/1.2);
  //Right border
  drawQuad(GAME_PANEL_MAX_X, SPACE_Y_RESOLUTION/2.5, 20, SPACE_Y_RESOLUTION/1.2);
  // Top border
  drawQuad(SPACE_X_RESOLUTION/2, GAME_PANEL_HEIGHT - 20, SPACE_X_RESOLUTION/6 * 4 + 20, 20);
  
  glColor3f(1.0f, 0.0f, 0.0f);
  //Left border
  drawQuad(GAME_PANEL_MIN_X, SPACE_Y_RESOLUTION/2.5, 10, SPACE_Y_RESOLUTION/1.2);
  //Right border
  drawQuad(GAME_PANEL_MAX_X, SPACE_Y_RESOLUTION/2.5, 10, SPACE_Y_RESOLUTION/1.2);
  // Top border
  drawQuad(SPACE_X_RESOLUTION/2, GAME_PANEL_HEIGHT - 20, SPACE_X_RESOLUTION/6 * 4 + 10, 10);
  
  // Left Bottom Notch
  glColor3f(0.0, 0.0, 1.0);
  drawQuad(GAME_PANEL_MIN_X, SPACE_Y_RESOLUTION/12, 40, SPACE_Y_RESOLUTION/10);
  
  // Right Bottom Notch
  drawQuad(GAME_PANEL_MAX_X, SPACE_Y_RESOLUTION/12, 40, SPACE_Y_RESOLUTION/10);
  
  // Left Top Notch
  drawQuad(GAME_PANEL_MIN_X, SPACE_Y_RESOLUTION/1.5, 40, SPACE_Y_RESOLUTION/10);
  
  // Right Top Notch
  drawQuad(GAME_PANEL_MAX_X, SPACE_Y_RESOLUTION/1.5, 40, SPACE_Y_RESOLUTION/10);
}
