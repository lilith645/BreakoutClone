#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "./Paddle.h"
#include "./Ball.h"

namespace Collisions {
  void detect(Paddle *paddle, Ball *ball);
}

#endif
