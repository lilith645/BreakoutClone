#ifndef GAME_H
#define GAME_H

#include "./defines.h"
#include "./Paddle.h"
#include "./Ball.h"
#include "./Block.h"
#include "./Collisions.h"
#include "./Label.h"

#include <vector>
#include <sstream>

class Game {
  public:
    Game();
    void draw();
    void update(float delta, unsigned char* keyState, unsigned char* prevKeyState);
  protected:
    void restart();
    void nextLevel();
    void drawBorder();
    void levelSetup();
    int level;
    int lives;
    int score;
    bool paused;
    bool levelStarted;

    Paddle paddle;
    Ball ball;
    
    std::vector<Label*> labels;
    
    std::vector<Block*> blocks;
};

#endif
