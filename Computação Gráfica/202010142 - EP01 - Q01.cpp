#include <GL/glut.h>
#include<iostream>

#define PI 3.1415926535897932384626433832795

char translate, rotate, scale;
float t1 = 0.0, t2 = 0.0, t3 = 0.0, t4 = 0.0;
float r1 = 0.0, r2 = 0.0, r3 = 0.0, r4 = 0.0;
float up1 = 0.0, up2 = 0.0, up3 = 0.0, up4 = 0.0;
float s1 = 1.0, s2 = 1.0, s3 = 1.0, s4 = 1.0;

void base(GLfloat p1, GLfloat p2, GLfloat p3, GLfloat p4) {
    glBegin(GL_LINE_LOOP);
    glVertex2f(p1, p2);
    glVertex2f(p1, p3);
    glVertex2f(p4, p3);
    glVertex2f(p4, p2);
    glEnd();
}

void drawCircle(GLfloat x, GLfloat y, GLfloat radius) {
    GLfloat twicePi = 2.0f * PI;
    int lineAmount = 300;
    glBegin(GL_POLYGON);
    for (int i = 0; i <= lineAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / lineAmount)),
            y + (radius * sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
}

void drawDresser() {
    glBegin(GL_POLYGON);//c�moda
    glVertex2f(-0.45, 0.75);
    glVertex2f(-0.45, 0.55);
    glVertex2f(-0.20, 0.55);
    glVertex2f(-0.20, 0.75);
    glEnd();

    drawCircle(-0.325, 0.55, 0.02);
}

void drawTable() {
    glBegin(GL_POLYGON);//mesa
    glVertex2f(0.60, -0.15);
    glVertex2f(0.60, -0.75);
    glVertex2f(0.80, -0.75);
    glVertex2f(0.80, -0.15);
    glEnd();
}

void drawBed() {
    glBegin(GL_LINE_LOOP);//cama
    glVertex2f(-0.75, 0.75);
    glVertex2f(-0.75, 0.15);
    glVertex2f(-0.50, 0.15);
    glVertex2f(-0.50, 0.75);
    glEnd();

    glBegin(GL_POLYGON);//travesseiro
    glVertex2f(-0.72, 0.72);
    glVertex2f(-0.72, 0.52);
    glVertex2f(-0.53, 0.52);
    glVertex2f(-0.53, 0.72);
    glEnd();
}

void drawChair() {
    glBegin(GL_LINE_LOOP);//cadeira
    glVertex2f(0.40, -0.30);
    glVertex2f(0.40, -0.60);
    glVertex2f(0.55, -0.60);
    glVertex2f(0.55, -0.30);
    glEnd();

    glBegin(GL_LINE_LOOP);//cadeira
    glVertex2f(0.45, -0.35);
    glVertex2f(0.45, -0.55);
    glVertex2f(0.55, -0.55);
    glVertex2f(0.55, -0.35);
    glEnd();
}

void desenha() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glColor3f(1.0, 0.5, 0.1);
    base(-0.9, -0.9, 0.9, 0.9);//retangulo do quarto
    base(-0.87, -0.85, 0.85, 0.87);//retangulo do quarto
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 0.5, 0.9);
    base(-0.5, -0.9, -0.85, -0.25);//porta
    base(0.87, 0.35, -0.3, 0.9);//janela
    glPopMatrix();

    glPushMatrix();
    glLineWidth((GLfloat)1.5);
    glColor3f(0.4, 0.2, 0.2);
    drawBed();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.4, 0.2, 0.2);
    drawDresser();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.4, 0.2, 0.2);
    drawTable();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.4, 0.2, 0.2);
    drawChair();
    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Quarto");
    glutDisplayFunc(desenha);
    glutMainLoop();
    return 0;
}
