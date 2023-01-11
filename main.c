/*
	Program 2: Wumpus, version 2
  Course: CS 211, Fall 2022
  System: Mac using Visual Studio Code
  Author: Muhammad Muzzammil
  Date of submission: October 8, 2022
  Ned ID: mmuzza3
  UIN#: 661657007
  ---------------------------------------------

*/




#include <stdio.h> // input/output related functions in our program
#include <stdlib.h> // contains information of memory allocation/freeing functions
#include <time.h> // contains time and date function declarations
#include <stdbool.h> // allows the use of boolian
#include <ctype.h> // declares several functions that are useful for testing


// Prints the displays of the cave
void displayCave()
{
    printf( "\n       ______18______             \n"
    		"      /      |       \\           \n"
    		"     /      _9__      \\          \n"
    		"    /      /    \\      \\        \n"
    		"   /      /      \\      \\       \n"
    		"  17     8        10     19       \n"
    		"  | \\   / \\      /  \\   / |    \n"
    		"  |  \\ /   \\    /    \\ /  |    \n"
    		"  |   7     1---2     11  |       \n"
    		"  |   |    /     \\    |   |      \n"
    		"  |   6----5     3---12   |       \n"
    		"  |   |     \\   /     |   |      \n"
    		"  |   \\       4      /    |      \n"
    		"  |    \\      |     /     |      \n"
    		"  \\     15---14---13     /       \n"
    		"   \\   /            \\   /       \n"
    		"    \\ /              \\ /        \n"
    		"    16---------------20           \n"
    		"\n");
}
//----------End of displayCave()----------

// Instructions for the game
void displayInstructions()
{
    printf( "Hunt the Wumpus:                                             \n"
    		"The Wumpus lives in a completely dark cave of 20 rooms. Each \n"
    		"room has 3 tunnels leading to other rooms.                   \n"
    		"                                                             \n"
    		"Hazards:                                                     \n"
        	"1. Two rooms have bottomless pits in them.  If you go there you fall and die.   \n"
        	"2. Two other rooms have super-bats.  If you go there, the bats grab you and     \n"
        	"   fly you to some random room, which could be troublesome.  Then those bats go \n"
        	"   to a new room different from where they came from and from the other bats.   \n"
    		"3. The Wumpus is not bothered by the pits or bats, as he has sucker feet and    \n"
        	"   is too heavy for bats to lift.  Usually he is asleep.  Two things wake       \n"
        	"    him up: Anytime you shoot an arrow, or you entering his room.  The Wumpus   \n"
        	"    will move into the lowest-numbered adjacent room anytime you shoot an arrow.\n"
        	"    When you move into the Wumpus' room, then he wakes and moves if he is in an \n"
        	"    odd-numbered room, but stays still otherwise.  After that, if he is in your \n"
        	"    room, he snaps your neck and you die!                                       \n"
        	"                                                                                \n"
        	"Moves:                                                                          \n"
        	"On each move you can do the following, where input can be upper or lower-case:  \n"
        	"1. Move into an adjacent room.  To move enter 'M' followed by a space and       \n"
        	"   then a room number.                                                          \n"
        	"2. Shoot your guided arrow through a list of up to three adjacent rooms, which  \n"
        	"   you specify.  Your arrow ends up in the final room.                          \n"
        	"   To shoot enter 'S' followed by the number of rooms (1..3), and then the      \n"
        	"   list of the desired number (up to 3) of adjacent room numbers, separated     \n"
        	"   by spaces. If an arrow can't go a direction because there is no connecting   \n"
        	"   tunnel, it ricochets and moves to the lowest-numbered adjacent room and      \n"
        	"   continues doing this until it has traveled the designated number of rooms.   \n"
        	"   If the arrow hits the Wumpus, you win! If the arrow hits you, you lose. You  \n"
        	"   automatically pick up the arrow if you go through a room with the arrow in   \n"
        	"   it.                                                                          \n"
        	"3. Enter 'R' to reset the person and hazard locations, useful for testing.      \n"
        	"4. Enter 'C' to cheat and display current board positions.                      \n"
        	"5. Enter 'D' to display this set of instructions.                               \n"
        	"6. Enter 'P' to print the maze room layout.                                     \n"
        	"7. Enter 'X' to exit the game.                                                  \n"
        	"                                                                                \n"
        	"Good luck!                                                                      \n"
        	" \n\n");
}//end displayInstructions()
//----------End of displayInstructions()---------


// function Searches the array to find the player's room number
// recieves room array as a parameter where the location is saved of the player
// returns integer value: player's room number
int whereIsThePlayer(int room[])
{
  int saveRoomNumber;
  for(int i=0; i<20; i++){
    if(room[i] == 'l'){
      saveRoomNumber = i + 1;
      break;
    }
  }
  return(saveRoomNumber);
}
//----------End of whereIsThePlayer()---------

