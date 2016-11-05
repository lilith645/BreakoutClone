#ifndef GAME_H
#define GAME_H

#include "./defines.h"
#include "./Paddle.h"
#include "./Ball.h"
#include "./Block.h"
#include "./Collisions.h"

#include <vector>

class Game {
  public:
    Game();
    void draw();
    void update(float delta, unsigned char* keyState, unsigned char* prevKeyState);
  protected:
    void drawBorder();
    void levelSetup();
    int level;
    int score;
    bool paused;
    bool levelStarted;

    Paddle paddle;
    Ball ball;
    
    std::vector<Block*> blocks;
};

#endif
