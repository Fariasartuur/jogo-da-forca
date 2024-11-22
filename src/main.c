#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define TAMANHO_MAX 20
#define JOGADAS_MAX 6

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void esperarEnter()
{
    printf("\n|| Pressione Enter para continuar...\n");

    limparBuffer();
}

int numAleatorio()
{
    int numRand = rand() % 5 + 1;

    return numRand;
}

void limparTela()
{
    system("cls");
}

int contador(char palavra[TAMANHO_MAX])
{

    int cont = 0;

    while (palavra[cont] != '\0')
    {
        cont++;
    }

    return cont;
}

void imprimirJogo(int cont, char palavra[TAMANHO_MAX], char tabuleiro[TAMANHO_MAX])
{

    int i;

    for (i = 0; i < cont; i++)
    {
        if (palavra[i] == '-')
        {
            tabuleiro[i] = ' ';
        }
        printf("%c ", tabuleiro[i]);
    }
    printf("\n");
}

char verificar(char tabuleiro[TAMANHO_MAX], char palavra[TAMANHO_MAX], int *jogadas, int cont, bool *pnt)
{
    int i;
    char letra;
    bool letraIncorreta = true;

    printf("Tentativas (%d/%d)\n", *jogadas, JOGADAS_MAX);
    printf("\nInsira uma letra: ");
    scanf(" %c", &letra);
    letra = tolower(letra);

    limparBuffer();

    // substitui os '-' por espaço
    for(i=0;i<cont;i++){
        if(tabuleiro[i] == '-'){
            tabuleiro[i] = ' ';
        }
    }

    // verifica se a letra ja foi inserida
    for(i=0;i<cont;i++){
        if(tabuleiro[i] == letra){
            printf("Voce ja tentou esta letra. Tente novamente.\n");
        }
    }
 
    // atualizar a letra no tabuleiro
    for(i=0;i<cont;i++){
        if(palavra[i] == letra){
            tabuleiro[i] = letra;
            letraIncorreta = false;
        }

    }

    // exibir o tabuleiro
    for (i = 0; i < cont; i++)
    {
        printf("%c ", tabuleiro[i]);
    }
    printf("\n");

    // aumenta a quantidade de jogadas se estiver errado e termina o jogo se atingir o limite
    if (letraIncorreta)
    {
        printf("Letra incorreta.\n");
        (*jogadas)++;
        if (*jogadas >= JOGADAS_MAX)
        {
            *pnt = false; // termina o jogo se atingir o limite de jogadas
        }
    }

    // verifica se tem letra faltando
    *pnt = false;
    for (i = 0; i < cont; i++)
    {
        if (tabuleiro[i] == '_')
        {
            *pnt = true;
            break;
        }
    }

    return tabuleiro[TAMANHO_MAX];
}

void jogo(char palavra[TAMANHO_MAX], char tabuleiro[TAMANHO_MAX]){
    int cont = contador(palavra);
    int jogadas = 0;
    bool final = true;
    imprimirJogo(cont, palavra, tabuleiro);

    do
    {
        tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
    } while (jogadas < JOGADAS_MAX && final);

    if (!final)
    {
        printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
    }
    else
    {
        printf("Tentativas (%d/%d)\n", jogadas, JOGADAS_MAX);
        printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
    }
}

