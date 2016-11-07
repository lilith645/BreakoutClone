#ifndef LABEL_H 
#define LABEL_H

#include "./defines.h"
#include "GL/glc.h"

#include<string>

class Label {
  public:
    Label();
    void setup(std::string str, int length, float x, float y, int colour);
    void setText(std::string);
    void draw();
    void update();
  protected:
    void setupGLC();
  
    float x, y;
    int length;
    int colour;
    std::string str;
       
    GLint ctx, myFont;
};

#endif
