# Calculadora em C

## Descrição do projeto
Este projeto é uma calculadora científica desenvolvida em linguagem C como atividade prática da disciplina **Desenvolvimento de Algoritmos e Pensamento Computacional**. O programa apresenta um menu interativo no terminal, permitindo ao usuário escolher entre **25 operações matemáticas** diferentes, cada uma implementada em sua própria função.

## Objetivo da calculadora
Aplicar de forma integrada os conceitos fundamentais da linguagem C — variáveis, entrada e saída de dados, estruturas condicionais, estruturas de repetição, funções, modularização e uso da biblioteca `math.h` — construindo um programa funcional, organizado e com tratamento básico de erros, seguindo boas práticas de um pequeno projeto de software.

## Funcionalidades implementadas
- Menu interativo exibido em loop até o usuário optar por sair (opção `0`).
- Leitura de dados via `scanf()` e exibição de resultados via `printf()`.
- Tratamento de erros para:
  - divisão por zero;
  - raiz quadrada e logaritmos de números negativos ou zero;
  - tangente indefinida (90° + k·180°);
  - opções de menu inválidas;
  - entrada inválida (não numérica).

## Relação das funções desenvolvidas (25 no total)

| # | Função | Descrição |
|---|--------|-----------|
| 1 | `somar` | Soma de dois números |
| 2 | `subtrair` | Subtração de dois números |
| 3 | `multiplicar` | Multiplicação de dois números |
| 4 | `dividir` | Divisão com verificação de divisor zero |
| 5 | `potencia` | Potenciação (`pow`) |
| 6 | `raiz_quadrada` | Raiz quadrada (`sqrt`) com verificação de domínio |
| 7 | `raiz_cubica` | Raiz cúbica (`cbrt`) |
| 8 | `seno` | Seno de um ângulo em graus |
| 9 | `cosseno` | Cosseno de um ângulo em graus |
| 10 | `tangente` | Tangente com verificação de indefinição |
| 11 | `logaritmo_natural` | Logaritmo natural (`log`) |
| 12 | `logaritmo_base10` | Logaritmo na base 10 (`log10`) |
| 13 | `valor_absoluto` | Módulo de um número (`fabs`) |
| 14 | `porcentagem` | Cálculo de percentual de um valor |
| 15 | `media_aritmetica` | Média aritmética de três valores |
| 16 | `graus_para_radianos` | Conversão de graus para radianos |
| 17 | `radianos_para_graus` | Conversão de radianos para graus |
| 18 | `area_circulo` | Área do círculo |
| 19 | `area_retangulo` | Área do retângulo |
| 20 | `area_triangulo` | Área do triângulo |
| 21 | `hipotenusa` | Cálculo da hipotenusa (Teorema de Pitágoras) |
| 22 | `volume_esfera` | Volume da esfera |
| 23 | `fatorial` | Fatorial de um número inteiro |
| 24 | `mdc` | Máximo divisor comum (Algoritmo de Euclides) |
| 25 | `mmc` | Mínimo múltiplo comum |

Funções auxiliares de apoio: `exibirMenu()` (imprime o menu) e `limparBufferEntrada()` (evita loop infinito quando o usuário digita algo não numérico).

## Bibliotecas utilizadas
- `stdio.h` — entrada e saída de dados (`printf`, `scanf`, `getchar`).
- `math.h` — funções matemáticas (`pow`, `sqrt`, `cbrt`, `sin`, `cos`, `tan`, `log`, `log10`, `fabs`, `fmod`).

## Organização do código
O código está dividido em três blocos principais:
1. **Protótipos das funções**, declarados no topo do arquivo para organização e legibilidade.
2. **`main()`**, responsável apenas pelo controle do fluxo: exibir o menu, ler a opção do usuário em um `switch...case` e chamar a função correspondente dentro de um laço `while`.
3. **Implementação das funções**, cada uma isolada e com responsabilidade única, o que facilita testes, manutenção e reaproveitamento do código.

Funções que podem falhar (divisão por zero, raiz de negativo, logaritmo de valor não positivo, tangente indefinida, hipotenusa com catetos negativos) retornam um `int` como código de sucesso/erro (`1`/`0`) e devolvem o resultado por meio de um ponteiro (`double *resultado`), permitindo tratar o erro em `main()` sem usar valores "mágicos" como retorno.

## Conceitos de programação utilizados
- **Funções**: cada operação matemática é isolada em uma função própria, com parâmetros e retorno bem definidos, promovendo modularização e reuso.
- **Estruturas condicionais**: uso de `switch...case` para direcionar a opção escolhida no menu e de `if...else` dentro das funções para validar domínios matemáticos (ex.: impedir raiz quadrada de número negativo).
- **Estruturas de repetição**: um laço `while` mantém o programa em execução, exibindo o menu repetidamente até que o usuário escolha encerrar (opção `0`); um laço `for` é usado no cálculo do fatorial.
- **Entrada e saída de dados**: `scanf()` para capturar os valores digitados pelo usuário e `printf()` para exibir o menu e os resultados formatados.
- **Biblioteca `math.h`**: usada em praticamente todas as operações científicas (potenciação, raízes, trigonometria, logaritmos, valor absoluto).

## Instruções para compilação e execução

### Compilar (Linux/Mac ou WSL/MinGW no Windows)
```bash
gcc -Wall -Wextra -o calculadora calculadora.c -lm
```
> A flag `-lm` é necessária para vincular a biblioteca matemática (`math.h`).

### Executar
```bash
./calculadora
```
No Windows (sem WSL), após compilar:
```bash
calculadora.exe
```

## Exemplo de uso
```
=====================================
      CALCULADORA CIENTIFICA EM C
=====================================
-------------------------------------
 1  - Soma
 2  - Subtracao
 ...
 0  - Sair
-------------------------------------
Escolha uma opcao: 1
Digite dois numeros: 5 3
Resultado: 8.0000

Escolha uma opcao: 4
Digite dividendo e divisor: 10 0
[ERRO] Divisao por zero nao permitida.

Escolha uma opcao: 0

Encerrando a calculadora. Ate mais!
```

## Identificação do estudante
- **Nome:** Davi Carvalho Macedo
- **Disciplina:** Desenvolvimento de Algoritmos e Pensamento Computacional
- **Atividade:** Calculadora em C
