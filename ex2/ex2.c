#include <stdio.h>
struct tRacional{
    int num;
    int deno;
};

struct tRacional racional(int, int);
struct tRacional negativo(struct tRacional);
struct tRacional soma(struct tRacional, struct tRacional);
struct tRacional multiplicacao (struct tRacional, struct tRacional);
struct tRacional divisao (struct tRacional, struct tRacional);
struct tRacional reduz(struct tRacional);

int main (){
    char ope;
    int den1, num1, den2, num2;
    
    
    while (scanf("%d %d %c %d %d", &num1, &den1, &ope, &num2, &den2) != EOF){

        struct tRacional x1;
        struct tRacional x2;

        x1.num = num1;
        x1.deno = den1;
        x2.num = num2;
        x2.deno = den2;

        if (ope == '+'){
            struct tRacional adicao;
            adicao = soma (x1, x2);

            struct tRacional printSoma;
            printSoma = reduz(adicao);
            printf("%d %d\n", printSoma.num, printSoma.deno);
        }
        else if (ope == '-'){
            struct tRacional negSub;
            negSub = negativo (x2);

            struct tRacional sub;
            sub = soma (x1, negSub);

            struct tRacional printsub;
            printsub = reduz(sub);
            printf("%d %d\n", printsub.num, printsub.deno);
        }
        else if (ope == '/'){
            struct tRacional dividindo;
            dividindo = divisao(x1, x2);

            struct tRacional printDivisao;
            printDivisao = reduz(dividindo);
            printf("%d %d\n", printDivisao.num, printDivisao.deno);
        }
        else if (ope == '*'){
            struct tRacional multiplicando;
            multiplicando = multiplicacao (x1, x2);

            struct tRacional MostraMultiplicacao;
            MostraMultiplicacao = reduz(multiplicando);
            printf("%d %d\n", MostraMultiplicacao.num, MostraMultiplicacao.deno);
        }
    }

    return 0;
}

struct tRacional racional(int d, int n){

    struct tRacional racional;
    racional.num = d;
    racional.deno = n;

    return racional;
}

struct tRacional negativo(struct tRacional negativo){

    negativo.num = negativo.num * -1;
    return negativo;
}

struct tRacional soma(struct tRacional x1, struct tRacional x2){

    struct tRacional fracao3;
    int aux1, aux2;

    fracao3.deno = x1.deno * x2.deno;
    aux1 = (fracao3.deno / x1.deno) * x1.num;
    aux2 = (fracao3.deno / x2.deno) * x2.num;
    fracao3.num = aux1 + aux2;

    return fracao3;
}

struct tRacional multiplicacao (struct tRacional x1, struct tRacional x2){

    struct tRacional produto;

    produto.num = x1.num * x2.num;
    produto.deno = x1.deno * x2.deno;

    return produto;
}

struct tRacional divisao (struct tRacional x1, struct tRacional x2){

    struct tRacional quociente;

    quociente.num = x1.num * x2.deno;
    quociente.deno = x1.deno * x2.num;

    return quociente;
}

struct tRacional reduz (struct tRacional red){

    int resto, num1, num2;
    num1 = red.num;
    num2 = red.deno;

    struct tRacional reduz;

    do {
        resto = num1 % num2;

        num1 = num2;
        num2 = resto;

    } while (resto != 0);

    if (num1 < 0) {
        reduz.num = (red.num * -1) / num1;
        reduz.deno = (red.deno * -1) / num1;
    }
    else {
        reduz.num = red.num/num1;
        reduz.deno = red.deno/num1;
    }

    return reduz;
}