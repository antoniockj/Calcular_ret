/*============================================================================*/
/* ICSF13 - 2023-2 - TRABALHO 1                                               */
/*----------------------------------------------------------------------------*/
/* Bogdan T. Nassu                                                            */
/* Leyza E. B. Dorini                                                         */
/* Daniel F. Pigatto                                                          */
/*============================================================================*/
/** Fun��es pedidas e auxiliares para o 1o trabalho da disciplina Fundamentos
 * de Programa��o 1, 2o semestre de 2023, profs. Bogdan T. Nassu, Leyza E. B.
 * Dorini e Daniel F. Pigatto, Universidade Tecnol�gica Federal do Paran�. */
/*============================================================================*/

#include <float.h>
#include <math.h> 
#ifndef __TRABALHO1_H
#define __TRABALHO1_H

/*============================================================================*/
/* Fun��es do trabalho. */
int pegaXSE(int pos);
int pegaYSE(int pos);
int pegaXID(int pos);
int pegaYID(int pos);


int calculaInterseccao(int n_retangulos) {
    // retangulo de referencia
    int xSuperiorEsq = pegaXSE(0);
    int ySuperiorEsq = pegaYSE(0);
    int xInferiorDir = pegaXID(0);
    int yInferiorDir = pegaYID(0);

    for (int i = 1; i < n_retangulos; i++) {
        int x1 = pegaXSE(i);
        int y1 = pegaYSE(i);
        int x2 = pegaXID(i);
        int y2 = pegaYID(i);

        if (x1 > xSuperiorEsq) {
            xSuperiorEsq = x1;
        }
        if (y1 > ySuperiorEsq) {
            ySuperiorEsq = y1;
        }
        if (x2 < xInferiorDir) {
            xInferiorDir = x2;
        }
        if (y2 < yInferiorDir) {
            yInferiorDir = y2;
        }
    }

    // intersecção
    int area_interseccao = 0;
    if (xSuperiorEsq < xInferiorDir && ySuperiorEsq > yInferiorDir) {
        area_interseccao = (xInferiorDir - xSuperiorEsq) * (ySuperiorEsq - yInferiorDir);
    }

    // Verificacao
    if (area_interseccao > 0) {
        return area_interseccao;
    } else {
        return 0;
    }
}
unsigned int encontraParMaisProximo (int n_retangulos){
    
    unsigned int parMaisProximo = 0;  // Inicializa com algum valor (neste caso, 0)

    // Inicializa a menor distância com um valor grande
    float menorDistancia = FLT_MAX;

    for (int i = 0; i < n_retangulos; i++) {
        float xi = (pegaXSE(i) + pegaXID(i)) / 2.0;  // Calcula o centro X do retângulo
        float yi = (pegaYSE(i) + pegaYID(i)) / 2.0;  // Calcula o centro Y do retângulo

        for (int j = i + 1; j < n_retangulos; j++) {
            float xj = (pegaXSE(j) + pegaXID(j)) / 2.0;  // Calcula o centro X do retângulo
            float yj = (pegaYSE(j) + pegaYID(j)) / 2.0;  // Calcula o centro Y do retângulo

            // Calcula a distância entre os centros dos retângulos
            float distancia = sqrt((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj));

            // Se a distância é menor que a menor distância registrada até agora, atualize
            if (distancia < menorDistancia) {
                menorDistancia = distancia;

                // Atualize o par mais próximo (usando bits do valor de retorno)
                parMaisProximo = ((unsigned int)i << 16) | (unsigned int)j;
            }
        }
    }

    return parMaisProximo;
}


/*---------------------------
-------------------------------------------------*/
/* Fun��es auxiliares que DEVEM ser chamadas pelos alunos. */

int pegaXSE (int pos);
int pegaYSE (int pos);
int pegaXID (int pos);
int pegaYID (int pos);

/*----------------------------------------------------------------------------*/
/* Fun��es auxiliares que N�O DEVEM ser chamadas pelos alunos. */

void criaVetorRetangulos (int tamanho);
void destroiVetorRetangulos ();
void adicionaRetangulo (int pos, int tlx, int tly, int brx, int bry);
void mostraRetangulos (int n);

/*============================================================================*/
#endif /* __TRABALHO1_H */

