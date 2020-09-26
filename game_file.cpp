//ROAD CHAMPION GAME
//FOP SEMESTER PROJECT
//BY USMAN ALI ABBASI 
//REQUIRED LIBRARIES
#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
using namespace std;
//PROTOTYPES OF USER DEFINED FUNCTIONS
void road(); // FUNCTION FOR MAKING ROAD 
void whitelines(); // FUNCTION FOR MAKING AND MOVING WHITE LINES IN ROAD
void traffic();// FUNCTION TO GENERATE TRAFFIC FROM OPPOSITE SIDE OF ROAD
void playercar();// FUNCTION FOR MAKING PLAYER'S CAR
void name();// FUNCTION FOR PLAYER NAME
void instructions();// FUNCTION FOR GAME PLAYING INSTRUCTIONS 
void mainmenu();// FUNCTION FOR MAKING MAIN MENU OF GAME
void gamestarting();// FUNCTION FOR STARTING GAME
int gameover();// FUNCTION FOR PRINTING GAME OVER AFTER COLLISION
void game();
//Global declaration of variables used in a game
// variables for moving white lines in a road
int page, m=-300; 
// for moving traffic on opposite side of road
float p, n=-50; 
// for moving player's car left and right
float x1=600, x2=685,x3=610,x4=670,x5=620,x6=660;
// for giving speed to player's car
float s=10;
// Switches characters input
char u;char c;
// for taking player's name in the start of the game
string x;

// Main function starts here
int main()
{
	name(); //user inputs name
	Start:
    mainmenu();  //displays main menu 
    char c; 
    cin>>c;
	
    switch(c)
    {
    // case for exiting the game
    	case 'E':
        case 'e':
{
	cout<<"Are you sure to quit the game?"<<endl;
	cout<<"Press y if you want to quit "<<endl;
	cout<<"Press n if you want to stay "<<endl;
	cin>>u;
	cout<<"";
	// further conditions for exiting
	switch(u)
	{
		// to exit
		case 'y':
			{
				system("cls");
				system("color e9");
				cout<<"\n\n\n\n\n\n\t\t\t\tTHANK YOU!";
				getch();
				break;
			}
		// to stay
		case 'n':
			{
				system("cls");
				goto Start;
				break;
			}
	} //inner switch ends here
}  //case e ends here

    	// for instructions of game
    	case 'I':
        case 'i':
        {
        	
        	instructions();// displays instructions if 'i' is pressed
        	
        	// provides key to go back to the mainmenu
        	char t;
			cin>>t;
			cout<<"";
			switch(t)
			{
			case 'g':
			case 'G':
			{
			system("cls");
			goto Start;
			}
			}//switch ends
        }
        
        // Game window opens if 'p' is pressed and game starts
        // GREEN WORLD
    	case 'G':
    	case 'g':
    	{
    		initwindow(1360,700,"CHAMPION");
    		// displays some important texts and sounds
    		gamestarting();
    		setbkcolor(BLACK);setcolor(GREEN);
	        settextstyle(BOLD_FONT, HORIZ_DIR,9);
	        outtextxy(400,290,"GREEN WORLD");
	        delay(1500);
	        cleardevice();
            setbkcolor(GREEN);
    	    game(); //game starts here
    	    break;
        }
        
        // BLUE WORLD
        case 'S':
        case 's':
        {
        	initwindow(1360,700,"CHAMPION");
    		// displays some important texts and sounds
    		gamestarting();
    		setbkcolor(BLACK);setcolor(BLUE);
	        settextstyle(BOLD_FONT, HORIZ_DIR,9);
	        outtextxy(400,290,"BLUE WORLD");
	        delay(1500);
	        cleardevice();
            setbkcolor(BLUE);
        	game(); //game starts here
        	break;
        }
        
        //RED WORLD
        case 'R':
        case 'r':
        {
        	initwindow(1360,700,"CHAMPION");
    		// displays some important texts and sounds
    		gamestarting();
    		setbkcolor(BLACK);setcolor(RED);
	        settextstyle(BOLD_FONT, HORIZ_DIR,9);
	        outtextxy(400,290,"RED WORLD");
	        delay(1500);
	        cleardevice();
            setbkcolor(RED);
        	game(); //game starts here
        	break;
		}
		
		// NIGHT DRIVE
		case 'N':
		case 'n':
		{
			initwindow(1360,700,"CHAMPION");
    		// displays some important texts and sounds
    		gamestarting();
    		setbkcolor(BLACK);setcolor(WHITE);
	        settextstyle(BOLD_FONT, HORIZ_DIR,9);
	        outtextxy(400,290,"NIGHT DRIVE");
	        delay(1500);
	        cleardevice();
            setbkcolor(BLACK);
        	game(); //game startshere
        	break;
		}
		
		//YELLOW WORLD
		case 'Y':
		case 'y':
		{
			initwindow(1360,700,"CHAMPION");
    		// displays some important texts and sounds
    		gamestarting();
    		setbkcolor(BLACK);setcolor(YELLOW);
	        settextstyle(BOLD_FONT, HORIZ_DIR,9);
	        outtextxy(400,290,"YELLOW WORLD");
	        delay(1500);
	        cleardevice();
            setbkcolor(YELLOW);
        	game();	//game starts here
        	break;
		}
		
		//BROWN WORLD
		case 'B':
		case 'b':
		{
			initwindow(1360,700,"CHAMPION");
    		// displays some important texts and sounds
    		gamestarting();
    		setbkcolor(BLACK);setcolor(BROWN);
	        settextstyle(BOLD_FONT, HORIZ_DIR,9);
	        outtextxy(400,290,"BROWN WORLD");
	        delay(1500);
	        cleardevice();
            setbkcolor(BROWN);
        	game(); //game starts here
        	break;
		}
        default: {
    	system("cls");
		goto Start;}
	}   //switch ends here
	
}  //main function ends here


