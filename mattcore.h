#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <Shlobj.h>
#include <stdio.h>
#include <lmcons.h>
using namespace std;
void clear() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(console, topLeft);
}
bool fexists(const char *filename) {
  std::ifstream ifile(filename);
  return (bool)ifile;
}
void clFile(const char *filename){
  std::ofstream off(filename);
}
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
string getOsName()
{
    #ifdef _WIN32
    return "Windows";
    #elif _WIN64
    return "Windows";
    #elif __unix || __unix__
    return "Unix";
    #elif __APPLE__ || __MACH__
    return "Mac OSX";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #else
    return "Other";
    #endif
}
int getRESX()
{
  int x = GetSystemMetrics(SM_CXSCREEN);
  return x;
}
int getRESY()
{
  int y = GetSystemMetrics(SM_CYSCREEN);
  return y;
}
int wayBoot()
{
  int way=GetSystemMetrics(SM_CLEANBOOT);
  if(way==1)
    cout<<"SAFE BOOT"<<endl;
  if(way==2)
    cout<<"SAFE BOOT (WITH NETWORK)"<<endl;
  if(way==0)
    cout<<"NORMAL BOOT"<<endl;
}
int howManyMonitors()
{
  int a=GetSystemMetrics(SM_CMONITORS);
  return a;
}
int getCursorWidth()
{
  int a=GetSystemMetrics(SM_CXCURSOR);
  return a;
}
int mouseWheel()
{
  int a=GetSystemMetrics(SM_MOUSEWHEELPRESENT);
  return a;
}
int hasMouse()
{
  int a=GetSystemMetrics(SM_MOUSEPRESENT);
  return a;
}
int isSlow()
{
  int a=GetSystemMetrics(SM_SLOWMACHINE);
  return a;
}
int hasStarterWindows()
{
  int a=GetSystemMetrics(SM_STARTER);
  return a;
}
int hasClicksSwapped()
{
  int a=GetSystemMetrics(SM_SWAPBUTTON);
  return a;
}
int isTablet()
{
  int a=GetSystemMetrics(SM_TABLETPC);
  return a;
}
int getMouseX()
{
  POINT pt;
  GetCursorPos(&pt);
  int x=pt.x;
  return x;
}
int getMouseY()
{
  POINT pt;
  GetCursorPos(&pt);
  int x=pt.y;
  return x;
}
