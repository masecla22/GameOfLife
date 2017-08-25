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
void sendN() {
  cout << "  ";
}

//the thing that makes up every cell
struct cell {
  bool state;
};

struct grid {
  cell space[255][255];
  int size, style;
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
  void showGrid() {
    if (style == 1) {
      for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            cout << space[x][y].state << ' ';
        cout << endl;
      }
    }
    if (style == 2) {
      for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
          if (space[x][y].state == 0)
            sendN();
          else
            sendW();
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

  void loadFrom(char a[255]) {
    ifstream fin(a);
    for (int y = 0; y < size; y++)
      for (int x = 0; x < size; x++)
        fin >> space[x][y].state;
  }

  int getCell(int x, int y) {
    return space[x][y].state;
  }

  int getNeigh(int x, int y) {
    int howmany = 0;
    if (space[(x - 1)][y].state == 1 && x != 0)
      howmany++;
    if (space[(x - 1)][(y - 1)].state == 1 && x != 0 && y != 0)
      howmany++;
    if (space[(x - 1)][(y + 1)].state == 1 && x != 0 && y != size)
      howmany++;
    if (space[(x)][(y - 1)].state == 1 && y != 0)
      howmany++;
    if (space[(x)][(y + 1)].state == 1 && y != size)
      howmany++;
    if (space[(x + 1)][y].state == 1 && x != size)
      howmany++;
    if (space[(x + 1)][(y + 1)].state == 1 && x != size && y != size)
      howmany++;
    if (space[(x + 1)][(y - 1)].state == 1 && x != size && y != 0)
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
void runGame(int theSize,int styles,bool stats,int delays,char file[255])
{
  grid thegrid;
  thegrid.size = theSize;
  const int numofcells=thegrid.size*thegrid.size;
  thegrid.loadFrom("inp.in");
  thegrid.style=styles;
  int a[100][100],s[100][100],prob=0,v=0,malive=0,tt=0;
  double delay=double(delays);
  while(2)
  {
    int x=thegrid.getAlive();
    if(x>malive)
    malive=x;
    if(stats==1)
    cout<<"Generation: "<<v<<"  Alive: "<<x<<"  Most Alive: "<<malive<<"  Dead: "<<numofcells-x<<"  Total: "<<numofcells<<"  SameGen: "<<prob<<"  Speed: "<<tt/v<<" gens/second  "<<endl;
    thegrid.copyIn(a);
    if(checkB(a,s,thegrid.size)==1)
    prob++;
    if(prob==9)
    break;
    thegrid.showGrid();
    Sleep(delay);
    clear();
    thegrid.copyIn(s);
    thegrid.nextStep();
    v++;
  }
  cout<<"Simulation terminated."<<endl;
}
