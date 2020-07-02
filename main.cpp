#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#define PI 3.14159265f
using namespace std;

class material
{
public:void emission(float r,float g,float b)
{
	GLfloat mat_emission[] = {r, g, b, 0.0};
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
}

void Diffusion(float r,float g,float b)
{
	GLfloat c[] = {r, g, b, 0.0};
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
}


//void shine(float r)
//{
	//GLfloat high_shininess[] = { r };
     //glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

//}

//void SPECULAR(float r,float g,float b)
//{
	//GLfloat c[] = {r, g, b, 0.0};
	//glMaterialfv(GL_FRONT, GL_SPECULAR, c);
//}

};
material materials;

//--------------------------------------------------------start 20 nov 2019
GLfloat redDiffuseMaterial[] = {1.0, 0.0, 0.0}; //set the material to red
GLfloat whiteSpecularMaterial[] = {1.0, 1.0, 1.0}; //set the material to white
GLfloat greenEmissiveMaterial[] = {0.0, 1.0, 0.0}; //set the material to green
GLfloat whiteSpecularLight[] = {1.0, 1.0, 1.0}; //set the light specular to white
GLfloat blackAmbientLight[] = {0.0, 0.0, 0.0}; //set the light ambient to black
GLfloat whiteDiffuseLight[] = {1.0, 1.0, 1.0}; //set the diffuse light to white
GLfloat blankMaterial[] = {0.0, 0.0, 0.0}; //set the diffuse light to white
GLfloat mShininess[] = {128}; //set the shininess of the material


void init (void) {
	glShadeModel (GL_SMOOTH);
    glEnable (GL_DEPTH_TEST);
    glEnable (GL_LIGHTING);
    glEnable (GL_LIGHT0);
}

void light (void) {
    glLightfv(GL_LIGHT0, GL_SPECULAR, whiteSpecularLight);
    glLightfv(GL_LIGHT0, GL_AMBIENT, blackAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteDiffuseLight);
}

//--------------------------------------------------------end 20 nov 2019

//--------------------------------------------------------start


#pragma comment (lib,"opengl32.lib")
#pragma comment (lib,"glu32.lib")
#pragma comment (lib,"glut32.lib")

