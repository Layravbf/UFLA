#include <GL/glut.h>
#include <math.h>
#include <iostream>

void drawCircle(GLfloat x, GLfloat y) {
    GLfloat radius = 0.01;
    GLfloat twicePi = 2.0f * 3.14;
    int lineAmount = 100;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= lineAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / lineAmount)),
            y + (radius * sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        std::cout << x;
        std::cout << "/n";
        std::cout << y;
        
    }
}

void mobilia(GLfloat p1, GLfloat p2, GLfloat p3, GLfloat p4) {
    glBegin(GL_LINE_LOOP);
    glVertex2f(p1, p2);
    glVertex2f(p1, p3);
    glVertex2f(p4, p3);
    glVertex2f(p4, p2);
    glEnd();
}

void RenderScene(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(1.2f, 0.5f, 0.0f);
    glEnd();

    glMatrixMode(GL_MODELVIEW);

    mobilia(-0.9, 0.0, 0.9, 0.9);

    //glBegin(GL_LINE_LOOP); //retangulo do quarto
    //glVertex2f(-0.9f, 0.0f);
    //glVertex2f(-0.9f, 0.9f);
    //glVertex2f(0.9f, 0.9f);
    //glVertex2f(0.9f, 0.0f);
    //glEnd();

    mobilia(0.05, 0.0, 0.5, 0.25);

    //glBegin(GL_LINE_LOOP); //armário
    //glVertex2f(0.05f, 0.0f);
    //glVertex2f(0.05f, 0.5f);
    //glVertex2f(0.25f, 0.5f);
    //glVertex2f(0.25f, 0.0f);
    //glEnd();

    mobilia(0.06, 0.02, 0.48, 0.14);

    //glBegin(GL_LINE_LOOP); //armário (porta esquerda)
    //glVertex2f(0.06f, 0.02f);
    //glVertex2f(0.06f, 0.48f);
    //glVertex2f(0.14f, 0.48f);
    //glVertex2f(0.14, 0.02f);
    //glEnd();

    mobilia(0.16, 0.02, 0.48, 0.24);

    //glBegin(GL_LINE_LOOP); //armário (porta direita)
    //
    //glVertex2f(0.16f, 0.02f);
    //glVertex2f(0.16f, 0.48f);
    //glVertex2f(0.24f, 0.48f);
    //glVertex2f(0.24f, 0.02f);
    //glEnd();

    mobilia(0.3, 0.0, 0.43, 0.42);

    //glBegin(GL_LINE_LOOP); //porta
    //glVertex2f(0.3f, 0.0f);
    //glVertex2f(0.3f, 0.43f);
    //glVertex2f(0.42f, 0.43f);
    //glVertex2f(0.42f, 0.0f);
    //glEnd();

    drawCircle(0.40, 0.25); // maçaneta

    mobilia(0.6, 0.5, 0.7, 0.85);

    //glBegin(GL_LINE_LOOP); //janela
    //glVertex2f(0.6f, 0.5f);
    //glVertex2f(0.6f, 0.7f);
    //glVertex2f(0.85f, 0.7f);
    //glVertex2f(0.85f, 0.5f);
    //glEnd();

    mobilia(0.62, 0.52, 0.68, 0.83);

    //glBegin(GL_LINE_LOOP); //janela
    //glVertex2f(0.62f, 0.52f);
    //glVertex2f(0.62f, 0.68f);
    //glVertex2f(0.83f, 0.68f);
    //glVertex2f(0.83f, 0.52f);
    //glEnd();

    mobilia(0.7, 0.54, 0.55, 0.75);

    //glBegin(GL_LINE_LOOP); //tranca da janela
    //glVertex2f(0.70f, 0.54f);
    //glVertex2f(0.70f, 0.55f);
    //glVertex2f(0.75f, 0.55f);
    //glVertex2f(0.75f, 0.54f);
    //glEnd();

    mobilia(-0.85, 0.0, 0.25, -0.80);

    //glBegin(GL_LINE_LOOP); //cama (cabeceira)
    //glVertex2f(-0.85f, 0.0f);
    //glVertex2f(-0.85f, 0.25f);
    //glVertex2f(-0.80f, 0.25f);
    //glVertex2f(-0.80f, 0.0f);
    //glEnd();

    mobilia(-0.8, 0.15,0.05, -0.40);

    //glBegin(GL_LINE_LOOP); //cama (colchão)
    //glVertex2f(-0.80f, 0.15f);
    //glVertex2f(-0.40f, 0.15f);
    //glVertex2f(-0.40f, 0.05f);
    //glVertex2f(-0.80f, 0.05f);
    //glEnd();

    mobilia(-0.4, 0.0, 0.2, -0.35);

    //glBegin(GL_LINE_LOOP); //cama pé
    //glVertex2f(-0.40f, 0.0f);
    //glVertex2f(-0.40f, 0.20f);
    //glVertex2f(-0.35f, 0.20f);
    //glVertex2f(-0.35f, 0.0f);
    //glEnd();

    mobilia(-0.3, 0.0, 0.2, -0.15);

    //glBegin(GL_LINE_LOOP); //cômoda
    //glVertex2f(-0.30f, 0.0f);
    //glVertex2f(-0.30f, 0.20f);
    //glVertex2f(-0.15f, 0.20f);
    //glVertex2f(-0.15f, 0.0f);
    //glEnd();

    mobilia(-0.28, 0.02, 0.08, -0.17);

    //glBegin(GL_LINE_LOOP); //cômoda gaveta1
    //glVertex2f(-0.28f, 0.02f);
    //glVertex2f(-0.28f, 0.08f);
    //glVertex2f(-0.17f, 0.08f);
    //glVertex2f(-0.17f, 0.02f);
    //glEnd();

    mobilia(-0.28, 0.1, 0.16, -0.17);

    //glBegin(GL_LINE_LOOP); //cômoda gaveta2
    //glVertex2f(-0.28f, 0.1f);
    //glVertex2f(-0.28f, 0.16f);
    //glVertex2f(-0.17f, 0.16f);
    //glVertex2f(-0.17f, 0.1f);
    //glEnd();

    drawCircle(-0.225, 0.13); //puxadores gavetas
    drawCircle(-0.225, 0.05); //puxadores gavetas

    mobilia(-0.8, 0.5, 0.52, -0.40);

    //glBegin(GL_LINE_LOOP); //prateleira 
    //glVertex2f(-0.80f, 0.5f);
    //glVertex2f(-0.80f, 0.52f);
    //glVertex2f(-0.40f, 0.52f);
    //glVertex2f(-0.40f, 0.5f);
    //glEnd();

    mobilia(-0.8, 0.5, 0.52, -0.40);

    //glBegin(GL_LINE_LOOP); //prateleira 
    //glVertex2f(-0.80f, 0.5f);
    //glVertex2f(-0.80f, 0.52f);
    //glVertex2f(-0.40f, 0.52f);
    //glVertex2f(-0.40f, 0.5f);
    //glEnd();
    
    glPushMatrix();
    glTranslatef(0.78f, -0.52, 0.0);
    glRotatef(27.5, -2, 0, 0);
    glTranslatef(-0.78f, 0.52, 0.0);

    mobilia(-0.78, 0.52, 0.58, -0.76);

    //glBegin(GL_LINE_LOOP); //prateleira - livro1
    //glVertex2f(-0.78f, 0.52f);
    //glVertex2f(-0.78f, 0.58f);
    //glVertex2f(-0.76f, 0.58f);
    //glVertex2f(-0.76f, 0.52f);
    //glEnd();

    glPopMatrix();

    mobilia(-0.76, 0.52, 0.60, -0.74);

    //glBegin(GL_LINE_LOOP); //prateleira - livro2
    //glVertex2f(-0.76f, 0.52f);
    //glVertex2f(-0.76f, 0.60f);
    //glVertex2f(-0.74f, 0.60f);
    //glVertex2f(-0.74f, 0.52f);
    //glEnd();

    glPushMatrix();
    glScalef(2, 1, 0);
    glColor3f(1.0f, 0.7f, 0.5f);

    mobilia(-0.002, 0.9, 0.8, 0.01);

    //glBegin(GL_LINE_LOOP); //luz
    //glVertex2f(-0.002f, 0.9f);
    //glVertex2f(-0.002f, 0.80f);
    //glVertex2f(0.01f, 0.80);
    //glVertex2f(0.01f, 0.9f);
    //glEnd();

    //mobilia(-0.002, 0.8, 0.75, 0.028);

    glBegin(GL_LINE_LOOP); //luz
    glVertex2f(-0.002f, 0.80f);
    glVertex2f(-0.02f, 0.75f);
    glVertex2f(0.028f, 0.75f);
    glVertex2f(0.01f, 0.80f);
    glEnd();
    glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("OpenGL - Quarto");
    glutMouseFunc(mouse);
    glutDisplayFunc(RenderScene);
    glutMainLoop();
    return 0;
}
