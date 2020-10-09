#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main() {	

	printf("Bem vindo ao jogo de adivinhacao\n\n\n");


	int segundos = time(0);
	srand(segundos);

	int numerogrande = rand();

	int numerosecreto = numerogrande % 100;
	int chute;
	int tentativas = 1;
	double pontos = 1000;
	int acertou = 0;

	int nivel;
	printf("Qual o nivel de dificuldade?\n");
	printf("(1)facil (2)medio (3)dificil\n\n");
	printf("Escolha: ");
	scanf("%i", &nivel);
	printf("\n");
	int numerodetentativas;

	switch (nivel)
	{
	case 1: 
		numerodetentativas = 20;
		break;
	case 2: 
		numerodetentativas = 15;
		break;
	default: 
		numerodetentativas = 6;
		break;
	}

	for (int i = 1; i <= numerodetentativas; i++)
	{
		printf("tentativa %i\n",tentativas);
		printf("Qual eh o seu chute? ");

		scanf("%i", &chute);
		printf("Seu chute foi %i\n", chute);
		
		if (chute < 0)
		{
			printf("Voce não pode chutar numeros negativos\n");
			continue;
		}

		acertou = (chute == numerosecreto);
		int maior = chute > numerosecreto;

		if (acertou)
		{
			break;
		}

		else if (maior)
		{
			printf("Seu chute foi MAIOR que o numero secreto\n\n");
		}
		else
		{
			printf("Seu chute foi MENOR que o numero secreto\n\n");
		}

		tentativas++;

		double pontosperdidos = abs(chute - numerosecreto) / (double)2;

		pontos -= pontosperdidos;
		
	}
	printf("\n");
	printf("fim de jogo\n\n");

	if (acertou)
	{
		printf("Voce ganhou\n");
		printf("Voce acertou em %i tentativas\n", tentativas);
		printf("Total de pontos: %.1f\n", pontos);
	}
	else
	{
		printf("Voce perdeu, tente de novo\n");
	}
	
	

	system("pause");
	return 0;
}