void drawBitmapText(char *string,float x,float y,float z)
{
	char *c;
	glRasterPos3f(x, y,z);

	for (c=string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}
/*
void drawStrokeText(char*string,int x,int y,int z)
{
	  char *c;
	  glPushMatrix();
	 // glTranslatef(x, y+8,z);
	 // glScalef(0.09f,-0.08f,z);

	  for (c=string; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  }
	  glPopMatrix();
}
*/



void textShowString(char *string,int x,int y,int z )
{

 glPushMatrix();
	glColor3f(0,1,0);
drawBitmapText(string,x,y,z);

	glPopMatrix();

}
//--------------------------------------------------------end

//--------------------------------------------------------start  19 nov 2019
 /*class LightAndMaterial {
public:

     // GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  // GLfloat mat_shininess[] = { 50.0 };
float i=0;
GLfloat light_position[4];// = { 0.0, 0.0, 1.0, 0.0 };//in x direction in positive . it means that light is on.
   GLfloat lmodel_ambient[4];// = { 0.1, 0.1, 0.1, 1.0 };
// automatic inline
bool positionOn=true;

 void Light_Ani()
 {

	if(i<1.0)
	{
		i=i+.1;
	}
	else
	i=0;
}*/
/*
 void Light_position(float x,float y,float z,float Isdirection)
 {

Light_Ani();
 	if(!positionOn)
 	{
 		 	light_position[0] = 0;
 	light_position[1] = 0;
 	light_position[2] = 0;
 	light_position[3] = 0;
	 }
	 else
	 {
	 	light_position[0] = x;
 	light_position[1] = y;
 	light_position[2] = z;
 	light_position[3] = Isdirection;

	 }
glClearColor (0.0, 0.0, 0.0, 0.0);

//   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  // glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
 }

*/
/* void material()
 {
 	   GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
   GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
   //GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
    GLfloat mat_diffuse[] = { 0, 0, 1, 0.0 };

   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat no_shininess[] = { 0.0 };
   GLfloat low_shininess[] = { 5.0 };
   GLfloat high_shininess[] = { 100.0 };
   //GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};
   GLfloat mat_emission[] = {0.0, .0, i, 0.0};
   GLfloat mat_emission_fire[] = {i, i, 0.0, 0.0};


   glTranslatef (0, 0.0, 2.0);
     // glColor3f(1.0f, 1.0f, 1.0f);
   glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   //glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission_fire);
   glutSolidSphere(1.5, 16, 16);

 }*/
//};
//LightAndMaterial Light1;

//--------------------------------------------------------end    19 nov 2019
 #include <cmath>
// global variable
GLfloat angle = 0.0f;  // rotational angle of the shapes
GLfloat translateX = 0.0f;  // translate in X of the shapes
int refreshMills =200; // refresh interval in milliseconds
bool stop=false;
 float orthoLen=3.0;


 float tankX=0.3,tankY=.3;
/* Initialize OpenGL Graphics */
//void initGL() {
   // Set "clearing" or background color
//   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque

//}

   //-------------------s 19 nov 2019


   //-------------------e 19 nov 2019


/* Called back when timer expired */
void Timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
  // if(stop==false)
   glutTimerFunc(refreshMills, Timer, 0); // next Timer call milliseconds later
}
class ball {
public:
int a, b;
float ballRadius = 00.1f;   // Radius of the bouncing ball
float ballX = 0.0f;         // Ball's center (x, y) position
float ballY = 0.0f;
float ballXMax, ballXMin, ballYMax, ballYMin; // Ball's center (x, y) bounds
bool up=false,keyP=false,inAir=false;
// automatic inline

 void makeball()
 {
 	// Use triangular segments to form a circle

   glBegin(GL_TRIANGLE_FAN);
      glColor3f(0.0f, 0.0f, 1.0f);  // Blue
      glVertex2f(0.0f, 0.0f);       // Center of circle
      int numSegments = 100;
      GLfloat angle;
      for (int i = 0; i <= numSegments; i++) { // Last vertex same as first vertex
         angle = i * 2.0f * PI / numSegments;  // 360 deg for all segments
         glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
      }
   glEnd();
 }
 void moveUp()
 {
 	glTranslatef(ballX, ballY, 0.0f);

 }


 void icreaseInY();
void decreaseInY();
void keyPress();
void initialPosition(float x,float y);

};
void ball ::  initialPosition(float x,float y)
{
	this->ballX=x;
	this->ballY=y;
}
void ball :: icreaseInY()
{


 	if(ballY<1.2 )
 	{
 		ballY +=0.2;

	 }



 }

 void ball :: decreaseInY()
{
 	if( this->ballY>0.0)
 	{
 		ballY -=0.2;

	 }
 }

void ball ::keyPress()
{
	if(this->keyP==true )
	{
	  	this->icreaseInY();
   		this->decreaseInY();
	}

}
void translateInX()
 {
 	if(translateX<1.5)
 	{
 		translateX += 0.01f;
	}
	//if(translateX==.9)
	else
 	{
 		translateX = -1.0;
	}

 }
 ball b;

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */

 class Cube
{
	public:
		int width,lenght ;
		float s=.1 ,centerX,centerY,x1,x2,y1,y2,speed=.1,life=100.0,fanRot=0.0;
		bool moveBack=false;
	void make(float s);
	void centerOfCurrentLocation(float tx,float t);
	void moveCar(float y);
	void translate(float x,float y,float z);
	void icreaseInX();
	void decreaseInX();
	void LeftRightInX();
	void decraseLife();
	void makeLife();
	void BackFan();
};
Cube c;

