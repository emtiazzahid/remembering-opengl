#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#include <stdlib.h>


float tx=0,ty=0,mv=0,limitX=215,limitY=340,carPos=0,bodyPos=0,success=0;

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
    int i;
    float PI = 3.1416;
    int triangleAmount = 50; //# of triangles used to draw circle
    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle

    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
        x + (radius * cos(i * twicePi / triangleAmount)),
        y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}
void initframe()
{
    glColor3f( 1.0 , 1.0 , 1.0 ) ;
    glBegin(GL_POLYGON) ;

		glVertex3f( 5.0 , 5.0 , 0.0 ) ;
		glVertex3f( 995.0 , 5.0 , 0.0 ) ;
		glVertex3f( 995.0 , 495.0 , 0.0 ) ;
		glVertex3f( 5.0 , 495.0 , 0.0 ) ;
	glEnd() ;
}
// ======================== Road part ===============================
void road()
{
         glColor3f( 0.329412 , 0.329412  , 0.329412 ) ;
    glBegin(GL_POLYGON) ;

		glVertex3f( 5.0 , 250.0 , 0.0 ) ;
		glVertex3f( 5.0 , 100.0 , 0.0 ) ;
		glVertex3f( 995.0 , 100.0 , 0.0 ) ;
		glVertex3f( 995.0 , 250.0 , 0.0 ) ;
    glEnd() ;
}
void roadline(){
glColor3f( 1.0 ,1.0 , 1.0) ;
    glBegin(GL_LINES) ;
		glVertex3f( 5.0 , 175.0 , 0.0 ) ;
		glVertex3f( 995.0 , 175.0 , 0.0 ) ;
	glEnd() ;
}
// =================== background part=======================
void upergreen()
{
    glColor3f( 0.0 , 1.0 , 0.0 ) ;
    glBegin(GL_POLYGON) ;
		glVertex3f( 5.0 , 300.0 , 0.0 ) ;
		glVertex3f( 5.0 , 250.0 , 0.0 ) ;
		glVertex3f( 995.0 , 250.0 , 0.0 ) ;
		glVertex3f( 995.0 , 300.0 , 0.0 ) ;
	glEnd() ;
}
void lowerGreen()
{
    glColor3f( 0.0 , 1.0 , 0.0 ) ;
    glBegin(GL_POLYGON) ;
		glVertex3f( 5.0 , 100.0 , 0.0 ) ;
		glVertex3f( 5.0 , 5.0 , 0.0 ) ;
		glVertex3f( 995.0 , 5.0 , 0.0 ) ;
		glVertex3f( 995.0 , 100.0 , 0.0 ) ;
	glEnd() ;
}

void sky()
{
        glColor3f( 0.0 , 0.498039, 1.0 ) ;
    glBegin(GL_POLYGON) ;
		glVertex3f( 5.0 , 495.0 , 0.0 ) ;
		glVertex3f( 5.0 , 300.0 , 0.0 ) ;
		glVertex3f( 995.0 , 300.0 , 0.0 ) ;
		glVertex3f( 995.0 , 495.0 , 0.0 ) ;
	glEnd() ;
}
//============================station part===============================
void station()
{

    glBegin(GL_POLYGON) ;
        glColor3f( 0.0 , 0.0, 1.0 ) ; //station body
		glVertex3f( 160.0 , 250.0 , 0.0 ) ;
		glVertex3f( 370.0 , 250.0 , 0.0 ) ;
		glVertex3f( 370.0 , 320.0 , 0.0 ) ;
		glVertex3f( 160.0 , 320.0 , 0.0 ) ;
	glEnd() ;
}
void stationRoof()
{
    glBegin(GL_POLYGON) ;
glColor3f( 0.0 , 1.0, 1.0 ) ; //station roof
		glVertex3f( 220.0 , 360.0 , 0.0 ) ;
		glVertex3f( 160.0 , 320.0 , 0.0 ) ;
		glVertex3f( 370.0 , 320.0 , 0.0 ) ;
		glVertex3f( 420.0 , 360.0 , 0.0 ) ;
glEnd() ;
}
void stationStick()
{
        glBegin(GL_LINES) ;
     glColor3f( 1.0 , 0.0, 1.0 ) ;
    	glVertex3f( 220.0 , 360.0 , 0.0 ) ;
    	glVertex3f( 220.0 , 250.0 , 0.0 ) ;

     glColor3f( 1.0 , 0.0, 1.0 ) ;
    	glVertex3f( 420.0 , 360.0 , 0.0 ) ;
    	glVertex3f( 420.0 , 250.0 , 0.0 ) ;
    	glEnd() ;
}
//=======================Bus Parts==============================

