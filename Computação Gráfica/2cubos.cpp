#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* display() draws 5 spheres at different z positions.
 */
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(1, 0, 0.2);
    glTranslatef(0.15, 0.15, -7.4);
    glRotatef(15.0, 1.0, 1.0, 0.0);
    glRotatef(30.0, 0.0, 1.0, 0.0);
    glutSolidCube(0.6);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0.8, 0.2);
    glTranslatef(0.25, -0.15, -8.0);
    glRotatef(15.0, 1.0, 1.0, 0.0);
    glRotatef(30.0, 0.0, 1.0, 0.0);
    glutSolidCube(0.6);
    glPopMatrix();

    glFlush();


}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w,
            2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-2.5 * (GLfloat)w / (GLfloat)h,
            2.5 * (GLfloat)w / (GLfloat)h, -2.5, 2.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow(argv[0]);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}