void Cube:: BackFan()
{
	//back
   glTranslatef(-.4,-.3,.5);
   // materials.emission(1,0.8,1);
     glRotatef(this->fanRot, 0.0,0.0,  1.0);

    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTorus(.08, 0.2, 100, 2);


    glColor3f(1.0f, 0.0f, 0.0f);
    glRotatef(90, 0.0,0.0,  1.0);

   // glutWireTorus(0.02, 0.05, 50, 10);

     glutWireTorus(.08, 0.2, 100, 2);
if(this->fanRot<361)
{
	this->fanRot=this->fanRot+50;
}
else
{
	this->fanRot=0.0;
}

//front

}

void Cube::decraseLife()
{
	if(this->life>0)
	{
		this->life-=10.0;
	}
	else
		// stop game
		;
}
void Cube:: makeLife()
{
	if(this->life>0)
	{

	glTranslatef(4.0-(this->life/100.0), 2.84, -.1f);    // Translate
		glLineWidth(50.0);


 	glBegin(GL_LINES);
 	glColor3f(1.0f, 0.0f, 0.0f);     // Red
		 glVertex2i(0.0, 0.0);
		 	glColor3f(0.0f, 1.0f, 0.0f);     // Red

		 glVertex2i(1.0, 0.0);
	   glEnd();

}
}

void Cube::make(float si)
{
	this->s=si;
	float w=.6,l=.1,gunFace=.0001,gW=.1,gH=.2,movX=.3,movY=.1;
	materials.emission(.1,1,.5);

	glBegin(GL_POLYGON);                  // gunFace
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex2f(-si+.05+movX-.2, -si-.05-movY);	//x1,y1
      glVertex2f( si-.05+movX-.05, -si-.05-movY);	//x2,y1
      glVertex2f( si-.05, si);	//x2,y2
      glVertex2f(-si+.05+movX-.2, si);
   glEnd();


	glBegin(GL_POLYGON);                  // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex2f(x1=-si, y1=-si);	//x1,y1
      glVertex2f( x2=si+w, -si);	//x2,y1
      glVertex2f( x2-.1, y2=si-.1);	//x2,y2
      glVertex2f(-si, si);	//x1,y2
   glEnd();
   materials.emission(.1,1,.5);
   float moveback=.5;
 	glBegin(GL_POLYGON);
	                // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex2f(-.7, -.2);	//x1,y1
      glVertex2f( -.2, -.2);	//x2,y1
      glVertex2f( -.2, .1);	//x2,y2
      glVertex2f(-.5, .0001);	//x1,y2
	  glVertex2f(-.8, .2);	//x1,y2
   glEnd();

   glBegin(GL_POLYGON);
	                // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex2f(-.05,.3);	//x1,y1
      glVertex2f(.05, .3);	//x2,y1
      glVertex2f( .05, .05);	//x2,y2
      glVertex2f(-.05, .05);	//x1,y2

   glEnd();
   float s=.1,width=.6,front=.1,back=.1;
   glTranslatef(-0.3, .4, 0.0f);    // Translate
materials.emission(0,0,1);
   glBegin(GL_POLYGON);                  // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex2f(x1=-s, y1=-s);	//x1,y1

      glVertex2f( x2=s+width, -s);	//x2,y1
      //front
      glVertex2f( s+width+front, -s+front);	//x2,y1
      glVertex2f(s+width+front, s-front);	//x2,y1
      //end

      glVertex2f( s+width, y2=s);	//x2,y2
      glVertex2f(-s, s);	//x1,y2


	  //back

 	   glVertex2f(-s-back, s-back);	//x1,y2
      glVertex2f(x1=-s-back, y1=-s+back);	//x1,y1

   glEnd();
    	glPushMatrix();

 this->BackFan();
  	glPopMatrix();

}
void Cube::centerOfCurrentLocation(float tx,float ty)
{
	this->centerX=(this->x1+this->x2)/2.0;
	this->centerX=this->centerX+tx;

	this->centerY=(this->y1+this->y2)/2.0;
	this->centerY=this->centerY+ty;


}
	void Cube:: translate(float x,float y,float z)
	{
		glTranslatef(x, y, 0.0f);    // Translate

   	this->centerOfCurrentLocation(x,y);

	}
