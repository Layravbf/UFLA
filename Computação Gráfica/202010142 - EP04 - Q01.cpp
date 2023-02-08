#include <GL/glut.h>
#include<iostream>

GLfloat m = 0.0;             // slope
GLfloat c = (-0 - m * -1);     // constant
GLfloat j = -0;
GLfloat i = 0;



void desenha() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    // check division by 0
    if (1 - -1 == 0)
        m = 0;
    else
        m = (-0.5 - -0) / (1 - -1);

    glColor3f(1, 0, 0);
    glPointSize(5);
    GLfloat x = 0.0;
   
}

void display() {
    desenha();
    for (i = 0; i < 100; i++) {
        
        glBegin(GL_POINTS);
        c += -0.5;
        for (double i = -1; i < 1; i += 0.001) {
            j = m * i * c;        // result of y from line function
            std::cout << j;
            glVertex2f(i, j);
        }
        glEnd();
        glFlush();
    }
    
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

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'a':
        glutDestroyWindow(glutGetWindow());
        exit(0);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(50, 50);
    glutReshapeFunc(reshape);
    glutCreateWindow("Pontos");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
