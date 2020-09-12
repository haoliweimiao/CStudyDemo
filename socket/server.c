#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void printSocketInfo(const int socket) {
  unsigned optVal;
  socklen_t optLen = sizeof(socklen_t);
  getsockopt(socket, SOL_SOCKET, SO_SNDBUF, (char *)&optVal, &optLen);
  // 打印
  printf("Socket id: %d, Buffer length: %d\n", socket, optVal);
}

int main() {
  //创建套接字
  int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  //将套接字和IP、端口绑定
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr)); //每个字节都用0填充
  serv_addr.sin_family = AF_INET;           //使用IPv4地址
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //具体的IP地址
  serv_addr.sin_port = htons(1234);                   //端口
  bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

  //接收客户端请求
  struct sockaddr_in clnt_addr;
  socklen_t clnt_addr_size = sizeof(clnt_addr);

  //进入监听状态，等待用户发起请求
  int result = 0;
  char sendBuffer[1024];
  char readBuffer[1024];
  while ((result = listen(serv_sock, 20)) >= 0) {
    printf("listen client result:%d \n", result);
    int clnt_sock = 0;
    while ((clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr,
                               &clnt_addr_size)) >= 0) {
      printSocketInfo(clnt_sock);
      read(clnt_sock, readBuffer, sizeof(readBuffer) - 1);
      printf("read message from client:%s \n", readBuffer);
      memset(readBuffer, '\0', 1);
      //向客户端发送数据
      printf("input string to response client: ");
      scanf("%s", sendBuffer);
      write(clnt_sock, sendBuffer, sizeof(sendBuffer));
      close(clnt_sock);
      printf("send %s to client :%d, close socket\n", sendBuffer, clnt_sock);
    }
  }

  //关闭套接字
  close(serv_sock);
  printf("close serv_sock:%d \n", serv_sock);
  serv_sock = -1;

  return 0;
}