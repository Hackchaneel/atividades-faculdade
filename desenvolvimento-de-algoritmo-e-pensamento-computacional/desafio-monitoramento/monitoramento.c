/* ============================================================
 * Sistema de Monitoramento de Temperatura
 * Disciplina: Algoritmos e Pensamento Computacional
 * Autor: Davi Carvalho Macedo
 * ============================================================
 *
 * O programa le um limite de temperatura definido pelo usuario,
 * em seguida recebe leituras de temperatura uma a uma, validando
 * cada entrada. Sempre que uma leitura ultrapassa o limite, um
 * contador de "leituras consecutivas acima do limite" e
 * incrementado; caso contrario, o contador e zerado. Se esse
 * contador atingir 3, o monitoramento e encerrado automaticamente
 * (simulando um alarme critico). O operador tambem pode encerrar
 * o monitoramento manualmente a qualquer momento digitando o
 * valor sentinela -999.
 *
 * Ao final, e exibido um relatorio com total de leituras validas,
 * media, maior e menor temperatura, quantidade e percentual de
 * leituras acima do limite, e o motivo do encerramento.
 * ============================================================ */

#include <stdio.h>

int main(void) {
    float limite;
    int limiteValido = 0;
    int status; /* retorno do scanf, usado para validar entradas */

    printf("=== SISTEMA DE MONITORAMENTO DE TEMPERATURA ===\n\n");

    /* ------------------------------------------------------------
     * 1) LEITURA E VALIDACAO DO LIMITE DE TEMPERATURA
     * Usamos do...while porque o limite PRECISA ser perguntado ao
     * menos uma vez, e repetimos a pergunta enquanto o valor
     * informado nao for numerico ou estiver fora de uma faixa
     * fisica plausivel (-50 a 60 graus C).
     * ------------------------------------------------------------ */
    do {
        printf("Informe o limite de temperatura (-50 a 60 C): ");
        status = scanf("%f", &limite);

        if (status != 1) {
            /* Entrada nao numerica: limpa o buffer do teclado
             * caractere por caractere ate encontrar a quebra de linha. */
            while (getchar() != '\n')
                ; /* descarta o restante da linha invalida */
            printf("Entrada invalida! Digite um valor numerico.\n\n");
        } else if (limite < -50 || limite > 60) {
            printf("Valor fora da faixa permitida (-50 a 60). Tente novamente.\n\n");
        } else {
            limiteValido = 1;
        }
    } while (!limiteValido);

    printf("\nLimite de temperatura definido: %.1f C\n", limite);
    printf("Dica: digite -999 a qualquer momento para encerrar manualmente.\n\n");

    /* ------------------------------------------------------------
     * 2) VARIAVEIS DE CONTROLE DO MONITORAMENTO
     * ------------------------------------------------------------ */
    float temperatura;
    float soma = 0.0f;
    float maior = -1000.0f;
    float menor = 1000.0f;
    int totalLeituras = 0;      /* total de leituras VALIDAS aceitas */
    int totalAcima = 0;         /* quantas leituras ficaram acima do limite */
    int consecutivasAcima = 0;  /* contador de leituras consecutivas acima */
    int encerradoPorAlarme = 0; /* 1 = encerrou por 3 consecutivas, 0 = manual */
    int leituraValida;
    int continuarMonitorando = 1;

    /* ------------------------------------------------------------
     * 3) LACO PRINCIPAL DE MONITORAMENTO (while)
     * Usamos while aqui porque a continuidade do monitoramento
     * depende de uma condicao que so e conhecida DEPOIS de cada
     * leitura (alarme de 3 consecutivas ou pedido manual de saida),
     * entao a condicao de parada precisa ser reavaliada a cada volta.
     * ------------------------------------------------------------ */
    while (continuarMonitorando) {

        /* --- 3.1 Leitura validada de UMA temperatura (do...while) ---
         * do...while porque sempre precisamos pedir a leitura pelo
         * menos uma vez, repetindo apenas se a entrada nao for um
         * numero valido. */
        leituraValida = 0;
        do {
            printf("Leitura %d - Temperatura: ", totalLeituras + 1);
            status = scanf("%f", &temperatura);

            if (status != 1) {
                while (getchar() != '\n')
                    ;
                printf("Entrada invalida! Digite um numero.\n");
            } else {
                leituraValida = 1;
            }
        } while (!leituraValida);

        /* --- 3.2 Encerramento manual via valor sentinela --- */
        if (temperatura == -999) {
            printf("\nEncerramento manual solicitado pelo operador.\n");
            continuarMonitorando = 0;
            continue; /* volta ao topo do while, que ja vai encerrar */
        }

        /* --- 3.3 Validacao da faixa fisica da leitura --- */
        if (temperatura < -50 || temperatura > 100) {
            printf("Leitura fora da faixa fisica esperada (-50 a 100). Descartada.\n\n");
            continue;
        }

        /* --- 3.4 Atualizacao das estatisticas --- */
        totalLeituras++;
        soma += temperatura;
        if (temperatura > maior) maior = temperatura;
        if (temperatura < menor) menor = temperatura;

        /* --- 3.5 Verificacao do limite e contagem de consecutivas ---
         * Se a leitura atual ultrapassa o limite, incrementa o
         * contador de consecutivas; caso contrario, o contador
         * e reiniciado (a sequencia foi quebrada). */
        if (temperatura > limite) {
            totalAcima++;
            consecutivasAcima++;
            printf(">> ALERTA: temperatura acima do limite! (%d consecutiva(s))\n\n",
                   consecutivasAcima);
        } else {
            consecutivasAcima = 0;
            printf("Temperatura dentro do limite.\n\n");
        }

        /* --- 3.6 Encerramento automatico por 3 alertas consecutivos --- */
        if (consecutivasAcima == 3) {
            printf("!!! ALARME: 3 temperaturas consecutivas acima do limite !!!\n");
            printf("Monitoramento encerrado automaticamente.\n");
            encerradoPorAlarme = 1;
            continuarMonitorando = 0;
        }
    }

    /* ------------------------------------------------------------
     * 4) RELATORIO FINAL
     * ------------------------------------------------------------ */
    printf("\n===== RELATORIO FINAL =====\n");
    if (totalLeituras == 0) {
        printf("Nenhuma leitura valida foi registrada.\n");
    } else {
        float media = soma / totalLeituras;
        float percentualAcima = (float) totalAcima / totalLeituras * 100.0f;

        printf("Total de leituras validas : %d\n", totalLeituras);
        printf("Temperatura media         : %.2f C\n", media);
        printf("Maior temperatura         : %.2f C\n", maior);
        printf("Menor temperatura         : %.2f C\n", menor);
        printf("Leituras acima do limite  : %d\n", totalAcima);
        printf("Percentual acima do limite: %.1f%%\n", percentualAcima);
        printf("Motivo do encerramento    : %s\n",
               encerradoPorAlarme
                   ? "3 temperaturas consecutivas acima do limite"
                   : "Encerramento manual pelo operador (-999)");
    }

    return 0;
}
