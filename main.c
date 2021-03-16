#include <stdio.h>
#include "raizes.h"

int main() {
    float a = 2.0;
    float b = 3.0;
    float e = 0.0001;

    float raiz_bissecao = bisseccao(a, b, e);
    float raiz_posicao_falsa = posicao_falsa(a, b, e);

    printf("por bisseccao, %.10f e zero da funcao no intervalo [%.2f, %.2f] com precisao %.4f\n", raiz_bissecao, a, b, e);
    printf("por posicao falsa, %.10f e zero da funcao no intervalo [%.2f, %.2f] com precisao %.4f\n", raiz_posicao_falsa, a, b, e);
    
    return 0;
}