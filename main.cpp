#include <stdio.h>
#include <string.h>

/*  
 *\brief
 * This  structure is for remembering values of players 'A' and 'B' and the actions made to get that values 
 *
 * \note 
 * In array "trip" are saved such values :
 *    1) 'l' -- the first left value was taken
 *    2) 'r' -- the last right value was taken 
 *    3) 'b' -- the first left and the last rigth were taken
 *    4) 's' -- means "start" or the first two values from left were taken
 *    5) 'e' -- means "end" or the last two values from end were taken
 * all even indexes describe the actions with 'A'
 * all odd with B
*/
struct Road{
    int A;
    int B;
    char trip[200];
};

typedef struct Road road;

/*declaring the function of searching all combinations of game and returning the "best" one */
road search(road road_looping, int coins[100], int indexstart, int indexend, char letter, int index_road, int flag2A, int flag2B);


/*declaring the function of the found result */
void Print(road End, int index_of_array, int array_coins[]);




int main() {


    int array_coins[100];  //array of coins which by the rules can not be more than 100 and to which all values of coins are written to work with 
    int index_of_array = 0; //index of current position to write in array of coins
    int result = 1; // variable created to control input
    int a; // variable to which input will be written before writting it to the array. In case of bad input when there are more than 100 values entered it will not provide buffer overflow
    
    
    while (result != -1 && result != 0) {     // while loop to enter values of coins . Will end when EOF is entered or non-integer
        result = scanf(" %d",&a);     // Enter of the temporary value
        if (result == 0) { // checking whether integer was entered 
            break;
        }
        
        if (result == -1 && index_of_array == 0) { //Check if any coin value was entered before the EOF
            printf("Zetony:\nNespravny vstup.\n");
            return 1;
        }

        if (index_of_array >= 100) { //Check for bufer overflow
            printf("Nespravny vstup.\n");
            return 1;
        }

        array_coins[index_of_array] = a;  // If everything was entered correctly -> write it into the array
        index_of_array++;

    }
    printf("Zetony:\n");
    if (result == 0) {  // End of program if non-iteger was entered
        printf("Nespravny vstup.\n");
        return 1;
    }
    
    index_of_array--;  // This is made because in the end EOF is entered and 'index_of_array' is one bigger than should
    
    
    road road_to_search; // Creating temporary structure for search of the ways
    /*start values of the structures*/
    road_to_search.A = 0; 
    road_to_search.B = 0;


    


    road End; // Declairing the best option of game with values os sum of each player and the trip how they were gotten
    End.A = 0;
    End.B = 0;
    End = search(road_to_search,array_coins,0,index_of_array-1,'A',-1,0,0); // the start of search 

   Print(End, index_of_array, array_coins); // print of the result

    return 0;
}


/*
* \brief
*   This function depending on the "trip" shows how the game was going by showing each gamers's step and their final results
* \note
*   From the begining there are two variables which show th indexes of "not-taken" positions, which are change while the game is going, from the left and right in array of enetred coins:
*       1) start -- for the coin on left side
*       2) end --  for the coin on the right side
*/
void Print(road End, int index_of_array, int array_coins[])
{
    
    size_t length = strlen(End.trip);
    int start = 0; 
    int end = index_of_array-1;
    for (size_t i = 0; i < length; i++) { // Loop for each step of the game written in "trip"

       if (End.trip[i] =='l') {  // checking whether one of the players have taken coin from the left side
           if ( i % 2 == 0) { //checking if it was player 'A' 
               printf("A [%d]: %d\n", start, array_coins[start]); // because only one coin was taken from left -> show the first left coin from left( which index is written to "start" value)
               start += 1; // changing the first left coin index to 1 rigth 
           }
           else { //check if it was 'B' player
               printf("B [%d]: %d\n", start, array_coins[start]);
               start += 1;
           }
       }
       else if (End.trip[i] =='r') { //checking whether one of the players have taken coin from the right side
           if (i % 2 == 0) {
               printf("A [%d]: %d\n", end, array_coins[end]); // because only one coin was taken from rigth -> show the last right coin ( which index is written to "end" value)
               end -= 1; // changing the last right coin index to 1 left
           }
           else {
               printf("B [%d]: %d\n", end, array_coins[end]);
               end -= 1;
           }
       }

       /*Other steps are variations of two above*/
       else if (End.trip[i] =='b') {
           if (i % 2 == 0) {
               printf("A [%d], [%d]: %d + %d\n", start, end, array_coins[start], array_coins[end]);
               start += 1;
               end -= 1;
           }
           else {
               printf("B [%d], [%d]: %d + %d\n", start, end, array_coins[start], array_coins[end]);
               start += 1;
               end -= 1;
           }
       }
       else if (End.trip[i] =='s') {
           if (i % 2 == 0) {
               printf("A [%d], [%d]: %d + %d\n", start, start+1, array_coins[start], array_coins[start+1]);
               start += 2;

           }
           else {
               printf("B [%d], [%d]: %d + %d\n", start, start+1, array_coins[start], array_coins[start+1]);
               start += 2;

           }
       }
       else if (End.trip[i] =='e')  {
           if (i %2 == 0) {
               printf("A [%d], [%d]: %d + %d\n", end, end-1, array_coins[end], array_coins[end-1]);
               end -= 2 ;

           }
           else {
               printf("B [%d], [%d]: %d + %d\n", end, end-1, array_coins[end], array_coins[end-1]);
               end -= 2;

           }
       }

    }
    printf("A: %d, B: %d\n", End.A , End.B);//print of the final results of players 'A' and 'B' in the end

}


