#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<conio.h>
using namespace std;
void MainMenu();
void PlayGame();
void Instructions();
void Credits();
void Score();
void WinningCondition();
void LoseCondition();
void DrawCondition();
bool PlayerTurn1();
bool PlayerTurn2();
bool MachineTurn();
bool TossPlayerVSPlayer(bool X1, bool X2);
bool TossPlayerVSMachine(bool X3, bool X4);
void PlayerVSPlayer(bool a, bool b);
void PlayerVSMachine(bool c, bool d);
int P1=0, P2=0, GD=0;
int GS=0;
char ARR1[3][3];

                            // int Main Function
int main()

{
	MainMenu();            //MainMenu Function Call
}

void MainMenu()            //Main Menu Definition
{
	GS=0;
	int MenuInput;
	cout<<"        Main Menu       "<<endl;
	
	cout<<"Press 1 for play game"<<endl;
	cout<<"Press 2 for Score"<<endl;
	cout<<"Press 3 for instructions"<<endl;
	cout<<"Press 4 for credits"<<endl;
	cout<<"Press 5 to exit"<<endl;
	cin>>MenuInput;
	
	if(MenuInput==1)
		{
			for(int i=0; i<3; i++)
			{
				for(int j=0; j<3; j++)
				{
					ARR1[i][j]=' ';
				}
			}
			PlayGame();             //Play Game Call
		}
		else if(MenuInput==2)
		{
			Score();              //Score Function Call
		}
		else if(MenuInput==3)
		{
			Instructions();        //Instruction Function Call
		}
		 else if(MenuInput==4)
		{
			Credits();             //Credits Function Call
		}
		else if(MenuInput==5)
		{
			exit(0);
		}
}
void Score()                   //Score Function Definition
{
	
	
	cout<<"Score of player 1 is : "<<P1<<endl;
	cout<<"Score of player 2 is : "<<P2<<endl;
	cout<<"The draw games are: "<<GD<<endl;
	getch();
	system("cls");
	MainMenu();
}

void PlayGame()                 //Play Game Function Definition
{
	bool PL1, PL2;
	int PlayGameInput;
	cout<<"Enter 1 for Player VS Player and 2 for Player VS Machine"<<endl;
	cin>>PlayGameInput;
	
	switch(PlayGameInput)
	{
		case 1:
			TossPlayerVSPlayer(PL1, PL2);       //TossPlayerVSPlayer Funtion Call
			
			break;
			
		case 2:
			TossPlayerVSMachine(PL1, PL2);      //TossPlayerVSMachine Call
			
			break;
	}
}
void Credits()                        //Credits Function Definition
{
	cout<<"This is a Tic Tac Toe game which is developed by a first semester student of FAST National University of Computer and Emerging Sciences.\nThe name of developer is MURAD HAMEED\nAll rights resevered\nCopyright 2021";
	getch();
	system("cls");
	MainMenu();
}
void Instructions()                  //Instruction Function Call
{
	cout<<"It is a two player game.\nAll you have to do is be the one who get three in a row on a 3 by 3 board.\nYou have to place crosses or noughts on the board."<<endl;
	getch();
	system("cls");
	MainMenu(); 
}
void PlayerVSPlayer(bool a, bool b)      //PlayerVSPlayer Funtion Definition
{
	cout<<"\n\n\nPlayer 1 has to put X"<<endl;
	cout<<"PLayer 2 has to put O"<<endl;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
		    if(a==true)
	        {
	    	    PlayerTurn1();         //Player Turn 1 Function Call
	    	    a=false;
    	    	b=true;
	        } 
            else if(b==true)
            {
    	        PlayerTurn2();        //Player Turn 2 Function Call
	        	b=false;
	        	a=true;
	        }
		}
	}
	
}
 bool TossPlayerVSPlayer(bool X1, bool X2)     //TossPlayerVSPlayer Function Definition
{
	
	int TossNumber= rand()%2+1;
		if(TossNumber%2==0)
		{
			cout<<"\t\tPlayer 1 won the toss"<<endl;
			
			X1=true;
		    X2=false;
		    PlayerVSPlayer(X1, X2);         //PlayerVSPlayer Function Call
	
		}
		else
		{
			cout<<"\t\tPlayer 2 won the toss"<<endl;
			
		 	X1=false;
		    X2=true;
		PlayerVSPlayer(X1, X2);          //PlayerVSPLayer Function Call
		}
}
	

