#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {

  //向服务器（特定的IP和端口）发起请求
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr)); //每个字节都用0填充
  serv_addr.sin_family = AF_INET;           //使用IPv4地址
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //具体的IP地址
  serv_addr.sin_port = htons(1234);                   //端口

  char sendBuffer[] = "ping";
  //读取服务器传回的数据
  char readBuffer[1024];
  const char QUIT[] = "quit";
  int result = 0;
  while (result == 0) {
    //创建套接字
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    result = connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    printf("connect server result:%d \n", result);

    if (result != 0) {
      printf("connect server failed, exit process\n");
      return 0;
    }
    send(sock, sendBuffer, sizeof(sendBuffer) - 1, 0);

    read(sock, readBuffer, sizeof(readBuffer) - 1);

    printf("Message form server: %s\n", readBuffer);
    //关闭套接字
    close(sock);
    printf("disconnect server!");

    if (strcmp(readBuffer, QUIT) == 0) {
      printf("receiver quit message from message");
      break;
    }
  }

  return 0;
}