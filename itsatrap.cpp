#include <cstdlib>
#include <iostream>          
/*******************************************************************/
/*  Developer  : Sebastian Carter                                  */
/*  Date       : 25/10/2017                                        */
/*  Title      : Battlestar Gatreckticka                           */
/*  Description: battleship game that has error correction for both*/
/*  out of bounds coordinates and previously used coordinates      */
/*******************************************************************/


using namespace std;

void printMatrix(int matrix[11][11])
{    
 //this makes it so the title will appear underlined and will be printed
 //every time printMatrix is used which is easier and neater than printing it
 //manually every screen
 cout<<"BATTLESTAR GATRECKTICA"<<endl;
 cout<<"--------------------------------------------------------------------------------"<<endl;                 
     for(int y=0;y<11;y++)
     {
             for(int x=0;x<11;x++)
             {
                     cout<<matrix[y][x]<<" ";
             }
             cout<<endl;
     }
}
     
int main(int argc, char *argv[])
{
 int deathstar, deathstarD, stardestroyer, stardestroyerD, corvette, corvetteD; 
 int starfighter, starfighterD, xaxis, yaxis, aD;  //all variables. D = destroyed    

//ship position grid
int mranderson[11][11] = {{0,1,2,3,4,5,6,7,8,9,10},
                          {1,14,0,0,0,0,0,0,0,0,0},
                          {2,14,0,0,0,0,0,0,0,12,0},
                          {3,14,0,0,0,0,0,0,0,12,0}, 
                          {4,14,0,0,0,0,0,0,0,0,0},
                          {5,0,0,0,0,0,0,0,0,0,0},
                          {6,0,0,0,0,11,0,0,0,0,0},
                          {7,0,0,0,0,0,0,0,0,0,0},
                          {8,0,0,0,0,13,13,13,0,0,0},
                          {9,0,0,0,0,0,0,0,0,0,0},
                          {10,0,0,0,0,0,0,0,0,0,0}};
//ship numbers are the amount of hitpoints the ship has + 10
//this stops the side and top numbers from being used

//player's grid
int neo[11][11] = {{0,1,2,3,4,5,6,7,8,9,1},  
                   {1,0,0,0,0,0,0,0,0,0,0},  //I changed the 10 to 1 as it 
                   {2,0,0,0,0,0,0,0,0,0,0},  //ruined the formating of the grid.
                   {3,0,0,0,0,0,0,0,0,0,0}, //as you can see in mranderson
                   {4,0,0,0,0,0,0,0,0,0,0},
                   {5,0,0,0,0,0,0,0,0,0,0},
                   {6,0,0,0,0,0,0,0,0,0,0},
                   {7,0,0,0,0,0,0,0,0,0,0},
                   {8,0,0,0,0,0,0,0,0,0,0},
                   {9,0,0,0,0,0,0,0,0,0,0},
                   {1,0,0,0,0,0,0,0,0,0,0}};

//this declares the ships and their hitpoints
deathstar = 0; //all ships starts at zero hits
deathstarD = 1; //when it is hit 1 time it will be destroyed
starfighter = 0;
starfighterD = 2; //when it is hit 2 times it will be destroyed
corvette = 0;
corvetteD = 3; //when it is hit 3 times it will be destroyed
stardestroyer = 0;
stardestroyerD = 4; //when it is hit 4 times it will be destroyed
aD = 0; //this variable is used to count the number of ships you have destroyed
//when aD == 4 it will end the game
//I wrote the code that utilises these variables further down through the code

//this is the starting sequence for the game and is designed to tell them key
//info about the ships they have to destroy.
cout<<"BATTLESTAR GATRECKTICA"<<endl; 
cout<<"--------------------------------------------------------------------------------"<<endl; 
cout<<"WELCOME TO BATTLESTAR GATRECKTICA"<<endl;                          
system("PAUSE");
system("cls");

cout<<"BATTLESTAR GATRECKTICA"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"THE SHIPS YOU WILL BE FACING:"<<endl;
system("PAUSE");
system("cls");

cout<<"BATTLESTAR GATRECKTICA"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"THE EMPIRIAL STAR DESTROYER - 4 HITPOINTS"<<endl;
system("PAUSE");
system("cls");

cout<<"BATTLESTAR GATRECKTICA"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"THE TANTIVE IV CORVETTE - 3 HITPOINTS"<<endl;
system("PAUSE");
system("cls");

cout<<"BATTLESTAR GATRECKTICA"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"THE REPUBLIC STARFIGHTER - 2 HITPOINTS"<<endl;
system("PAUSE");
system("cls");

cout<<"BATTLESTAR GATRECKTICA"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"THE DEATH STAR - 1 EXHAUST PORT"<<endl;	
system("PAUSE");
system("cls");

cout<<"GAME START"<<endl; //notifies user game is starting
system("PAUSE");
system("cls");
do{	//the main loop of game that lets user input more than one coordinate
  do{  ///loop for error correction when grid pos has already been chosen///////

//screen for user to input x value  
printMatrix(neo);
cout<<"Please input the x value of your targeting coordinates. "<<endl;
cin>>xaxis;
//after user has given x value error correction will run below
//error correction x//////////////////////////////////////////////////////////
//if xaxis is greater than or equal to 11 (outside of array)
//or xaxis is less than or equal to 0 (the reference numbers or outside array)
if(xaxis <= 0 || xaxis >= 11)
{
 do{ //loop only allows player to continue if correct coordinate is given//
 system("cls");// clears screen so new screen can be made
 
 printMatrix(neo); //shows grid
 cout<<"The input "<<xaxis<<" is invalid. Please input a valid x coordinate "<< 
 "to continue"<<endl; //lets user see which number they have entered
 cin>>xaxis; //player enters num
//only allows player to continue if correct coordinate is given//
   }while(xaxis <= 0 || xaxis >= 11);
}
///////////////////////////////////////////////////////////////////////////////

system("cls"); //clears last screen

//screen for user to input y axis
printMatrix(neo); //starts new screen again
cout<<"Please input the y value of your targeting coordinates. "<<endl;
cin>>yaxis;
//after user has input y value error correction will run below
//error correction y///////////////////////////////////////////////////////////
if(yaxis <= 0 || yaxis >= 11)
{
 do{  //loop only allows player to continue if correct coordinate is given//
 system("cls");
 
 printMatrix(neo);
 cout<<"The input "<<yaxis<<" is invalid. Please input a valid y coordinate "<< 
 "to continue"<<endl; // lets user see which number they had entered
 cin>>yaxis;
//only allows player to continue if correct coordinate is given//
   }while(yaxis <= 0 || yaxis >= 11);
}
///////////////////////////////////////////////////////////////////////////////

system("cls");

//error text when grid pos has already been chosen////////////////////////////
  if(neo[yaxis][xaxis] != 0) //if the coordinate has been used before
  {
   cout<<"BATTLESTAR GATRECKTICA"<<endl;
   cout<<"--------------------------------------------------------------------------------"<<endl;
   cout<<"You have chosen this coordinate before. Please try again."<<endl;
   system("PAUSE"); //allows user to see message before do while loop restarts
   system("cls"); //clears message before looping
  }
//////////////////////////////////////////////////////////////////////////////

////for error correction when grid pos has already been chosen///////
 }while(neo[yaxis][xaxis] != 0);
///////////////////////////////////////////////////////////////////////////////


//tells user their coordinates
printMatrix(neo);
cout<<"Your coordinates are "<<xaxis<<", "<<yaxis<<endl;
system("PAUSE");
system("cls");

///////////////////////////////////////////////////////////////////////////////
//for miss
///////////////////////////////////////////////////////////////////////////////

if(mranderson[yaxis][xaxis] == 0)//if target is 0 (does not have ship)
{
 neo[yaxis][xaxis] += 1; //add 1 to that pos on user array to symbolise miss
 printMatrix(neo);
 cout<<"You have missed."<<endl;
}
///////////////////////////////////////////////////////////////////////////////
//for hit
///////////////////////////////////////////////////////////////////////////////
if(mranderson[yaxis][xaxis] >= 11)//if target is >= 11(11 is smallest ship num)
{
 neo[yaxis][xaxis] += 8; //add 8 to pos on user array to symbolise hit
 printMatrix(neo);
 cout<<"Hit!"<<endl;
}

///////////////////////////////////////////////////////////////////////////////
//for deathstar (one space)
///////////////////////////////////////////////////////////////////////////////
if(mranderson[yaxis][xaxis] == 11)//if enemy ship is deathstar (11)
{
deathstar= deathstar + 1; //add one to ship hits

if(deathstar == deathstarD) //if ship hit val is = to ship max hits
  {
  cout<<"You have destroyed the Death Star. One in a million shot kid!"<<endl;
  aD += 1; //add one to ships destroyed
  }
}
///////////////////////////////////////////////////////////////////////////////
//for starfighter (2 spaces)
///////////////////////////////////////////////////////////////////////////////
if(mranderson[yaxis][xaxis] == 12)
{
starfighter= starfighter + 1;

if(starfighter == starfighterD)
  {
  cout<<"You have destroyed the starfighter"<<endl;
  aD += 1;
  }
}
///////////////////////////////////////////////////////////////////////////////
//for corvette (3 spaces)
///////////////////////////////////////////////////////////////////////////////
if(mranderson[yaxis][xaxis] == 13)
{
corvette= corvette + 1;

if(corvette == corvetteD)
  {
  cout<<"You have destroyed the corvette."<<endl;
  aD += 1;          
  }
}    
///////////////////////////////////////////////////////////////////////////////
//for star destroyer (4 spaces)
///////////////////////////////////////////////////////////////////////////////
if(mranderson[yaxis][xaxis] == 14)
{
stardestroyer= stardestroyer + 1;

if(stardestroyer == stardestroyerD)
 {   
  cout<<"You have destroyed the star destroyer."<<endl;
  aD += 1;
 }
}
 system("PAUSE");
 system("cls");
}while(aD != 4);

cout<<"You have won the game!"<<endl; 
cout<<"Good work Admiral."<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
