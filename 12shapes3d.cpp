#include <GL/glut.h>
#include <cmath>

float angleCube = 0.0f;
float angleSphere = 0.0f;
float angleCone = 0.0f;
float angleCylinder = 0.0f;
float angleTorus = 0.0f;

void drawCube()
{
    glutSolidCube(1.0);
}

void drawSphere()
{
    glutSolidSphere(0.5, 20, 20);
}

void drawCone()
{
    glutSolidCone(0.5, 1.0, 20, 20);
}

void drawCylinder(float radius, float height, int slices)
{
    GLUquadric *quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluCylinder(quadric, radius, radius, height, slices, 1);
    gluDeleteQuadric(quadric);
}

void drawTorus()
{
    glutSolidTorus(0.2, 0.5, 20, 20);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1.5, 1.5, -5.0);
    glRotatef(angleCube, 1.0f, 0.0f, 0.0f);
    glColor3f(1.0, 0.0, 0.0); // Red color
    drawCube();

    glLoadIdentity();
    glTranslatef(1.5, 1.5, -5.0);
    glRotatef(angleSphere, 0.0f, 1.0f, 0.0f);
    glColor3f(0.0, 1.0, 0.0); // Green color
    drawSphere();

    glLoadIdentity();
    glTranslatef(-1.5, -1.5, -5.0);
    glRotatef(angleCone, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0, 0.0, 1.0); // Blue color
    drawCone();

    glLoadIdentity();
    glTranslatef(1.5, -1.5, -5.0);
    glRotatef(angleCylinder, 1.0f, 0.0f, 1.0f);
    glColor3f(1.0, 1.0, 0.0);   // Yellow color
    drawCylinder(0.5, 1.0, 20); // Adjust the parameters as needed

    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
    glRotatef(angleTorus, 0.0f, 1.0f, 1.0f);
    glColor3f(1.0, 0.0, 1.0); // Magenta color
    drawTorus();

    glutSwapBuffers();
}

void update(int value)
{
    angleCube += 2.0f;
    angleSphere += 1.5f;
    angleCone += 1.0f;
    angleCylinder += 0.8f;
    angleTorus += 0.5f;

    if (angleCube > 360)
        angleCube -= 360;
    if (angleSphere > 360)
        angleSphere -= 360;
    if (angleCone > 360)
        angleCone -= 360;
    if (angleCylinder > 360)
        angleCylinder -= 360;
    if (angleTorus > 360)
        angleTorus -= 360;

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Objects");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(25, update, 0);

    glutMainLoop();

    return 0;
}

/*
-lopengl32
-lfreeglut
-lglu32
*/
