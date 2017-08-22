#include <windows.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

pthread_t thread_jog1;
pthread_t thread_jog2;
pthread_t thread_resultado;

sem_t semaforo_jog1;
sem_t semaforo_jog2;
sem_t semaforo_res;

int n1 = 0;
int n2 = 0;

void* jogador1(void *p)
{
	srand( (unsigned)time(NULL) );
	for(;;)
	{
		sem_wait(&semaforo_res);
		sem_wait(&semaforo_jog1);
		printf("\nJogador 1 escolhendo....");
		n1 = rand()%10;
		Sleep(1000);
		sem_post(&semaforo_jog1);
		sem_post(&semaforo_res);
	}
}

void* jogador2(void *p)
{
	srand( (unsigned)time(NULL)+100 );
	for(;;)
	{
		sem_wait(&semaforo_res);
		sem_wait(&semaforo_jog2);
		printf("\nJogador 2 escolhendo....");
		n2 = rand()%10;
		Sleep(1000);
		sem_post(&semaforo_jog2);
		sem_post(&semaforo_res);
	}
}

void* resultado(void *p)
{
	for(;;)
	{
		sem_wait(&semaforo_res);
		sem_wait(&semaforo_jog1);
		sem_wait(&semaforo_jog2);
		int par = (n1+n2)%2;
		printf("\n--> Jogador 1 (%i) x Jogador 2 (%i) = %i", n1,n2,n1+n2);
		if (par == 0)
		{
			printf("\n--> Venceu Jogador 1");
		} else {
			printf("\n--> Venceu Jogador 2");
		}
		sem_post(&semaforo_jog1);
		sem_post(&semaforo_jog2);
		sem_post(&semaforo_res);
	}
}

int main()
{
	system("cls");
	sem_init(&semaforo_jog1, 0, 1);
	sem_init(&semaforo_jog2, 0, 1);
	sem_init(&semaforo_res, 0, 1);
	pthread_create(&thread_jog1, NULL, jogador1, NULL);
	pthread_create(&thread_jog2, NULL, jogador2, NULL);
	pthread_create(&thread_resultado, NULL, resultado, NULL);
	getchar();
	return 0;	
}
