# 部分知识点/题目要求？
## 作业要求

客户端应有图形界面，便于发送和接收数据；

可以满足3个以上的客户端同时接入系统，并且任意客户端之间可以同时进行全双工通信。

用户需登录服务端。

## 一些小tips
### 网络编程函数

#### inet_ntoa
`inet_ntoa` 用于将一个网络字节顺序（网络字节顺序是大端格式）表示的 IP 地址（以 `struct in_addr` 类型存储）转换为点分十进制的字符串表示形式。

**原型**:
```cpp
char *inet_ntoa(struct in_addr in);
```
> 例如，"192.168.1.1"

头文件: `#include <arpa/inet.h>`

---

#### inet_addr
`inet_addr` 用于将点分十进制的字符串 IP 地址（如 "192.168.1.1"）转换为网络字节序的 32 位整数格式（`in_addr_t` 类型），适用于 `struct in_addr` 的 `s_addr` 字段。

**原型**:
```cpp
in_addr_t inet_addr(const char *cp);
```
> 返回值是网络字节序的 IPv4 地址，字符串无效则返回 `INADDR_NONE`。

头文件: `#include <arpa/inet.h>`

---

#### inet_pton
`inet_pton` 用于将点分十进制的字符串 IP 地址（IPv4 或 IPv6）转换为网络字节序的二进制表示。

**原型**:
```cpp
int inet_pton(int af, const char *src, void *dst);
```
> 支持 IPv4 (`AF_INET`) 和 IPv6 (`AF_INET6`)，成功返回 1，失败返回 0。

头文件: `#include <arpa/inet.h>`

---

#### inet_ntop
`inet_ntop` 用于将网络字节序的二进制 IP 地址转换为点分十进制字符串表示的 IPv4 或 IPv6 地址。

**原型**:
```cpp
const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);
```
> 返回点分十进制的 IP 地址，支持 IPv4 和 IPv6，错误时返回 `NULL`。

头文件: `#include <arpa/inet.h>`

---

#### htonl
`htonl` 用于将 32 位整数从主机字节序（小端序）转换为网络字节序（大端序）。

**原型**:
```cpp
uint32_t htonl(uint32_t hostlong);
```
> 主要用于处理 32 位整数（如 IPv4 地址）。

头文件: `#include <arpa/inet.h>`

---

#### htons
`htons` 用于将 16 位短整数从主机字节序（小端序）转换为网络字节序（大端序）。

**原型**:
```cpp
uint16_t htons(uint16_t hostshort);
```
> 主要用于处理 16 位整数（如端口号）。

头文件: `#include <arpa/inet.h>`

---

#### ntohl
`ntohl` 用于将 32 位整数从网络字节序转换为主机字节序（小端序）。

**原型**:
```cpp
uint32_t ntohl(uint32_t netlong);
```
> 主要用于将从网络接收到的 32 位整数转换为主机可读的格式。

头文件: `#include <arpa/inet.h>`

---

#### ntohs
`ntohs` 用于将 16 位短整数从网络字节序转换为主机字节序（小端序）。

**原型**:
```cpp
uint16_t ntohs(uint16_t netshort);
```
> 主要用于将从网络接收到的 16 位整数（如端口号）转换为主机可读的格式。

头文件: `#include <arpa/inet.h>`

---


### 实验过程用到的结构体
`struct sockaddr` : 本身是一个通用的地址结构体，不能直接使用来存储特定类型（如 IPv4 或 IPv6）的地址信息
``` cpp
struct sockaddr 
{
    sa_family_t sa_family;  /* 地址族 (Address Family)*/
    char sa_data[14];        /* 地址数据 (Address Data)*/
};
```
`struct sockaddr_in` : 用于IPv4地址的结构体，包含了IP地址和端口号等信息。
```cpp
struct sockaddr_in
{
    sa_family_t sin_family;  /* 协议族 */
    in_port_t sin_port;      /* 端口号 */
    struct in_addr sin_addr; /* IP 地址 */
    unsigned char sin_zero[8];
};
```
`struct in_addr` : 是用于表示 IPv4 地址的结构体.它主要用于存储一个 32 位的 IPv4 地址，通常与 sockaddr_in 结构体结合使用。

``` cpp
struct in_addr {
    in_addr_t s_addr;  /* 32 位 IPv4 地址，按网络字节序存储 */
};
```

> 记得包含`netinet/in.h `头文件

## server服务器


### 采用循环接收数据的主要原因

循环结构是构建一个稳定且能够处理多个连接的 TCP 服务器的基本方式。
1. **持续监听连接**：通过循环，服务器能够持续监听和接受来自客户端的连接请求。当有多个客户端同时尝试连接时，循环能够确保每个连接都被接受并处理。

2. **处理多个客户端**：每次接受到一个新的连接后，服务器可以处理与该客户端的通信，而不需要关闭服务器或结束程序。这样可以实现并发处理。

3. **错误处理**：如果在 `accept` 函数中出现错误，使用 `continue;` 可以让程序继续监听下一个连接，而不是直接退出。

4. **数据交换**：在接收到客户端连接后，服务器能够处理数据接收和发送。循环确保这一过程可以重复进行，直到服务器被显式关闭。

