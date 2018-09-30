#include <stdio.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

#include "window.h"
#include "game.h"

void glKeyboard(unsigned char key,int x,int y);
void glMouse(int button,int state,int x,int y);
void glPassive(int x,int y);
void glReshape(int w,int h);
void glLoop();

CGame theGame;
unsigned t0;
int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( theGame.width,theGame.height );
    glutCreateWindow(theGame.name);
    glutDisplayFunc(glLoop);
    glutIdleFunc(glLoop);
    glutKeyboardFunc(glKeyboard);
    glutMouseFunc(glMouse);
    glutPassiveMotionFunc(glPassive);
    glutReshapeFunc(glReshape);
    glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS );

    theGame.start();
    t0=clock();
    glutMainLoop();
    printf("End\n");
}

void glKeyboard(unsigned char key,int x,int y)
{
    theGame.keyboard(key,x,y);
};
void glMouse(int button,int state,int x,int y)
{
    theGame.mouse(button,state,x,y);
};
void glPassive(int x,int y)
{
    theGame.passive(x,y);
};
void glReshape(int w,int h)
{
    CWindow::mainHeight=h;
    theGame.reshape(w,h);
};
void glLoop()
{
	unsigned ck=clock();
	if((ck>t0)&&((ck-t0)<theGame.clk))return;
	t0=clock();

	theGame.loop();
};

