#include "mattcore.h"

using namespace std;

int getSlash(char a[255])
{
  int ss=0;
  for(int i=0;i<strlen(a);i++)
    if(a[i]=='/' && a[i+1]!='/')
      ss++;
  return ss;
}
void showArg(char a[255],int which)
{
  int j=0;
  for(int i=0;i<strlen(a);i++)
  {
    if(a[i]=='/')
    {
      j++;
    }
    if(j==which)
    {
      if(a[i]!='/')
      cout<<a[i];
    }
  }
}
void show(char opts[255],int vals[100], int style)
{
if(style==1)
{
  for(int i=0;i<getSlash(opts);i++)
  {
    if(vals[i]==1)
    cout<<"> ";
    showArg(opts,i);
    cout<<"   "<<endl;
  }
}
if(style==2)
{
  for(int i=0;i<getSlash(opts);i++)
  {
cout<<"                           ";
    if(vals[i]==1)
    cout<<">";
    showArg(opts,i);
    if(vals[i]==1)
    cout<<"<   "<<endl;
    else
    cout<<"      "<<endl;
  }
}
}
int gui(char opts[255],int style=1)
{
  system("cls");
  if(style==1)
  {
  cout<<"> ";
  int vals[100];
  for(int i=0;i<getSlash(opts);i++)
  {
    vals[i]=0;
  }
  show(opts,vals,style);
  int pos=0;
  while(2)
  {
    int a=getch();
    ShowConsoleCursor(false);
    clear();
    if(a==80)
      if(pos==(getSlash(opts)-1))
        pos=0;
      else
        pos++;
    if(a==72)
      if(pos==0)
        pos=(getSlash(opts)-1);
      else
        pos--;
    if(a==13)
    {
      system("cls");
      break;
    }
      for(int i=0;i<getSlash(opts);i++)
      {
        vals[i]=(pos==i);
      }
      show(opts,vals,style);

  }
  return pos;
}
if(style==2)
{
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   >";
  int vals[100];
  for(int i=0;i<getSlash(opts);i++)
  {
    vals[i]=0;
  }
  show(opts,vals,style);
  int pos=0;
  while(2)
  {
    int a=getch();
    clear();
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    if(a==80 && pos<(getSlash(opts)-1))
      pos++;
    if(a==72 && pos>0)
      pos--;
    if(a==13)
    {
      system("cls");
      break;
    }
      for(int i=0;i<getSlash(opts);i++)
      {
        vals[i]=(pos==i);
      }
      show(opts,vals,style);

  }
  return pos;
}
}
