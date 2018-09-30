#ifndef _GAME
#define _GAME
#include <math.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <time.h>
#include "window.h"


class CGame
{
public:
	const static char *name;
	static GLint width,height;
	static unsigned clk;
	CWindow window;
	GLdouble mousex,mousey;
	GLdouble screenx,screeny;
public:
	CGame();
	void start();
	void keyboard(unsigned char key,int x,int y);
	void mouse(int button,int state,int x,int y);
	void passive(int x,int y);
	void reshape(int w,int h);
	void loop();
};

#endif