void Cube :: icreaseInX()
{


 	if(this->centerX<1.2 )
 	{
 		this->centerX +=0.2;

	 }



 }

 void Cube :: decreaseInX()
{
 	if( this->centerX>0.0)
 	{
 		this->centerX -=0.2;

	 }



 }

 void Cube :: LeftRightInX()
 {
 	float minX=0.0,maxX=3.0;
 	if(this->centerX<maxX&&moveBack==false  )
 	{
 		this->centerX +=speed;

	 }
	 else
	 	moveBack=true;

	if(this->centerX>minX&&moveBack==true  )
 	{
 		this->centerX -=speed;

	 }
	 else
	 	moveBack=false;

 }

class Cannon
{
	public:
		int width,lenght ;
		float s=.1 ,centerX=.5,centerY,x1,x2,y1,y2,targetX,targetY,ANGLE,ballRadius=2.0,inc=90.0,
		rotatZ=0.0,translatX=0.0,
		speed=.1	;
		bool firstTimeShoot=false,moveBack=false;

		// tank info:
		float TankcenterX,TankcenterY,Tankx1,Tankx2,Tanky1,Tanky2;
	void make(float s);
	void centerOfCurrentLocation(float tx,float t);
	void moveCan();
	void translate(float x,float y,float z);
	void positCan(char c);
	void move(float x,float y);
	//tank
//	void tankBody(float si);

};
/*void Cannon:: move(float x,float y)
{
	float minX=0.0,maxX=3.0;
	this->centerX=x,this->centerY=y;
 	if(this->centerX<maxX&&moveBack==false  )
 	{
 		this->centerX +=speed;

	 }
	 else
	 	moveBack=true;

	if(this->centerX>minX&&moveBack==true  )
 	{
 		this->centerX -=speed;

	 }
	 else
	 	moveBack=false;

}*/
/*void Cannon:: tankBody(float si)
{
	//this->s=si;
	float width=.6,front=.2,back=.2;
	glBegin(GL_POLYGON);                  // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex2f(Tankx1=-si, Tanky1=-si);	//x1,y1
      glVertex2f( Tankx2=si+width, -si);	//x2,y1
      //front
      glVertex2f( si+width+front, -si+front);	//x2,y1
      glVertex2f(si+width+front, si-front);	//x2,y1
      //end

      glVertex2f( si+width, Tanky2=si);	//x2,y2
      glVertex2f(-si, si);	//x1,y2


	  //back

 	   glVertex2f(-si-back, si-back);	//x1,y2
      glVertex2f(Tankx1=-si-back, Tanky1=-si+back);	//x1,y1

   glEnd();

}*/
void Cannon::make(float si)
{
	 glPushMatrix();
	this->s=si;
	float height=.6,f=.1,upper=.1;
	glBegin(GL_QUADS);                  // Each set of 4 vertices form a quad
     glColor3f(1.0f, 0.0f, 0.0f);     // Red

      glVertex2f(x1=-si, y1=-si);	//x1,y1

	  glVertex2f( x2=si, -si);	//x2,y1

	  glVertex2f( si+upper, y2=si+height);	//x2,y2

      glVertex2f(-si-upper, si+height);	//x1,y2
//materials.emission(0,1,0);

   glEnd();
 	 glPopMatrix();

}
void Cannon::centerOfCurrentLocation(float tx,float ty)
{
	this->centerX=(this->x1+this->x2)/2.0;
	this->centerX=this->centerX+tx;

	this->centerY=(this->y1+this->y2)/2.0;
	this->centerY=this->centerY+ty;


}
	void Cannon:: translate(float x,float y,float z)
	{
		float factor=.1;
		glTranslatef(x, y, 0.0f);    // Translate

   	this->centerOfCurrentLocation(x,y);

	}

