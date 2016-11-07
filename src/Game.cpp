#include "../include/Game.h"

Game::Game() {
  this->score        = 0;
  this->lives        = 3;
  this->level        = 2;
  this->paused       = false;
  this->levelStarted = false;  
  
  labels.push_back(new Label);
  labels.push_back(new Label);
  
  levelSetup();
  
  std::stringstream ss;
  ss << score;
  std::string str = "Score: " + ss.str();
  labels[0]->setup(str.c_str(), 8, 100, SPACE_Y_RESOLUTION-100, RED);
      
  std::stringstream ss1;
  ss1 << lives;
  std::string str1 = "Lives: " + ss1.str();
  labels[1]->setup(str1.c_str(), 8, SPACE_X_RESOLUTION-100, SPACE_Y_RESOLUTION-100, RED);
  
  printf("Game setup\n");
}

void Game::levelSetup() {      
  switch(level) {
    case 1:


      for(int i = 0; i < 68; ++i) {
        blocks.push_back(new Block);
      }
      for(int i = 0; i < 17; ++i) {
        blocks[0+i]->setup( (GAME_PANEL_MIN_X+blocks[0+i]->getWidth()/2+15) + (i*(blocks[0+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2, BLUE);
        blocks[17+i]->setup( (GAME_PANEL_MIN_X+blocks[17+i]->getWidth()/2+15) + (i*(blocks[17+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2-blocks[17+i]->getHeight() - 10, LIGHTBLUE);
        blocks[34+i]->setup( (GAME_PANEL_MIN_X+blocks[34+i]->getWidth()/2+15) + (i*(blocks[34+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2-(blocks[34+i]->getHeight() - 10)*4, PURPLE);
        blocks[51+i]->setup( (GAME_PANEL_MIN_X+blocks[51+i]->getWidth()/2+15) + (i*(blocks[51+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2-(blocks[51+i]->getHeight() - 10)*6, RED);
      }
      break;
    
    case 2:
      for(int i = 0; i < 72; ++i) {
        blocks.push_back(new Block);
      }
      for(int i = 0; i < 4; ++i) {
        blocks[0+i]->setup( (GAME_PANEL_MIN_X+blocks[0+i]->getWidth()/2+15) + ((i+0)*(blocks[0+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2, BLUE);
        
        blocks[4+i]->setup( (GAME_PANEL_MIN_X+blocks[4+i]->getWidth()/2+15) + ((i+0)*(blocks[4+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2+(blocks[4+i]->getHeight() - 10)*2, RED);
        
        blocks[8+i]->setup( (GAME_PANEL_MIN_X+blocks[8+i]->getWidth()/2+15) + ((i+0)*(blocks[8+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2+(blocks[8+i]->getHeight() - 10)*4, PURPLE);

        blocks[12+i]->setup( (GAME_PANEL_MIN_X+blocks[12+i]->getWidth()/2+15) + ((i+5)*(blocks[12+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2, BLUE);
        
        blocks[16+i]->setup( (GAME_PANEL_MIN_X+blocks[16+i]->getWidth()/2+15) + ((i+5)*(blocks[16+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2+(blocks[16+i]->getHeight() - 10)*2, RED);
        
        blocks[20+i]->setup( (GAME_PANEL_MIN_X+blocks[20+i]->getWidth()/2+15) + ((i+5)*(blocks[20+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2+(blocks[20+i]->getHeight() - 10)*4, PURPLE);

        blocks[24+i]->setup( (GAME_PANEL_MIN_X+blocks[24+i]->getWidth()/2+15) + ((i+10)*(blocks[24+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2, BLUE);
        
        blocks[28+i]->setup( (GAME_PANEL_MIN_X+blocks[28+i]->getWidth()/2+15) + ((i+10)*(blocks[28+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2+(blocks[28+i]->getHeight() - 10)*2, RED);
        
        blocks[32+i]->setup( (GAME_PANEL_MIN_X+blocks[32+i]->getWidth()/2+15) + ((i+10)*(blocks[32+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2+(blocks[32+i]->getHeight() - 10)*4, PURPLE);
        
        // Second Rows of 4
        blocks[36+i]->setup( (GAME_PANEL_MIN_X+blocks[36+i]->getWidth()/2+15) + ((i+13)*(blocks[36+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2+(blocks[36+i]->getHeight() - 10)*-8, BLUE);
        
        blocks[40+i]->setup( (GAME_PANEL_MIN_X+blocks[40+i]->getWidth()/2+15) + ((i+13)*(blocks[40+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2+(blocks[40+i]->getHeight() - 10)*-10, RED);
        
        blocks[44+i]->setup( (GAME_PANEL_MIN_X+blocks[44+i]->getWidth()/2+15) + ((i+13)*(blocks[44+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2+(blocks[44+i]->getHeight() - 10)*-12, PURPLE);

        blocks[48+i]->setup( (GAME_PANEL_MIN_X+blocks[48+i]->getWidth()/2+15) + ((i+8)*(blocks[48+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2+(blocks[48+i]->getHeight() - 10)*-8, BLUE);
        
        blocks[52+i]->setup( (GAME_PANEL_MIN_X+blocks[52+i]->getWidth()/2+15) + ((i+8)*(blocks[52+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2+(blocks[52+i]->getHeight() - 10)*-10, RED);
        
        blocks[56+i]->setup( (GAME_PANEL_MIN_X+blocks[56+i]->getWidth()/2+15) + ((i+8)*(blocks[56+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2+(blocks[56+i]->getHeight() - 10)*-12, PURPLE);

        blocks[60+i]->setup( (GAME_PANEL_MIN_X+blocks[60+i]->getWidth()/2+15) + ((i+3)*(blocks[60+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2+(blocks[60+i]->getHeight() - 10)*-8, BLUE);
        
        blocks[64+i]->setup( (GAME_PANEL_MIN_X+blocks[64+i]->getWidth()/2+15) + ((i+3)*(blocks[64+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2+(blocks[64+i]->getHeight() - 10)*-10, RED);
        
        blocks[68+i]->setup( (GAME_PANEL_MIN_X+blocks[68+i]->getWidth()/2+15) + ((i+3)*(blocks[68+i]->getWidth()+10)), SPACE_Y_RESOLUTION/2+(blocks[68+i]->getHeight() - 10)*-12, PURPLE);
      }
      
  }
  levelStarted = true;
}

void Game::draw() {
  drawBorder();
  paddle.draw();
  ball.draw();
  for(unsigned int i = 0; i < blocks.size(); ++i)
    blocks[i]->draw();
  for(unsigned int i = 0; i < labels.size(); ++i)
    labels[i]->draw();
  
}

void Game::update(float delta, unsigned char* keyState, unsigned char* prevKeyState) {
  
  if( (keyState['p'] || keyState['P']) == BUTTON_DOWN && 
      (prevKeyState['p'] || prevKeyState['P']) != BUTTON_DOWN) {
    if(paused) {
      paused = false;
    } else {
      paused = true;
    }
  }
  
  if(!paused) {
    paddle.update(delta, keyState, prevKeyState);
    ball.update(delta, keyState, prevKeyState, paddle.getX());
    Collisions::detect(&paddle, &ball, blocks);
    
    for(unsigned int i = 0; i < blocks.size(); ++i) {
      if(!blocks[i]->getVisible()) {
        blocks.erase(blocks.begin() + i);
        score+=10;
        std::stringstream ss;
        ss << score;
        std::string str = "Score: " + ss.str();
        labels[0]->setText(str.c_str());
      }
    }
    
    if(blocks.size() == 0)
      nextLevel();
      
    if(!ball.getVisible()) {
      lives--;
      std::stringstream ss;
      ss << lives;
      std::string str = "Lives: " + ss.str();
      labels[1]->setText(str.c_str());
      if(lives > 0) {
        ball.reset();
      } else {
        restart();
      }
    }
  }
}

void Game::restart() {
  level = 1;
  lives = 3;
  levelSetup();
  ball.reset();
} 

void Game::nextLevel() {
  level++;
  lives++;
  if(level > 2)
    level = 1;
  levelSetup();
  ball.reset();
}

void Game::drawBorder() {
  glColor3f(1.0f, 1.0f, 1.0f);
  //Left border
  drawQuad(GAME_PANEL_MIN_X, SPACE_Y_RESOLUTION/2.5, 20, SPACE_Y_RESOLUTION/1.2);
  //Right border
  drawQuad(GAME_PANEL_MAX_X, SPACE_Y_RESOLUTION/2.5, 20, SPACE_Y_RESOLUTION/1.2);
  // Top border
  drawQuad(SPACE_X_RESOLUTION/2, GAME_PANEL_HEIGHT - 20, SPACE_X_RESOLUTION/6 * 4 + 20, 20);
  
  glColor3f(1.0f, 0.0f, 0.0f);
  //Left border
  drawQuad(GAME_PANEL_MIN_X, SPACE_Y_RESOLUTION/2.5, 10, SPACE_Y_RESOLUTION/1.2);
  //Right border
  drawQuad(GAME_PANEL_MAX_X, SPACE_Y_RESOLUTION/2.5, 10, SPACE_Y_RESOLUTION/1.2);
  // Top border
  drawQuad(SPACE_X_RESOLUTION/2, GAME_PANEL_HEIGHT - 20, SPACE_X_RESOLUTION/6 * 4 + 10, 10);
  
  // Left Bottom Notch
  glColor3f(0.0, 0.0, 1.0);
  drawQuad(GAME_PANEL_MIN_X, SPACE_Y_RESOLUTION/12, 40, SPACE_Y_RESOLUTION/10);
  
  // Right Bottom Notch
  drawQuad(GAME_PANEL_MAX_X, SPACE_Y_RESOLUTION/12, 40, SPACE_Y_RESOLUTION/10);
  
  // Left Top Notch
  drawQuad(GAME_PANEL_MIN_X, SPACE_Y_RESOLUTION/1.5, 40, SPACE_Y_RESOLUTION/10);
  
  // Right Top Notch
  drawQuad(GAME_PANEL_MAX_X, SPACE_Y_RESOLUTION/1.5, 40, SPACE_Y_RESOLUTION/10);
}
