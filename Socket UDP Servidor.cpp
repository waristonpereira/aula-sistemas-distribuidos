#include <windows.h>
#include <winsock.h>
#include <stdio.h>

#define PORTA 6000

int main(int argc, char *argv[]) {
  
  int conexao;
  WSADATA wsaData;
  struct sockaddr_in servidor, cliente;
  char msg[255]; 

  // Inicializa Winsock	      
  WSAStartup(MAKEWORD(2,1),&wsaData);
  
  // Criação do Socket UDP
  // SOCK_STREAM - TCP
  // SOCK_DGRAM - UDP
  conexao=socket(AF_INET, SOCK_DGRAM, 0);
  
  // Configuração do Socket
  servidor.sin_family = AF_INET; // Tipo IPv4
  servidor.sin_port = htons(PORTA);  // Porta
  servidor.sin_addr.s_addr = htonl(INADDR_ANY); // IP Servidor (INADDR_ANY = Todos)

  // "Escuta" na porta e ip definido
  bind (conexao, (struct sockaddr *) &servidor,sizeof(servidor));
  
  printf("Aguardando cliente....\n");
  
  // Aguarda clientes
  while(1) {
  	// Aguarda receber algo
    int sizeCliente = sizeof(cliente);
    recvfrom(conexao, msg, 255, 0, 
		 (struct sockaddr *) &cliente, &sizeCliente);

    // Imprime a msg recebida
    printf("\nMensagem recebida de %s: %s", inet_ntoa(cliente.sin_addr), msg); 
    
    // Envia resposta (ECHO)
    sendto(conexao,msg,sizeof(msg),0,(struct sockaddr *)&cliente,sizeof(cliente));

  }
  
  // Fecha conexões
  closesocket(conexao);
  WSACleanup();
  return 0;
}
