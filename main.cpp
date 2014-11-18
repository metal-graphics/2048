/*
 * OGL01Shape3D.cpp: 3D Shapes
 */
//#include <windows.h>  // for MS Windows
#include<GL/freeglut.h> //Comment this if you are in Ubuntu
#include <GL/gl.h>  
#include<iostream>
#include<algorithm>
#include<cmath>
//#include<conio.h> Uncomment this if you are in Windows
#include <SOIL/src/SOIL.h> //path to the SOIL package
#include "2048.cpp"
using namespace std;

/* Global variables */
char title[] = "2048";

/*Define some colors*/
float quartz[]={0.847059,0.847059,0.74902};
float white[] = {1,1,1};
float wheat[]={0.83,0.847059,0.74902};

float yellow[]={1,1,0}; //2048
float yellowish[]={1,0.9,0};  //1024
float yell_orng[]={1,0.9,0.2};  //512
float orng_yell[]={1,0.9,0.5};  //256
float orng[]={1,1,0.6};       //128
float orange[]={1,0.6,0};  //64
float orn[]={1,0.7,1};          //32
float orangish[]={0.8,0.5,0};  //16
float ong[]={1,0.7,0.5};           //8
float wheatish[]={0.9,0.8,0.6};           //4
float  grey[]={0.9,0.9,0.8};          //2
/* Initialize OpenGL Graphics */
float cubecolor[] = {0,0,0}; //color of each cube in the 2048 puzzle,initial value doesn't matter
GLuint tex_2d[12]; //0,2,4,8,16,32,64,128,256,512,1024,2048


