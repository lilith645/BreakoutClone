#include "../include/Paddle.h"

Paddle::Paddle() {
  this->pos.x  = SPACE_X_RESOLUTION/2;
  this->pos.y  = SPACE_Y_RESOLUTION/12;
  this->length = GAME_PANEL_WIDTH/10;
  this->height = 10;
  this->speed  = 300;
  printf("Paddle setup\n");
}

void Paddle::draw() {
  glColor3f(1.0, 1.0, 0.0);
  drawQuad(pos.x, pos.y, length, height);
}

void Paddle::update(float delta, unsigned char* keyState, unsigned char* prevKeyState) {
 if( (keyState['d'] || keyState['D'] || keyState[GLFW_KEY_RIGHT]) == BUTTON_DOWN) {
    pos.x += speed * delta;
    if(pos.x > GAME_PANEL_MAX_X-length/2-20)
      pos.x = GAME_PANEL_MAX_X-length/2-20;
  }
  if( (keyState['a'] || keyState['A'] || keyState[GLFW_KEY_LEFT]) == BUTTON_DOWN) {
    pos.x -= speed * delta;
    if(pos.x < GAME_PANEL_MIN_X+length/2+20)
      pos.x = GAME_PANEL_MIN_X+length/2+20;
  } 
}

Pos Paddle::getDirection(Pos a) {
  Pos newBallDirection;
  float mag;
  if(pos.x > a.x) {
    mag = (pos.x - a.x);
  } else {
    mag = a.x - pos.x;
  }
  
  mag /= length/2;
  
  if(pos.x > a.x) {
    mag*=-1;
    newBallDirection.x = mag;
    newBallDirection.y = 1 - -1*mag;
  } else {
    newBallDirection.x = mag;
    newBallDirection.y = 1 - mag;
  }
    

  printf("%f, ", mag);
  
  printf("%f, %f\n", newBallDirection.x, newBallDirection.y);
  
  return newBallDirection;
}

