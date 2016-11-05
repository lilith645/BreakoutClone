#ifndef PADDLE_H 
#define PADDLE_H

#include "./defines.h"

class Paddle {
  public:
    Paddle();
    void draw();
    void update(float delta, unsigned char* keyState, unsigned char* prevKeyState);
  protected:
    float x, y;
    float speed;
    int length;
};

#endif
