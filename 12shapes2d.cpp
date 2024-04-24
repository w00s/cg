#include <GL/glut.h>
#include <cmath>

void drawTriangle()
{
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.25f, -0.5f);
    glVertex2f(0.25f, -0.5f);
    glEnd();
}

void drawSquare()
{
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(-0.5f, -0.5f);
    glEnd();
}

void drawPentagon()
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < 5; ++i)
    {
        float angle = 2.0f * M_PI * i / 5;
        glVertex2f(0.4f * cos(angle), 0.4f * sin(angle));
    }
    glEnd();
}

void drawHexagon()
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; ++i)
    {
        float angle = 2.0f * M_PI * i / 6;
        glVertex2f(0.4f * cos(angle), 0.4f * sin(angle));
    }
    glEnd();
}

void drawCircle()
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; ++i)
    {
        float angle = 2.0f * M_PI * i / 360;
        glVertex2f(0.4f * cos(angle), 0.4f * sin(angle));
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color

    glPushMatrix();
    glTranslatef(-0.5f, 0.5f, 0.0f);
    drawTriangle();
    glPopMatrix();

    glColor3f(0.0f, 1.0f, 0.0f);

    glPushMatrix();
    glTranslatef(0.5f, 0.5f, 0.0f);
    drawSquare();
    glPopMatrix();

    glColor3f(0.0f, 0.0f, 1.0f);

    glPushMatrix();
    glTranslatef(-0.8f, -0.5f, 0.0f);
    drawPentagon();
    glPopMatrix();

    glColor3f(1.0f, 0.5f, 0.5f);

    glPushMatrix();
    glTranslatef(0.8f, -0.5f, 0.0f);
    drawHexagon();
    glPopMatrix();

    glColor3f(0.5f, 0.5f, 1.0f);

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    drawCircle();
    glPopMatrix();

    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.5, 1.5); // 2D orthogonal projection
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Shapes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
