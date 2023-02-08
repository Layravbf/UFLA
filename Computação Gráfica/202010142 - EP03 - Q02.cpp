#include <GL/glut.h>
#include<iostream>

void drawDresser() {
    //glBegin(GL_POLYGON);//cômoda
    //glVertex2f(-0.45, 0.75);
    //glVertex2f(-0.45, 0.55);
    //glVertex2f(-0.20, 0.55);
    //glVertex2f(-0.20, 0.75);
    //glEnd();

    //drawCircle(-0.325, 0.55, 0.02);
}

GLfloat m = 0.0;             // slope
GLfloat c = (-0 - m * -1);     // constant
GLfloat j = -0;



void desenha() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

                 // starting y value

    // check division by 0
    if (1 - -1 == 0)
        m = 0;
    else
        m = (-0.5 - -0) / (1 - -1);

    glColor3f(1, 0, 0);
    glPointSize(5);
    glBegin(GL_POINTS);
    for (double i = -1; i < 1; i += 0.0001) {
        j = m * i + c;        // result of y from line function
        glVertex2f(i, j);
    }
    glEnd();

    //glPushMatrix();
    //
    //glBegin(GL_POINTS);
    //glVertex2f(2, 7);
    //glVertex2f(9, 7);
    //glEnd();
    //glPopMatrix();

    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w,
            1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-1.5 * (GLfloat)w / (GLfloat)h,
            1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(50, 50);
    glutReshapeFunc(reshape);
    glutCreateWindow("Pontos");
    glutDisplayFunc(desenha);
    glutMainLoop();
    return 0;
}
