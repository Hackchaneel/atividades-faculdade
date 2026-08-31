/* ============================================================
 * Calculadora em C
 * Disciplina: Desenvolvimento de Algoritmos e Pensamento Computacional
 * Autor: Davi Carvalho Macedo
 * ------------------------------------------------------------
 * Calculadora de menu com 24 operações matemáticas, cada uma
 * implementada em sua própria função, com tratamento básico
 * de erros (divisão por zero, domínio inválido, opção inválida).
 * ============================================================ */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

/* ---------------------- Protótipos das funções ---------------------- */
double somar(double a, double b);
double subtrair(double a, double b);
double multiplicar(double a, double b);
int dividir(double a, double b, double *resultado);
double potencia(double base, double expoente);
int raiz_quadrada(double x, double *resultado);
double raiz_cubica(double x);
double seno(double graus);
double cosseno(double graus);
int tangente(double graus, double *resultado);
int logaritmo_natural(double x, double *resultado);
int logaritmo_base10(double x, double *resultado);
double valor_absoluto(double x);
double porcentagem(double valor, double percentual);
double media_aritmetica(double a, double b, double c);
double graus_para_radianos(double graus);
double radianos_para_graus(double rad);
double area_circulo(double raio);
double area_retangulo(double base, double altura);
double area_triangulo(double base, double altura);
int hipotenusa(double cateto1, double cateto2, double *resultado);
double volume_esfera(double raio);
unsigned long fatorial(int n);
int mdc(int a, int b);
int mmc(int a, int b);

void exibirMenu(void);
void limparBufferEntrada(void);