void Busframe1()
{
            glColor3f( 0.80 , 0, 0.0 ) ;
    glBegin(GL_POLYGON) ;
		glVertex3f( tx+50.0 , 335.0 , 0.0 ) ;
		glVertex3f( tx+50.0 , 240.0 , 0.0 ) ;
		glVertex3f( tx+210.0 , 240.0 , 0.0 ) ;
		glVertex3f( tx+210.0 , 335.0 , 0.0 ) ;
	glEnd() ;
}
void Busframe2()
{
            glColor3f( 0.80 , 0, 0.0 ) ;
    glBegin(GL_POLYGON) ;
		glVertex3f( tx+210.0 , 240.0 , 0.0 ) ;
		glVertex3f( tx+250.0 , 240.0 , 0.0 ) ;
		glVertex3f( tx+250.0 , 335.0 , 0.0 ) ;
		glVertex3f( tx+210.0 , 335.0 , 0.0 ) ;
	glEnd() ;
}
void drawWindows(){
	glColor3f( 0, 0 , 1 ) ;
	glBegin(GL_QUADS) ;
		glVertex3f( tx+55.0 , 315.0 , 0.0 ) ;
		glVertex3f( tx+55.0 , 295.0 , 0.0 ) ;
		glVertex3f( tx+75.0 , 295.0 , 0.0 ) ;
		glVertex3f( tx+75.0 , 315.0 , 0.0 ) ;
	glEnd() ;
}
void  BusDoor()
{
    carPos=tx+limitX;
    glColor3f(0 , 0 , 1  ) ;
        glBegin(GL_POLYGON) ;
        glVertex3f( carPos , 240.0 , 0.0 ) ;
		glVertex3f( tx+240.0 , 240.0 , 0.0 ) ;
		glVertex3f( tx+240.0 , 290.0 , 0.0 ) ;
		glVertex3f( tx+limitX , 290.0 , 0.0 ) ;
		glEnd() ;
}
//========================================Man Parts============================
void manBody()
{
    bodyPos=limitY-mv;
    glBegin(GL_LINES) ;
     glColor3f( 1, 1, 1 ) ;
    	glVertex3f(340.0-mv , 250.0 , 0.0 ) ; //left leg aga
    	glVertex3f( 350.0-mv , 257.0 , 0.0 ) ; // left leg gura

    	glVertex3f( 350.0 -mv, 257.0 , 0.0 ) ; //body gura
    	glVertex3f( 350.0 -mv, 270.0 , 0.0 ) ; // body aga

    	glVertex3f( 350.0 -mv, 270.0 , 0.0 ) ; //left hand gura
    	glVertex3f( bodyPos, 275.0 , 0.0 ) ; //left hand aga

    	glVertex3f( 360.0 -mv, 275.0 , 0.0 ) ; //right hand aga
    	glVertex3f( 350.0 -mv, 270.0 , 0.0 ) ; //right hand gura

    	glVertex3f( 360.0 -mv, 250.0 , 0.0 ) ; //right leg aga
    	glVertex3f( 350.0 -mv, 257.0 , 0.0 ) ;//right leg gura

    	glVertex3f( 350.0 -mv, 270.0 , 0.0 ) ; // head gura
    	glVertex3f( 350.0 -mv, 280.0 , 0.0 ) ; // head aga

    	glEnd() ;

}

