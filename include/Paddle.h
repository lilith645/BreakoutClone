#ifndef PADDLE_H 
#define PADDLE_H

#include "./defines.h"
#include "./Pos.h"

class Paddle {
  public:
    Paddle();
    void draw();
    void update(float delta, unsigned char* keyState, unsigned char* prevKeyState);
    
    float getX() { return pos.x; }
    float getY() { return pos.y; }
    float getLength() { return length; }
    float getHeight() { return height; }
    
    Pos getDirection(Pos a);
  protected:
    Pos pos;
    float speed;
    int length, height;
};

#endif
