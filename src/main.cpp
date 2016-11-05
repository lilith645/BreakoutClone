/*
 * main.cpp
 * This file is part of ReturnVoid
 *
 * Copyright (C) 2016 - Akuma
 *
 * ReturnVoid is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * ReturnVoid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ReturnVoid. If not, see <http://www.gnu.org/licenses/>.
 */

#include <GLFW/glfw3.h>

#ifdef __APPLE__
#include <OpenGL/gl.h>// Header File For The OpenGL32 Library
#include <OpenGL/glu.h>// Header File For The GLu32 Library
#else 
#include <GL/glc.h>
#include <GL/glu.h>
#include <png.h>
#endif

#include <stdio.h>

#include "../include/defines.h"

#include "../include/Game.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

int screenResX;
int screenResY;

int refreshMillis = 20;

//Screen grid 100x100
double gridWidth = 100; //veiwing world x
double gridHeight = 100; // veiwing world y

//Aspect ratio of screen resolution
float aspectRatio;

//Scaled aspect Ratios, for the width and height
float aspectW;
float aspectH;

//Current coords of the mouse
int mouseX, mouseY;

Game game;

//Keeps the current key state, keeps the key state of the previous key state
unsigned int  specialKey[5];
unsigned int  mouseBtnState[3];
unsigned int  prevSpeicalKey[5];
unsigned int  prevMouseBtnState[3];

unsigned char keyState[350];
unsigned char prevKeyState[350];

GLuint mouseTexture;

static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {
  mouseX = xpos*aspectW;
  mouseY = (screenResY - ypos) * aspectH;
}

//Updates what keys are pressed
void keyboard(int key) {
  //printf("key: %d\n", key);
  keyState[key] = BUTTON_DOWN;
}

//Updates what keys are released
void keyboard_up(int key) {
    keyState[key] = BUTTON_UP;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {    
  if(action == GLFW_PRESS) {
    keyboard(key);
  }
  if(action == GLFW_RELEASE) {
    keyboard_up(key);
  }
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
  mouseBtnState[button] = action;
}
  

void drawCursor() {

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, mouseTexture);
    // Nice blue #1e00d5
    //glColor3f(0.117647059f, 0, 0.835294197f);
    glColor4f(1, 0.643137255, 0, 1.0f);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 1.0f);
      glVertex3f(mouseX-20, mouseY+20, 0.0);
      glTexCoord2f(1.0f, 1.0f);
      glVertex3f(mouseX+20, mouseY+20, 0.0);
      glTexCoord2f(1.0f, 0.0f);
      glVertex3f(mouseX+20, mouseY-20, 0.0);
      glTexCoord2f(0.0f, 0.0f);
      glVertex3f(mouseX-20, mouseY-20, 0.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0f);
    glDisable(GL_TEXTURE_2D);
  
}

void clean() {
  glfwTerminate();
}

void display(GLFWwindow* window, float deltaTime) {      
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Wipes screen clear

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//Blends colours with alpha
  glClearColor(0.0f, 0.0f, 0.0f, 255.0f);
  
  //Texture options
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  glColor4ub(255,255,255,255); //sets full colours and alpha

  game.update(deltaTime, keyState, prevKeyState);
  game.draw();
 
  glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
  prevKeyState[ESC] = keyState[ESC];
  prevMouseBtnState[0] = mouseBtnState[0]; // Left Mouse Button
  prevKeyState['W'] = keyState['W'];
  prevKeyState['w'] = keyState['w'];
  prevKeyState['s'] = keyState['s'];
  prevKeyState['S'] = keyState['S'];
  prevKeyState['a'] = keyState['a'];
  prevKeyState['A'] = keyState['A'];
  prevKeyState['d'] = keyState['d'];
  prevKeyState['D'] = keyState['D'];
  
  glEnable (GL_BLEND);
  glBlendFunc (GL_ONE, GL_ONE);
}

GLFWwindow* init() {
    
  /* Initialize the library */
  GLFWwindow* window;
  if (!glfwInit()) {
    glfwSetWindowShouldClose(window, true);
    return window;
  }
  // Use OpenGL 2.1    
 
  bool isFullscreen = false;
  screenResX = 1024;
  screenResY = 576;

  /* Create a windowed mode window and its OpenGL context */

  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);


  printf("Entering windowed mode\n");
  
  //Create Window
  // gWindow = SDL_CreateWindow("Return-Void", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,  screenResX, screenResY, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
  window = glfwCreateWindow(screenResX, screenResY, "Return-Void", NULL, NULL);
      
  if (!window) {
    glfwTerminate();
    glfwSetWindowShouldClose(window, true);
    return window;
  }  
  
  aspectRatio = (float)screenResX / (float)screenResY;
  aspectW = (float)SPACE_X_RESOLUTION/(float)screenResX;
  aspectH = (float)SPACE_Y_RESOLUTION/(float)screenResY;
  
  gluOrtho2D(0.f, SPACE_X_RESOLUTION, 0.f, SPACE_Y_RESOLUTION);

  //screen =SDL_GetWindowSurface(gWindow);    
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

  return window;
}

int main(int argc, char* args[]) {
  
  GLFWwindow* window = init();
  
  /* Make the window's context current */
  glfwMakeContextCurrent(window);
  
  glfwSetKeyCallback(window, key_callback);
  glfwSetCursorPosCallback(window, cursor_pos_callback);
  glfwSetMouseButtonCallback(window, mouse_button_callback);
  
 // mouseTexture = txt::LoadTexture("Textures/Game/Crosshair.png");
  //Initialize clear color
  glClearColor( 0.0f, 0.0f, 0.0f, 1.0f ); 
  
  double lastTime = glfwGetTime();
  while(!glfwWindowShouldClose(window)) {
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    float ratio = width / (float)height;
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    gluOrtho2D(0.f, SPACE_X_RESOLUTION, 0.f, SPACE_Y_RESOLUTION);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    double currentTime = glfwGetTime();
   // printf("Time: %f", currentTime);
    float deltaTime = float(currentTime - lastTime);
    lastTime = glfwGetTime();
    display(window, deltaTime);  
    
    glfwSwapInterval(1);

    glfwSwapBuffers(window);
    glfwPollEvents();
    
  }
  clean();
  glfwTerminate();
  return 0;
}