void Cannon:: moveCan()
{
glTranslatef(this->translatX, 0.0, 0.0);
 glRotatef(this->rotatZ, 0.0,0.0,  0.1);


}
void Cannon:: positCan(char c)
{
	float r=1.0+orthoLen+3;
	float speedX=.0001,SpeedZ=5.0,i=5.7,angle=40;
	if(c=='l'&&this->rotatZ<angle)
	{
		this->rotatZ=this->rotatZ+SpeedZ;
		this->translatX=this->translatX+speedX;


		ANGLE = inc * 3.142f  / 180.0;
		this->targetX= (cos(ANGLE) * r)+this->centerX;
		this->targetY= (sin(ANGLE) * r)+this->centerY;
		this->inc+=i;
	}
	if(c=='k'&&this->rotatZ>-angle)
	{
		this->rotatZ=this->rotatZ-SpeedZ;
		this->translatX=this->translatX-speedX;

		ANGLE = inc * 3.142f  / 180.0;
		this->targetX= (cos(ANGLE) * r)+this->centerX;
		this->targetY= (sin(ANGLE) * r)+this->centerY;
		this->inc-=i;

	}

}


Cannon can,relativeBox;
bool fire=false;
float inc=0;


class TankBody
{
	public:
		int width,lenght ;
		float s=.1 ,centerX,centerY,x1,x2,y1,y2,targetX,targetY,ANGLE,ballRadius=2.0,inc=90.0,
		rotatZ=0.0,translatX=0.0,RoWheel=0;
		float life=100;
		bool IsCollision=false;
	void make(float s);
	void centerOfCurrentLocation(float tx,float t);
	void moveCan();
	void translate(float x,float y,float z);
	void positCan(char c);
	void decraseLife();
	void makeLife();
	void makewheel(); // back wheel
	void makewheelF();//front wheel

};

void TankBody:: makewheel()
{
	//back
   glTranslatef(-.2,-.2,.5);
     glRotatef(this->RoWheel, 0.0,0.0,  1.0);

    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTorus(0.03, 0.2, 2, 10);


    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTorus(0.1, 0.05, 50, 2);


//front

}

void TankBody:: makewheelF()
{
	//back
   glTranslatef(.99,-.2,.5);
   // materials.emission(1,0.8,1);
     glRotatef(this->RoWheel, 0.0,0.0,  1.0);

    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTorus(0.03, 0.2, 2, 10);


   //glTranslatef(0.0,0,0);
   // materials.emission(1,0.8,1);
     //glRotatef(this->RoWheel, 0.0,0.0,  1.0);

    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTorus(0.1, 0.05, 50, 2);


//front

}


void TankBody::decraseLife()
{
	if(this->life>0)
	{
		this->life=this->life-2;
	}
	else
		// stop game
		;
}
void TankBody:: makeLife()
{
	if(this->life>0)
	{

	glTranslatef((this->life/100.0), 2.8, 0.0f);    // Translate
		glLineWidth(50.0);
		glColor3f(1.0f, 0.0f, 0.0f);     // Red

 	glBegin(GL_LINES);
		 glVertex2i(-1.0, 0.0);
		 glVertex2i(0.0, 0.0);
	   glEnd();

}
}