void loadTextures() {
	
	  tex_2d[0] = SOIL_load_OGL_texture
	(
		"./pictures/0.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	  tex_2d[1] = SOIL_load_OGL_texture
	(
		"./pictures/2.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	  tex_2d[2] = SOIL_load_OGL_texture
	(
		"./pictures/4.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	tex_2d[3] = SOIL_load_OGL_texture
	(
		"./pictures/8.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	  tex_2d[4] = SOIL_load_OGL_texture
	(
		"./pictures/16.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	  tex_2d[5] = SOIL_load_OGL_texture
	(
		"./pictures/32.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	 tex_2d[6] = SOIL_load_OGL_texture
	(
		"./pictures/64.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	tex_2d[7] = SOIL_load_OGL_texture
	(
		"./pictures/128.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	 tex_2d[8] = SOIL_load_OGL_texture
	(
		"./pictures/256.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	  tex_2d[9] = SOIL_load_OGL_texture
	(
		"./pictures/512.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	  tex_2d[10] = SOIL_load_OGL_texture
	(
		"./pictures/1024.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	tex_2d[11] = SOIL_load_OGL_texture
	(
		"./pictures/2048.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	tex_2d[11] = SOIL_load_OGL_texture
	(
		"./pictures/board.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	glBindTexture(GL_TEXTURE_2D, tex_2d[0]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	
	
} //loadTextures

void initGL() {
	
   
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
   
 //  glEnable (GL_BLEND);
  // glBlendFunc (GL_SRC_ALPHA, GL_ONE);
   glEnable(GL_TEXTURE_2D);
   glEnable(GL_POINT_SPRITE);
   glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
   glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
   /* Load Textures*/
  loadTextures();

}


void DrawCube(float * color ){
	glBindTexture(GL_TEXTURE_2D, tex_2d[1]);
    glColor3f(color[0],color[1],color[2]);
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Bottom Right Of The Quad (Top)
   glColor3f(color[0],color[1],color[2]);
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Top Right Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Top Left Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Bottom)
    glColor3f(color[0],color[1],color[2]);
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Front)
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Front)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Front)
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Front)
    glColor3f(color[0],color[1],color[2]);
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Top Right Of The Quad (Back)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Top Left Of The Quad (Back)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Bottom Left Of The Quad (Back)
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Bottom Right Of The Quad (Back)
    glColor3f(color[0],color[1],color[2]);
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Left)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Left)
    glColor3f(color[0],color[1],color[2]);
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Right)
    glVertex3f( -1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Right)
    glVertex3f( -1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Right)

}


void createCube(float x,float y,float z,float sx,float sy,float sz,float *color)
{

    glLoadIdentity();                 // Reset the model-view matrix

   glTranslatef(x, y, z);  // Move right and into the screen
    glScalef(sx,sy,sz); //4,.25,1


   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
    DrawCube(color);
   glEnd();
}


void changeColor(int i,int j) {
    int value;

    value = getNumber(i,j);
    //cout<<"VALUE IS "<<getNumber(i,j)<<endl;

     switch (value)
    {
        case 0:
           cubecolor[0]=white[0];
            cubecolor[1]=white[1];
             cubecolor[2]=white[2];
             glBindTexture(GL_TEXTURE_2D, tex_2d[0]);
            //cout<<"Color 0"<<endl;
            break;
        case 2:
            cubecolor[0]=grey[0];
             cubecolor[1]=grey[1];
              cubecolor[2]=grey[2];
              glBindTexture(GL_TEXTURE_2D, tex_2d[1]);
              // cout<<"Color 2"<<endl;
            break;
        case 4:
            cubecolor[0]=wheatish[0];
             cubecolor[1]=wheatish[1];
              cubecolor[2]=wheatish[2];
              glBindTexture(GL_TEXTURE_2D, tex_2d[2]);
             //  cout<<"Color 4"<<endl;
            break;
        case 8:
            cubecolor[0]=ong[0];
            cubecolor[1]=ong[1];
            cubecolor[2]=ong[2];
            glBindTexture(GL_TEXTURE_2D, tex_2d[3]);
            // cout<<"Color 8"<<endl;
            break;
        case 16:
            cubecolor[0]=orangish[0];
            cubecolor[1]=orangish[1];
            cubecolor[2]=orangish[2];
            glBindTexture(GL_TEXTURE_2D, tex_2d[4]);
            // cout<<"Color 16"<<endl;
            break;
        case 32:
            cubecolor[0]=orn[0];
             cubecolor[1]=orn[1];
              cubecolor[2]=orn[2];
              glBindTexture(GL_TEXTURE_2D, tex_2d[5]);
            //   cout<<"Color 32"<<endl;
            break;
        case 64:
            cubecolor[0]=orange[0];
            cubecolor[1]=orange[1];
            cubecolor[2]=orange[2];
            glBindTexture(GL_TEXTURE_2D, tex_2d[6]);
           //  cout<<"Color 64"<<endl;
            break;
        case 128:
            cubecolor[0]=orng[0];
            cubecolor[1]=orng[1];
            cubecolor[2]=orng[2];
            glBindTexture(GL_TEXTURE_2D, tex_2d[7]);
           //  cout<<"Color 128"<<endl;
            break;
        case 256:
            cubecolor[0]=orng_yell[0];
            cubecolor[1]=orng_yell[1];
            cubecolor[2]=orng_yell[2];
            glBindTexture(GL_TEXTURE_2D, tex_2d[8]);
            // cout<<"Color 256"<<endl;
            break;
        case 512:
            cubecolor[0]=yell_orng[0];
            cubecolor[1]=yell_orng[1];
            cubecolor[2]=yell_orng[2];
            glBindTexture(GL_TEXTURE_2D, tex_2d[9]);
           //  cout<<"Color 512"<<endl;
            break;
        case 1024:
            cubecolor[0]=yellowish[0];
              cubecolor[1]=yellowish[1];
                cubecolor[2]=yellowish[2];
                glBindTexture(GL_TEXTURE_2D, tex_2d[10]);
              //   cout<<"Color 1024"<<endl;
            break;
        case 2048:
            cubecolor[0]=yellow[0];
             cubecolor[1]=yellow[1];
              cubecolor[2]=yellow[2];
              glBindTexture(GL_TEXTURE_2D, tex_2d[11]);
             //  cout<<"Color 2048"<<endl;
    }



}



/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   int value;

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

   // Render a color-cube consisting of 6 quads with different colors
						glBindTexture(GL_TEXTURE_2D, tex_2d[12]);
                        createCube(0,0.2,-50,2, 2,0.1,quartz);

    cout<<"In Display Function"<<endl;

changeColor(0,0);
 createCube(-1.5,1.7,-50,0.4,0.4,0.1,cubecolor);
 changeColor(1,0);
 createCube(-1.5,0.7,-50,0.4,0.4,0.1,cubecolor);
changeColor(2,0);
 createCube(-1.5,-0.3,-50,0.4,0.4,0.1,cubecolor);
  changeColor(3,0);
 createCube(-1.5,-1.3,-50,0.4,0.4,0.1,cubecolor);

changeColor(0,1);
 createCube(-0.5,1.7,-50,0.4,0.4,0.1,cubecolor);
  changeColor(1,1);
 createCube(-0.5,0.7,-50,0.4,0.4,0.1,cubecolor);
 changeColor(2,1);
 createCube(-0.5,-0.3,-50,0.4,0.4,0.1,cubecolor);
 changeColor(3,1);
 createCube(-0.5,-1.3,-50,0.4,0.4,0.1,cubecolor);

 changeColor(0,2);
 createCube(0.5,1.7,-50,0.4,0.4,0.1,cubecolor);
changeColor(1,2);
 createCube(0.5,0.7,-50,0.4,0.4,0.1,cubecolor);
 changeColor(2,2);
 createCube(0.5,-0.3,-50,0.4,0.4,0.1,cubecolor);
changeColor(3,2);
 createCube(0.5,-1.3,-50,0.4,0.4,0.1,cubecolor);

changeColor(0,3);
 createCube(1.5,1.7,-50,0.4,0.4,0.1,cubecolor);
 changeColor(1,3);
 createCube(1.5,0.7,-50,0.4,0.4,0.1,cubecolor);
 changeColor(2,3);
 createCube(1.5,-0.3,-50,0.4,0.4,0.1,cubecolor);
changeColor(3,3);
 createCube(1.5,-1.3,-50,0.4,0.4,0.1,cubecolor);

       glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

}


void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset

   // Set up orthographic projection view [NEW]
   if (width >= height) {
     // aspect >= 1, set the height from -1 to 1, with larger width
      glOrtho(-3.0 * aspect, 3.0 * aspect, -3.0, 3.0, 0.1, 100);
   } else {
      // aspect < 1, set the width to -1 to 1, with larger height
     glOrtho(-3.0, 3.0, -3.0 / aspect, 3.0 / aspect, 0.1, 100);
   }
}

void keyPressed(unsigned char key,int x,int y) {

            cout<<"Irrelevant key pressed"<<endl;
}

void specialKeypressed(int key,int x,int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            cout<<"Left Key Pressed"<<endl;
            moveLeft();
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            moveRight();
            glutPostRedisplay();
            cout<<"Right Key Pressed"<<endl;
            break;
        case GLUT_KEY_UP:
            cout<<"Up Key Pressed"<<endl;
            moveUp();
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            cout<<"Down Key Pressed"<<endl;
            moveDown();
            glutPostRedisplay();
            break;
 }
}


/* Main function: GLUT s as a console application starting at main() */
int main(int argc, char** argv) {
   initializeBoard();

   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses
  glutSpecialFunc(specialKeypressed);

   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
