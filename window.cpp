#include "window.h"
#include <math.h>
int CWindow::mainHeight;
char CWindow::buffer[100];

CWindow::CWindow()
{
}
void CWindow::define(GLint x,GLint y,GLint w,GLint h)
{
	posx=x;
	posy=y;
	width=w;
	height=h;

	xmin=0;
	ymin=0;
	xmax=w;
	ymax=h;
};
void CWindow::range(GLdouble minx,GLdouble maxx,GLdouble miny,GLdouble maxy)
{
    xmin=minx;
    xmax=maxx;
    ymin=miny;
    ymax=maxy;
}

void CWindow::plotAdjust()
{
	glViewport(posx,mainHeight-posy-height,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glScalef(2.0/(xmax-xmin),2.0/(ymax-ymin),1);
	glTranslatef(-(xmax+xmin)/2.0,-(ymax+ymin)/2.0,0);
}
void CWindow::textAdjust()
{
	glViewport(posx,mainHeight-posy-height,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glScalef(2.0/(width),2.0/(-height),1);
	glTranslatef(-(width)/2.0,-(height)/2.0+1,0);//13 is hight of a char
}

void CWindow::textConvert(GLdouble ix,GLdouble iy,GLdouble &ox,GLdouble &oy)
{
	ox=ix-posx;//-xmin;//xmin+((ix-posx)/GLdouble(width))*(xmax-xmin);
	oy=iy-posy;//-ymin;//ymin+((height-iy+posy)/GLdouble(height))*(ymax-ymin);
};
void CWindow::plotConvert(GLdouble ix,GLdouble iy,GLdouble &ox,GLdouble &oy)
{
	ox=xmin+((ix-posx)/GLdouble(width))*(xmax-xmin);
	oy=ymin+((height-iy+posy)/GLdouble(height))*(ymax-ymin);
};
//text coords
void CWindow::printText(GLdouble ix,GLdouble iy,const char *string, ... )
{
	va_list st;
	va_start(st,string);

	vsnprintf(buffer,100,string,st);
	va_end(st);

	textAdjust();
	glPointSize(1);
	glBegin(GL_POINTS);
	unsigned char ch,pixelLine;
	for(int l=0;(ch=buffer[l])!=0;l++)
	{
		if((ch>=0x20)&&(ch<=0x7f))
			
			for(int y=0;y<8;y++)
			{
				pixelLine=charset[ch-0x20][y];
				for(int x=0;x<8;x++)
				{
					if(pixelLine&(0x80>>x))
						glVertex2f(	ix+(((l*8)+x)),
							iy+y);
				}
			}
	}
	glEnd();
	plotAdjust();
};
//Point coord
void CWindow::printPoint(GLdouble ix,GLdouble iy,const char *string, ... )
{
	va_list st;
	va_start(st,string);

	vsnprintf(buffer,100,string,st);
	va_end(st);

	plotAdjust();
	glPointSize(1);
	glBegin(GL_POINTS);
	unsigned char ch,pixelLine;
	for(int l=0;(ch=buffer[l])!=0;l++)
	{
		if((ch>=0x20)&&(ch<=0x7f))
			
			for(int y=0;y<8;y++)
			{
				pixelLine=charset[ch-0x20][y];
				for(int x=0;x<8;x++)
				{
					if(pixelLine&(0x80>>x))
						glVertex2f(	ix+((l*8)+x)*(xmax-xmin)/double(width),
							iy-y*(ymax-ymin)/double(height));
				}
			}
	}
	glEnd();
};
void CWindow::clear()
{
	plotAdjust();
	glBegin(GL_QUADS);
		glVertex2d(xmin,ymin);
		glVertex2d(xmax,ymin);
		glVertex2d(xmax,ymax);
		glVertex2d(xmin,ymax);
	glEnd();
};


