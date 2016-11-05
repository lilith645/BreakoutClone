#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "./Paddle.h"
#include "./Ball.h"
#include "./Block.h"

#include <vector>

namespace Collisions {
  void detect(Paddle *paddle, Ball *ball, std::vector<Block*> blocks);
}

#endif
