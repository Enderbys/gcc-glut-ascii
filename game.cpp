#include "game.h"

const char *CGame::name="Teapot";
unsigned CGame::clk=0;
GLint CGame::width=800;
GLint CGame::height=600;

CGame::CGame()
{
}
void CGame::start()
{
    window.define(50,50,501,501);
	window.range(-1,1,-1,1);//0,100,0,100);
}
void CGame::keyboard(unsigned char key,int x,int y)
{
}
void CGame::mouse(int button,int state,int x,int y)
{
}
void CGame::passive(int x,int y)
{
	window.textConvert(GLint(x),GLint(y),screenx,screeny);
	window.plotConvert(GLint(x),GLint(y),mousex,mousey);
};
void CGame::reshape(int w,int h)
{
    width=GLint(w);
    height=GLint(h);

    glClearColor(0.1,0.2,0.3,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
 	glutSwapBuffers();
    glClear(GL_COLOR_BUFFER_BIT);
};
void CGame::loop()
{
	int x,y;
	glColor4f(0.0f,0.0f,0.5f,1.0f);
	window.clear();
	glColor4f(1.0f,0.0f,0.5f,1.0f);
	window.printText(0,0,"[%f,%f]",mousex,mousey);
	glColor4f(1.0f,0.5f,0.0f,1.0f);
	window.printText(0,8,"[%f,%f]",screenx,screeny);

	glPointSize(8);
	glColor4f(1.0f,0.5f,0.5f,1.0f);
	glBegin(GL_POINTS);
		glVertex2f(mousex,mousey);
	glEnd();
	glColor4d(0.0,0.0,1.0,1.0);
	window.printPoint(mousex,mousey,"[%f,%f]",mousex,mousey);
	glColor4d(0.5,0.4,1.0,1.0);
	window.printText(screenx,screeny,"[%f,%f]",mousex,mousey);
	for(double n=0;n<360;n++)
	{
		glBegin(GL_POINTS);
			glVertex2d(sin(n/180.0*3.1415)*n/360.0,cos(n/180.0*3.1415)*n/360.0);
		glEnd();
	}
 	glutSwapBuffers();
};