void signalStick()
{
        glBegin(GL_POLYGON) ;

         glColor3f( 1.0 , 1.5, 0.0 ) ; //signal stick
    	glVertex3f( 440.0 , 390.0 , 0.0 ) ;
    	glVertex3f( 440.0 , 250.0 , 0.0 ) ;
    	glVertex3f( 450.0 , 250.0 , 0.0 ) ;
    	glVertex3f( 450.0 , 390.0 , 0.0 ) ;
    	glEnd();
}
void signalBody(){
    glBegin(GL_POLYGON) ;
    glColor3f( 0.0 , 0.0, 0.0 ) ; //signal body
        glVertex3f( 440.0 , 390.0 , 0.0 ) ;
		glVertex3f( 400.0 , 390.0 , 0.0 ) ;
		glVertex3f( 400.0 , 370.0 , 0.0 ) ;
		glVertex3f( 440.0 , 370.0 , 0.0 ) ;
		glEnd() ;

}

void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
       case GLUT_KEY_UP:
            //do something here
            mv += 3;
            break;
       case GLUT_KEY_DOWN:
            //do something here
            mv -= 3;
            break;
        case GLUT_KEY_LEFT:
            //do something here
            tx -= 3;
            break;
        case GLUT_KEY_RIGHT:
            //do something here
            tx += 3;
        break;
    }

    glutPostRedisplay();
}


void display(void){
	glClear( GL_COLOR_BUFFER_BIT) ;


	initframe();
    road();
    roadline();
    upergreen();
    lowerGreen();
    sky();
     station();
    stationRoof();
    stationStick();

    glPushMatrix(); //translate station
		glTranslatef(530,0,0);
		 station();
    stationRoof();
    stationStick();
	glPopMatrix();


	signalBody();
	signalStick();

	 glPushMatrix(); //translate signal
		glTranslatef(530,0,0);
		 signalBody();
    signalStick();
	glPopMatrix();
    Busframe2();

 BusDoor();
     manBody();

    glColor3f (1.0, 1.0, 1.0); //for man head
   drawFilledCircle(350.0-mv,285.0,5);
     Busframe1();


	glMatrixMode(GL_MODELVIEW) ;
	glLoadIdentity();

    glPushMatrix();
		 drawWindows();
		glTranslatef(30,0,0);
		 drawWindows();
		 glTranslatef(30,0,0);
		 drawWindows();
		  glTranslatef(30,0,0);
		 drawWindows();
		  glTranslatef(30,0,0);
		 drawWindows();
		  glTranslatef(30,0,0);
		 drawWindows();
	glPopMatrix();



    glColor3f (0.0, 0.0, 0.0);   //for tire =============================================
   drawFilledCircle(tx+90.0,240.0,20);
   drawFilledCircle(tx+190.0,240.0,20);

   glColor3f (1.0, 0.0, 0.0);   //for signal 1 red=============================================
   drawFilledCircle(410.0,380.0,5);
   glColor3f (0.0, 1.0, 0.0); //for signal 1 green
   drawFilledCircle(430.0,380.0,5);




	glColor3f (1.0, 0.0, 0.0);   //for signal 2 red=============================================
   drawFilledCircle(940.0,380.0,5);
   glColor3f (0.0, 1.0, 0.0); //for signal 2 green
   drawFilledCircle(960.0,380.0,5);



   if(bodyPos<850)
    success=1;
   else
    success=0;

   if(carPos>bodyPos && success==1 )
    mv-=3;
	glutSwapBuffers() ;
}
void init(){

    glLineWidth(5.0);
	glClearColor( 0.0 , 0.0 , 0.0 , 0.0 );  //Setting Background-RGBA
	glMatrixMode( GL_PROJECTION) ;
	glLoadIdentity() ;
	glOrtho( 0.0 , 1000.0 , 0.0 , 500.0 , -1.0 , 1.0) ;

}

int main()
{

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //display mode

	glutInitWindowSize(1000,500 );
	glutInitWindowPosition(100,100);
	glutCreateWindow("BUS") ;

	init() ;
	glutDisplayFunc(display) ;

	glutSpecialFunc(SpecialInput);
	//glutKeyboardFunc(keyboardHandler);
	//glutIdleFunc(anim) ;

	glutMainLoop() ;

	return 0;

}
