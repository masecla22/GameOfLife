
#include "structs.h"
using namespace std;

//main structure

int main() {
  chgValue("setts.inp","style",9);
  //Load Settings
  /**
  int style=getValue("setts.inp","style");
  int delay=getValue("setts.inp","speed");
  int stats=getValue("setts.inp","stats");
  int neigh=getValue("setts.inp","neigh");
  //Load Settings
  sGUI_1:
  int GUI_1=gui("New Game/Load Game/Settings/",1);
  if(GUI_1==2)
  {
    //Settings is pressed
    sGUI_12:
    int GUI_12 = gui("Grid Style/Generation Speed/Neighbouring/About/Back to Main Menu/");
    if(GUI_12==0)
    {
      system("cls");
      cout<<"Current grid style: "<<style<<endl;
      cout<<"Possible styles: "<<endl;
      cout<<"1. Using Binary. Dead 0 Alive 1"<<endl;
      cout<<"2. Pixels. Dead ";sendN();cout<<"Alive ";sendW();
      cout<<"\n3. Stars and spaces. Dead  Alive *"<<endl;
      cout<<"4. Plusses and minuses. Dead -- Alive ++"<<endl;
      cout<<"5. Reverted Pixels. Dead ";sendW();cout<<" Alive\n";
      int newOpt=0;
      cout<<"Input your option: ";
      cin>>newOpt;
    }
    if(GUI_12==2)
    {
      system("cls");
      cout<<"Thanks to all my pals who encouraged me to continue the development of this game."<<endl;
      cout<<"Thanks to Chervil over at cplusplus.com"<<endl;
      cout<<"Thanks to the teahcers who tought me C++"<<endl;
      cout<<"And thanks to YOU for playing this game!"<<endl;
      cout<<"\nPress any key to return to the settings..."<<endl;
      getch();
      system("cls");
      goto sGUI_12;
    }
    if(GUI_12==3)
    {
      goto sGUI_1;
    }
  }
  */
}
