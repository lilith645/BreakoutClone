#ifndef PADDLE_H 
#define PADDLE_H

#include "./defines.h"

class Paddle {
  public:
    Paddle();
    void draw();
    void update(float delta, unsigned char* keyState, unsigned char* prevKeyState);
    
    float getX() { return x; }
    float getY() { return y; }
    float getLength() { return length; }
    float getHeight() { return height; }
  protected:
    float x, y;
    float speed;
    int length, height;
};

#endif
