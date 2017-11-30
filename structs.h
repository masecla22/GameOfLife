#include "settings.h"
using namespace std;
void genBGrid(char name[255], int size) {
  ofstream fout(name);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++)
    fout << 0 << " ";
    fout << endl;
  }
}
// FMA2-EDK2-PL21-DEP2
int tryCode(const char* a)
{
  int is=1;
  if(a[2]!='A')
    is=0;
  if(strlen(a)!=19)
    is=0;
  return is;
}
int checkB(int a[100][100],int b[100][100],int size)
{
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      if(a[i][j]!=b[i][j])
        return 0;
  return 1;
}

void sendW() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 240);
  cout << "  ";
  SetConsoleTextAttribute(hConsole, 7);
}
void sendWC(char char1,char char2,int color=0) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  if(color==1)
  SetConsoleTextAttribute(hConsole, 0);
  else
    SetConsoleTextAttribute(hConsole, color*16);
  cout <<char1<<char2;
  SetConsoleTextAttribute(hConsole, 7);
}
void sendWX()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 240);
  cout << "()";
  SetConsoleTextAttribute(hConsole, 7);
}
void sendN() {
  cout << "  ";
}
void sendNX() {
  cout<<"()";
}

//the thing that makes up every cell
struct cell {
  bool state;
};

struct grid {
  cell space[255][255];
  int size, style;
  int neigh;
  void sSwitch(int x, int y) {
    space[x][y].state = (space[x][y].state == 0);
  }
  int checkIf(int a)
  {
    for(int i=0;i<size;i++)
      if(space[a][i].state==1)
        return 1;
    return 0;
  }
  void showGrid(char chr1,char chr2) {
    if (style == 1) {
      for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
        {
            cout << space[x][y].state << ' ';
        }
        cout << endl;
      }
    }
    if (style == 2) {
      for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
          if (space[x][y].state == 0)
            sendN();
          else
            sendWC(chr1,chr2);
        }
        cout << endl;
      }
    }
    if (style == 3) {
      for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
          if (space[x][y].state == 0)
            cout<<"  ";
          else
            cout<<"*";
        }
        cout << endl;
      }
    }
    if (style == 4) {
        for (int y = 0; y < size; y++) {
          for (int x = 0; x < size; x++) {
            if (space[x][y].state == 0)
              cout<<"--";
            else
              cout<<"++";
          }
          cout << endl;
        }
      }
      if (style == 5) {
        for (int y = 0; y < size; y++) {
          for (int x = 0; x < size; x++) {
            if (space[x][y].state == 0)
              sendW();
            else
              sendN();
          }
          cout << endl;
        }
      }
  }

  int loadFrom(char a[255]) {
    ifstream fin(a);
    fin>>size;
    for (int y = 0; y < size; y++)
      for (int x = 0; x < size; x++)
        fin >> space[x][y].state;
    return size;
  }

  int getCell(int x, int y) {
    return space[x][y].state;
  }

  int getNeigh(int x, int y) {
    int howmany = 0;
    if (space[(x - 1)][y].state == 1 && x != 0 && neigh!=3)
      howmany++;
    if (space[(x-1)][(y-1)].state==1&&x!=0&&y!=0&&neigh!=2)
      howmany++;
    if (space[(x-1)][(y+1)].state==1&&x!=0&&y!=size&&neigh!=2)
      howmany++;
    if (space[(x)][(y - 1)].state == 1 && y != 0 && neigh!=3)
      howmany++;
    if (space[(x)][(y + 1)].state == 1 && y != size && neigh!=3)
      howmany++;
    if (space[(x + 1)][y].state == 1 && x != size && neigh!=3)
      howmany++;
    if (space[(x + 1)][(y + 1)].state == 1 && x != size && y != size && neigh!=2)
      howmany++;
    if (space[(x + 1)][(y - 1)].state == 1 && x != size && y != 0 && neigh!=2)
      howmany++;
    return howmany;
  }
  int showNGrid() {
    int s[100][100];
    for (int y = 0; y < size; y++)
      for (int x = 0; x < size; x++)
        s[x][y] = getNeigh(x, y);
    for (int y = 0; y < size; y++) {
      for (int x = 0; x < size; x++)
        cout << s[x][y] << " ";
      cout << endl;
    }
  }
  void nextStep() {
    int s[100][100];
    for (int y = 0; y < size; y++)
      for (int x = 0; x < size; x++)
        s[x][y] = getNeigh(x, y);
    for (int y = 0; y < size; y++)
      for (int x = 0; x < size; x++) {
        if (getCell(x, y) == 1) {
          if (s[x][y] > 3)
            sSwitch(x, y);
          if (s[x][y] < 2)
            sSwitch(x, y);
        } else {
          if (s[x][y] == 3)
            sSwitch(x, y);
        }
      }
  }
  void copyIn(int in[100][100])
  {
    for(int y=0;y<size;y++)
      for(int x=0;x<size;x++)
        in[x][y]=space[x][y].state;
  }
  /**
  void genFrom(char name[255],char from[2000])
  {

  }
  */
  int getAlive()
  {
    int num=0;
    for(int y=0;y<size;y++)
      for(int x=0;x<size;x++)
        if(space[x][y].state==1)
          num++;
    return num;
  }
};
void runGame(int styles,bool stats,int delays,char file[255],int neigh,int smg,char chr1=' ',char chr2=' ')
{
  grid thegrid;
  thegrid.size=thegrid.loadFrom(file);
  const int numofcells=thegrid.size*thegrid.size;
  thegrid.style=styles;
  thegrid.neigh=neigh;
  int a[100][100],s[100][100],prob=0,v=0,malive=0,tt=0;
  double delay=double(delays);
  while(2)
  {
    int x=thegrid.getAlive();
    if(x>malive)
    malive=x;
    if(stats==true)
    cout<<"Generation: "<<v<<"  Alive: "<<x<<"  Most Alive: "<<malive<<"  Dead: "<<numofcells-x<<"  Total: "<<numofcells<<"  SameGen: "<<prob<<endl;
    thegrid.copyIn(a);
    if(checkB(a,s,thegrid.size)==1)
    prob++;
    if(prob==smg)
    break;
    thegrid.showGrid(chr1,chr2);
    Sleep(delay);
    clear();
    thegrid.copyIn(s);
    thegrid.nextStep();
    v++;
    //Prevent residue
    if(v<2)
      system("cls");
    if(GetAsyncKeyState(0x45)!=0)
    {
      Sleep(500);
      if(GetAsyncKeyState(0x45)!=0)
      break;
    }
  }
  system("cls");
//  cout<<"Simulation terminated."<<endl;
}

