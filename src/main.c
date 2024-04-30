#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define TAMANHO_MAX 20

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

    printf("Tentativas (%d/6)\n", *jogadas);
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
        if (*jogadas >= 6)
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

void PM(char tabuleiro[TAMANHO_MAX], int num)
{
    char palavra[TAMANHO_MAX];
    int cont;
    int jogadas = 0;
    bool final = true;

    switch (num){
        case 1: //Brasil
        {
            strcpy(palavra, "brasil");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 2: // Japao
        {
            strcpy(palavra, "japao");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 3: // Australia
        {
           strcpy(palavra, "australia");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 4: // Egito
        {
            strcpy(palavra, "egito");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 5: // Canada
        {
            strcpy(palavra, "canada");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }
            
            esperarEnter();
            break;
        }
    }
}

void animais(char tabuleiro[TAMANHO_MAX], int num)
{
    char palavra[TAMANHO_MAX];
    int cont;
    int jogadas = 0;
    bool final = true;

    switch (num){
        case 1: // Elefante
        {
            strcpy(palavra, "elefante");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 2: // Jirafa
        {
            strcpy(palavra, "jirafa");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 3: // Borboleta
        {
           strcpy(palavra, "borboleta");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 4: // Tubarao
        {
            strcpy(palavra, "tubarao");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 5: // Pinguim
        {
            strcpy(palavra, "pinguim");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }
            
            esperarEnter();
            break;
        }
    }

}

void FF(char tabuleiro[TAMANHO_MAX], int num)
{
    char palavra[TAMANHO_MAX];
    int cont;
    int jogadas = 0;
    bool final = true;

    switch (num){
        case 1: // Titanic
        {
            strcpy(palavra, "titanic");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 2: // Star Wars
        {
            strcpy(palavra, "star-wars");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 3: // O Poderoso Chefão
        {
           strcpy(palavra, "o-poderoso-chefao");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 4: // Matrix
        {
            strcpy(palavra, "matrix");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 5: // Avatar
        {
            strcpy(palavra, "avatar");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }
            
            esperarEnter();
            break;
        }
    }
}

void cidades(char tabuleiro[TAMANHO_MAX], int num)
{
    char palavra[TAMANHO_MAX];
    int cont;
    int jogadas = 0;
    bool final = true;

    switch (num){
        case 1: // Paris
        {
            strcpy(palavra, "paris");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 2: // Nova York
        {
            strcpy(palavra, "nova-york");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 3: // Toquio
        {
           strcpy(palavra, "toquio");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 4: // Sydney
        {
            strcpy(palavra, "sydney");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 5: // Cairo
        {
            strcpy(palavra, "cairo");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }
            
            esperarEnter();
            break;
        }
    }

}

void VC(char tabuleiro[TAMANHO_MAX], int num)
{
    char palavra[TAMANHO_MAX];
    int cont;
    int jogadas = 0;
    bool final = true;

    switch (num){
        case 1: // DNA
        {
            strcpy(palavra, "dna");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 2: // Atomo
        {
            strcpy(palavra, "atomo");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 3: // Ecossistema
        {
           strcpy(palavra, "ecossistema");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 4: // Teorema
        {
            strcpy(palavra, "teorema");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }

            esperarEnter();
            break;
        }
        case 5: // Neutrino
        {
            strcpy(palavra, "neutrino");
            cont = contador(palavra);
            imprimirJogo(cont, palavra, tabuleiro);
            do
            {
                tabuleiro[TAMANHO_MAX] = verificar(tabuleiro, palavra, &jogadas, cont, &final);
            } while (jogadas < 6 && final);

            if (!final)
            {
                printf("\nParabens! Voce adivinhou a palavra e venceu o jogo!\n");
            }
            else
            {
                printf("Tentativas (%d/6)\n", jogadas);
                printf("\nVoce atingiu o limite de jogadas. A palavra era: %s\n", palavra);
            }
            
            esperarEnter();
            break;
        }
    }

}

#define TAMANHO_MAX 20

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