/* 
* \brief
*      This function is a recursive function which looks all variations of game until no coins are left
*  \note
*       road_looping is "road" structure which saves each step values of sum of each player and trip how the were get
*       coins is the array of all coins. it does not change. Only values are read
*       From the begining there are two variables which show th indexes of "not-taken" positions, which are change while the game is going, from the left and right in array of enetred coins:
*           1) indexstart -- for the coin on left side
*           2) indexend --  for the coin on the right side
*       index_road -- index of step to write the movement to player
*       letter -- shows which player's turn is it(now is 'A' or 'B')
*       flag2A -- shows whether in previous step of 'A' it has taken 2 coins
*       flag2B -- shows whether in previous step of 'B' it has taken 2 coins
*/

road search(road road_looping, int coins[100], int indexstart, int indexend, char letter, int index_road, int flag2A, int flag2B)
{
    int quantity = indexend-indexstart+1; //counts how many coins have not been taken yet
    road best; // the road with the biggest sum of coins for player whose step is at this moment
    if (quantity == 0) { //if no coins are left return the final road
        index_road++;
        road_looping.trip[index_road] = '\0'; // putting the end of string when the final road is written
        return  road_looping;
    }
    else {
        index_road++;
        if (letter == 'A') { //check if it is the step of player 'A'
            //take left one
             road tmp; 
             tmp = road_looping;//remembering previous steps to look for others
             tmp.A += coins[indexstart]; //adding the first left value of coin to sum of coins of player 'A'  
             tmp.trip[index_road] = 'l';//adding to the trip that first left value was taken for player 'A'
             road next = search(tmp,coins, indexstart+1, indexend, 'B', index_road, 0, flag2B); // continue looking but adding that for that step is turn of player 'B' and the first left value was taken

             best = next; //adding first variation because nothing to compare with

             //take right one
             tmp = road_looping;//remembering previous steps to look for others
             tmp.A += coins[indexend]; //adding the last right value of coin to sum of coins of player 'A'
             tmp.trip[index_road] = 'r';//adding to the trip that last right value was taken for player 'A'
             next = search(tmp, coins, indexstart, indexend-1, 'B', index_road, 0, flag2B);// continue looking but adding that for that step is turn of player 'B' and the last right value was taken

             if (next.A > best.A)  { // if the value of taking right was bigger than taking left -> the best for 'A' will be right 

                 best = next;


             }

             if (quantity > 1 && flag2A == 0) { // check if quantity is bigger than 1 to take 2 coins and if 2 coins were not taken in previous step of player 'A'

                /*Other steps are variations of two above for player 'A' only changing flag of taking 2 coins and changing the indexes of not taken to two values moving : 
                                        1) two from the left side
                                        2) two from the right side
                                        3) one from each side */
                 //take to last

                 tmp = road_looping;
                 tmp.A += ( coins[indexend] + coins[indexend-1] );
                 tmp.trip[index_road] = 'e';
                 next = search(tmp, coins, indexstart, indexend-2, 'B', index_road, 1,flag2B);
                 if (next.A > best.A) {
                     best = next;
                 }

                 //take two first
                 tmp = road_looping;
                 tmp.A += ( coins[indexstart] + coins[indexstart+1] );
                 tmp.trip[index_road] = 's';
                 next = search(tmp, coins, indexstart+2, indexend, 'B', index_road, 1, flag2B);
                 if (next.A > best.A) {
                     best = next;
                 }
                 //take first and last
                 tmp = road_looping;
                 tmp.A += ( coins[indexstart] + coins[indexend] );
                 tmp.trip[index_road] = 'b';
                 next = search(tmp, coins, indexstart+1, indexend-1, 'B', index_road,1,flag2B);
                 if (next.A > best.A) {
                     best = next;
                 }



             }





        }
        /*All the same as in work of 'A' only changing that next step is for 'A'*/
        else if (letter == 'B') { 
            //take left one 
            road tmp;
            tmp = road_looping;
            tmp.B += coins[indexstart];
            tmp.trip[index_road] = 'l';
            road next = search(tmp, coins, indexstart+1, indexend, 'A', index_road, flag2A, 0);

            best = next;

            //take right one
            tmp = road_looping;
            tmp.B += coins[indexend];
            tmp.trip[index_road] = 'r';
            next = search(tmp, coins, indexstart, indexend-1, 'A', index_road, flag2A, 0);

            if (next.B > best.B) {
                best = next;
            }

            if (quantity > 1 && flag2B == 0) {


                //take to last

                tmp = road_looping;
                tmp.B += ( coins[indexend] + coins[indexend-1] );
                tmp.trip[index_road] = 'e';
                next = search(tmp, coins, indexstart, indexend-2, 'A', index_road, flag2A, 1);
                if (next.B > best.B) {
                    best = next;
                }

                //take two first
                tmp = road_looping;
                tmp.B += ( coins[indexstart] + coins[indexstart+1] );
                tmp.trip[index_road] = 's';
                next = search(tmp, coins, indexstart+2, indexend, 'A',index_road, flag2A, 1);
                if (next.B > best.B)   {
                    best = next;
                }

                //take first and last
                tmp = road_looping;
                tmp.B += (coins[indexstart]+coins[indexend]);
                tmp.trip[index_road] = 'b';
                next = search(tmp, coins, indexstart+1, indexend-1, 'A', index_road, flag2A, 1);
                if (next.B > best.B) {
                    best = next;
                }

            }
        }
    }

    return best;
}