bool PlayerTurn1()                    //PlayerTurn1 Call
{
	   int r, c;
	   cout<<endl<<"\t\tPlayer 1 turn"<<endl;
	   do
	   {
	       cout<<endl<<"Enter the row in which you want to place X"<<endl;
	       cin>>r;
	       cout<<"Enter the column in which you want to place X"<<endl;
    	   cin>>c;
    	   if(ARR1[r-1][c-1]=='X' || ARR1[r-1][c-1]=='O')
    	   {
    	    	cout<<"Your input is already placed please enter again"<<endl;
    	   }
    	   else 
	   {
	   	GS++;
	   }
	   }
	   while(ARR1[r-1][c-1]=='X' || ARR1[r-1][c-1]=='O');
	   
	   ARR1[r-1][c-1]='X';  
	  
	   for(int i=0; i<3; i++)   // Displaying Board
	   {
	     	for(int j=0; j<3; j++)
	   		{   
	   		    
	   		    cout<<setw(5)<<ARR1[i][j];
	   		    if(j==0||j==1)
	   	    	{
	   		    	cout<<"|";
			    }
	   	    }
	   	    if(i==2)
	   	    {
	   	    	continue;
			}
	   	    cout<<endl<<setw(5)<<"  ---|-----|---"<<endl;
		}
		WinningCondition();                 //Winning Condition Function Call
}
bool PlayerTurn2()                    //PlayerTurn2 Funtion Definition
{
		cout<<endl<<"\t\tPlayer 2 turn"<<endl;
	   int r, c;
	   do
	   {
	   cout<<endl<<"Enter the row in which you want to place O"<<endl;
	   cin>>r;
	   cout<<"Enter the column in which you want to place O"<<endl;
	   cin>>c;
	   
	   if(ARR1[r-1][c-1]=='X'||ARR1[r-1][c-1]=='O')
	   {
	   	cout<<"Your input is already placed please enter again"<<endl;
	   }
	   else 
	   {
	   	GS++;
	   }
	   }
	   while(ARR1[r-1][c-1]=='X'||ARR1[r-1][c-1]=='O');
	   
	   ARR1[r-1][c-1]='O';  
	  
	   for(int i=0; i<3; i++)
	   {
	     	for(int j=0; j<3; j++)
	   		{   
	   		cout<<setw(5)<<ARR1[i][j];
	   		if(j==0||j==1)
	   		{
	   			cout<<"|";
			   }
	   	    }
	   	    
	   	    if(i==2)
	   	    {
	   	    	continue;
			}
	   	    cout<<endl<<setw(5)<<"  ---|-----|---"<<endl;
		} 
	   
}
void WinningCondition()                     //Winning Condition Function Definition
{
		if((ARR1[0][0]=='X' && ARR1[0][1]=='X' && ARR1[0][2]=='X') || (ARR1[1][0]=='X' && ARR1[1][1]=='X' && ARR1[1][2]=='X') || (ARR1[2][0]=='X' && ARR1[2][1]=='X' && ARR1[2][2]=='X') || (ARR1[0][0]=='X' && ARR1[1][0]=='X' && ARR1[2][0]=='X')|| (ARR1[0][1]=='X' && ARR1[1][1]=='X' && ARR1[2][1]=='X')|| (ARR1[0][2]=='X' && ARR1[1][2]=='X' && ARR1[2][2]=='X')|| (ARR1[0][0]=='X' && ARR1[1][1]=='X' && ARR1[2][2]=='X'))
		{
			cout<<endl<<"\t\tPlayer 1 wins"<<endl;
			P1+=1;
		
		}
		
		if((ARR1[0][0]=='O' && ARR1[0][1]=='O' && ARR1[0][2]=='O') || (ARR1[1][0]=='O' && ARR1[1][1]=='O' && ARR1[1][2]=='O') || (ARR1[2][0]=='O' && ARR1[2][1]=='O' && ARR1[2][2]=='O') || (ARR1[0][0]=='O' && ARR1[1][0]=='O' && ARR1[2][0]=='O')|| (ARR1[0][1]=='O' && ARR1[1][1]=='O' && ARR1[2][1]=='O')|| (ARR1[0][2]=='O' && ARR1[1][2]=='O' && ARR1[2][2]=='O')|| (ARR1[0][0]=='O' && ARR1[1][1]=='O' && ARR1[2][2]=='O'))
		{
			cout<<endl<<"\t\tPlayer 2 wins"<<endl;
			P2+=1;
		
		}
		
	LoseCondition();                 //Lose Condition Function Call
}
void LoseCondition()           //Lose Condition Function Definition
{
			if((ARR1[0][0]=='X' && ARR1[0][1]=='X' && ARR1[0][2]=='X') || (ARR1[1][0]=='X' && ARR1[1][1]=='X' && ARR1[1][2]=='X') || (ARR1[2][0]=='X' && ARR1[2][1]=='X' && ARR1[2][2]=='X') || (ARR1[0][0]=='X' && ARR1[1][0]=='X' && ARR1[2][0]=='X')|| (ARR1[0][1]=='X' && ARR1[1][1]=='X' && ARR1[2][1]=='X')|| (ARR1[0][2]=='X' && ARR1[1][2]=='X' && ARR1[2][2]=='X')|| (ARR1[0][0]=='X' && ARR1[1][1]=='X' && ARR1[2][2]=='X'))
		{
			cout<<endl<<"\t\tPlayer 2 lose"<<endl;
			getch();
			system("cls");
			MainMenu();
		}
		
		if((ARR1[0][0]=='O' && ARR1[0][1]=='O' && ARR1[0][2]=='O') || (ARR1[1][0]=='O' && ARR1[1][1]=='O' && ARR1[1][2]=='O') || (ARR1[2][0]=='O' && ARR1[2][1]=='O' && ARR1[2][2]=='O') || (ARR1[0][0]=='O' && ARR1[1][0]=='O' && ARR1[2][0]=='O')|| (ARR1[0][1]=='O' && ARR1[1][1]=='O' && ARR1[2][1]=='O')|| (ARR1[0][2]=='O' && ARR1[1][2]=='O' && ARR1[2][2]=='O')|| (ARR1[0][0]=='O' && ARR1[1][1]=='O' && ARR1[2][2]=='O'))
		{
			cout<<endl<<"\t\tPlayer 1 lose"<<endl;
			getch();
			system("cls");
			MainMenu();
	    }

        if(GS==9)
		{
				DrawCondition();
		}
}
void DrawCondition()              //Draw Condition Definition
{
	cout<<"\n\nThe game has been drawn"<<endl;
	GD++;
	GS=0;
	getch();
	system("cls");
	MainMenu();
}

 bool TossPlayerVSMachine(bool X3, bool X4)     //Toss PlayerVSMachine Definition
{
	
	int TossNumber= rand()%2+1;
		if(TossNumber%2==0)
		{
			cout<<"\t\tPlayer 1 won the toss"<<endl;
			
			X3=true;
		    X4=false;
		    PlayerVSMachine(X3, X4);  //PlayerVSMachine Call
	
		}
		else
		{
			cout<<"\t\tPlayer 2 won the toss"<<endl;
			
		 	X3=false;
		    X4=true;
		PlayerVSMachine(X3, X4);       //PlayerVSMachine Call
		}
}

