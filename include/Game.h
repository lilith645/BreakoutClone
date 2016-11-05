#ifndef GAME_H
#define GAME_H

#include "./defines.h"
#include "./Paddle.h"

class Game {
  public:
    Game();
    void draw();
    void update(float delta, unsigned char* keyState, unsigned char* prevKeyState);
  protected:
    void drawBorder();
    int level;

    Paddle paddle;
};

#endif
