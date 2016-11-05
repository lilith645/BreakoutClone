#include "../include/Paddle.h"

Paddle::Paddle() {
  this->x      = SPACE_X_RESOLUTION/2;
  this->y      = SPACE_Y_RESOLUTION/12;
  this->length = GAME_PANEL_WIDTH/10;
  this->height = 10;
  this->speed  = 150;
  printf("Paddle setup\n");
}

void Paddle::draw() {
  glColor3f(1.0, 1.0, 0.0);
  drawQuad(x, y, length, height);
}

void Paddle::update(float delta, unsigned char* keyState, unsigned char* prevKeyState) {
 if( (keyState['d'] || keyState['D']) == BUTTON_DOWN) {
    x += speed * delta;
    if(x > GAME_PANEL_MAX_X-length/2-20)
      x = GAME_PANEL_MAX_X-length/2-20;
  }
  if( (keyState['a'] || keyState['A']) == BUTTON_DOWN) {
    x -= speed * delta;
    if(x < GAME_PANEL_MIN_X+length/2+20)
      x = GAME_PANEL_MIN_X+length/2+20;
  } 
}


