#ifndef BLOCK_H
#define BLOCK_H

#include "./defines.h"

class Block {
  public:
    Block();
    
    void draw();
    void setup(float x, float y, int colour);
    void update();
    
    void setVisible(bool visible) { this->visible = visible; }
    
    float getX() { return x; }
    float getY() { return y; }
    float getWidth() { return width; }
    float getHeight() { return height; }
    bool getVisible() { return visible; }
  protected:
    float x, y;
    int width, height;
    int colour;
    bool visible;
};

#endif
