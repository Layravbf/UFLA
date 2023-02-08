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
    glBegin(GL_POLYGON);//cômoda
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
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, -0.60);
    glVertex2f(0.25, -0.60);
    glVertex2f(0.25, 0.0);
    glEnd();

    glBegin(GL_POLYGON);//travesseiro
    glVertex2f(0.03, -0.03);
    glVertex2f(0.03, -0.22);
    glVertex2f(0.22, -0.22);
    glVertex2f(0.22, -0.03);
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

void display() {
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
    glTranslatef(t1, 0, 0);
    glTranslatef(0, up1, 0);
    glTranslatef(-0.75, 0.75, 0);
    glRotatef(r1, 0, 0, 1);
    glScalef(s1, s1, 0);
    glLineWidth((GLfloat)1.5);
    glColor3f(0.4, 0.2, 0.2);
    drawBed();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(t2, 0, 0);
    glTranslatef(0, up2, 0);
    glRotatef(r2, 0, 0, 1);
    glScalef(s2, s2, 0);
    glColor3f(0.4, 0.2, 0.2);
    drawDresser();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(t3, 0, 0);
    glTranslatef(0, up3, 0);
    glRotatef(r3, 0, 0, 1);
    glScalef(s3, s3, 0);
    glColor3f(0.4, 0.2, 0.2);
    drawTable();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(t4, 0, 0);
    glTranslatef(0, up4, 0);
    glRotatef(r4, 0, 0, 1);
    glScalef(s4, s4, 0);
    glColor3f(0.4, 0.2, 0.2);
    drawChair();
    glPopMatrix();

    glFlush();
}

void myMouse(int button, int state, int x, int y) {
    if (rotate == '1') {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) r1 -= 5;
        else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) r1 += 5;
    }
    else if (rotate == '2') {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) r2 -= 5;
        else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) r2 += 5;
    }
    else if (rotate == '3') {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) r3 -= 5;
        else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) r3 += 5;
    }
    else if (rotate == '4') {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) r4 -= 5;
        else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) r4 += 5;
    }
}

void myKeyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
        translate = '1';
        rotate = '1';
        scale = '1';
        break;
    case '2':
        translate = '2';
        rotate = '2';
        scale = '2';
        break;
    case '3':
        translate = '3';
        rotate = '3';
        scale = '3';
        break;
    case '4':
        translate = '4';
        rotate = '4';
        scale = '4';
        break;
    default:
        break;
    }

    if (translate == '1') {
        if (key == 'd') t1 += 0.05;
        else if (key == 'a') t1 -= 0.05;
        else if (key == 'w') up1 += 0.05;
        else if (key == 's') up1 -= 0.05;
    }
    else if (translate == '2') {
        if (key == 'd') t2 += 0.05;
        else if (key == 'a') t2 -= 0.05;
        else if (key == 'w') up2 += 0.05;
        else if (key == 's') up2 -= 0.05;
    }
    else if (translate == '3') {
        if (key == 'd') t3 += 0.05;
        else if (key == 'a') t3 -= 0.05;
        else if (key == 'w') up3 += 0.05;
        else if (key == 's') up3 -= 0.05;
    }
    else if (translate == '4') {
        if (key == 'd') t4 += 0.05;
        else if (key == 'a') t4 -= 0.05;
        else if (key == 'w') up4 += 0.05;
        else if (key == 's') up4 -= 0.05;
    }

    if (scale == '1') {
        if (key == '=') s1 += 0.09;
        else if (key == '-') s1 -= 0.09;
    }
    else if (scale == '2') {
        if (key == '=') s2 += 0.09;
        else if (key == '-') s2 -= 0.09;
    }
    else if (scale == '3') {
        if (key == '=') s3 += 0.09;
        else if (key == '-') s3 -= 0.09;
    }
    else if (scale == '4') {
        if (key == '=') s4 += 0.09;
        else if (key == '-') s4 -= 0.09;
    }


    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Quarto");
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(myMouse);
    glutMainLoop();
    return 0;
}
