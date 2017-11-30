#include "mattgui.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int lines(char a[255])
{
  int number_of_lines = 0;
string line;
ifstream myfile(a);
while (getline(myfile, line))
    ++number_of_lines;
return number_of_lines;
}
void newSetting(char file[255],char name[255],int value)
{
  ofstream fout(file,ios::app);
  fout<<name<<" : "<<value<<endl;
}
int getValue(const char * file, const char * name)
{
    char key [255];
    char separator;
    int value;

    ifstream fin(file);

    while (fin >> key >>  separator >> value)
    {
        if (strcmp(key, name) == 0)
        {
            return value;
        }
    }

    return 0;
}
int getLine(char file[255],char a[255])
{
  char name[255];
  int aux;
  ifstream fin(file);
  for(int i=0;i<lines(file);i++)
  {
    fin.getline(name,255);
    for(int j=0;j<strlen(name);j++)
      if(name[j]==':')
        name[(j-1)]='\0';
    if(strcmp(name,a)==0)
      return i;
  }
}
int CFile(char file[255])
{
ofstream fff(file);
}
void doValue(char a[255],int value)
{
  for(int i=0;i<strlen(a);i++)
  {
    if(a[i]==':')
    {
      i--;
      a[i]='\0';
    }
  }
  char val[255];
  itoa(value,val,10);
  strcat(a," : ");
  strcat(a,val);
}
int chgValue(char file[255],char name[255],int value)
{
  fstream fin(file,ios::app|ios::in|ios::out);
  char setts[255][100];
  int f=lines(file);
  char aux[20];
  for(int i=0;i<lines(file);i++)
  {
    fin.getline(setts[i],255);
  }
  int a = getLine(file,name);
  doValue(setts[a],value);
  CFile(file);
  ofstream fout(file,ios::app);
  for(int i=0;i<f;i++)
  {
    fout<<setts[i]<<endl;
  }
}
