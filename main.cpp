
#include "structs.h"
using namespace std;

//main structure

int main() {
  //Load Settings
  int style=getValue("setts.inp","style");
  int delay=getValue("setts.inp","delay");
  int stats=getValue("setts.inp","stats");
  int neigh=getValue("setts.inp","neigh");
  //Load Settings
  sGUI_1:
  int GUI_1=gui("New Game/Load Game/Settings/",1);
  if(GUI_1==2)
  {
    //Settings is pressed
    sGUI_12:
    int GUI_12 = gui("Grid Style/Generation Speed/Neighbouring/Stats/About/Back to Main Menu/");
    //Styles
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
    //Speed
    if(GUI_12==1)
    {
      system("cls");
      cout<<"Current Delay speed: "<<delay<<endl;
      cout<<"Any number from 0 - 10000"<<endl;
      cout<<"Setting the number to 0 will run it as fast as it can"<<endl;
      cin>>delay;
      chgValue("setts.inp","delay",delay);
      delay=getValue("setts.inp","delay");
      system("cls");
      goto sGUI_12;
    }
    //Neighbouring
    if(GUI_12==2)
    {
      cout<<"There are 3 types of Neighbouring. Fully, Edged and Cornered."<<endl;
      cout<<"The Fully one checks all the cells around one cell"<<endl;
      cout<<"The Edged one will check only the edges of the cell"<<endl;
      cout<<"And the Cornered one check the corners. Here is a visalisation"<<endl;
      sendW();sendW();sendW();cout<<"      ";sendN();sendW();sendN();cout<<"      ";sendW();sendN();sendW();cout<<endl;
      sendW();cout<<"XX";sendW();cout<<"Fully ";sendW();cout<<"XX";sendW();cout<<"Edge  ";sendN();cout<<"XX";sendN();cout<<" Cornered"<<endl;
      sendW();sendW();sendW();cout<<"      ";sendN();sendW();sendN();cout<<"      ";sendW();sendN();sendW();cout<<endl;
      cout<<"Which one do you want? F=Fully, E=Edged, C=Cornered"<<endl;
      char choice;
      cin>>choice;
      int choice1=0;
      if(choice=="f"|| choice=="F")
      choice1=1;
      if(choice=="e"|| choice=="E")
      choice1=1;
      if(choice=="c"|| choice=="C")
      choice1=1;    
      
      chgValue("setts.inp","neigh",choice);
      neigh = getValue("setts.inp","neigh");
    }
    //Stats on or off
    if(GUI_12==3)
    {
      cout<<"This will display a small bar with stats about the game while running.";
      cout<<"Is it curently ";
      if(stats==1)
        cout<<"enabled.\n";
      else
        cout<<"disabled.\n";
      cout<<"Would you like to change it's state? (yes or no) ";
      char chgs;
      cin>>chgs;
      int ff;
      ff=stats;
      if(chgs=='y')
        ff=(ff==0);
      chgValue("setts.inp","stats",ff);
      stats = getValue("setts.inp","stats");
      system("cls");
      goto sGUI_12;
    }
    //About
    if(GUI_12==4)
    {
      system("cls");
      cout<<"Thanks to all my pals who encouraged me to continue the development of this game."<<endl;
      cout<<"Thanks to Chervil over at cplusplus.com"<<endl;
      cout<<"Thanks to the teahcers who taught me C++"<<endl;
      cout<<"And thanks to YOU for playing this game!"<<endl;
      cout<<"\nPress any key to return to the settings..."<<endl;
      getch();
      system("cls");
      goto sGUI_12;
    }
    if(GUI_12==5)
    {
      goto sGUI_1;
    }
  }
}