int whereIsBatOne(int room[])
{
  int saveRoomNumber;
  for(int i=0; i<20; i++){
    if(room[i] == 'b'){
      saveRoomNumber = i + 1;
      break;
    }
  }
  return(saveRoomNumber);
}


int whereIsBatTwo(int room[])
{
  int saveRoomNumber;
  for(int i=0; i<20; i++){
    if(room[i] == 'y'){
      saveRoomNumber = i + 1;
      break;
    }
  }
  return(saveRoomNumber);
}


int whereIsTheArrow(int room[])
{
  int saveRoomNumber;
  for(int i=0; i<20; i++){
    if(room[i] == 'a'){
      saveRoomNumber = i + 1;
      break;
    }
  }
  return(saveRoomNumber);
}

// function Searches the array to find the Wumpus's room number
// recieves room array as a parameter where the location is saved of the Wumpus
// returns integer value: wumpus's room number
int whereIsTheWumpus(int room[])
{
  int saveRoomNumber;
  for(int i=0; i<20; i++){
    if(room[i] == 'w'){
      saveRoomNumber = i + 1;
      break;
    }
  }
  return(saveRoomNumber);
}
//----------End of whereIsTheWumpus()---------


// function Searches the array to find the pit one's room number
// recieves room array as a parameter where the location is saved of the pit1
// returns integer value: pit1's room number
int whereIsPitOne(int room[])
{
  int saveRoomNumber;
  for(int i=0; i<20; i++){
    if(room[i] == 'p'){
      saveRoomNumber = i + 1;
      break;
    }
  }
  return(saveRoomNumber);
}
//----------End of whereIsPitOne()---------


// function Searches the array to find the pit two's room number
// recieves room array as a parameter where the location is saved of the pit2
// returns integer value: pit2's room number
int whereIsPitTwo(int room[])
{
  int saveRoomNumber;
  for(int i=0; i<20; i++){
    if(room[i] == 't'){
      saveRoomNumber = i + 1;
      break;
    }
  }
  return(saveRoomNumber);
}
//----------End of whereIsPitTwo()---------


// function Evaluates if the player's current room is adjacent to its new room using the 2d array in main.
// recieves the adjacent array, player's current room, and where the player wants to move
// returns bool: True if room is adjacent; False if room is Not Adjacent
bool adjacentRooms(int adjacentArray[][3], int currentRoomNumber, int moveToRoomNumber)
{
  int playerRoomIndex = currentRoomNumber-1;

  if((moveToRoomNumber == adjacentArray[playerRoomIndex][0]) ||
     (moveToRoomNumber == adjacentArray[playerRoomIndex][1]) ||
     (moveToRoomNumber == adjacentArray[playerRoomIndex][2]))
  {
    return true;
  }
  else
  {
    return false;
  }
}
//----------End of adjacentRooms()---------


// function Checks if Wumpus is in the adjacent room then displays message
// recieves adjacent array, room array, and players current room number as parameters 
void adjacentWumpus(int adjacentArray[][3],int room[], int playersCurrentRoom)
{
  int wumpusRoomCheck;
  
  for(int i = 0; i < 20; i++){
    if(room[i] == 'w'){
      wumpusRoomCheck = i + 1; 
      break;
    }
  }
  
  if(adjacentRooms(adjacentArray, wumpusRoomCheck, playersCurrentRoom)){
    printf("You smell a stench. ");
  }
}
//----------End of adjacentWumpus()---------


// function Checks if pit is in the adjacent room then displays message
// recieves adjacent array, room array, and players current room number as parameters
void adjacentPit(int adjacentArray[][3], int room[], int playersCurrentRoom)
{

  int pitRoomCheck1, pitRoomCheck2;
  bool checkPitAdjacent1, checkPitAdjacent2;
  
  // Checks for pit1 in adjacent room
  for(int i=0; i < 20; i++){
    if(room[i] == 'p'){
      pitRoomCheck1 = i + 1; 
      break;
    }
  }
  checkPitAdjacent1 = adjacentRooms(adjacentArray, pitRoomCheck1, playersCurrentRoom);
  if(checkPitAdjacent1){
    printf("You feel a draft. ");
  }
  
  // Checks for pit2 in adjacent room
  for(int i=0; i < 20; i++){
    if(room[i] == 't'){
      pitRoomCheck2 = i + 1; 
      break;
    }
  }
  checkPitAdjacent2 = adjacentRooms(adjacentArray, pitRoomCheck2, playersCurrentRoom);
  if(checkPitAdjacent2){
    printf("You feel a draft. ");
  }
}
//----------End of adjacentPit()---------


