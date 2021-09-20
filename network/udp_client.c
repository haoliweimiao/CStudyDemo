#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define BUF_SIZE 1024

int createUdpSocket() {
  //创建套接字
  int clientSocket = socket(PF_INET, SOCK_DGRAM, 0);

  // 设置超时
  struct timeval timeout;
  timeout.tv_sec = 1;  //秒
  timeout.tv_usec = 0; //微秒
  if (setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, &timeout,
                 sizeof(timeout)) == -1) {
    printf("setsockopt failed:");
    return -1;
  }

  return clientSocket;
}

int main() {
  const char EXIT[] = "exit";
  const char QUIT[] = "quit";

  //服务器地址信息
  struct sockaddr_in serverAddr;
  memset(&serverAddr, 0, sizeof(serverAddr)); //每个字节都用0填充
  serverAddr.sin_family = PF_INET;
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  serverAddr.sin_port = htons(1234);

  //不断获取用户输入并发送给服务器,然后接受服务器数据
  struct sockaddr fromAddr;
  int addrLen = sizeof(fromAddr);

  while (1) {
    char buffer[BUF_SIZE] = {0};
    printf("Input a string: ");
    scanf("%s", buffer);

    if (strcmp(EXIT, buffer) == 0 || strcmp(QUIT, buffer) == 0) {
      printf("exit process \n");
      break;
    }

    int clientSocket = createUdpSocket();

    printf("clientSocket:%d \n", clientSocket);
    if (clientSocket < 0) {
      printf("connect server failed, finish process \n");
      break;
    }

    ssize_t sendToResult =
        sendto(clientSocket, buffer, strlen(buffer) + 1, 0,
               (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    printf("sendToResult:%zd \n", sendToResult);
    memset(buffer, '\0', 1);

    int strLen = recvfrom(clientSocket, buffer, BUF_SIZE, 0, &fromAddr,
                          (socklen_t *)&addrLen);
    printf("recvfrom strLen:%d \n", strLen);
    buffer[strLen] = 0;
    printf("Message form server: %s \n", buffer);
    memset(buffer, '\0', 1);
    close(clientSocket);
  }

  return 0;
}