/* camera.cpp
*
*  abril, 2002 - Luciana Nedel
*  adaptado por Carla Freitas
*  adaptado por Bruno Schneider em marco de 2012
*  modificado por Bruno Schneider em outubro de 2016
*  modificado por Layra Vilas Boas Ferreira em junho de 2022
*
*  Exemplo para manipulacao de camera em OpenGL
*/

#include <cmath>
#include <iostream>
#include <GL/glut.h>

using namespace std;

bool perspectiva = true;
typedef float color[3];

// estrutura que representa uma camera
typedef struct {
    GLdouble atx;
    GLdouble aty;
    GLdouble atz;
    GLdouble tox;
    GLdouble toy;
    GLdouble toz;
} Observador;

Observador camera;

// Parametros de projecao
GLfloat fAspect;
GLfloat angle = 100;    // angulo de abertura para proj. perspectiva

// limites do volume ortografico (projecao paralela)
GLdouble minX = -100.00;
GLdouble maxX = 100.00;
GLdouble minY = -100.00;
GLdouble maxY = 100.00;
GLint incremento = 0;

// planos near e far para recorte em profundidade
GLdouble near_plane = 2.0;
GLdouble far_plane = 240.0;

void ImprimirCamera() {
    cout << "eye: (" << camera.atx << "," << camera.aty << "," << camera.atz
        << ") foco: (" << camera.tox << "," << camera.toy << ","
        << camera.toz << ")" << endl;
}

/* Funcao usada para especificar o volume de visualizacao
*  no caso de projecao perspectiva.
*/
void ComputarProjecaoPerspectiva() {
    // Especifica manipulacao da matriz de projecao
    glMatrixMode(GL_PROJECTION);
    // Inicializa matriz com a identidade
    glLoadIdentity();

    // Especifica a projecao perspectiva
    gluPerspective(angle, fAspect, near_plane, far_plane);

    // Especifica sistema de coordenadas do modelo
    glMatrixMode(GL_MODELVIEW);
    // Inicializa matriz modelview com a identidade
    glLoadIdentity();
    // Especifica posicao do observador e do alvo
    gluLookAt(camera.atx, camera.aty, camera.atz, camera.tox, camera.toy, camera.toz, 0, 1, 0);
}

/* Funcao usada para especificar o volume de visualizacao
*  no caso de projecao paralela.
*/
void ComputarProjecaoParalela()
{
    // Especifica sistema de coordenadas do modelo
    glMatrixMode(GL_MODELVIEW);
    // Inicializa matriz modelview com a identidade
    glLoadIdentity();
    // Especifica posicao do observador e do alvo
    gluLookAt(camera.atx, camera.aty, camera.atz, camera.tox, camera.toy, camera.toz, 0, 1, 0);

    // Especifica manipulacao da matriz de projecao
    glMatrixMode(GL_PROJECTION);
    // Inicializa matriz com a identidade
    glLoadIdentity();

    // Especifica a projecao ortografica
    glOrtho(minX - incremento,
        maxX + incremento,
        minY - incremento,
        maxY + incremento,
        near_plane, far_plane);

    glMatrixMode(GL_MODELVIEW);
}

void ComputarProjecao() {
    if (perspectiva) {                 // chamada para atualizar o volume de visualizacao
        ComputarProjecaoPerspectiva(); // no caso de perspectiva
    }
    else {                          // chamada para atualizar o volume de visualizacao
        ComputarProjecaoParalela(); // no caso de projeção ortográfica
    }
}

void InicializarCamera() {
    camera.atx = 0.0;
    camera.aty = 15.0;
    camera.atz = -100.0;

    camera.tox = 0.0;   // olhando para o ponto central da pirâmide
    camera.toy = 15.0;
    camera.toz = 0.0;
    ComputarProjecao();
}

// Inicialização
void SetupRC(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    // Limpa a janela e habilita o teste para eliminar faces posteriores
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    // habilita o uso de uma cor por face
    glShadeModel(GL_FLAT);
    InicializarCamera();
}

