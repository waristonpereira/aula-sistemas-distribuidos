#include <windows.h>
#include <stdio.h>
#include <pthread.h>

pthread_t thread_1[5];
pthread_t thread_2[5];

int saldo = 1000;

void* saque(void *p)
{
	saldo = saldo - 100;
	printf("\n(D -100) SALDO = %i", saldo);
}

void* deposito(void *p)
{
	saldo = saldo + 100;
	printf("\n(C +100) SALDO = %i", saldo);
}

int main()
{
	system("cls");
	printf("Saldo inicial  = %i\n", saldo);
	for (int i=0; i < 5; i++){
		pthread_create(&thread_1[i], NULL, saque, NULL);
		pthread_create(&thread_2[i], NULL, deposito, NULL);
	}
	for (int i=0; i < 5; i++){
		pthread_join(thread_1[i], NULL);
		pthread_join(thread_2[i], NULL);
	}
	printf("\n\nSaldo final    = %i\n", saldo);
	getchar();
	return 0;	
}
