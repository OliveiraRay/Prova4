#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Jogador{
    char nome[60]; int gols;
};
struct Jogador criaJogador(char *, int);

struct Time {
    struct Jogador *jogadores;
    char nome[60];
    int media;
    int QuantidadeDeJogadores;
};

struct Time criaTime(char *, struct Jogador *, int);

int calculaMedia(struct Jogador *, int);
int somaVetor(struct Jogador *, int);
void verificaAcimMedia(struct Time, int);

int main(){
    int qtdTimes, QuantidadeDeJogadores, gols, media;
    char nomeTime[60], nomeJogador[60];
    struct Time t;
    struct Jogador jogadores[60];

    scanf("%d", &qtdTimes);

    for (int i = 0; i < qtdTimes; i++){
        scanf("%s", nomeTime);
        scanf("%d", &QuantidadeDeJogadores);
        for (int j = 0; j < QuantidadeDeJogadores; j++){
            scanf("%s %d", nomeJogador, &gols);
            jogadores[j] = criaJogador(nomeJogador, gols);
        }
        t = criaTime(nomeTime, jogadores, QuantidadeDeJogadores);
        media = calculaMedia(jogadores, QuantidadeDeJogadores);
        verificaAcimMedia(t, media);
    }

    return 0;
}

struct Jogador criaJogador(char * nome, int gols){
    struct Jogador j;
    strcpy(j.nome, nome);
    j.gols = gols;
    return j;
};

struct Time criaTime(char * nome, struct Jogador * jogadores, int QuantidadeDeJogadores){
    struct Time t;
    strcpy(t.nome, nome);
    t.media = 0;
    t.jogadores = jogadores;
    t.QuantidadeDeJogadores = QuantidadeDeJogadores;
    return t;
};

int somaVetor(struct Jogador * jogadores, int tam){
    int i, soma = 0;

    for (i = 0; i < tam; i++){
        soma = soma + jogadores[i].gols;
    }

    return soma;
}

int calculaMedia(struct Jogador * jogadores, int n){
    int i;
    return (somaVetor(jogadores, n) / n);
}

void verificaAcimMedia(struct Time clube, int media){
    for (int i = 0; i < clube.QuantidadeDeJogadores; i++){
        if (clube.jogadores[i].gols > media){
            printf("[%s] %s\n", clube.nome, clube.jogadores[i].nome);
        }
    }
}