void PlayerVSMachine(bool c, bool d)       //PlayerVSMachine Definition
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
		    if(c==true)
	        {
	    	    PlayerTurn1();          //PlayerTurn1 function Call
	    	    c=false;
    	    	d=true;
	        } 
            else if(d==true)
            {
    	        MachineTurn();          //MachineTurn function Call
	        	d=false;
	        	c=true;
	        }
		}
	}
}

bool MachineTurn()          //MachineTurn Function Definition
{
	int r,c;
	cout<<endl<<"\t\tPlayer 2 turn"<<endl;
	 do
	   {
	      r=rand()%3+1;
	      c=rand()%3+1;
	   
	   if(ARR1[r-1][c-1]=='X'||ARR1[r-1][c-1]=='O')
	   {
	   }
	   }
	   while(ARR1[r-1][c-1]=='X'||ARR1[r-1][c-1]=='O');
	   
	   ARR1[r-1][c-1]='O';  
	  
	   for(int i=0; i<3; i++)
	   {
	     	for(int j=0; j<3; j++)
	   		{   
	   		cout<<setw(5)<<ARR1[i][j];
	   		if(j==0||j==1)
	   		{
	   			cout<<"|";
			   }
	   	    }
	   	    
	   	    if(i==2)
	   	    {
	   	    	continue;
			}
	   	    cout<<endl<<setw(5)<<"  ---|-----|---"<<endl;
		} 
	   
}
