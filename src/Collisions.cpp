#include "../include/Collisions.h"

float Collisions::magnitude( Pos b, Pos a ) {
  Pos Vector;

  Vector.x = a.x - b.x;
  Vector.y = a.y - b.y;

  return (float)sqrt( Vector.x * Vector.x + Vector.y * Vector.y );
}

Pos Collisions::GetIntersection(Pos c, float r, Pos a, Pos b) {
  float lineMagnitude;
  float u;
  Pos Intersection;
 
  lineMagnitude = magnitude( b, a );
 
  u = ( ( ( c.x - a.x ) * ( b.x - a.x ) ) +
      ( ( c.y - a.y ) * ( b.y - a.y ) ) ) /
      ( lineMagnitude * lineMagnitude );
 
  Intersection.x = a.x + u * ( b.x - a.x );
  Intersection.y = a.y + u * ( b.y - a.y );
    
  return Intersection;
}

bool Collisions::intersectCircle(Pos c, float r, Pos a, Pos b) {
  float lineMagnitude;
  float u;
  Pos Intersection;
 
  lineMagnitude = magnitude( b, a );
 
  u = ( ( ( c.x - a.x ) * ( b.x - a.x ) ) +
      ( ( c.y - a.y ) * ( b.y - a.y ) ) ) /
      ( lineMagnitude * lineMagnitude );
 
  if( u < 0.0f || u > 1.0f )
    return false;   // closest point does not fall within the line segment
 
  Intersection.x = a.x + u * ( b.x - a.x );
  Intersection.y = a.y + u * ( b.y - a.y );
    
  float Distance = magnitude( c, Intersection );
  if(Distance > r)
    return false;      
      
  return true;
}

void Collisions::detect(Paddle *paddle, Ball *ball, std::vector<Block*> blocks) {
  // Ball collision with paddle
  Pos pPaddleA;
  Pos pPaddleB;
  pPaddleA.x = paddle->getX() - paddle->getLength()/2;
  pPaddleA.y = paddle->getY() + paddle->getHeight()/2;
  pPaddleB.x = paddle->getX() + paddle->getLength()/2;
  pPaddleB.y = pPaddleA.y;
  
  Pos pBall;
  pBall.x = ball->getX();
  pBall.y = ball->getY(); 
  float Br = ball->getRadius();
    /*if( (By-Br/2 < Py+Ph && By-Br/2 > Py-Ph) && (Bx > Px-Pl && Bx < Px+Pl) ) {
    ball->setDirectionUp();
  } */
  // Ball hits paddle
  if(intersectCircle(pBall, Br, pPaddleA, pPaddleB)) {
    if(ball->getY() > paddle->getY()+paddle->getHeight()/2) {
      
      ball->setDirection(paddle->getDirection(GetIntersection(pBall, Br, pPaddleA, pPaddleB)));
    }
  }
  
  bool hasCollided = false; 
  for(unsigned int i = 0; i < blocks.size(); ++i) {
    Pos BpA;
    Pos BpB;
    Pos BpC;
    Pos BpD;
    
    BpA.x = blocks[i]->getX() - blocks[i]->getWidth()/2;
    BpA.y = blocks[i]->getY() + blocks[i]->getHeight()/2;
    
    BpB.x = blocks[i]->getX() + blocks[i]->getWidth()/2;
    BpB.y = BpA.y;
    
    BpC.x = blocks[i]->getX() + blocks[i]->getWidth()/2;
    BpC.y = blocks[i]->getY() - blocks[i]->getHeight()/2;
    
    BpD.x = blocks[i]->getX() - blocks[i]->getWidth()/2;
    BpD.y = BpC.y;
    
    //Top side
    if(intersectCircle(pBall, Br, BpA, BpB)) {
      ball->setDirectionUp();
      hasCollided = true;
    } else    
    //Bottom side
    if(intersectCircle(pBall, Br, BpC, BpD)) {
      ball->setDirectionDown();
      hasCollided = true;
    } 
    
    // Right side
    if(intersectCircle(pBall, Br, BpB, BpC)) {
      // Check if is colliding with another block
      if(i != blocks.size()-1) {
        Pos BpE;
        Pos BpF;
        
        BpE.x = blocks[i+1]->getX() - blocks[i+1]->getWidth()/2;
        BpE.y = blocks[i+1]->getY() + blocks[i+1]->getHeight()/2;
    
        BpF.x = blocks[i+1]->getX() - blocks[i+1]->getWidth()/2;
        BpF.y = blocks[i+1]->getY() - blocks[i+1]->getHeight()/2;
        
        if (intersectCircle(pBall, Br, BpE, BpF)) {
          ball->setDirectionDown();
        }
      }
       
      ball->setDirectionRight();
      hasCollided = true;
    } else
    // Left side
    if(intersectCircle(pBall, Br, BpD, BpA)) {
          // Check if is colliding with another block
      if(i != blocks.size()-1) {
        Pos BpE;
        Pos BpF;
        
        BpE.x = blocks[i+1]->getX() + blocks[i+1]->getWidth()/2;
        BpE.y = blocks[i+1]->getY() + blocks[i+1]->getHeight()/2;
    
        BpF.x = blocks[i+1]->getX() + blocks[i+1]->getWidth()/2;
        BpF.y = blocks[i+1]->getY() - blocks[i+1]->getHeight()/2;
        
        if (intersectCircle(pBall, Br, BpE, BpF)) {
          ball->setDirectionDown();
        }
      }
      ball->setDirectionLeft();
      hasCollided = true;
    } 
    
    if(hasCollided) {
      blocks[i]->setVisible(false);
      break;
    }
  }
}
