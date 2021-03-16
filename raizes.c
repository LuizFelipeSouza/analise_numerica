#include <stdio.h>
#include <math.h>

float funcao(float x) {
    // return x * log10f(x) - 1;
    return powf(x, 3) - 9*x + 3;
}

float derivada_fx(float x) {
    return pow(3*x, 3) - 9;
}

float bisseccao(float a, float b, float e)  {
    float x, fa, fb, fx;
    int k = 1;

    fa = funcao(a);
    fb = funcao(b);

    if (b - a < e) {
        return b - a;
    }
    else {
        while (b - a >= e) {
            x = (a + b) / 2.0;

            fx = funcao(x);
            fa = funcao(a);
            fb = funcao(b);        

            if (fx * fa < 0) {
                b = x;
            }
            else if (fx * fb < 0) {
                a = x;
            }
            // printf("iteracao %d\n x = %.10f\nf(x) = %.10f\nb - a = %.10f\n\n", k, x, fx, b - a);
            k += 1;
            if (k > 1000) {
                printf("Foram ultrapassadas 1000 iteracoes. O algoritmo foi interrompido!\n");
                break;
            }
        }
        return x;
    }
}

float posicao_falsa(float a, float b, float e) {
    float x, fa, fb, fx;
    int k = 1;

    fa = funcao(a);
    fb = funcao(b);

    if (b - a < e) {
        return b - a;
    }
    else {
        while (b - a >= e) {
            // Operação básica
            x = (a*fb - b*fa) / (fb - fa);

            fx = funcao(x);
            fa = funcao(a);
            fb = funcao(b);        

            if (fx * fa < 0) {
                b = x;
            }
            else if (fx * fb < 0) {
                a = x;
            }
            // printf("iteracao %d\n x = %.10f\nf(x) = %.10f\nb - a = %.10f\n\n", k, x, fx, b - a);
            k += 1;
            if (k > 1000) {
                printf("Foram ultrapassadas 1000 iteracoes. O algoritmo foi interrompido!\n");
                break;
            }
        }
        return x;
    }
}

float ponto_fixo(float x, float e) {
    float fx = funcao(x);
    float x_anterior = 0;

    if (fx < e) {
        return x;
    }
    else {
        while (fx < e || x - x_anterior < e) {
            x_anterior = x;
            x = funcao(x);
        }
        return x;
    }
}

float newton_raphson(float x, float e) {
    float fx = funcao(x);
    float x_anterior = 0;

    if (fx < e) {
        return x;
    }
    else {
        while (fx < e || x - x_anterior < e) {
            x_anterior = x;
            x = x - (funcao(x) / derivada_fx(x));
        }
        return x;
    }
}

float secante(float x, float e) {
    float fx = funcao(x);
    float x_anterior = 0;
    float fxa;
    int k = 0;

    if (fx < e) {
        return x;
    }
    else {
        while (fx < e || x - x_anterior < e) {
            x_anterior = x;
            fx = funcao(x);
            fxa = funcao(x_anterior);

            if (k > 1) {
                x = x - ((fx * (x - x_anterior)) / (fx - fxa));
            }
            k += 1;
        }
        return x;
    }
}