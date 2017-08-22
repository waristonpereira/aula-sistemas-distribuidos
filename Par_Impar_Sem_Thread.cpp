#include <windows.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

int n1 = 0;
int n2 = 0;

void jogador1()
{
	srand( (unsigned)time(NULL) );
	printf("\nJogador 1 escolhendo....");
	n1 = rand()%10;
	Sleep(1000);
}

void jogador2()
{
	srand( (unsigned)time(NULL)+1000 );
	printf("\nJogador 2 escolhendo....");
	n2 = rand()%10;
	Sleep(1000);
}

void resultado()
{
	int par = (n1+n2)%2;
	printf("\n--> Jogador 1 (%i) x Jogador 2 (%i) = %i", n1,n2,n1+n2);
	if (par == 0)
	{
		printf("\n--> Venceu Jogador 1");
	} else {
		printf("\n--> Venceu Jogador 2");
	}
}

int main()
{
	system("cls");
	for(;;)
	{
		jogador1();
		jogador2();
		resultado();
	}
	getchar();
	return 0;	
}
