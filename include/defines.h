#ifndef DEFINES
#define DEFINES

#ifdef __APPLE__
#include <OpenGL/gl.h>// Header File For The OpenGL32 Library
#include <OpenGL/glu.h>// Header File For The GLu32 Library
#else
#include <GL/glu.h>
#include <png.h>
#endif

#include <GLFW/glfw3.h>

#include <cstdlib>

#define VERSION                1.5

#define GAME_MODE_POSSIBLE     0

// Game x, y coordinate system
#define SPACE_X_RESOLUTION     1920 //1440
#define SPACE_Y_RESOLUTION     1080 //810

#define GAME_PANEL_WIDTH       (1920/6*4)
#define GAME_PANEL_HEIGHT      (1080/1.2)
#define GAME_PANEL_MIN_X       (1920/6)
#define GAME_PANEL_MAX_X       (1920/6*5)

// key states
#define BUTTON_UP              0
#define BUTTON_DOWN            1

#define BUTTONWIDTH            247
#define BUTTONHEIGHT           95
#define ARROWWIDTH             59

#define UP                     0
#define DOWN                   1

// Arrow Keys
#define LEFT_KEY               263
#define RIGHT_KEY              262
#define UP_KEY                 265
#define DOWN_KEY               264

#define LEFT                   0
#define RIGHT                  1

#define NOTHING                -1
#define RED                    0
#define GREEN                  1
#define BLUE                   2
#define YELLOW                 3
#define LIGHTBLUE              4
#define PURPLE                 5

// Keys
#define ESC                    256

inline void drawQuad(float x, float y, float w, float h)
	{
		glBegin(GL_QUADS);
		  glTexCoord2f(0.0, 0.0); glVertex3f( x-w/2,  y+h/2, 0.0);
			glTexCoord2f(0.0, 1.0); glVertex3f( x-w/2,  y-h/2, 0.0);
			glTexCoord2f(1.0, 1.0); glVertex3f( x+w/2,  y-h/2, 0.0);
		  glTexCoord2f(1.0, 0.0); glVertex3f( x+w/2,  y+h/2, 0.0);
		glEnd();
	}

#endif
