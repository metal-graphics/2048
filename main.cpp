/*
 * OGL01Shape3D.cpp: 3D Shapes
 */
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<iostream>
using namespace std;

/* Global variables */
char title[] = "3D Shapes";

/*Define some colors*/
float  brown[]  = {0.65 ,0.5 ,0.39};
float white[] = {1,1,1};
float black[] = {0,0,0};
float blue[] = {.8,.8,.8};
float green[] ={.1,1,.1};
float red[] = {1,.4,.2};
float cream[] = { .83,.91,.69};
float cream1[] = { .78,.80,.76};
float cyan[]={0.678431,0.917647,0.917647};
float olive[]={0.309804,0.309804,0.184314};
float wood[]={0.52,0.37,0.26};
float choc[]={0.36,0.2,0.09};
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}


void DrawCube(float * color ){

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
void DrawTiles(int colorflag,float x,float y,float z) {
   float cubefacecolor[] = {0.329412,0.329412,0.329412};
    glScalef(1,1,1);
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(x, y, z);  // Move right and into the screen


   //colorflag = 1 => white cube
   //colorflag =  0 => black cube
    if(colorflag == 1){
            //cout<<"here";
        cubefacecolor[0] = 0.752941;
        cubefacecolor[1] =0.752941 ;
        cubefacecolor[2] = 0.752941;
    }


   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
       DrawCube(cubefacecolor);
   glEnd();  // End of drawing color-cube
}



void DrawFloor(int width, int length,float baseX,float baseY,float baseZ) {
    int i,j;


    for(i=0;i<length;i++)
        for(j=0;j<width;j++)
        {

                DrawTiles((i+j)%2+1, baseX - i  , -1 ,baseZ - j);
        }
    for(i=0;i<length;i++)
        for(j=0;j<width;j++)
                //if(i==0 && j==0)
             //DrawTiles((i+j)%2-0.5, baseX +i  , -1 ,baseZ - j);

               //else
                DrawTiles((i+j)%2, baseX + i  , -1 ,baseZ - j);



}

void DrawTableTop(float x,float y,float z,float legScaleX,float legScaleY,float legScaleZ,float topScaleX,float topScaleY,float topScaleZ,float *color) {
    //float color[] = {.4,.2,.2};
   glLoadIdentity();                 // Reset the model-view matrix

   glTranslatef(x, y, z);  // Move right and into the screen
    glScalef(topScaleX,topScaleY,topScaleZ); //4,.25,1


   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
    DrawCube(color);
   glEnd();  // End of drawing color-cube
}

void DrawTableLeg(float x,float y,float z,float legScaleX,float legScaleY,float legScaleZ,float topScaleX,float topScaleY,float topScaleZ,float *color) {
   //float color[] = {.4,.2,.2};
   glLoadIdentity();         // Reset the model-view matrix

   glTranslatef(x,y,z);  // Move left and into the screen
   glScalef(legScaleX,legScaleY,legScaleZ); //.1,2,.1


   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      DrawCube(color);

   glEnd();  // End of drawing color-cube
}

void createTable(float x,float y,float z){

     glLoadIdentity();         // Reset the model-view matrix


     DrawTableTop(x+0,y+4,z+-6,.1,2,.1,4,.35,1,brown);//co-ordinates
     //DrawTableTop(0,4,-10);//co-ordinates
     //  DrawTableTop(0,4,-14);//co-ordinates

    DrawTableLeg(x+-4+.2,y+2,z+-5,.15,2,.1,2,.25,1,brown);//co-ordinates
    DrawTableLeg(x+-4+.2,y+2,z+-7,.15,2,.1,2,.25,1,brown);//co-ordinates
     DrawTableLeg(x+4-.2,y+2,z+-5,.15,2,.1,2,.25,1,brown);//co-ordinates
    DrawTableLeg(x+4-.2,y+2,z+-7,.15,2,.1,2,.25,1,brown);//co-ordinates


}

void createClassRoomWalls(float x,float y,float z,float scaleX,float scaleY,float scaleZ,float * color ){


    glLoadIdentity();         // Reset the model-view matrix



    glTranslatef(x, y, z);  // Move right and into the screen
    glScalef(scaleX,scaleY,scaleZ); //.1,2,.1


    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
    DrawCube(color);
    glEnd();  // End of drawing color-cube

}


void createBench(float x,float y,float z){

     glLoadIdentity();         // Reset the model-view matrix


     DrawTableTop(x+0,y+2,z+-6,.1,2,.1,4,.125,1,olive);//co-ordinates
     //DrawTableTop(0,4,-10);//co-ordinates
     //  DrawTableTop(0,4,-14);//co-ordinates

    DrawTableLeg(x+-4+.2,y+1,z+-5,.1,1,.1,4,.125,1,olive);//co-ordinates
    DrawTableLeg(x+-4+.2,y+1,z+-7,.1,1,.1,4,.125,1,olive);//co-ordinates
     DrawTableLeg(x+4-.2,y+1,z+-5,.1,1,.1,4,.125,1,olive);//co-ordinates
    DrawTableLeg(x+4-.2,y+1,z+-7,.1,1,.1,4,.125,1,olive);//co-ordinates


}

void createBoard() {
     glLoadIdentity();
        glTranslatef(0, 15, -60);  // Move right and into the screen
    glScalef(19,6,.1);


    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
    DrawCube(black);

    glEnd();  // End of drawing color-cube
}


void createDoor(float *color,float sx,float sy,float sz) {
     glLoadIdentity();
        glTranslatef(43.7, 3, -56);  // Move right and into the screen
    glScalef(sx,sy,sz);


    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
    DrawCube(color);
    glEnd();  // End of drawing color-cube
}



void createLight() {
     glLoadIdentity();
        glTranslatef(0, 25, -60);  // Move right and into the screen
    glScalef(13,0.3,.1);


    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
    DrawCube(white);

    glEnd(); // End of drawing color-cube
}

void createBook(float *color,float x,float y,float z) {
     glLoadIdentity();
        glTranslatef(x,y,z);  // Move right and into the screen
    glScalef(0.5,0.25,.25);


    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
    DrawCube(color);

    glEnd(); // End of drawing color-cube
}

/*void drawStage(float *color)
{
     glLoadIdentity();
        glTranslatef(0, 15, -60);  // Move right and into the screen
    glScalef(20,0,10);


    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
    DrawCube(color);

    glEnd();
}*/

/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   int i,j;

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

   // Render a color-cube consisting of 6 quads with different colors
                        createTable(0, 2, -50);

            /*Draw all the Benches*/
                        for(i=0;i<6;i++)
                            if(i%2==0)
                                createTable(-8*1,2,-12*(i/2+1)), createTable(-6*3,2,-12*(i/2+1));
                            else
                                createTable(8,2,-12*(i/2+1)),createTable(6*3,2,-12*(i/2+1));



                     for(i=0;i<6;i++)
                        if(i%2==0)
                            createBench(-8*1,2,-12*(i/2+1)+4), createBench(-6*3,2,-12*(i/2+1)+4);
                        else
                            createBench(8,2,-12*(i/2+1)+4), createBench(6*3,2,-12*(i/2+1)+4);

        /* Draw the Class Board*/

        createClassRoomWalls(0,15,-70,50,15,1,cream1); //front
        createClassRoomWalls(-35,15,-70,.25,15,70,cream); //left
        createClassRoomWalls(35,15,-70,.25,15,70,cream); //right
        createClassRoomWalls(0,95,-35,50,60,60,white); //top
    createBoard();

    createDoor(choc,9,16,9);
    createDoor(wood,9,15,8);


    createLight();

    createBook(black,2.5, 6.5, -52);
    createBook(cyan,2.5, 6.75, -52);

   DrawFloor(500,500,0,0,-6); //width,height,xy position


   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}




/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
 //
 //(0,0,0,0,0,-100,0,0,-1);
   gluPerspective(90.0f, aspect, 0.1f, 100.0f);

 // glOrtho(-20,20,20,20,0,-100);
  // glScalef(1,1,5);
  gluLookAt(1, 12, -5, /* look from camera XYZ */
               0, 0, -30, /* look at the origin */
               0, 1, 0); /* positive Y up vector */
//               glCallList(SCENE);

}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {

   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