void TankBody::make(float si)
{
 glPushMatrix();

	materials.Diffusion(.5,1,0);
	materials.emission(0.5,1,0);
	//this->s=si;
	float width=.6,front=.2,back=.2;
	glBegin(GL_POLYGON);                  // Each set of 4 vertices form a quad

	  glColor3f(1.0f, 0.0f, 0.0f);     // Red
      materials.emission(0,0,0);
	  glVertex2f(x1=-si, y1=-si);	//x1,y1
      glVertex2f( x2=si+width, -si);	//x2,y1
      //front
      materials.emission(1,0,0);
	  glVertex2f( si+width+front, -si+front);	//x2,y1
      materials.emission(1,0,0);
	  glVertex2f(si+width+front, si-front);	//x2,y1
      //end

      glVertex2f( si+width, y2=si);	//x2,y2
      glVertex2f(-si, si);	//x1,y2


 	   glVertex2f(-si-back, si-back);	//x1,y2
      glVertex2f(x1=-si-back, y1=-si+back);	//x1,y1

   glEnd();
   this->makewheel();
    glPopMatrix();

 	glPushMatrix();
 	this->makewheelF();
 	glPopMatrix();
}
void TankBody::centerOfCurrentLocation(float tx,float ty)
{
	this->centerX=(this->x1+this->x2)/2.0;
	this->centerX=this->centerX+tx;

	this->centerY=(this->y1+this->y2)/2.0;
	this->centerY=this->centerY+ty;


}
	void TankBody:: translate(float x,float y,float z)
	{
		//glTranslatef(x, y, 0.0f);    // Translate

   	this->centerOfCurrentLocation(x,y);

	}
TankBody TB;

class Laser
{
	public:
		int width,lenght ;
		float s=.1 ,centerX,centerY,x1,x2,y1,y2,targetX,targetY,ANGLE,ballRadius=2.0,inc=90.0,
		rotatZ=0.0,translatX=0.0,
		speed=.1	;
		bool firstTimeShoot=false,moveBack=false;

		// tank info:
		float TankcenterX,TankcenterY,Tankx1,Tankx2,Tanky1,Tanky2;
	void make(float s);
	void centerOfCurrentLocation(float tx,float t);
	void moveCan();
	void translate(float x,float y,float z);
	void positCan(char c);
	void initialmove(float x,float y);
	void move(float x,float y);
	//tank

};

void Laser:: initialmove(float x,float y)
{
	glTranslatef(x, y, -.1);
}

void Laser::make(float si)
{
	glPushMatrix();

	this->s=si;
	float w=.1,l=3.0,moveDown=.6;
	initialmove(.5,0.0);
	materials.Diffusion(1,0,0.0);
	glBegin(GL_POLYGON);                  // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, .8f);     // Red
    materials.emission(1,0,0);
	  glVertex2f(x1=-si, y1=-si-l);	//x1,y1
      glVertex2f( x2=si+w, -si-l);	//x2,y1
      glVertex2f( x2-.1, y2=si-.1-moveDown);	//x2,y2
      glVertex2f(-si, si-moveDown);	//x1,y2
   glEnd();
glPopMatrix();

}
Laser laser;

class collision
{
		public:
			bool hasAnyOneLose=false;
			void collisionWithLaser(float cX,float cY,float ballX,float ballY);
			void collisionWithVehicle(float carX,float carY,float ballX,float ballY);
			void collisionWithSquare(float cX,float cY,float ballX,float ballY);
			void result();
};
	void collision::result()
{
	float r=10.0;
	if(TB.life==0.0)
	{
		this->hasAnyOneLose=true;
 textShowString("You lost",1.7,1.8,0.0);

glDisable (GL_LIGHTING);
	}
	if(c.life==0.0){
		this->hasAnyOneLose=true;

	textShowString("You won",1.7,1.8,0.0);

glDisable (GL_LIGHTING);

	}


}
void collision::collisionWithSquare(float cX,float cY,float ballX,float ballY)
{

	float A=0.5,maxX=cX+A,minX=cX-A,maxY=cY+A,minY=cY-A;
	if((ballX<=maxX+.6 && ballX>=minX)&&(ballY<=maxY && ballY>=minY))
	{
		c.decraseLife();
		glBegin(GL_QUADS);                  // Each set of 4 vertices form a quad
      glColor3f(0.0f, 0.0f, 0.0f);     // Red
      glVertex2f(-0.1f+c.centerX, -0.1f+c.centerY);
      glVertex2f( 0.1f+c.centerX, -0.1f+c.centerY);
      glVertex2f( 0.1f+c.centerX, 0.1f+c.centerY);
      glVertex2f(-0.1f+c.centerX, 0.1f+c.centerY);
   glEnd();
	}

}

