#include <windows.h>
#include <winsock.h>
#include <stdio.h>
#include <string.h>

#define SERVIDOR 	"127.0.0.1"
#define PORTA 		6000

int main(int argc, char *argv[]) {
  
  int conexao;
  WSADATA wsaData;
  struct sockaddr_in servidor;
  char msg[255];
    
  // Inicializa Winsock
  WSAStartup(MAKEWORD(2,1),&wsaData);

  // Criação do Socket UDP
  // SOCK_STREAM - TCP
  // SOCK_DGRAM - UDP
  conexao = socket(AF_INET,SOCK_DGRAM,0);

  // Configuração do Socket
  servidor.sin_family = AF_INET; // Tipo IPv4
  servidor.sin_port = htons(PORTA); // Porta
  servidor.sin_addr.s_addr = inet_addr(SERVIDOR); // Servidor
 
  // Le mensagem
  printf("Digite a mensagem:");
  scanf("%s", &msg);
  
  // Envia 
  sendto(conexao,msg,sizeof(msg),0,(struct sockaddr *)&servidor,sizeof(servidor));
  
  // Recebe resposta
  recv(conexao, msg, sizeof(msg), 0);
  printf("\nResposta: %s", msg);
  
  // Fecha conexões
  closesocket(conexao);
  WSACleanup();
  return 0;
}