// ALL OF USER DEFINED FUNCTIONS DEFINITION STARTS HERE

void name() // FUNCTION FOR PLAYER NAME
{
	system("color c7");
	cout<<"\n\n\n\n\n\n\t\t\t\tROAD CHAMPION";
	cout<<"\n\n\n\n\n\t\t\tCROSS THE TRAFFIC AND BE A CHAMPION";
	Sleep(5000);system("cls");
	system("color c7");
    cout<<"Enter your name..."<<endl;
    cin>>x;
}
void instructions() // FUNCTION FOR GAME PLAYING INSTRUCTIONS 
{
	system("cls");
	system("color c7");
	cout<<"\t\t\t\tGAME INSTRUCTIONS MENU";
	cout<<"\n\n\nHi! "<<x<<" Welcome to the instruction menu! \n";
    cout<<"\n\nWell! in this game you are given with your own car.";
    cout<<"All you need to do is to\nprotect your car from being";
    cout<<" collided with the cars coming from opposite side of\n";
    cout<<"the road. Use 'left' 'right' keys from the keyboard";
    cout<<" to control your car. If you\nhit the car from opposite";
    cout<<" side of the road, you'll loose.Scores will be awarded\n";
    cout<<"according to the time of playing the game. So, drive safe "<<x<<"!";
    cout<<"\n\nThank you!\n\n\n";
	cout<<"Press G to go to the main menu...\n\nPress any other key to start the game...";
}

void mainmenu() // FUNCTION FOR MAKING MAIN MENU OF GAME
{
	system("color c7");
	cout<<"\t\t\tWELCOME! "<<x<<" IN ROAD CHAMPION!\n\n\n";
    cout<<"YOU ARE NEEDED TO SEE THE INSTRUCTIONS BEFORE PLAYING THE GAME...\n\n";
	cout<<"Press I to see the instructions\n"<<endl;
    cout<<"Press the following buttons to choose game level"<<endl;
	cout<<"Press G to drive in green world\n"<<endl;
	cout<<"Press S to drive in Blue world\n"<<endl;
	cout<<"Press B to drive in Brown world\n"<<endl;
	cout<<"Press Y to drive in Yellow world\n"<<endl;
	cout<<"Press R to drive in red world\n"<<endl;
	cout<<"Press N to drive at night\n"<<endl;
	cout<<"\nPress E to quit the game\n"<<endl;
}

