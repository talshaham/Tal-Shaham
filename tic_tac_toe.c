

#include <stdio.h>
#include <stdlib.h>
/*declarations of functions*/

void Board();
void player_1_turn();
void player_2_turn();
void scan_1();
void scan_2();
int win(char *numbers, int count);







int main() {
int flag_play_again=1;

while(flag_play_again){// if play again scanf=1 after finish of game it will be another game
char choose[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};     /*reset of the 1 dimesional array*/
int count=0;
int flag_tie=0; /*flag for sure that it will not print tie after winning*/
while(1){ /*infinte loop that will end after 5 games of player 1*/
system("cls");// cleaning board before showing him
Board(choose); // painting of board
player_1_turn();
scan_1(choose); // scan player 1 chose
count++; // count games of player 1
system("cls"); // clean old board before showing new board
Board(choose);

/*you can be a winner in this game just after your turn, thats why
there is just 1 and same 'function win' for both players*/
if(win(choose,count)==1){
printf("\n\nplayer 1 ('X') is the winner!!!\n\n\n");
flag_tie=1;// not a tie
printf("\n\ndo you want to play again?\nplease eneter a number (1=YES,0=NO) ");
scanf("%d",&flag_play_again);
break;
}

if(count==5){/*if player 1 played 5 times so its 9 moves for 2 players and thats the maximun that can be so
if nobody wins and its a tie*/
    break;
}

player_2_turn();
scan_2(choose);
system("cls");
Board(choose);

if(win(choose,count)==1){
printf("\n\nplayer 2 ('O') is the winner!!!\n\n\n");
flag_tie=1;
printf("\n\ndo you want to play again?\nplease eneter a number (1=YES,0=NO) ");
scanf("%d",&flag_play_again);
break;
}
}

if(flag_tie==0)// check for tie
printf("\n\nits a tie");
printf("\n\ndo you want to play again?\nplease eneter a number (1=YES,0=NO) ");
scanf("%d",&flag_play_again);
}

printf("\nGAME OVER\n");

    return 0;

}









/* the %c are spaces in the beginning and after each scan they become 'X'/'O'*/
void Board(char *choose) {
   printf("\n\n     tic tac toe GAME");
   printf("\n\n1       |2       |3\n   %c    |   %c    |    %c\n        |        | \n---------------------------\n4       |5       |6\n   %c    |   %c    |    %c\n        |        |\n---------------------------\n7       |8       |9\n   %c    |   %c    |    %c\n        |        |\n\n",choose[1],choose[2],choose[3],choose[4],choose[5],choose[6],choose[7],choose[8],choose[9]);
}

void player_1_turn(){
   printf("player 1 ('X') turn\nenter a number: ");
}
void player_2_turn(){
   printf("player 2 ('O') turn\nenter a number: ");

}

/*scan of the chose of the player and assignement of that chose to the array,
the right location in the array obtain with 'int l' that match the game table.
also 2 checks/flags: one to see that the scan number between 1-9,
the second to see that this number in the array is not been taken alredy*/
void scan_1(char *choose){
   int l, flag_picked=1, flag_boundries=1;
   while(flag_picked==1 || flag_boundries==1){ /*just if both flags equale to zero loop is over*/
   scanf("%d",&l);
      if(l>9||l<1)// check that the 'int l' or the chosen number at the tanle is between 1-9
   {
    printf("\n**please pick a number between 1-9**\nenter a number");
   continue;
   }
    flag_boundries=0;// check that the scan location in the array is free (not 'X' or 'O')
   if(*(choose+l)=='O'||*(choose+l)=='X')
   {
   printf("\n**please pick another number that didnt picked before**\nenter a number");
   continue;
   }
   flag_picked=0;

   }

    choose[l]='X';// assignement of the chosen number after checking that is valid

}

void scan_2(char *choose){// same for player 2
int l, flag_picked=1, flag_boundries=1;
   while(flag_picked==1 || flag_boundries==1){
   scanf("%d",&l);
      if(l>9||l<1)
   {
    printf("\n**please pick a number between 1-9**\nenter a number");
   continue;
   }
    flag_boundries=0;
   if(*(choose+l)=='O'||*(choose+l)=='X')
   {
   printf("\n**please pick another number that didnt picked before**\nenter a number");
   continue;
   }
   flag_picked=0;

   }

    choose[l]='O';
}

/* the thought behind this long code is to check for a sequance of winning- scan all the 8 option,
this function valid for both players because you can win in this game just after your turn,
beside the sequence of 3 sames arguements in the array, this function assured that this arguements are 
not spaces like in the beginnig of the game*/
int win(char *numbers,int count){
    if(count>2){ // nested if for shortcut progress because you can win in this game just after 3 turns at least
if((*(numbers+1)==*(numbers+2)&&*(numbers+2)==*(numbers+3))&&(*(numbers+1)=='X'||*(numbers+1)=='O'))
return 1;
if((*(numbers+4)==*(numbers+5)&&*(numbers+5)==*(numbers+6))&&(*(numbers+4)=='X'||*(numbers+4)=='O'))
return 1;
if((*(numbers+7)==*(numbers+8)&&*(numbers+8)==*(numbers+9))&&(*(numbers+7)=='X'||*(numbers+7)=='O'))
return 1;
if((*(numbers+1)==*(numbers+4)&&*(numbers+4)==*(numbers+7))&&(*(numbers+1)=='X'||*(numbers+1)=='O'))
return 1;
if((*(numbers+2)==*(numbers+5)&&*(numbers+5)==*(numbers+8))&&(*(numbers+2)=='X'||*(numbers+2)=='O'))
return 1;
if((*(numbers+3)==*(numbers+6)&&*(numbers+6)==*(numbers+9))&&(*(numbers+3)=='X'||*(numbers+3)=='O'))
return 1;
if((*(numbers+1)==*(numbers+5)&&*(numbers+5)==*(numbers+9))&&(*(numbers+1)=='X'||*(numbers+1)=='O'))
return 1;
if((*(numbers+3)==*(numbers+5)&&*(numbers+5)==*(numbers+7))&&(*(numbers+3)=='X'||*(numbers+3)=='O'))
return 1;
    }
return 0;
}



