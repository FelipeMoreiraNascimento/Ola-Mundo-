#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void abertura();
void chuta();

int main ()
{  
    char palavrasecreta[20];

    sprintf(palavrasecreta,"melancia");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    abertura();

    do
    {
        //imprime a palavra secreta
        for (int i = 0; i < strlen(palavrasecreta); i++)
        {
            int achou = 0;

            //a letra ja foi chutada?
            for (int j = 0; j < tentativas; j++)
            {
                if (chutes[j]==palavrasecreta[i])
                {
                    achou = 1;
                    break;
                }        
            }
            if (achou)
            {
                printf("%c ", palavrasecreta[i]);
            }
            else
            {
                printf("_ ");
            }
            
        }
        printf("\n");

        chuta(chutes, tentativas);
        tentativas++;
        
    } while (!acertou && !enforcou);
    

    return 0;
}

void abertura() 
{
    printf("**************************\n");
    printf("*     Jogo De Forca      *\n");
    printf("**************************\n\n");
}

void chuta(char chutes[26], int tentativas)
{
    char chute;
    scanf(" %c",&chute);
    chutes[tentativas] = chute;
}