// Chamada pela GLUT quando a janela e' redimensionada.
void ChangeSize(GLsizei w, GLsizei h) {
    // Para prevenir uma divisão por zero
    if (h == 0)
        h = 1;

    // Especifica o tamanho da viewport
    glViewport(0, 0, w, h);

    // Calcula a correção de aspecto
    fAspect = (GLfloat)w / (GLfloat)h;

    ComputarProjecao();
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

// Minha função de desenho
void RenderScene() {
    // Limpa a janela
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float d = 10 / 2.0;
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
    color c2 = { 1.0, 0.49, 0.49 };
    rect(v4, v3, v6, v5, c2);

    //back
    color c3 = { 0.37, 1.0, 0.35 };
    rect(v5, v8, v7, v6, c3);

    //esquerda
    color c4 = { 0.89, 0.58, 0.94 };
    rect(v1, v8, v7, v2, c4);

    //topo
    color c5 = { 0.93, 0.94, 0.58 };
    rect(v1, v4, v5, v8, c5);

    //bottom
    color c6 = { 1.0, 0.69, 0.35 };
    rect(v2, v7, v6, v3, c6);
}

/* Minha Callback para gerenciar eventos do mouse
 * Devolve o botão pressionado, o estado do botão e
 * posição do cursor, relativa à janela.
*/
// A especificação da GLUT traz os demais detalhes desse tratamento

void HandleMouse(int button, int state, int x, int y) {
    // o botão esquerdo diminui o angulo (perspectiva)
    // ou a largura do volume ortográfico
    if (button == GLUT_LEFT_BUTTON)
        if (state == GLUT_DOWN) {
            // Zoom-in
            if (perspectiva) {
                if (angle >= 10)
                    angle -= 5;
            }
            else {
                incremento -= 10; // veja o que acontece se fica negativo!!
            }
        }
    // o botão direito aumenta o angulo (perspectiva)
    // ou a largura do volume ortográfico
    if (button == GLUT_RIGHT_BUTTON)
        if (state == GLUT_DOWN) {
            // Zoom out
            if (perspectiva) {
                if (angle <= 130)
                    angle += 5;
            }
            else {
                incremento += 10;
            }
        }
    if (perspectiva)
        ComputarProjecaoPerspectiva();
    else
        ComputarProjecaoParalela();
    glutPostRedisplay();
}

// Girar a camera em torno do seu eixo vertical.
void GirarCamera(GLdouble radianos) {
    camera.atx += radianos;
    camera.toz += radianos;
    ComputarProjecao();
}

void TransladarCamera(GLdouble distancia) {
    GLdouble direcao[3];
    GLdouble norma;

    direcao[0] = camera.tox - camera.atx;
    direcao[1] = camera.toy - camera.aty;
    direcao[2] = camera.toz - camera.atz;
    norma = sqrt(direcao[0] * direcao[0] + direcao[1] * direcao[1] + direcao[2] * direcao[2]);
    direcao[0] /= norma;
    direcao[1] /= norma;
    direcao[2] /= norma;
    camera.atx += direcao[0] * distancia;
    camera.aty += direcao[1] * distancia;
    camera.atz += direcao[2] * distancia;
    camera.tox += direcao[0] * distancia;
    camera.toy += direcao[1] * distancia;
    camera.toz += direcao[2] * distancia;
    ComputarProjecao();
}

void CallbackTeclado(unsigned char key, int x, int y) {
    switch (key)
    {
    case 'a':
        GirarCamera(0.5);
        break;
    case 'd':
        GirarCamera(-0.5);
        break;
    case 'w':
        TransladarCamera(0.5);
        break;
    case 's':
        TransladarCamera(-0.5);
        break;
    case 'i':
        ImprimirCamera();
        break;
    case 'p': // trocar tipo de projecao
        perspectiva = !perspectiva;
        if (perspectiva)
            cout << "Usando projecao perspectiva.\n";
        else
            cout << "Usando projecao paralela.\n";
        ComputarProjecao();
        break;
    case 27: // tecla ESCAPE
        exit(0);
    default:
        // Nao redesenhar a tela
        return;
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[]) {
    // Procedimento de inicializacao da GLUT
    glutInit(&argc, argv);
    cout << "Coloque a mao esquerda nas teclas asdw.\n";
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 350);
    glutCreateWindow("Controle da Camera");
    glutKeyboardFunc(CallbackTeclado);
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutMouseFunc(HandleMouse);
    SetupRC();
    cout << "Comandos do teclado:\n"
        << "a: girar para esquerda\n"
        << "d: girar para direita\n"
        << "w: andar para frente\n"
        << "s: andar para tras\n"
        << "i: voltar para posicao inicial\n"
        << "p: trocar o tipo de projecao (paralela/perspectiva)\n"
        << "ESC: terminar a execucao\n";
    glutMainLoop();
    return 0;
}