void adjacentBat(int adjacentArray[][3],int room[], int playersCurrentRoom){
  int batRoomCheck1, batRoomCheck2;
  bool checkBatAdjacent1, checkBatAdjacent2;

  // Checks for bat1 in adjacent room
  for(int i=0; i < 20; i++){
    if(room[i] == 'b'){
      batRoomCheck1 = i + 1; 
      break;
    }
  }
  checkBatAdjacent1 = adjacentRooms(adjacentArray, batRoomCheck1, playersCurrentRoom);
  if(checkBatAdjacent1){
    printf("You hear rustling of bat wings. ");
  }

  // Checks for bat2 in adjacent room
  for(int i=0; i < 20; i++){
    if(room[i] == 'y'){
      batRoomCheck2 = i + 1; 
      break;
    }
  }
  checkBatAdjacent2 = adjacentRooms(adjacentArray, batRoomCheck2, playersCurrentRoom);
  if(checkBatAdjacent2){
    printf("You hear rustling of bat wings. ");
  }
}


// function Checks if user entered the same room as pit or not
// recieves room array and player's current room number as parameters
// returns a bool: True if player's room matches the pit's room; False if it doesn't 
bool enteredPitRoom(int room[], int playersCurrentRoom) // KEEPING
{
  bool died = false;
  for(int i = 0; i < 20; i++){
    if(((room[i] == 't') || (room[i] == 'p')) && (playersCurrentRoom == i+1))
    {
      died = true;
      break;
    }
  }
  return died;
  }
//----------End of enteredPitRoom()---------


bool enteredBatsRoom(int room[], int playersCurrentRoom)
{
  bool sameRoomWithBats = false;

  for(int i = 0; i < 20; i++){
    if((room[i] == 'b') && (i+1 == playersCurrentRoom) 
    || (room[i] == 'y') && (i+1 == playersCurrentRoom))
    {
       sameRoomWithBats = true;
      break;
    }
  }
  return sameRoomWithBats;
}


// function Checks if user enter the same room as wumpus or not
// recieves room array, and player's current room number as parameters
// returns a bool: True if player's room matches the wumpus's room
bool enteredWumpusRoom(int room[], int playersCurrentRoom)
{
  bool sameRoomWithWumpus = false;

  for(int i = 0; i < 20; i++){
    if((room[i] == 'w') && (i+1 == playersCurrentRoom)){
       sameRoomWithWumpus = true;
      break;
    }
  }
  return sameRoomWithWumpus;
}
//----------End of enteredWumpusRoom()---------


// function checks if wumpus room is in odd room or even room
// recieves adjacent array, room array, and players current room as paramenters.
// returns an integer: Lowest adjacent room that wumpus will move to when it is in the odd room.
int wumpusInOddRoom(int adjacentArray[][3], int room[], int playersCurrentRoom)
{
  int playerRoomIndex = playersCurrentRoom-1;
  int lowestNumberRoom;
  
  for(int i = 0; i < 20; i++){
    
      if((room[i] == 'w') && ((i+1) % 2 != 0))
      {
              if ((adjacentArray[i][0] < (adjacentArray[i][1])) && 
                 ((adjacentArray[i][0] < (adjacentArray[i][2]))))
              {
                lowestNumberRoom = adjacentArray[i][0];
              }
                
              else if ((adjacentArray[i][1] < (adjacentArray[i][0])) && 
                      ((adjacentArray[i][1] < (adjacentArray[i][2]))))
              {
                lowestNumberRoom = adjacentArray[i][1];
              }
        
              else if ((adjacentArray[i][2] < (adjacentArray[i][0])) && 
                      ((adjacentArray[i][2] < (adjacentArray[i][1]))))\
              {
                lowestNumberRoom = adjacentArray[i][2];
              }
        return(lowestNumberRoom);
      }
  }
  return(0);
}
//----------End of wumpusInOddRoom()---------


int lowestAdjacentRoom(int adjacentArray[][3], int roomNumber){
  
  int lowestNumberRoom;
  int roomIndex = roomNumber - 1;
  
  if ((adjacentArray[roomIndex][0] < adjacentArray[roomIndex][1]) && 
      (adjacentArray[roomIndex][0] < adjacentArray[roomIndex][2]))
  {
        lowestNumberRoom = adjacentArray[roomIndex][0];
    }
                
  else if ((adjacentArray[roomIndex][1] < adjacentArray[roomIndex][0]) && 
           (adjacentArray[roomIndex][1] < adjacentArray[roomIndex][2]))
          {
            lowestNumberRoom = adjacentArray[roomIndex][1];
          }
        
  else if ((adjacentArray[roomIndex][2] < adjacentArray[roomIndex][0]) && 
          (adjacentArray[roomIndex][2] < adjacentArray[roomIndex][1]))
          {
            lowestNumberRoom = adjacentArray[roomIndex][2];
          }
  
  return(lowestNumberRoom);
  
}


