#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>


// 定义函数:    int stat(const char *file_name, struct stat *buf);
// 函数说明:    通过文件名filename获取文件信息，并保存在buf所指的结构体stat中
// 返回值:      执行成功则返回0，失败返回-1，错误代码存于errno

// 错误代码:
//     ENOENT         参数file_name指定的文件不存在
//     ENOTDIR        路径中的目录存在但却非真正的目录
//     ELOOP          欲打开的文件有过多符号连接问题，上限为16符号连接
//     EFAULT         参数buf为无效指针，指向无法存在的内存空间
//     EACCESS        存取文件时被拒绝
//     ENOMEM         核心内存不足
//     ENAMETOOLONG   参数file_name的路径名称太长

int main() {
  struct stat buf;
  stat("/etc/hosts", &buf);
  printf("/etc/hosts file size = %d\n", buf.st_size);
}