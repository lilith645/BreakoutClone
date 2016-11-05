#ifndef BALL_H
#define BALL_H

#include "./defines.h"
#include "./Random.h"

class Ball {
  public:
    Ball();
    void draw();
    void update(float delta, unsigned char* keyState, unsigned char* prevKeyState, float Px);
    
    void reverseYDirection() { dirY *= -1; }
    
    float getX() { return x; }
    float getY() { return y; }
    float getRadius() { return radius; }
  protected:
    void reset();
    float x, y;
    float speed;
    float radius;
    float angle;
    float dirX, dirY;
    float startTimer;
    
    Random boostRand;
};

#endif