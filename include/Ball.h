#ifndef BALL_H
#define BALL_H

#include "./defines.h"
#include "./Random.h"
#include "./LoadTexture.h"
#include "./Pos.h"

class Ball {
  public:
    Ball();
    void draw();
    void update(float delta, unsigned char* keyState, unsigned char* prevKeyState, float Px);
    
    void reset();
    
    void reverseYDirection() { dirY *= -1; }
    void reverseXDirection() { dirX *= -1; }
    
    void setDirection(Pos dir);
    
    void setDirectionDown() { if(dirY > 0 ) dirY *= -1; }
    void setDirectionUp() { if(dirY < 0 ) dirY *= -1; }
    void setDirectionRight() { if(dirX < 0 ) dirX *= -1; }
    void setDirectionLeft() { if(dirX > 0 ) dirX *= -1; }
    
    void setVisible(bool visible) { this->visible = visible; }
    
    float getX() { return x; }
    float getY() { return y; }
    float getRadius() { return radius; }
    bool getVisible() { return visible; }
  protected:    
    float x, y;
    float speed;
    float radius;
    float angle;
    float dirX, dirY;
    float startTimer;
    
    bool visible;
    
    Random boostRand;
    
    GLuint texture;
};

#endif
