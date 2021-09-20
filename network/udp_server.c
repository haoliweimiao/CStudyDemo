#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

struct sockaddr_in create_sockaddre_in(const int port);
int printSocketInfo(const int socket);

const int PORT = 1234;

int main() {
  printf("start run udp server");

  int serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
  printf("create serverSocket:%d \n", serverSocket);

  struct sockaddr_in servAddr = create_sockaddre_in(PORT);

  // 开启server服务
  int bindResult =
      bind(serverSocket, (struct sockaddr *)&servAddr, sizeof(servAddr));

  if (bindResult < 0) {
    printf("server start bind port:%d result:%d ,port locked!\n", PORT,
           bindResult);
  }

  // 开始接受client消息
  struct sockaddr_in clientAddr;
  socklen_t clientAddrSize = sizeof(clientAddr);
  // 进入监听状态，等待client端发送信息
  char readBuffer[1024];
  char sendBuffer[1024] = "receiver data";
  while (1) {
    recvfrom(serverSocket, readBuffer, 1024, 0, (struct sockaddr *)&clientAddr,
             (socklen_t *)&clientAddrSize);
    printf("read message from client:%s \n", readBuffer);
    memset(readBuffer, '\0', 1);
    sendto(serverSocket, sendBuffer, 1024, 0, (struct sockaddr *)&clientAddr,
           clientAddrSize);
  }

  close(serverSocket);

  return 0;
}

int printSocketInfo(const int socket) {
  unsigned optVal;
  socklen_t optLen = sizeof(socklen_t);
  getsockopt(socket, SOL_SOCKET, SO_SNDBUF, (char *)&optVal, &optLen);
  // 打印
  printf("Socket id: %d, Buffer length: %d\n", socket, optVal);

  return 1;
}

struct sockaddr_in create_sockaddre_in(const int port) {
  struct sockaddr_in servAddr;
  memset(&servAddr, 0, sizeof(servAddr));
  // 使用 IPV4地址
  servAddr.sin_family = PF_INET;
  // 自动获取IP地址
  servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  // 设置端口
  servAddr.sin_port = htons(port);
  return servAddr;
}