void gamestarting() // FUNCTION FOR STARTING GAME
{
	setcolor(BLACK);
	setbkcolor(RED);
	settextstyle(BOLD_FONT, HORIZ_DIR,6);
	outtextxy(310,280,"USMAN GAME PRESENTS");
	delay(3000);cleardevice();
	setcolor(CYAN);
	settextstyle(BOLD_FONT, HORIZ_DIR,10);
	outtextxy(250,290,"ROAD CHAMPION");
	delay(3000);
	cleardevice();
	
	rectangle(300,200,950,240);
    settextstyle(BOLD_FONT, HORIZ_DIR,8);
	outtextxy(410,100,"LOADING...");
	setbkcolor(BLUE);
	for(int i=0; i<=650; i+=2)//	LOADING BAR
	{
    line(300+i,200,300+i,240);
	line(301+i,200,301+i,240);
	delay(1);
	}
	delay(1500);
    cleardevice();
	settextstyle(BOLD_FONT, HORIZ_DIR,8);
	outtextxy(600,300,"3");
	settextstyle(BOLD_FONT, HORIZ_DIR,8);
	delay(1000);
	outtextxy(600,300,"2");
    settextstyle(BOLD_FONT, HORIZ_DIR,8);
	delay(1000);
	outtextxy(600,300,"1");
	delay(1000);   
    settextstyle(BOLD_FONT, HORIZ_DIR,8);
    outtextxy(500,300,"START!!!");
	delay(500);
	delay(1500);
}

void road() // FUNCTION FOR MAKING ROAD
{
	setcolor(WHITE);
	setfillstyle(1,DARKGRAY);
	rectangle(450,-1,850,800);
	floodfill(650,400,WHITE);
}

void whitelines() // FUNCTION FOR MAKING AND MOVING WHITE LINES IN ROAD
{
	setcolor(WHITE);
	
	for(int y=10; y<=800; y+=100) 
	{
	rectangle(570,0+y+m,590,50+y+m);
	setfillstyle(1,WHITE);
	rectangle(710,0+y+m,730,50+y+m);
	floodfill(580,30+y+m,WHITE);
	floodfill(720,20+y+m,WHITE);
    }
	m+=14;
	if(m>200)
	m=-300;
}

void traffic() // FUNCTION TO GENERATE TRAFFIC FROM OPPOSITE SIDE OF ROAD
{
	for(int p=1; p<20; p++)
	{
	for(int i=-1820; i<0; i+=650 )
	{
	setcolor(CYAN);
    setfillstyle(1,CYAN);
    rectangle(470,120+n+i,550,220+n+i);
    floodfill(500,200+n+i,CYAN);
    rectangle(480,220+n+i,540,250+n+i);
    floodfill(500,230+n+i,CYAN);
    }
    
    for(int k=-1750; k<0; k+=700){
    setcolor(BLUE);
    setfillstyle(1,BLUE);
    rectangle(610,350+n+k,690,450+n+k);
    floodfill(620,400+n+k,BLUE);
    rectangle(620,450+n+k,680,480+n+k);
    floodfill(630,460+n+k,BLUE);
	}
	
    for(int j=-1800; j<0; j+=750){
    setcolor(YELLOW);
    setfillstyle(1,YELLOW);
    rectangle(750,20+n+j,830,120+n+j);
    floodfill(800,50+n+j,YELLOW);
    rectangle(760,120+n+j,820,150+n+j);
    floodfill(800,130+n+j,YELLOW);
	}

    n+=0.4;
	if(n>2500) 
	n=-50;	
    }
}

void playercar() // FUNCTION FOR MAKING PLAYER'S CAR
{
	setcolor(RED);
    for(int i=530; i<=630; i++)
	line(x1,i,x2,i);
    setcolor(BLACK);
	for(int i=1; i<=5; i++)
	rectangle(x1-i,535-i,x2-i,635-i);
    line(x3,500,x3,535);
    line(x4,500,x4,535);
    for(int k=500; k<=503; k++)
	line(x3,k,x4,k);
    setcolor(RED);
	for(int k=503; k<=530; k++)
	line(x3+2,k,x4,k);
    setcolor(BLACK);
	pieslice(x2,560,270,90,13);//TYRES OF PLAYER CAR
	pieslice(x2,605,270,90,13);
    pieslice(x1,605,90,270,13);
	pieslice(x1,560,90,270,13);
}

