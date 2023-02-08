#include <GL/glut.h>
#include <GL/GLU.h>
#include <GLFW/glfw3.h>

typedef float color[3];

void ChangeSize(GLsizei width, GLsizei height) {
    glViewport(0, 0, width, height);
    float aspect = (float)width / (float)height;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 0.1, 500.0);
    //glOrtho(-10.0, 10.0, -10.0, 10.0, 1.0, -1.0);
    glMatrixMode(GL_MODELVIEW);
}

void rect(float p1[3], float p2[3], float p3[3], float p4[3], color cor) {
    glColor3fv(cor);
    glBegin(GL_QUADS);
    glVertex3fv(p1);
    glVertex3fv(p2);
    glVertex3fv(p3);
    glVertex3fv(p4);
    glEnd();
    glFlush();
}

void desenhaCubo(float s) {
    float d = s / 2.0;
    float v1[3] = { -d, d, d };
    float v2[3] = { -d, -d, d };
    float v3[3] = { d, -d, d };
    float v4[3] = { d, d, d };
    float v5[3] = { d, d, -d };
    float v6[3] = { d, -d, -d };
    float v7[3] = { -d, -d, -d };
    float v8[3] = { -d, d, -d };

    //frente
    color c1 = { 0.35, 0.72, 1.0 };
    rect(v1, v2, v3, v4, c1);

    //direita
    color c2 = { 0.72, 0.35, 1.0 };
    rect(v4, v3, v6, v5, c2);

    //back
    color c3 = { 0.37, 1.0, 0.35 };
    rect(v5, v8, v7, v6, c3);

    //esquerda
    color c4 = { 1.0, 0.35, 0.85 };
    rect(v1, v8, v7, v2, c4);

    //topo
    color c5 = { 0.35, 1.0, 0.87 };
    rect(v1, v4, v5, v8, c5);

    //bottom
    color c6 = { 1.0, 0.69, 0.35 };
    rect(v2, v7, v6, v3, c6);
}

void RenderScene() {
    glLoadIdentity();
    glTranslated(0.0, 0.0, -50.0);
    //glRotated(30.0, 1.0, 1.0, 0.0);
    desenhaCubo(10);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Linhas");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_ALWAYS);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(RenderScene);
    //glfwSwapBuffers(window);
    glutMainLoop();
    return 0;
}
