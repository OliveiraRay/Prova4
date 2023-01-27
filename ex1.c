#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct tComplex{
    double inteiro, i;
};

struct tComplex complexo(int, int);
struct tComplex soma(struct tComplex, struct tComplex);
struct tComplex sub(struct tComplex, struct tComplex);
struct tComplex mult(struct tComplex, struct tComplex);
struct tComplex divi(struct tComplex, struct tComplex);

int PegaString(char*);



int main(){
    double inteiro1, comp1, inteiro2, comp2;
    char comp_str1[7], comp_str2[7], oper;

    struct tComplex *vComplexos;
    vComplexos = (struct tComplex*) malloc(5*sizeof(struct tComplex));

    while(scanf("%lf %s %c %lf %s", &inteiro1, comp_str1, &oper, &inteiro2, comp_str2) != EOF){
        comp1 = PegaString(comp_str1);
        comp2 = PegaString(comp_str2);
        vComplexos[0] = complexo(inteiro1, comp1);
        vComplexos[1] = complexo(inteiro2, comp2);

        if (oper == '+'){
            vComplexos[2] = soma(vComplexos[0], vComplexos[1]);
        }
        else if (oper == '-'){
            vComplexos[2] = sub(vComplexos[0], vComplexos[1]);
        }
        else if (oper == '/'){
            vComplexos[2] = divi(vComplexos[0], vComplexos[1]);
        }
        else{
            vComplexos[2] = mult(vComplexos[0], vComplexos[1]);
        }

        if (vComplexos[2].i >= 0){
            printf("%.0lf +%.0lfi\n", vComplexos[2].inteiro, vComplexos[2].i);
        }else{
            printf("%.0lf %.0lfi\n", vComplexos[2].inteiro, vComplexos[2].i);
        }


    }
    free(vComplexos);

    return 0;
}

int PegaString(char* str){
    char *ptr;
    int result;
    result = strtol(str, &ptr, 10);
	return result;

}

struct tComplex complexo(int A, int B){
    struct tComplex Num;
    Num.inteiro = A;
    Num.i = B;
    return Num;
}

struct tComplex soma(struct tComplex complex_one, struct tComplex complex_two){
    struct tComplex new_Complex;
    new_Complex.inteiro = complex_one.inteiro + complex_two.inteiro;
    new_Complex.i = complex_one.i + complex_two.i;
    return new_Complex;

}
struct tComplex sub(struct tComplex complex_one, struct tComplex complex_two){
    struct tComplex new_Complex;
    new_Complex.inteiro = complex_one.inteiro - complex_two.inteiro;
    new_Complex.i = complex_one.i - complex_two.i;
    return new_Complex;
}

struct tComplex mult(struct tComplex complex_one, struct tComplex complex_two){
    struct tComplex new_Complex;
    new_Complex.inteiro = (complex_one.inteiro * complex_two.inteiro) + (complex_one.i*complex_two.i*-1);
    new_Complex.i = (complex_one.inteiro * complex_two.i) + (complex_one.i * complex_two.inteiro);
    return new_Complex;
}

struct tComplex divi(struct tComplex complex_one, struct tComplex complex_two){
    struct tComplex new_Complex;
    int a = complex_one.inteiro;
    int b = complex_one.i;
    int c = complex_two.inteiro;
    int d = complex_two.i;

    new_Complex.inteiro = (a*c + b*d)/((c*c)+ (d*d));
    new_Complex.i = (c*b - a*d)/((c*c)+ (d*d));
    return new_Complex;
}