void openEditor(char file[255],int size,bool bypass=0)
{
  int a[255][255];
  if(bypass==0)
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      a[i][j]=0;
  else
  {
  ifstream fin(file);
  int n;
  fin>>n;
  for(int y=0;y<size;y++)
    for(int x=0;x<size;x++)
      fin>>a[x][y];
    }
  int xpos,ypos;
  xpos=0;ypos=0;
  if(fexists(file)==1 && bypass==0)
  {
    cout<<"This file already exists!"<<endl;
  }
  else
  {
    clFile(file);
    ofstream fout(file,ios::app);
    system("cls");
    while(2)
    {
      cout<<"Press space to change the cells state, and enter to exit"<<endl;
      for(int y=0;y<size;y++)
      {
        for(int x=0;x<size;x++)
        {
          if(x==xpos && y==ypos)
            {
              if(a[x][y]==1)
                sendWX();
              else
                sendNX();
            }
          else
          {
            if(a[x][y]==1)
              sendW();
            else
              sendN();
          }
        }
      cout<<endl;
      }
      int f=getch();
      clear();
      if(f==32)
        a[xpos][ypos]=(a[xpos][ypos]==0);
      if(f==13)
      {
        clFile(file);
        fout<<size<<endl;
        for(int y=0;y<size;y++)
        {
          for(int x=0;x<size;x++)
            fout<<a[x][y]<<" ";
          fout<<endl;
        }
        break;
      }
      if(f==72 && ypos!=0)
        ypos--;
      if(f==80 && ypos!=size)
        ypos++;
      if(f==75 && xpos!=0)
        xpos--;
      if(f==77 && xpos!=size)
        xpos++;
      //32=spc 13=enterz
    }
  }
}