void collision::collisionWithLaser(float cX,float cY,float ballX,float ballY)
{
	float A=0.5,back=.2,
	maxX=cX+A,minX=cX-A,maxY=cY+A,minY=cY-A;
	if((ballX<=maxX && ballX>=minX)&&(ballY<=maxY && ballY>=minY))
	{
		TB.decraseLife();
   TB.IsCollision=true;
	}
	else
		TB.IsCollision=false;
}

/*void collision::collisionWithVehicle(float carX,float carY,float ballX,float ballY)
{
	if(ballX>=carX && ballX<=carX+.5 || ballY>=carY && ballY<=carY+0.2 )
	{
		glBegin(GL_QUADS);                  // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex2f(-.5f, -0.5f);
      glVertex2f( 0.5f, -0.5f);
      glVertex2f( 0.5f, 0.5f);
      glVertex2f(-0.5f, 0.5f);
   glEnd();
stop=true;
	}
}*/
collision collisionWithCar1;

//----------------------------------------------------------start
#include <vector>
//#include <algorithm>
std::vector<float> arrX,arrY;
float arrI=0.0;
void drawline(float x1, float y1, float x2, float y2)
{
 float m,c,y,x;
 m=(y2-y1)/(x2-x1);

 c=y1-m*x1;
 y=m*x+c;
 if(x2<x1)
 {
 	float xx1=x1,xx2=x2;

 	while(xx2<=xx1)
 	{
 		y=m*xx1+c;
       	arrX.push_back(xx1);
		arrY.push_back(y);

 		xx1=xx1-.1;
	 }
 }

  if(x2>x1)
 {
 	float xx1=x1,xx2=x2;
 	while(xx2>=xx1)//xx2 will decrease
 	{
 		y=m*xx1+c;
        arrX.push_back(xx1);
		arrY.push_back(y);

 		xx1+=.1;
	 }
 }

}

//----------------------------------------------------------end
void display() {

    glClearColor (0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


//   glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
   glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
   glLoadIdentity();               // Reset the model-view matrix

    light();

//----------------------------------------------------------Start
float x = 123.4567;
    char buf[10];


 glPushMatrix();
TB.makeLife();
glTranslatef(-2,0,0);
//Light1.material();
GLfloat mat_emission[] = {0, 1, 0, 0.0};
  GLfloat high_shininess[] = { 100.0 };
GLfloat mat_diffuse[] = { 0, .5, 0, 0.0 };
GLfloat heli_diffuse[] = { .8, 0, 0, 0.0 };

GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };

   GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
   GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };


  glPopMatrix();

 glPushMatrix();
c.makeLife();
  glPopMatrix();

//-----------------------------------------------------------end
 glPushMatrix();

 	if(fire && !can.firstTimeShoot)
 	{
 				//drawline(2.5,0.0,can.targetX,can.targetY);
 				drawline(can.centerX,can.centerY,can.targetX,can.targetY);
	 }


 	if(fire)
	 {

		   if(arrI<arrX.size())
		   {
		   		glTranslatef(b.ballX= arrX[arrI],b.ballY= arrY[arrI], 0.0f);

				//glTranslatef(-1, -1, 0.0f);
				arrI=arrI+2;
		   can.firstTimeShoot=true;

		   }
		   else
		   {
		   		fire=false;
	//	   		textShowFloat(b.ballX,0,-1,0);
//		   		textShowString("in fire",-1,-1,0);
		   		can.firstTimeShoot=false;
		   		//b.initialPosition(2.5,0.0);
				b.initialPosition(can.centerX,can.centerY);
		   		b.moveUp();
		   }

 	}
	 b.makeball();
 	glPopMatrix();



 	float transY=1.0,transX=0.0;
 glPushMatrix();                     // Save model-view matrix setting
   	   glTranslatef(laser.centerX=c.centerX+.5, laser.centerY=c.centerY=2.0, 0.0f);
