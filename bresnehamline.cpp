#include<GL/glut.h>
#include<math.h>
void Draw()
{	GLfloat x1=120,y1=50,x2=300,y2=350;
GLfloat m,dx,dy;
	glClear(GL_COLOR_BUFFER_BIT);
	if((x2-x1)==0)
		m=(y2-y1);
	else
		m=(y2-y1)/(x2-x1);
		
	dx=x2-x1;
	dy=y2-y1;
	p=2*dy-dx;
	x=x1;
	y=y1;
	glBegin(GL_POINTS);
	while(x<=x2)
	{
		glVertex2f(x,y);
		x++;
		
		if(p>=1)
		{
			y++;
			p=p+2*dy-2*2dx;
		}
		else{
		y=y;
		p=p+2*dy;
		}
	}
	glEnd();
		
	glFlush();
}
void MyInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argC,char *argV[])
{
	glutInit(&argC,argV);
	glutInitDisplayMode(GL_RGB|GLUT_SINGLE);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("Brehensham line");
	MyInit();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}