// This function flies player into new random room.
int batsFlyYou(int room[], int playerRoom){
  
  int i = 0;
  int randomValue, saveRoom;
  
  while(i < 1){
    randomValue = rand() % 20 + 1;
    if (randomValue != playerRoom) // Bat does not drop in same room
    {
      saveRoom = randomValue;
      i++;
    }
  }
  return(saveRoom);
}


int newBatRoom(int playerRoom, int bat1Room, int bat2Room){
  
  int i = 0;
  int randomValue, newRoom;
  
  while(i < 1){
    randomValue = rand() % 20 + 1;
    if(randomValue != playerRoom && 
       randomValue != bat1Room && 
       randomValue != bat2Room)
    {
      newRoom = randomValue;
      i++;
    }
  }
  return(newRoom);
}

//----------------------------END OF FUNCTIONS--------------------------


// Main Function:
int main(void) {

  // Fixed random number for testing purposes
  srand(1);


  // whatIsInTheRoom array holds:
  // l(player), w(wumpus), p(pit1), t(pit2), b(bat1), y(bat2), a(arrow)
  char whatIsInTheRoom[7] = {'l', 'w', 'p', 't', 'b', 'y', 'a'};
  
  // Using this array we will randomly assign things from whatIsInTheRoom array.
  int roomArray[20] = {};

  // Assigning Random Locations in this order: person, Wumpus, pit1, pit2, bat1, bat2, arrow 
  int i=0;
  int randomValue;
  
  while(i < 7){
    randomValue = rand() % 20 + 1;
    if (roomArray[randomValue-1] == 0)
    {
      roomArray[randomValue-1] = whatIsInTheRoom[i];
      //printf("%d  %c\n", randomValue, roomArray[randomValue-1]); // TEMPORARY DELETEE
      i++;
    }
  }

  
  // Following array is used to check if rooms are adjacent in the adjacent room function
  int adjacentArray[21][3] = { {2,5,8}, {1,3,10}, {2,4,12}, {3,5,14}, 
                               {1,4,6}, {5,7,15}, {6,8,17}, {1,7,9}, 
                               {8,10,18}, {2,9,11}, {10,12,19},{3,11,13},
                               {12,14,20}, {4,13,15}, {6,14,16},{15,17,20},
                               {7,16,18},{9,17,19},{11,18,20},{19,13,16} };


  // Storing all room numbers in these variables to make it easy to update if needed
  int storePlayerRoomNumber, storeWumpusRoomNumber, storePit1RoomNumber, storePit2RoomNumber;
  int storeBat1RoomNumber, storeBat2RoomNumber, storeArrowRoomNumber;

  storeBat1RoomNumber = whereIsBatOne(roomArray);
  storeBat2RoomNumber = whereIsBatTwo(roomArray);
  storeArrowRoomNumber = whereIsTheArrow(roomArray);
  storePlayerRoomNumber = whereIsThePlayer(roomArray);
  storeWumpusRoomNumber = whereIsTheWumpus(roomArray);
  storePit1RoomNumber = whereIsPitOne(roomArray);
  storePit2RoomNumber = whereIsPitTwo(roomArray);
  
  // Prints the room ONLY when the game starts
  printf("You are in room %d. ", storePlayerRoomNumber);

  // Checks if player's current room is adjacent to a pit, wumpus, or bat
  adjacentWumpus(adjacentArray, roomArray, storePlayerRoomNumber);
  adjacentPit(adjacentArray, roomArray, storePlayerRoomNumber);
  adjacentBat(adjacentArray, roomArray, storePlayerRoomNumber);
  printf("\n");
  
  
  int countdown = 1;
  int moveToRoom, userGuess, tempArrow;
  char move;  

  int numberOfRooms, newWumpusRoom; // menu option s
  
  while(move != 'x'){

    // Takes user input for menu option and makes it all lowercase.
    printf("\n%d. Enter your move (or 'D' for directions): ", countdown);
    scanf("%c", &move);
    move = tolower(move);

    // Controls the menu option:
    switch(move)
    {

      // MENU OPTION M START BELOW -------------------------
      
      // Player chooses to move
      case 'm':
        
        scanf("%d", &moveToRoom);

        // ***Checks if user's chosen room to move in is a permissible move (Adjacent).***
        if (adjacentRooms(adjacentArray, storePlayerRoomNumber, moveToRoom) == true) { 

                // counting number goes up
                countdown++;
                bool playerArrowTogether = false;
                if(storePlayerRoomNumber == storeArrowRoomNumber){
                  playerArrowTogether = true;
                }
                
                // **Then checks if the room entered by user has a pit, if so then player dies and game is over!**
                if (enteredPitRoom(roomArray, moveToRoom) == true){
                  printf("Aaaaaaaaahhhhhh....   \n");
                  printf("    You fall into a pit and die. \n");
                  move = 'x';
                }

                // **Otherwise checks if the room entered by user has a Wumpus in it**
                else if(enteredWumpusRoom(roomArray, moveToRoom) == true){
      
                        // *If the Wumpus is in an ODD numbered room, the wumpus moves to lowest adjacent room number*
                        int lowestRoomNumber = wumpusInOddRoom(adjacentArray, roomArray, moveToRoom);
                        if (lowestRoomNumber != 0)
                        {
            
                          // Deletes current and Updates new room for wumpus in the array
                          roomArray[storeWumpusRoomNumber - 1] = 0; 
                          roomArray[lowestRoomNumber - 1] = whatIsInTheRoom[1];
                          storeWumpusRoomNumber = lowestRoomNumber;
            
                          // Deletes current and Updates new room for the player in the array
                          roomArray[storePlayerRoomNumber - 1] = 0;
                          roomArray[moveToRoom - 1] = whatIsInTheRoom[0];
                          storePlayerRoomNumber = moveToRoom;


                          if(moveToRoom == storeArrowRoomNumber){
                            printf("Congratulations, you found the arrow and can once again shoot.\n");
                            storeArrowRoomNumber = moveToRoom;
                          }
            
                          printf( "You hear a slithering sound, as the Wumpus slips away. \n"
            			        "Whew, that was close! \n");
            
                          printf("You are in room %d. ", storePlayerRoomNumber);
            
                          // Checks if player's current room is adjacent to a pit, wumpus, or bat
                          adjacentWumpus(adjacentArray, roomArray, moveToRoom);
                          adjacentPit(adjacentArray, roomArray, moveToRoom);
                          adjacentBat(adjacentArray, roomArray, moveToRoom);
                          
                        }
            
                        // *Otherwise Wumpus is an EVEN numbered room and kills the player and game is over!*
                        else
                        {
                          printf(	"You briefly feel a slimy tentacled arm as your neck is snapped. \n"
            			        "It is over.\n");
                          move = 'x';
                        }
                }


            //-----------------------!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!      

                // UNDER WORK !!!
                // **Otherwise checks if the room entered by user has a Bats in it**
                else if(enteredBatsRoom(roomArray, moveToRoom) == true){

                  // Following code places player into random room
                  int dontMoveHere = moveToRoom; // use this to make sure bats dont drop in this room
                  int temp, newBatLocation;
                  temp = batsFlyYou(roomArray, dontMoveHere);

                  roomArray[storePlayerRoomNumber - 1] = 0; // delete original player room number
                  storePlayerRoomNumber = temp; // assign new player room number

                  // just so it does not overwrite if something is already in room
                  if(roomArray[storePlayerRoomNumber-1] == 0){
                    roomArray[storePlayerRoomNumber-1] = 'l';
                  }

                  //move arrow with player
                  if(playerArrowTogether == true){
                    storeArrowRoomNumber = storePlayerRoomNumber;
                  }
                  if(moveToRoom == storeArrowRoomNumber){
                    printf("Congratulations, you found the arrow and can once again shoot.\n");
                    storeArrowRoomNumber = moveToRoom;
                  }

                  printf("Woah... you're flying! \n");
                  printf("You've just been transported by bats to room %d.\n", storePlayerRoomNumber);

                  newBatLocation = newBatRoom(storePlayerRoomNumber, storeBat1RoomNumber, storeBat2RoomNumber);

                  // update the location for bat and not overwrite the array because bat can be present with others
                  if(storeBat1RoomNumber == dontMoveHere){
                    roomArray[storeBat1RoomNumber-1] = 0;
                    storeBat1RoomNumber = newBatLocation;
                    if(roomArray[newBatLocation-1] == 0){
                      roomArray[newBatLocation-1] = 'b';
                    }
                  }
                  else if(storeBat2RoomNumber == dontMoveHere){
                    roomArray[storeBat2RoomNumber-1] = 0;
                    storeBat2RoomNumber = newBatLocation;
                    if(roomArray[newBatLocation-1] == 0){
                      roomArray[newBatLocation-1] = 'y';
                    }
                  }

                  
                  // check if bats dropped the player into a room with wumpus in it
                  if(enteredWumpusRoom(roomArray, storePlayerRoomNumber) == true){
                    
                        // *If the Wumpus is in an ODD numbered room, the wumpus moves to lowest adjacent room number*
                        int lowestRoomNumber = wumpusInOddRoom(adjacentArray, roomArray, storePlayerRoomNumber);
                        if (lowestRoomNumber != 0)
                          {
                              // Deletes current and Updates new room for wumpus in the array
                              roomArray[storeWumpusRoomNumber - 1] = 0; 
                              roomArray[lowestRoomNumber - 1] = whatIsInTheRoom[1];
                              storeWumpusRoomNumber = lowestRoomNumber;

                              if(moveToRoom == storeArrowRoomNumber){
                                printf("Congratulations, you found the arrow and can once again shoot.\n");
                                storeArrowRoomNumber = moveToRoom;
                              }
                            
                              printf( "You hear a slithering sound, as the Wumpus slips away. \n"
                    			    "Whew, that was close! \n");
                    
                              printf("You are in room %d. ", storePlayerRoomNumber);
                    
                              // Checks if player's current room is adjacent to a pit, wumpus, or bat
                              adjacentWumpus(adjacentArray, roomArray, storePlayerRoomNumber);
                              adjacentPit(adjacentArray, roomArray, storePlayerRoomNumber);
                              adjacentBat(adjacentArray, roomArray, storePlayerRoomNumber);
                          }
                          
                        // *Otherwise Wumpus is an EVEN numbered room and kills the player and game is over!*
                        else
                        {
                              printf(	"You briefly feel a slimy tentacled arm as your neck is snapped. \n"
                      			  "It is over.\n");
                              move = 'x';
                        }
                  }
                  // **Then checks if the room entered by user has a pit, if so then player dies and game is over!**
                  else if (enteredPitRoom(roomArray, moveToRoom) == true){
                    printf("Aaaaaaaaahhhhhh....   \n");
                    printf("    You fall into a pit and die. \n");
                    move = 'x';
                  }
                  else{
                    
                    printf("\nYou are in room %d. ", storePlayerRoomNumber);
                    // Checks if player's current room is adjacent to a pit, wumpus, or bat
                    adjacentWumpus(adjacentArray, roomArray, storePlayerRoomNumber);
                    adjacentPit(adjacentArray, roomArray, storePlayerRoomNumber);
                    adjacentBat(adjacentArray, roomArray, storePlayerRoomNumber);
                  }

                  
                }
                // UNDER WORK END !!!
                  
      
                // **User's chosen room DOESN'T have a PIT, BATS, or WUMPUS so the player moves safely**
                else{

                  if(moveToRoom == storeArrowRoomNumber){
                    printf("Congratulations, you found the arrow and can once again shoot.\n");
                    storeArrowRoomNumber = moveToRoom;
                  }
      
                  // Deletes current and Updates new room for the player in the array
                  roomArray[storePlayerRoomNumber - 1] = 0;
                  roomArray[moveToRoom - 1] = whatIsInTheRoom[0];
                  storePlayerRoomNumber = moveToRoom;

                  //move arrow with player
                  if(playerArrowTogether == true){
                    storeArrowRoomNumber = storePlayerRoomNumber;
                  }
      
                  printf("You are in room %d. ", storePlayerRoomNumber);
      
                  // Checks if player's current room is adjacent to a pit, wumpus, or bat
                  adjacentWumpus(adjacentArray, roomArray, moveToRoom);
                  adjacentPit(adjacentArray, roomArray, moveToRoom);
                  adjacentBat(adjacentArray, roomArray, moveToRoom);
                }
        }

        //------------------ UNDER WORK STOP !!!!

        // ***User chose a room that is not adacent to its current room. NOT PERMISSIBLE MOVE!***
        else {
          printf("Invalid move.  Please retry. \n");	// message for invalid move
          printf("You are in room %d. ", storePlayerRoomNumber);

          // Checks if player's current room is adjacent to a pit, wumpus, or bat
          adjacentWumpus(adjacentArray, roomArray, storePlayerRoomNumber);
          adjacentPit(adjacentArray, roomArray, storePlayerRoomNumber);
          adjacentBat(adjacentArray, roomArray, storePlayerRoomNumber);
        }
        
        break;
      // ------------------------- MENU OPTION M END -------------------------
      
      // MENU OPTION R START BELOW -------------------------
  
      // User gets to change the room number for the player, wumpus, pit1, and pit2
      case 'r':
        
          printf("Enter the room locations (1..20) for player, wumpus, pit1, pit2, bats1, bats2, and arrow: \n");
        
          // Erases the player, wumpus, pit1, and pit2 from their current room in the array.
          roomArray[storePlayerRoomNumber - 1] = 0;
          roomArray[storeWumpusRoomNumber - 1] = 0;
          roomArray[storePit1RoomNumber - 1] = 0;
          roomArray[storePit2RoomNumber - 1] = 0;
          roomArray[storeBat1RoomNumber - 1] = 0;
          roomArray[storeBat2RoomNumber - 1] = 0;
          roomArray[storeArrowRoomNumber - 1] = 0;

          scanf("%d", &storePlayerRoomNumber);
          scanf("%d", &storeWumpusRoomNumber);
          scanf("%d", &storePit1RoomNumber);
          scanf("%d", &storePit2RoomNumber);
          scanf("%d", &storeBat1RoomNumber);
          scanf("%d", &storeBat2RoomNumber);
          scanf("%d", &storeArrowRoomNumber);

          tempArrow = storeArrowRoomNumber;
    
          printf("\nYou are in room %d. ", storePlayerRoomNumber);

          // Updates the NEW room for the player, wumpus, pit1, and pit2 in the array
          roomArray[storePlayerRoomNumber - 1] = whatIsInTheRoom[0];
          roomArray[storeWumpusRoomNumber - 1] = whatIsInTheRoom[1];
          roomArray[storePit1RoomNumber - 1] = whatIsInTheRoom[2];
          roomArray[storePit2RoomNumber - 1] = whatIsInTheRoom[3];
          roomArray[storeBat1RoomNumber - 1] = whatIsInTheRoom[4];
          roomArray[storeBat2RoomNumber - 1] = whatIsInTheRoom[5];
          roomArray[storeArrowRoomNumber - 1] = whatIsInTheRoom[6];

          if(storeArrowRoomNumber == -1){
            roomArray[storeArrowRoomNumber - 1] = 0;
            storeArrowRoomNumber = storePlayerRoomNumber;
          }
        
          // Checks if player's current room is adjacent to a pit, wumpus, or bat
          adjacentWumpus(adjacentArray, roomArray, storePlayerRoomNumber);
          adjacentPit(adjacentArray, roomArray, storePlayerRoomNumber);
          adjacentBat(adjacentArray, roomArray, storePlayerRoomNumber);
          
        break;
      // ------------------------- MENU OPTION R END -------------------------
      
      // MENU OPTION C START BELOW -------------------------

      // User asks to cheat and display current positions of the player, pit1, pit2, and wumpus
      // person, Wumpus, pit1, pit2, bat1, bat2, arrow
      case 'c':

        if(storePlayerRoomNumber == storeArrowRoomNumber){
          tempArrow = -1;
        }
        else{
          tempArrow = storeArrowRoomNumber;
        }
        
        printf( "Cheating! Game elements are in the following rooms: \n"
    		"Player Wumpus Pit1 Pit2 Bats1 Bats2 Arrow  \n"
    		"%4d %5d %6d %5d %5d %5d %5d \n\n",
          storePlayerRoomNumber, storeWumpusRoomNumber,
          storePit1RoomNumber, storePit2RoomNumber,
          storeBat1RoomNumber, storeBat2RoomNumber,
          tempArrow);

        printf("You are in room %d. ", storePlayerRoomNumber);


        // Checks if player's current room is adjacent to a pit, wumpus, or bats
        adjacentWumpus(adjacentArray, roomArray, storePlayerRoomNumber);
        adjacentPit(adjacentArray, roomArray, storePlayerRoomNumber);
        adjacentBat(adjacentArray, roomArray, storePlayerRoomNumber);
        
        break; 
      // ------------------------- MENU OPTION C END -------------------------
      
      // MENU OPTION D START BELOW -------------------------

      // User asks for directions
      case 'd':
        
        displayCave();
        displayInstructions();
        printf("You are in room %d. ", storePlayerRoomNumber);
        
        break;   
      // ------------------------- MENU OPTION D END -------------------------

      // MENU OPTION P START BELOW -------------------------
      
      // User asks to display the room map
      case 'p':
        
        displayCave();
        printf("You are in room %d. ", storePlayerRoomNumber);
        
        break;
      // ------------------------- MENU OPTION P END -------------------------      





      

      // UNDER WORK !!!!!!!!!!! START

      case 's':

        countdown++;

        if(storeArrowRoomNumber == storePlayerRoomNumber){
        

              // take input of how many rooms user want to shoot arrow in
              printf("Enter the number of rooms (1..3) into which you want to shoot, followed by the rooms themselves: ");
              scanf("%d", &numberOfRooms);
      
              // take input of all the room numbers user want to shoot arrow in.
              int rooms[5];
              int whatRoom;
      
              rooms[0] = storeArrowRoomNumber;
              for(int i = 1; i <= numberOfRooms; i++){
                scanf("%d", &whatRoom);
                rooms[i] = whatRoom;
              }

          
                  bool roomAdjacent = true;
                  int tempRoomHolder = storeArrowRoomNumber;

              if(numberOfRooms<=3){
                
                  // check if those rooms entered by user are adjacent from left to right starting from arrow room
                  for(int i = 0; i < numberOfRooms+1; i++){
                    if(i < numberOfRooms){
                      roomAdjacent = adjacentRooms(adjacentArray, rooms[i], rooms[i+1]);
                    }
                    else{
                      break;
                    }
                    
                    if(roomAdjacent == false){
                      tempRoomHolder = rooms[i];
                      printf("Room %d is not adjacent.  Arrow ricochets...\n", rooms[i+1]);
                      break;
                      }
                  }
              }
            else{
                    printf("Sorry, the max number of rooms is 3.  Setting that value to 3.");
                }
      
      
               // Where will arrow go through
              int newArrowRoom;

              //printf("\n%d\n", newArrowRoom);
              
              if(roomAdjacent != true){ // user room is not adjacent
                newArrowRoom = lowestAdjacentRoom(adjacentArray, tempRoomHolder);
                //printf("\n%d\n", newArrowRoom);
                
                if(roomArray[storeArrowRoomNumber-1] == 'a'){ // delete arrow from room array
                  roomArray[storeArrowRoomNumber-1] = 0;
                }
                if(roomArray[newArrowRoom-1] == 0){ // update arrow location, not overwrite
                  (roomArray[newArrowRoom-1] = 'a');
                }
                storeArrowRoomNumber = newArrowRoom;
      
                if(storeArrowRoomNumber == storeWumpusRoomNumber){ // kills wumpus
                  printf( "Your arrow ricochet killed the Wumpus, you lucky dog!\n"
                  "Accidental victory, but still you win!\n");
                  move = 'x';
                }
                else if(storeArrowRoomNumber == storePlayerRoomNumber){
                  printf( "You just shot yourself, and are dying.\n"
                  "It didn't take long, you're dead.\n");
                  move = 'x';
                }
                else{
                  printf("You are in room %d. ", storePlayerRoomNumber);
                }
              }
                
              else if(roomAdjacent == true){
                for(int i = 1; i <= numberOfRooms; i++){
                  if(rooms[i] == storePlayerRoomNumber){
                    printf( "You just shot yourself.  \n"
                  "Maybe Darwin was right.  You're dead.\n");
                    move = 'x';
                  }
                  else if(rooms[i] == storeWumpusRoomNumber){
                    printf( "Wumpus has just been pierced by your deadly arrow! \n"
                  "Congratulations on your victory, you awesome hunter you.\n");
                    move = 'x';
                  }
                  else if(i == numberOfRooms){
                    
                    if(roomArray[storeArrowRoomNumber-1] == 'a'){ // delete arrow from room array
                      roomArray[storeArrowRoomNumber-1] = 0;
                    }
                    storeArrowRoomNumber = rooms[i];
                    if(roomArray[storeArrowRoomNumber-1] == 0){ // update arrow location, not overwrite
                      (roomArray[storeArrowRoomNumber-1] = 'a');
                    }
                    printf("You are in room %d. ", storePlayerRoomNumber);
                  }
                } // for loop end
              }
      
              // No matter what wumpus moves to lowest adjacent room
              newWumpusRoom = lowestAdjacentRoom(adjacentArray, storeWumpusRoomNumber);
                
              if(roomArray[storeWumpusRoomNumber-1] == 'w'){
                roomArray[storeWumpusRoomNumber-1] = 0;
                if(roomArray[newWumpusRoom-1] == 0){ // make sure new room is empty
                  roomArray[newWumpusRoom-1] = 'w';
                }
              }
              storeWumpusRoomNumber = newWumpusRoom;

          //storeArrowRoomNumber = -1;
              
        }
        else{
          printf("Sorry, you can't shoot an arrow you don't have.  Go find it.\n");
          printf("You are in room %d. ", storePlayerRoomNumber);
        }


      break;
      
      // MENU OPTION G START BELOW -------------------------

      // If user asks to guess which room Wumpus is in. Then Game Over!
      case 'g':
        
        printf("Enter room (1..20) you think Wumpus is in: ");
        scanf("%d", &userGuess);

        // Guessed correctly
        if (userGuess == whereIsTheWumpus(roomArray)){
          printf("You won!\n");
        }

        // Guessed incorrectly
        else{
          printf("You lost.\n");
        }
        move = 'x';
        
        break;
      // ------------------------- MENU OPTION G END -------------------------
    }
    getchar();
    printf("\n");
  }

  printf("Exiting Program ...\n");
	
	return 0;
}