/* ---------------------------- main() ---------------------------- */
int main(void) {
    int opcao;
    double a, b, c, resultado;
    int i1, i2;
    int continuar = 1;

    printf("=====================================\n");
    printf("      CALCULADORA CIENTIFICA EM C     \n");
    printf("=====================================\n");

    while (continuar) {
        exibirMenu();
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\n[ERRO] Entrada invalida. Digite um numero.\n\n");
            limparBufferEntrada();
            continue;
        }

        switch (opcao) {
            case 1: /* Soma */
                printf("Digite dois numeros: ");
                scanf("%lf %lf", &a, &b);
                printf("Resultado: %.4f\n", somar(a, b));
                break;

            case 2: /* Subtracao */
                printf("Digite dois numeros: ");
                scanf("%lf %lf", &a, &b);
                printf("Resultado: %.4f\n", subtrair(a, b));
                break;

            case 3: /* Multiplicacao */
                printf("Digite dois numeros: ");
                scanf("%lf %lf", &a, &b);
                printf("Resultado: %.4f\n", multiplicar(a, b));
                break;

            case 4: /* Divisao */
                printf("Digite dividendo e divisor: ");
                scanf("%lf %lf", &a, &b);
                if (dividir(a, b, &resultado))
                    printf("Resultado: %.4f\n", resultado);
                else
                    printf("[ERRO] Divisao por zero nao permitida.\n");
                break;

            case 5: /* Potenciacao */
                printf("Digite base e expoente: ");
                scanf("%lf %lf", &a, &b);
                printf("Resultado: %.4f\n", potencia(a, b));
                break;

            case 6: /* Raiz quadrada */
                printf("Digite um numero: ");
                scanf("%lf", &a);
                if (raiz_quadrada(a, &resultado))
                    printf("Resultado: %.4f\n", resultado);
                else
                    printf("[ERRO] Nao existe raiz quadrada real de numero negativo.\n");
                break;

            case 7: /* Raiz cubica */
                printf("Digite um numero: ");
                scanf("%lf", &a);
                printf("Resultado: %.4f\n", raiz_cubica(a));
                break;

            case 8: /* Seno */
                printf("Digite o angulo em graus: ");
                scanf("%lf", &a);
                printf("Resultado: %.4f\n", seno(a));
                break;

            case 9: /* Cosseno */
                printf("Digite o angulo em graus: ");
                scanf("%lf", &a);
                printf("Resultado: %.4f\n", cosseno(a));
                break;

            case 10: /* Tangente */
                printf("Digite o angulo em graus: ");
                scanf("%lf", &a);
                if (tangente(a, &resultado))
                    printf("Resultado: %.4f\n", resultado);
                else
                    printf("[ERRO] Tangente indefinida para esse angulo (90 + k*180).\n");
                break;

            case 11: /* Logaritmo natural */
                printf("Digite um numero: ");
                scanf("%lf", &a);
                if (logaritmo_natural(a, &resultado))
                    printf("Resultado: %.4f\n", resultado);
                else
                    printf("[ERRO] Logaritmo definido apenas para numeros positivos.\n");
                break;

            case 12: /* Logaritmo base 10 */
                printf("Digite um numero: ");
                scanf("%lf", &a);
                if (logaritmo_base10(a, &resultado))
                    printf("Resultado: %.4f\n", resultado);
                else
                    printf("[ERRO] Logaritmo definido apenas para numeros positivos.\n");
                break;

            case 13: /* Valor absoluto */
                printf("Digite um numero: ");
                scanf("%lf", &a);
                printf("Resultado: %.4f\n", valor_absoluto(a));
                break;

            case 14: /* Porcentagem */
                printf("Digite o valor e o percentual desejado: ");
                scanf("%lf %lf", &a, &b);
                printf("Resultado: %.4f\n", porcentagem(a, b));
                break;

            case 15: /* Media aritmetica */
                printf("Digite tres numeros: ");
                scanf("%lf %lf %lf", &a, &b, &c);
                printf("Resultado: %.4f\n", media_aritmetica(a, b, c));
                break;

            case 16: /* Graus para radianos */
                printf("Digite o valor em graus: ");
                scanf("%lf", &a);
                printf("Resultado: %.4f rad\n", graus_para_radianos(a));
                break;

            case 17: /* Radianos para graus */
                printf("Digite o valor em radianos: ");
                scanf("%lf", &a);
                printf("Resultado: %.4f graus\n", radianos_para_graus(a));
                break;

            case 18: /* Area do circulo */
                printf("Digite o raio: ");
                scanf("%lf", &a);
                if (a < 0) {
                    printf("[ERRO] O raio nao pode ser negativo.\n");
                } else {
                    printf("Resultado: %.4f\n", area_circulo(a));
                }
                break;

            case 19: /* Area do retangulo */
                printf("Digite base e altura: ");
                scanf("%lf %lf", &a, &b);
                if (a < 0 || b < 0) {
                    printf("[ERRO] Base e altura devem ser nao negativas.\n");
                } else {
                    printf("Resultado: %.4f\n", area_retangulo(a, b));
                }
                break;

            case 20: /* Area do triangulo */
                printf("Digite base e altura: ");
                scanf("%lf %lf", &a, &b);
                if (a < 0 || b < 0) {
                    printf("[ERRO] Base e altura devem ser nao negativas.\n");
                } else {
                    printf("Resultado: %.4f\n", area_triangulo(a, b));
                }
                break;

            case 21: /* Hipotenusa */
                printf("Digite os dois catetos: ");
                scanf("%lf %lf", &a, &b);
                if (hipotenusa(a, b, &resultado))
                    printf("Resultado: %.4f\n", resultado);
                else
                    printf("[ERRO] Catetos devem ser valores positivos.\n");
                break;

            case 22: /* Volume da esfera */
                printf("Digite o raio: ");
                scanf("%lf", &a);
                if (a < 0) {
                    printf("[ERRO] O raio nao pode ser negativo.\n");
                } else {
                    printf("Resultado: %.4f\n", volume_esfera(a));
                }
                break;

            case 23: /* Fatorial */
                printf("Digite um numero inteiro nao negativo: ");
                scanf("%d", &i1);
                if (i1 < 0)
                    printf("[ERRO] Fatorial nao definido para numeros negativos.\n");
                else
                    printf("Resultado: %lu\n", fatorial(i1));
                break;

            case 24: /* MDC */
                printf("Digite dois numeros inteiros: ");
                scanf("%d %d", &i1, &i2);
                printf("Resultado (MDC): %d\n", mdc(i1, i2));
                break;

            case 25: /* MMC */
                printf("Digite dois numeros inteiros: ");
                scanf("%d %d", &i1, &i2);
                if (i1 == 0 || i2 == 0)
                    printf("[ERRO] MMC nao definido quando um dos numeros e zero.\n");
                else
                    printf("Resultado (MMC): %d\n", mmc(i1, i2));
                break;

            case 0: /* Sair */
                printf("\nEncerrando a calculadora. Ate mais!\n");
                continuar = 0;
                break;

            default:
                printf("[ERRO] Opcao invalida. Tente novamente.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}

/* ---------------------- Implementacao das funcoes ---------------------- */

void exibirMenu(void) {
    printf("-------------------------------------\n");
    printf(" 1  - Soma\n");
    printf(" 2  - Subtracao\n");
    printf(" 3  - Multiplicacao\n");
    printf(" 4  - Divisao\n");
    printf(" 5  - Potenciacao\n");
    printf(" 6  - Raiz quadrada\n");
    printf(" 7  - Raiz cubica\n");
    printf(" 8  - Seno\n");
    printf(" 9  - Cosseno\n");
    printf("10  - Tangente\n");
    printf("11  - Logaritmo natural (ln)\n");
    printf("12  - Logaritmo base 10\n");
    printf("13  - Valor absoluto\n");
    printf("14  - Porcentagem\n");
    printf("15  - Media aritmetica (3 valores)\n");
    printf("16  - Graus para radianos\n");
    printf("17  - Radianos para graus\n");
    printf("18  - Area do circulo\n");
    printf("19  - Area do retangulo\n");
    printf("20  - Area do triangulo\n");
    printf("21  - Hipotenusa\n");
    printf("22  - Volume da esfera\n");
    printf("23  - Fatorial\n");
    printf("24  - MDC (maximo divisor comum)\n");
    printf("25  - MMC (minimo multiplo comum)\n");
    printf(" 0  - Sair\n");
    printf("-------------------------------------\n");
}

void limparBufferEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

double somar(double a, double b) {
    return a + b;
}

double subtrair(double a, double b) {
    return a - b;
}

double multiplicar(double a, double b) {
    return a * b;
}

int dividir(double a, double b, double *resultado) {
    if (b == 0) {
        return 0; /* erro: divisao por zero */
    }
    *resultado = a / b;
    return 1;
}

double potencia(double base, double expoente) {
    return pow(base, expoente);
}

int raiz_quadrada(double x, double *resultado) {
    if (x < 0) {
        return 0; /* erro: dominio invalido */
    }
    *resultado = sqrt(x);
    return 1;
}

double raiz_cubica(double x) {
    return cbrt(x);
}

double seno(double graus) {
    return sin(graus * PI / 180.0);
}

double cosseno(double graus) {
    return cos(graus * PI / 180.0);
}

int tangente(double graus, double *resultado) {
    double resto = fmod(graus - 90.0, 180.0);
    if (resto == 0.0) {
        return 0; /* tangente indefinida */
    }
    *resultado = tan(graus * PI / 180.0);
    return 1;
}

int logaritmo_natural(double x, double *resultado) {
    if (x <= 0) {
        return 0;
    }
    *resultado = log(x);
    return 1;
}

int logaritmo_base10(double x, double *resultado) {
    if (x <= 0) {
        return 0;
    }
    *resultado = log10(x);
    return 1;
}

double valor_absoluto(double x) {
    return fabs(x);
}

double porcentagem(double valor, double percentual) {
    return (valor * percentual) / 100.0;
}

double media_aritmetica(double a, double b, double c) {
    return (a + b + c) / 3.0;
}

double graus_para_radianos(double graus) {
    return graus * PI / 180.0;
}

double radianos_para_graus(double rad) {
    return rad * 180.0 / PI;
}

double area_circulo(double raio) {
    return PI * raio * raio;
}

double area_retangulo(double base, double altura) {
    return base * altura;
}

double area_triangulo(double base, double altura) {
    return (base * altura) / 2.0;
}

int hipotenusa(double cateto1, double cateto2, double *resultado) {
    if (cateto1 < 0 || cateto2 < 0) {
        return 0;
    }
    *resultado = sqrt(pow(cateto1, 2) + pow(cateto2, 2));
    return 1;
}

double volume_esfera(double raio) {
    return (4.0 / 3.0) * PI * pow(raio, 3);
}

unsigned long fatorial(int n) {
    unsigned long resultado = 1;
    int i;
    for (i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int mdc(int a, int b) {
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int mmc(int a, int b) {
    int divisor = mdc(a, b);
    if (divisor == 0) return 0;
    int resultado = (a / divisor) * b;
    return (resultado < 0) ? -resultado : resultado;
}
