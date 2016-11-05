#include "../include/Block.h"

Block::Block() {
  this->x       = -1;
  this->y       = -1;
  this->width   = GAME_PANEL_WIDTH/20;
  this->height  = 30;
  this->colour  = 0;
  this->visible = true;
}

void Block::setup(float x, float y, int colour) {
  this->x       = x;
  this->y       = y;
  this->colour  = colour;
  this->visible = true;
}

void Block::draw() {
  switch(colour) {
    case NOTHING:
      glColor3f(0.0, 0.0, 0.0);
      break;
    case RED:
      glColor3f(1.0, 0.0, 0.0);
      break;
    case GREEN:
      glColor3f(0.0, 1.0, 0.0);
      break;
    case BLUE:
      glColor3f(0.0, 0.0, 1.0);
      break;
    case YELLOW:
      glColor3f(1.0, 1.0, 0.0);
      break;
    case LIGHTBLUE:
      glColor3f(0.0, 1.0, 1.0);
      break;
    case PURPLE:
      glColor3f(1.0, 0.0, 1.0);
      break;
  }
  
  drawQuad(x, y, width, height);
  
  switch(colour) {
    case NOTHING:
      glColor3f(0.0, 0.0, 0.0);
      break;
    case RED:
      glColor3f(0.5, 0.0, 0.0);
      break;
    case GREEN:
      glColor3f(0.0, 0.5, 0.0);
      break;
    case BLUE:
      glColor3f(0.0, 0.0, 0.5);
      break;
    case YELLOW:
      glColor3f(0.5, 0.5, 0.0);
      break;
    case LIGHTBLUE:
      glColor3f(0.0, 0.5, 0.5);
      break;
    case PURPLE:
      glColor3f(0.5, 0.0, 0.5);
      break;
  }
  
  drawQuad(x, y, width-10, height-10);
}

void Block::update() {

}
