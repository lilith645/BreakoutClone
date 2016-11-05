#include "../include/Collisions.h"

void Collisions::detect(Paddle *paddle, Ball *ball) {
  // Ball collision with paddle
  float Px = paddle->getX();
  float Py = paddle->getY();
  float Pl = paddle->getLength()/2;
  float Ph = paddle->getHeight()/2;
  float Bx = ball->getX();
  float By = ball->getY();
  float Br = ball->getRadius();
  
  if( (By-Br/2 < Py+Ph && By-Br/2 > Py-Ph) && (Bx+Br/2 > Px-Pl && Bx-Br/2 < Px+Pl) ) {
    ball->reverseYDirection();
  } 
  
}
