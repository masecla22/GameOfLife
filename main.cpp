#include "structs.h"
using namespace std;
//main structure

/**
TO DO:
  -add a way to verify vip codes better DONE.
  -add something for vips.. they still don't have anything xDD

*/
int main() {
  //Load Settings
  int style = getValue("setts.inp", "style");
  int delay = getValue("setts.inp", "delay");
  int stats = getValue("setts.inp", "stats");
  int neigh = getValue("setts.inp", "neigh");
  int stag = getValue("setts.inp", "smg");
  //Load  VIP Settings
  int active = getValue("vips.inp","active");
  int chr1= getValue("vips.inp","char1");
  int chr2= getValue("vips.inp","char2");
  int color = getValue("vips.inp","color");
  //Hide the console cursor
  ShowConsoleCursor(false);
  int devmode=1;
  if(devmode==1)
  {
    system("title Welcome Matt! How are you doing today?");
    system("cls");
    cout<<"OPERATING SYSTEM:   "<<getOsName()<<endl;
    cout<<endl;
    cout<<"SCREEN RESOLUTION: "<<getRESX()<<"x"<<getRESY()<<endl;
cout<<endl;
    cout<<"HAS ADMIN RIGHTS: "<<" ?"<<endl;
cout<<endl;
    cout<<"BOOT MODE: ";wayBoot();
cout<<endl;
    cout<<"MONITORS: "<<howManyMonitors()<<endl;
cout<<endl;
    cout<<"CURSOR WIDTH: "<<getCursorWidth()<<endl;
  cout<<endl;
    cout<<"HAS MOUSE WHEEL: "<<mouseWheel()<<endl;
cout<<endl;
    cout<<"HAS MOUSE: "<<hasMouse()<<endl;
cout<<endl;
    cout<<"HAS A SLOW PROCESSOR: "<<isSlow()<<endl;
cout<<endl;
    cout<<"HAS STARTER WINDOWS: "<<hasStarterWindows()<<endl;
cout<<endl;
    cout<<"HAS CLICKS SWAPPED: "<<hasClicksSwapped()<<endl;
cout<<endl;
    cout<<"IS TABLET: "<<isTablet()<<endl;
cout<<endl;
    cout<<"MOUSE POS X: "<<getMouseX()<<" Y: "<<getMouseY()<<endl;
cout<<endl;
getch();
DEVGUI:
int a =gui("FORCE VIP(this session only)/DEACTIVATE VIP(this session only)/FORCE VIP(permanent)/DEACTIVATE VIP(permanent)/GO TO GAME/");
if(a==0)
{
  system("cls");
  cout<<"VIP ACTIVE!"<<endl;
  active=1;
  Sleep(1000);
  goto DEVGUI;
}
if(a==1)
{
  system("cls");
  cout<<"VIP DEACTIVATED!"<<endl;
  active=0;
  Sleep(1000);
  goto DEVGUI;
}
if(a==2)
{
  chgValue("vips.inp","active",1);
    cout<<"VIP ACTIVE!"<<endl;
  active = getValue("vips.inp","active");
  Sleep(1000);
  system("cls");
  goto DEVGUI;
}
if(a==3)
{
  chgValue("vips.inp","active",0);
    cout<<"VIP DEACTIVATED!"<<endl;
  active = getValue("vips.inp","active");
  Sleep(1000);
  system("cls");
  goto DEVGUI;
}
  }
  sGUI_1:
    int GUI_1 = gui("New Generation/Start a simulation/Edit a simulation/Settings/Exit/",1);
    if(GUI_1==0)//mega fast
    {
    cout<<"How would you like to name your save?"<<endl;
    char a[255];
    cin>>a;
    system("cls");
    cout<<"What should the size of the grid be?"<<endl;
    int size=0;
    cin>>size;
    strcat(a,".in");
    openEditor(a,size);
    system("cls");
    int aa=gui("Preview/Back to main menu/");
    if(aa==0&&active==0)
    runGame(style, (stats == 1), delay, a, neigh,stag);
    if(aa==0&&active==1)
    runGame(style, (stats == 1), delay, a, neigh,stag,chr1,chr2);
    system("cls");
    goto sGUI_1;
    }
    //lOAD GAME IS pressed
    if (GUI_1 == 1) {
      cout << "What is the name of the save? " << endl;
      char a[255];
      cin >> a;
      strcat(a, ".in");
      if(fexists(a))
      {
        thrun:
        if(active==0)
        runGame(style, (stats == 1), delay, a, neigh,stag);
        else
        runGame(style, (stats == 1), delay, a, neigh,stag,chr1,chr2);
        system("cls");
        int prev=gui("Run again/Back to main menu/");
        if(prev==0)
        goto thrun;
        goto sGUI_1;
        //void runGame(int theSize,int styles,bool stats,int delays,char file[255])
      }
      else
      {
        system("cls");
        cout<<"Save doesn't exist!"<<endl;
        Sleep(1000);
        system("cls");
        goto sGUI_1;
      }
      }
  //Edit Game is pressed
  if(GUI_1 ==2)
  {
    cout<<"Please enter the name of your save."<<endl;
    char a[255];
    cin>>a;
    strcat(a,".in");
    if(fexists(a)==0)
    {
      cout<<"An error occured. Maybe the save doesnt exist?\n Press any key to get back to the main menu"<<endl;
      getch();
      system("cls");
      goto sGUI_1;
    }
    else
    {
      ifstream fin(a);
      int sz;fin>>sz;
      openEditor(a,sz,true);
      cout<<"Your simulation was completed."<<endl;
      system("cls");
      Sleep(1000);
      int prev=gui("Preview/Back to main menu/");
      if(prev==0&&active==0)
        runGame(style, (stats == 1), delay, a, neigh,stag);
      if(prev==0&&active==1)
        runGame(style, (stats == 1), delay, a, neigh,stag,chr1,chr2);
      goto sGUI_1;
    }
  }
  if (GUI_1 == 3) {
    //Settings is pressed
    sGUI_12: int GUI_12 = gui("Grid Style/Generation Speed/Neighbouring/Stats/Stagnation/VIP Settings [WIP]/Changelog/About/Back to Main Menu/");
    //Styles
    if (GUI_12 == 0) {
      system("cls");
      cout << "Current grid style: " << style << endl;
      cout << "Possible styles: " << endl;
      cout << "1. Using Binary. Dead 0 Alive 1" << endl;
      cout << "2. Pixels. Dead ";
      sendN();
      cout << "Alive ";
      sendW();
      cout << "\n3. Stars and spaces. Dead  Alive *" << endl;
      cout << "4. Plusses and minuses. Dead -- Alive ++" << endl;
      cout << "5. Reverted Pixels. Dead ";
      sendW();
      cout << " Alive\n";
      int newOpt = 0;
      cout << "Input your option: ";
      cin >> newOpt;
      chgValue("setts.inp", "style", newOpt);
      style = getValue("setts.inp", "style");
      system("cls");
      goto sGUI_12;
    }
    //Speed
    if (GUI_12 == 1) {
      system("cls");
      cout << "Current Delay speed: " << delay << endl;
      cout << "Any number from 0 - 10000" << endl;
      cout << "Setting the number to 0 will run it as fast as it can" << endl;
      cin >> delay;
      chgValue("setts.inp", "delay", delay);
      delay = getValue("setts.inp", "delay");
      system("cls");
      goto sGUI_12;
    }
    //Neighbouring
    if (GUI_12 == 2) {
      cout << "There are 3 types of Neighbouring. Fully, Edged and Cornered." << endl;
      cout << "The Fully one checks all the cells around one cell" << endl;
      cout << "The Edged one will check only the edges of the cell" << endl;
      cout << "And the Cornered one check the corners. Here is a visalisation" << endl;
sendW();sendW();sendW();cout << "      ";sendN();sendW();sendN();cout << "      ";sendW();sendN();sendW();cout << endl;sendW();cout << "XX";sendW();
cout << "Fully ";sendW();cout << "XX";sendW();cout << "Edge  ";sendN();cout << "XX";sendN();cout << " Cornered" << endl;sendW();sendW();sendW();cout << "      ";sendN();sendW();sendN();cout << "      ";sendW();sendN();sendW();
      cout << endl;
      cout << "Which one do you want? F=Fully, E=Edged, C=Cornered" << endl;
      char choice;
      cin >> choice;
      int choice1 = 0;
      if (choice == 'f' || choice == 'F')
        choice1 = 1;
      if (choice == 'e' || choice == 'E')
        choice1 = 2;
      if (choice == 'c' || choice == 'C')
        choice1 = 3;
      chgValue("setts.inp", "neigh", choice1);
      neigh = getValue("setts.inp", "neigh");
      system("cls");
      goto sGUI_12;
    }
    //Stats on or off
    if (GUI_12 == 3) {
      cout << "This will display a small bar with stats about the game while running.";
      cout << "Is it curently ";
      if (stats == 1)
        cout << "enabled.\n";
      else
        cout << "disabled.\n";
      cout << "Would you like to change it's state? (yes or no) ";
      char chgs[5];
      cin >> chgs;
      int ff;
      ff = stats;
      if (chgs[0] == 'y')
        ff = (ff == 0);
      chgValue("setts.inp", "stats", ff);
      stats = getValue("setts.inp", "stats");
      system("cls");
      goto sGUI_12;
    }
    //Stagnation
    if(GUI_12==4){
      system("cls");
      int sms;
      cout<<"Stagnation means after how many identical generations should we stop the simulation?"<<endl;
      cout<<"Its currently: "<<stag<<endl;
      cout<<"Set it to -1 to never stop the simulation."<<endl;
      cout<<"Input: ";
      cin>>sms;
      chgValue("setts.inp","smg",sms);
      stag = getValue("setts.inp","smg");
      system("cls");
      goto sGUI_12;
    }


/**

    THE VIP SETTINGS.
    VERY IMPORTANT SHIT

*/
    if(GUI_12==5)
    {
      if(active==0)
      {
        system("cls");
        cout<<"I am deeply sorry for this message but it seems you don't have VIP."<<endl;
        cout<<"We made VIP so that you could play the game without feeling the need for it"<<endl;
        cout<<"but it would be appreciated to get it :D"<<endl;
        char code[255];
        cout<<"CODE: ";
        cin>>code;
        if(tryCode(code))
        {
        cout<<"We thank you deeply for buying the VIP features...\nHave a great day :D"<<endl;
        chgValue("vips.inp","active",1);
        active = getValue("vips.inp","active");
        Sleep(1000);
        system("cls");
        goto sGUI_1;
        }
        else
        {
          cout<<"Are you sure you haven't misread your code?"<<endl;
          Sleep(1000);
          system("cls");
          goto sGUI_1;
        }
      }
      else
      {
        int VIPGUI=gui("Customise cells/Blackground Color/Placeholder/Exit/");
        if (VIPGUI==0) {
          system("cls");
          cout<<"This allows you change the way your cell looks. You can change this to add letter in the cell. This only works on \nthe pixel style.\nYour current cell is: ";
          sendWC(chr1,chr2);
          cout<<endl;
          cout<<"Type the 2 charaters that will compose (type DEFAULT to return to 2 spaces) your cell: ";
          char a[2];
          while(strlen(a)!=2)
          cin>>a;
          if(strcmp(a,"DEFAULT")==0)
          strcpy(a,"  ");
          chgValue("vips.inp","char1",int(a[0]));
          chgValue("vips.inp","char2",int(a[1]));
          chr1=a[0];
          chr2=a[1];
          system("cls");
          goto sGUI_1;
      }
      if(VIPGUI==1)
      {
        cout<<"This will allow you to change the background color of alive cells.\nPress any key get to the menu."<<endl;
        getch();
        system("cls");
        int thecolor=gui("Black/Blue/Green/Aqua/Red/Magenta/Yellow/Light Gray/Gray/Light Blue/Light Green/Light Aqua/Light Red/Light Pink/Light Yellow/White/Back");
        chgValue("vips.inp","color",thecolor);
        color=thecolor;
      }
        if(VIPGUI==3)
        {
          system("cls");
          goto sGUI_1;
        }
























      }
    }
    //Changelog
    if(GUI_12==6){
      cout<<"Press any key to read the next log. Press E to go back to main menu"<<endl;
      int howmany = 22;
      for(int i=1;i<=(howmany+1);i++)
      {
      int a = getch();
      if(a==101)
      {
        system("cls");
        goto sGUI_12;
      }
      else
      {
        switch(i){
        case 1:
        cout<<"1.0 Created a basic game. Only input from files.\n Only style was with stars."<<endl;break;
        case 2:
        cout<<"1.1 Added some core functionality as well as some graphical things (cells with ++ and --)"<<endl;break;
        case 3:
        cout<<"1.2 Modified the clear() function of the game. Screen stops blinking"<<endl;break;
        case 4:
        cout<<"1.3 Fixed a major logic error, in which all cells would have died"<<endl;break;
        case 5:
        cout<<"1.4 ADDED GUIs! The game looks a lot better now. (WIP)"<<endl;break;
        case 6:
        cout<<"1.4.1 Implemented all the core functionality into the new GUI system!"<<endl;break;
        case 7:
        cout<<"1.5 Fixed small bugs with the GUI options leading the wrong way."<<endl;break;
        case 8:
        cout<<"1.6 Added the ability to change the style of the cells! (only style 1,2,3)"<<endl;break;
        case 9:
        cout<<"1.7 BIG UPDATE!\n Realised a library for the ability to save settings in files"<<endl;break;
        case 10:
        cout<<"1.8 SETTINGS UPDATE!\n You can now customise: generation speed, cornering, stats showing and added some more styles"<<endl;break;
        case 11:
        cout<<"1.9 Fixed minor bugs here and there, did some code cleanup."<<endl;break;
        case 12:
        cout<<"2.0 Yeah!!! Finally added in that sweet SWEET editor for making new games!"<<endl;break;
        case 13:
        cout<<"2.1 Added the abilty to use Edit Game. Uses the embedded editor :D"<<endl;break;
        case 14:
        cout<<"2.2 Added this changelog."<<endl;break;
        case 15:
        cout<<"2.3 Added scrolling on the changelog!"<<endl;break;
        case 16:
        cout<<"2.4 Fixed the bug in which the stats the settings would crash if you gave the program anything other than y or n"<<endl;break;
        case 17:
        cout<<"2.5 Did a small thing that is super useful! In the GUIs if you press UP and you are at the top of the list, it will send you at the bottom of the list"<<endl;break;
        case 18:
        cout<<"2.6 Added stagnation. [WIP] ATM"<<endl;break;
        case 19:
        cout<<"2.7 Completely implemented stagnation. [WIP] tag removed"<<endl;break;
        case 20:
        cout<<"2.8 I have finally implemented the abilty to stop an infinitely going game by pressing E. You need to hold it for half a second to stop the simulation! \n  *lovely note for nerds*I have managed to finally figure out how to use GetAsyncKeyState which is just lovely!"<<endl;break;
        case 21:
        cout<<"2.8.1 Also managed after scavaging the windows.h library and found a way to hide the little blinking white thing on the screen! This will make the editor much nicer to use!"<<endl;break;
        case 22:
        cout<<"2.8.2 And obviously the last update went horribly wrong. Fixed it. Now resizing the screen won't make the little thing reappear."<<endl;break;
        default:system("cls");goto sGUI_12;
      }}}}
      //About
    if (GUI_12==7) {system("cls");
      cout << "Thanks to all my pals who encouraged me to continue the development of this game." << endl;
      cout << "Thanks to Chervil over at cplusplus.com" << endl;
      cout << "Thanks to the teahcers who taught me C++" << endl;
      cout << "And thanks to YOU for playing this game!" << endl;
      cout << "\nPress any key to return to the settings..." << endl;
      getch();
      system("cls");
      goto sGUI_12;}
    //back to main Menu
    if (GUI_12 == 8) {goto sGUI_1;}}}
