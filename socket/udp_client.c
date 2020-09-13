#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 100

int main() {
  const char EXIT[] = "exit";
  const char QUIT[] = "quit";

  //创建套接字
  int clientSocket = socket(PF_INET, SOCK_DGRAM, 0);

  //服务器地址信息
  struct sockaddr_in serverAddr;
  memset(&serverAddr, 0, sizeof(serverAddr)); //每个字节都用0填充
  serverAddr.sin_family = PF_INET;
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  serverAddr.sin_port = htons(1234);

  //不断获取用户输入并发送给服务器，然后接受服务器数据
  struct sockaddr fromAddr;
  int addrLen = sizeof(fromAddr);
  while (1) {
    char buffer[BUF_SIZE] = {0};
    printf("Input a string: ");
    scanf("%s", buffer);

    if (strcmp(EXIT, buffer) == 0 || strcmp(QUIT, buffer) == 0) {
      printf("exit process");
      break;
    }

    sendto(clientSocket, buffer, strlen(buffer), 0,
           (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    int strLen = recvfrom(clientSocket, buffer, BUF_SIZE, 0, &fromAddr,
                          (socklen_t *)&addrLen);
    buffer[strLen] = 0;
    printf("Message form server: %s\n", buffer);
  }

  close(clientSocket);
  return 0;
}