void PM(char tabuleiro[TAMANHO_MAX], int num)
{
    char palavra[TAMANHO_MAX];

    switch (num){
        case 1: //Brasil
        {
            strcpy(palavra, "brasil");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 2: // Japao
        {
            strcpy(palavra, "japao");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 3: // Australia
        {
            strcpy(palavra, "australia");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 4: // Egito
        {
            strcpy(palavra, "egito");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 5: // Canada
        {
            strcpy(palavra, "canada");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
    }
}

void animais(char tabuleiro[TAMANHO_MAX], int num)
{
    char palavra[TAMANHO_MAX];

    switch (num){
        case 1: // Elefante
        {
            strcpy(palavra, "elefante");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 2: // Girafa
        {
            strcpy(palavra, "girafa");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 3: // Borboleta
        {
            strcpy(palavra, "borboleta");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 4: // Tubarao
        {
            strcpy(palavra, "tubarao");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 5: // Pinguim
        {
            strcpy(palavra, "pinguim");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
    }
}

void FF(char tabuleiro[TAMANHO_MAX], int num)
{
    char palavra[TAMANHO_MAX];

    switch (num){
        case 1: // Titanic
        {
            strcpy(palavra, "titanic");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 2: // Star Wars
        {
            strcpy(palavra, "star-wars");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 3: // O Poderoso Chefão
        {
            strcpy(palavra, "o-poderoso-chefao");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 4: // Matrix
        {
            strcpy(palavra, "matrix");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 5: // Avatar
        {
            strcpy(palavra, "avatar");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
    }
}

void cidades(char tabuleiro[TAMANHO_MAX], int num)
{
    char palavra[TAMANHO_MAX];

    switch (num){
        case 1: // São Paulo
        {
            strcpy(palavra, "sao-paulo");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 2: // Salvador
        {
            strcpy(palavra, "salvador");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 3: // Rio de Janeiro
        {
            strcpy(palavra, "rio-de-janeiro");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 4: // Brasilia
        {
            strcpy(palavra, "brasilia");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 5: // Maceió
        {
            strcpy(palavra, "maceio");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
    }
}

void VC(char tabuleiro[TAMANHO_MAX], int num)
{
    char palavra[TAMANHO_MAX];

    switch (num){
        case 1: // DNA
        {
            strcpy(palavra, "dna");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 2: // Atomo
        {
            strcpy(palavra, "atomo");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 3: // Ecossistema
        {
            strcpy(palavra, "ecossistema");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 4: // Teorema
        {
            strcpy(palavra, "teorema");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
        case 5: // Neutrino
        {
            strcpy(palavra, "neutrino");
            jogo(palavra, tabuleiro);
            esperarEnter();
            break;
        }
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    
    int op;
    int numRand;
    bool saida = true;
    bool escolha = true;
    char tabuleiro[TAMANHO_MAX];

    do{
        memset(tabuleiro, '_', sizeof(tabuleiro));
        limparTela();
        printf("========== Jogo da Forca ==========");
        printf("\n\nEscolha um dos temas abaixo:\n\n");
        printf("1- Paises do Mundo\n");
        printf("2- Animais\n");
        printf("3- Filmes Famosos\n");
        printf("4- Cidades\n");
        printf("5- Vocabulario Cientifico\n");
        printf("0- SAIR\n");
        printf("\nInsira um numero: ");

        do{
            scanf("%d", &op);
            if (op < 0 || op > 5)
            {
                printf("Opcao invalida, tente novamente.\n");
            }
            else
            {
                escolha = false;
            }
        }while(escolha);

        limparTela();

        switch(op){
            case 1:
            {
                printf("========== Paises do Mundo ==========\n");
                numRand = numAleatorio();
                PM(tabuleiro, numRand);
                break;
            }
            case 2:
            {
                printf("========== Animais ==========\n");
                numRand = numAleatorio();
                animais(tabuleiro, numRand);
                break;
            }
            case 3:
            {
                printf("========== Filmes Famosos ==========\n");
                numRand = numAleatorio();
                FF(tabuleiro, numRand);
                break;
            }
            case 4:
            {
                printf("========== Cidades ==========\n");
                numRand = numAleatorio();
                cidades(tabuleiro, numRand);
                break;
            }
            case 5:
            {
                printf("========== Vocabulario Cientifico ==========\n");
                numRand = numAleatorio();
                VC(tabuleiro, numRand);
                break;
            }
            case 0:
            {
                saida = false;
                break;
            }
        }

    }while(saida);
    return 0;
}