int gameover() // FUNCTION FOR PRINTING GAME OVER AFTER COLLISION
{
	setcolor(WHITE);
    settextstyle(BOLD_FONT, HORIZ_DIR,8);
	outtextxy(400,100,"GAME OVER!!!");
	delay(100);
}


void game() // GAME STARTS IN THIS FUNCTION 
{
	
			
	
	// scores start counting 
	 int scores=0;
	 while(1)
	{
	setactivepage(page);
	setvisualpage(1-page);
	cleardevice();
	
	//Background color
	
	
	//DISPLAYS ROAD
	road();
	
	//DISPLAYS WHITE LINES
	whitelines();
	
	//DISPLAYS Trafic

    traffic();
	

    //DISPLAYS CAR  
    playercar();
    // MOVING PLAYER'S CAR WITH LEFT RIGHT KEYS WITHIN THE BOUNDARY OF THE ROAD
	setcolor(CYAN);
    settextstyle(BOLD_FONT, HORIZ_DIR,1);
	outtextxy(865,40,"Press right arrow key to move the car right");
    if(GetAsyncKeyState(VK_RIGHT))
    {
    	// condition for the car not to cross the 
		//boundary of road from right side...
    	if(x1<770 && x2<840 && x6<820)
    	{
		x1+=s;
       	x2+=s;
		x3+=s;
		x4+=s;
		x5+=s;
		x6+=s;
		}
        else x1+=0; 
		x2+=0;
    }
    setcolor(CYAN);
    settextstyle(BOLD_FONT, HORIZ_DIR,1);
	outtextxy(865,60,"Press left arrow key to move the car left");
	if(GetAsyncKeyState(VK_LEFT))
    {
    	// condition for the car not to cross the 
		//boundary of road from left side...
    	if(x1>450 && x2>540 && x5>480)
    	{
		x1-=s;
    	x2-=s;
		x3-=s;
		x4-=s;
		x5-=s;
		x6-=s;
		}
    	else x1-=0; 
		x2-=0;
    }
    
    // Assigning arrow up key to pause the game..
    setcolor(CYAN);
    settextstyle(BOLD_FONT, HORIZ_DIR,1);
	outtextxy(5,40,"Press arrow up key to pause the game");
    if(GetAsyncKeyState(VK_UP))
    {
    	system("pause");
    }
    setcolor(CYAN);
    settextstyle(BOLD_FONT, HORIZ_DIR,1);
	outtextxy(5,70,"Press arrow down key to quit the game");

    //Assigning arrow down key to quit the game window..
    if(GetAsyncKeyState(VK_DOWN))
    {
    	setcolor(WHITE);
	    delay(2000);
        closegraph();
    }
    // CONDITIONS FOR COLLISION OF PLAYERS CAR WITH TRAFFIC
    // IF COORDINATES MATCH THEN GAME IS OVER
     if(n>=775 && n<=990 && x3<=550 
	 || n>=1425 && n<=1690 && x3<=550 
	 || n>=2080 && n<=2330 && x3<=550) 
     {
     	    gameover();// calling game over function
			delay(3000);
			closegraph();
			system("cls");
			
     	    system("color e9");
			cout<<"\t\t******GAME OVER!!!*****\n\nYOUR SCORES:"<<scores;
			
	 }
	 
	 if(n>=655 && n<=910 && x4>=750 
	 || n>=1405 && n<=1660 && x4>=750 
	 || n>=2155 && n<=2410 && x4>=750) 
	 {
	 	    gameover();
			delay(3000);
			closegraph();
			system("cls");
	 	    system("color e9");
			cout<<"\t\t******GAME OVER!!!******\n\nYOUR SCORES:"<<scores;
			
		
	 }
	 
     if(n>=375 && n<=605 && x3>=560 && x3<=680 
	 || n>=1070 && n<=1325 && x3>=560 && x3<=680 
	 || n>=1775 && n<=2030 && x3>=560 && x3<=680 ) 
	 {
	 	    gameover();
			delay(3000);
			closegraph();
			system("cls");
	 	    system("color e9");
			cout<<"\t\t******GAME OVER!!!******\n\nYOUR SCORES:"<<scores;
			
			
	 }
	
	    // Everytime 2 is added in infinite while loop until collision
	    scores=scores+=2;
    } //while loop ends here
	
}
