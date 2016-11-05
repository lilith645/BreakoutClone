#include "../include/Game.h"

Game::Game() {
  this->level        = 1;
  this->paused       = false;
  this->levelStarted = false;
  
  score = 0;
 
  levelSetup();
  
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
  }
  levelStarted = true;
}

void Game::draw() {
  drawBorder();
  paddle.draw();
  ball.draw();
  for(unsigned int i = 0; i < blocks.size(); ++i)
    blocks[i]->draw();
  
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
      if(!blocks[i]->getVisible())
        blocks.erase(blocks.begin() + i);
    }
  }
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
