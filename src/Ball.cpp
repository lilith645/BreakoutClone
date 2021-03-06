#include "../include/Ball.h"

Ball::Ball() {
  boostRand.newSeed(time(NULL));
  
  float diffx = 0; //boostRand.Int(0, GAME_PANEL_MAX_X) - x;
  float diffy = boostRand.Int(GAME_PANEL_HEIGHT/2, GAME_PANEL_HEIGHT) - y;

  float distance = pow(pow(diffy,2.0f) + pow(diffx,2.0f), 0.5f);
  
  this->dirX       = (diffx) / (distance);
  this->dirY       = (diffy) / distance;
  this->speed      = 200;
  this->radius     = 20;
  this->x          = SPACE_X_RESOLUTION/2;
  this->y          = GAME_PANEL_HEIGHT/12 + radius*2;
  this->angle      = 0;
  this->startTimer = 0;
  this->visible    = true;
  this->texture    = txt::LoadTexture("./Textures/Ball.png");
  
  printf("Ball setup\n");
}

void Ball::reset() {
  float diffx = boostRand.Int(0, GAME_PANEL_MAX_X) - x;
  float diffy = boostRand.Int(GAME_PANEL_HEIGHT/2, GAME_PANEL_HEIGHT) - y;

  float distance = pow(pow(diffy,2.0f) + pow(diffx,2.0f), 0.5f);
  
  this->dirX       = (diffx) / (distance);
  this->dirY       = (diffy) / distance;
  
  startTimer = 0;
  y = GAME_PANEL_HEIGHT/12 + radius*2;
  if(speed < 0)
    speed *= -1;
  
  visible = true;
}

void Ball::draw() {
  glEnable(GL_TEXTURE_2D);
  glColor3f(1.0, 1.0, 1.0);
  
  if(visible) {
    glBindTexture(GL_TEXTURE_2D, texture);
    drawQuad(x, y, radius, radius);  
  }
  glDisable(GL_TEXTURE_2D);
}

    
void Ball::setDirection(Pos diff) { 
  float distance = pow(pow(diff.y,2.0f) + pow(diff.x,2.0f), 0.5f);
  
  this->dirX = (diff.x) / (distance);
  this->dirY = (diff.y) / distance;  
}

void Ball::update(float delta, unsigned char* keyState, unsigned char* prevKeyState, float Px) {

  if(keyState[GLFW_KEY_SPACE] == BUTTON_DOWN && prevKeyState[GLFW_KEY_SPACE] != BUTTON_DOWN) {
    startTimer = 6;  
  }

  if(startTimer < 5) {
    x = Px;
    startTimer += delta;
    return;
  }     
    
  y+=dirY*speed*delta;
  x+=dirX*speed*delta;
  
  if(y > GAME_PANEL_HEIGHT-radius*2) {
    y = GAME_PANEL_HEIGHT-radius*2;
    dirY *= -1;
  }
  
  if(x > GAME_PANEL_MAX_X-radius) {
    x = GAME_PANEL_MAX_X-radius;
    dirX *= -1;
  }
  
  if(x < GAME_PANEL_MIN_X+radius) {
    x = GAME_PANEL_MIN_X+radius;
    dirX *= -1;
  }
  
  if(y < 0)
    visible = false;//reset();
}
