#include "../include/Label.h"

Label::Label() {
  this->x      = 0;
  this->y      = 0;
  this->colour = 0;
  this->length = 0;
  this->str    = "";
}

void Label::setup(std::string str, int length, float x, float y, int colour) {
  this->x      = x;
  this->y      = y;
  this->str    = str;
  this->length = length;
  this->colour = colour;
  setupGLC();
}

void Label::setText(std::string str) {
  this->str = str;
}

void Label::setupGLC() {
 /* ctx = glcGenContext();
  glcContext(ctx);
  glcEnable(GLC_GL_OBJECTS);
	//glcDisable(GLC_GL_OBJECTS);
	glcEnable(GLC_MIPMAP);
	glcEnable(GLC_HINTING_QSO);
  glcEnable(GLC_KERNING_QSO);

  glcAppendCatalog("/usr/lib/X11/fonts/Type1/");

  // Create a font "Palatino Bold"
  myFont = glcGenFontID();
  
  #ifdef __WIN32__
   // glcNewFontFromFamily(myFont, "Palatino Linotype");
   glcNewFontFromFamily(myFont, "Gothic Uralic");
  #else
   // glcNewFontFromFamily(myFont, "Palatino");
   glcNewFontFromFamily(myFont, "Gothic Uralic");
  #endif
  glcFontFace(myFont, "Bold");

  
  // Use the texture-based font renderer
	glcRenderStyle(GLC_TRIANGLE);

	// Use UTF-8 encoded strings
	glcStringType(GLC_UTF8_QSO);
	
  glcFont(myFont);*/
  glcContext( glcGenContext() );
  glcFont( glcNewFontFromFamily(1, "Gothic Uralic") );
  glcFontFace(1, "Bold");
  glcScale(24.0f, 24.0f);
}

void Label::draw() {
  glcRotate(0.0f);
  glColor3f(1.0f, 0.0f, 0.0f);
  glRasterPos2f(x-length*10, y);
  glcRenderString(str.c_str());
 /* glPushMatrix();
  
  glTranslatef(x-length*10, y, 0.0);
  glScalef(24.0f, 24.0f, 1.0f);
  
  glColor3f(1.0, 0.0, 0.0);
  
  //glRasterPos2f(x-length*10, y);
  
//  glcRenderString(str.c_str());
  glcRenderCountedString(ctx, (GLCchar*)&str);

  glPopMatrix();*/
}

void Label::update() {

}