if(collisionWithCar1.hasAnyOneLose)
   	   glTranslatef(laser.centerX=c.centerX=4.0, laser.centerY=c.centerY=2.0, 0.0f);

	   c.make(.2);
		if(TB.IsCollision)
	   			laser.make(.1);

 	glPopMatrix();

	                   // Restore the model-view matrix
collisionWithCar1.collisionWithSquare(c.centerX,c.centerY,b.ballX,b.ballY);
collisionWithCar1.collisionWithLaser(c.centerX+1.0,.3,TB.centerX+.1,TB.centerY);



float tx=can.centerX,ty=.5;

 glPushMatrix();
 if(collisionWithCar1.hasAnyOneLose)
can.translate(0,-10,0.0);

 can.translate(tx,ty,0.0);
 TB.centerOfCurrentLocation(tx,ty);

TB.make(.2);
can.moveCan();
can.make(.05);

   glPopMatrix();

 glPushMatrix();

glTranslatef(can.targetX, can.targetY, 0.0f);
//can.make(.5);
glBegin(GL_TRIANGLE_FAN);
      glColor3f(0.0f, 0.0f, 1.0f);  // Blue
      glVertex2f(0.0f, 0.0f);       // Center of circle
       int numSegments = 100;
       float angle;
      for (int i = 0; i <= numSegments; i++) { // Last vertex same as first vertex
         angle = i * 2.0f * PI / numSegments;  // 360 deg for all segments
         glVertex2f(cos(angle) * b.ballRadius, sin(angle) * b.ballRadius);
      }
   glEnd();


  glPopMatrix();


 float px=can.centerX-can.translatX;


glPushMatrix();




collisionWithCar1.result();
if(collisionWithCar1.hasAnyOneLose)
{

TB.make(5);

}
  glPopMatrix();

  glutSwapBuffers();   // Double buffered - swap the front and back buffers

   angle += 2.0f;
   translateInX();

c.LeftRightInX();


}
 void keyboard(unsigned char key, int x, int y) {

 	float inc=0.0, minX=0.5,maxX=3.0,wheelSp=100;
   switch (key) {
      case 'a':
 	if(can.centerX<maxX)
 	{
 		can.centerX +=can.speed;

	 }
	 TB.RoWheel=TB.RoWheel-wheelSp;
		 //exit(0);
         break;

         case 's':
      //b.decreaseInY();
      if(can.centerX>minX)
 	{
 		can.centerX -=can.speed;

	 }
     TB.RoWheel=TB.RoWheel+wheelSp;
         //exit(0);
         break;

         case 'f':
      fire=true;
     // inc++;
         //exit(0);
         break;

         case 'l':
    	 can.positCan('k');

    	 break;

		 case 'k':
      	 can.positCan('l');
         break;


		 case 'P':
      	 glDisable(GL_LIGHTING);
         break;
   }
   glutPostRedisplay();
}


/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix


   glLoadIdentity();
   if (width >= height) {
	gluOrtho2D(0.0 * aspect, orthoLen * aspect, 0.0, orthoLen);
   } else {
	 gluOrtho2D(0.0, orthoLen, 0.0 / aspect, orthoLen / aspect);
   }
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE);  // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height - non-square
   //glutInitWindowSize(720, 500);   // Set the window's initial width & height - non-square
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("Battle in the Dark");  // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   glutTimerFunc(0, Timer, 0);     // First timer call immediately
    glutKeyboardFunc(keyboard);

//   initGL();                       // Our own OpenGL initialization
 init();
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
