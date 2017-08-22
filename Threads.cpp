#include <windows.h>
#include <stdio.h>
#include <pthread.h>

pthread_t thread_1;

void* teste(void *p)
{
	for(;;)
	{
		printf("x");
		Sleep(1000);
	}
}
int numero;
int main()
{
	system("cls");
	pthread_create(&thread_1, NULL, teste, NULL);
	printf("Digite um numero: ");
	scanf("%i",&numero)
	getchar();
	return 0;	
}
