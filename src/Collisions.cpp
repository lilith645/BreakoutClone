#include "../include/Collisions.h"

void Collisions::detect(Paddle *paddle, Ball *ball, std::vector<Block*> blocks) {
  // Ball collision with paddle
  float Px = paddle->getX();
  float Py = paddle->getY();
  float Pl = paddle->getLength()/2;
  float Ph = paddle->getHeight()/2;
  float Bx = ball->getX();
  float By = ball->getY();
  float Br = ball->getRadius();
  
  if( (By-Br/2 < Py+Ph && By-Br/2 > Py-Ph) && (Bx+Br/2 > Px-Pl && Bx-Br/2 < Px+Pl) ) {
    ball->setDirectionUp();
  } 
  
  for(unsigned int i = 0; i < blocks.size(); ++i) {
    float Bkx = blocks[i]->getX();
    float Bky = blocks[i]->getY();
    float Bkw = blocks[i]->getWidth()/2;
    float Bkh = blocks[i]->getHeight()/2;
    
    // Top side of block collision
    if( (By-Br < Bky+Bkh && By-Br > Bky+Bkh/4) && 
      ( (Bx+Br < Bkx+Bkw && Bx+Br > Bkx-Bkw) ||
      (Bx-Br < Bkx+Bkw && Bx-Br > Bkx-Bkw) ) ) {
      ball->setDirectionUp(); 
      blocks[i]->setVisible(false);
      break;
    } else
    
    // Right side of block collision
    if( (Bx-Br < Bkx+Bkw && Bx-Br > Bkx+Bkw/4) &&
      ( (By+Br > Bky-Bkh/2 && By+Br < Bky+Bkh/2) ||
        (By-Br > Bky-Bkh/2 && By-Br < Bky+Bkh/2)) ) {
      ball->setDirectionRight(); 
      blocks[i]->setVisible(false);
      break;
    } else
    
    // Left side of block collision
    if( (Bx+Br > Bkx-Bkw && Bx+Br < Bkx-Bkw/4) &&
      ( (By+Br > Bky-Bkh/2 && By+Br < Bky+Bkh/2) ||
        (By-Br > Bky-Bkh/2 && By-Br < Bky+Bkh/2)) ) {
      ball->setDirectionLeft(); 
      blocks[i]->setVisible(false);
      break;
    } else
    
    // bottom side of block collision
    if( (By+Br > Bky-Bkh && By+Br < Bky-Bkh/4) && 
      ( (Bx+Br < Bkx+Bkw && Bx+Br > Bkx-Bkw) ||
      (Bx-Br < Bkx+Bkw && Bx-Br > Bkx-Bkw) ) ) {
      ball->setDirectionDown(); 
      blocks[i]->setVisible(false);
      break;
    }
  }  
}
