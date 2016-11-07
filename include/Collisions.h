#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "./Paddle.h"
#include "./Ball.h"
#include "./Block.h"
#include "./Pos.h"

#include <vector>

namespace Collisions {
  void detect(Paddle *paddle, Ball *ball, std::vector<Block*> blocks);
  
  float magnitude( Pos b, Pos a );
  bool intersectCircle(Pos c, float r, Pos a, Pos b);
}

#endif
