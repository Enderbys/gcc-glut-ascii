#ifndef _WINDOW
#define _WINDOW

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include <GL/freeglut.h>
#include <GL/gl.h>

class CWindow
{
private:
	static const unsigned char charset[][8];
public:
    static GLint mainHeight;
    static char buffer[];
    GLint posx,posy;
    GLint width,height;
    GLdouble xmin,ymin,xmax,ymax;
public:
    CWindow();
    void define(GLint x,GLint y,GLint w,GLint h);
    void range(GLdouble minx,GLdouble maxx,GLdouble miny,GLdouble maxy);
    void plotAdjust();
    void textAdjust();
	void plotConvert(GLdouble ix,GLdouble iy,GLdouble &ox,GLdouble &oy);
 	void textConvert(GLdouble ix,GLdouble iy,GLdouble &ox,GLdouble &oy);
	void printText(GLdouble x,GLdouble y,const char * string, ... );
    void printPoint(GLdouble x,GLdouble y,const char * string, ... );
    void clear();
};

#endif

