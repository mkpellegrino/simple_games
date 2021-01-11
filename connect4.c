/* Connect-4          */
/* By: Mr. Pellegrino */
/* 1/8/2021           */

#include <stdio.h>
int gb[42];    /* global array    */
int whos_move; /* global variable */

char p(int x)
{
  char return_value=' ';
  switch(x)
    {
    case 1:
      return_value = 'O';
      break;
    case 2:
      return_value = 'X';
    }
	
  return return_value;
}

int four_the_same_and_not_zero( int a, int b, int c, int d )
{
  int return_value=0;
  if( a==b && b==c && c==d && a != 0 ) return_value = 1;
  return return_value;
}
int check_for_winner()
{
  int return_value = 0;
  /* this is going to be a pretty complex function */
  /* look at each column and check for 4 in a row */
  for( int c=0; c<6; c++ )
    {
      if( four_the_same_and_not_zero( gb[c],gb[c+7],gb[c+14],gb[c+21] )) return_value = whos_move; 
      if( four_the_same_and_not_zero( gb[c+7],gb[c+14],gb[c+21],gb[c+28] )) return_value = whos_move; 
      if( four_the_same_and_not_zero( gb[c+14],gb[c+21],gb[c+28],gb[c+35] )) return_value = whos_move; 
    }
  /* look at each row and check for 4 in a row */
  for( int r=0; r<42; r+=7 )
    {
      if( four_the_same_and_not_zero( gb[r], gb[r+1], gb[r+2], gb[r+3] )) return_value=whos_move;
      if( four_the_same_and_not_zero( gb[r+1], gb[r+2], gb[r+3], gb[r+4] )) return_value=whos_move;
      if( four_the_same_and_not_zero( gb[r+2], gb[r+3], gb[r+4], gb[r+5] )) return_value=whos_move;
      if( four_the_same_and_not_zero( gb[r+3], gb[r+4], gb[r+5], gb[r+6] )) return_value=whos_move;
    }
  /* look at each diagonal \ and check for 4 in a row */
  /* 1111000 */
  /* 1111-00 */
  /* 1111--0 */
  /* 0------ */
  /* 00----- */
  /* 000---- */
  for( int c=0; c<4; c++ )
    {
      for( int r=0; r<21; r+=7 )
	{
	  if( four_the_same_and_not_zero( gb[r+c], gb[r+c+8], gb[r+c+16], gb[r+c+24] )) return_value=whos_move;
	}
    }  
  /* look at each diagonal / and check for 4 in a row */
  for( int c=4; c<7; c++ )
    {
      for( int r=0; r<21; r+=7 )
	{
	  if( four_the_same_and_not_zero( gb[r+c], gb[r+c+6], gb[r+c+12], gb[r+c+18] )) return_value=whos_move;
	}
    }  

   return return_value;
}

int drop_game_piece( int c /* which column the user entered */)
{
  /* check for a non-existant column */
  /* if it's a bad column, return -1 */
  if( (c<0) || (c>6) ) return -1;

  /* player drops a piece into column */
  /* if the column is filled already, return -1 */
  if( gb[c] != 0 ) return -1;

  /* if we've made it this far into the function */
  /* then the move must be a valid move */
  /*  */
  /* find the 'lowest' zero in column c */
  /* and replace it with the player's # */

  int x=-1; /* a variable that will be set to the 'lowest' zero's index in the gb[] array */
  for( int i=c; i<42; i+=7 )
    {
      /* for debugging purposes only */
      /* printf( "column %i   gb_index %i\n", c, i ); */
      
      if( gb[i] != 0 )
	{
	  x=i-7;
	  /* break out of the loop */
	  /* by setting i to be > 42 */
	  i=43;
	}
    }
  /* if the column was empty then the above 'for-loop' */
  /* wouldn't have found a spot where gb[i] != 0 */
  /* so x would still be -1 ... since the column was */
  /* empty, we can put the piece into column number = 35 */
  /* that would be the 'bottom' of the board */
  if( x == -1 )
    {
      x = c+35;
    }
  gb[x] = whos_move;
  return(0);
}

int displayBoard()
{
  /*  vv                     */
  /* |1 |  |  |  |  |  |  |  */
  /* ----------------------  */
  /* |1 |  |  |  |  |  |  |  */
  /* ----------------------  */
  /* |1 |  |  |  |  |  |  |  */
  /* ----------------------  */
  /* |1 |  |  |  |  |  |  |  */
  /* ----------------------  */
  /* |1 |  |  |  |  |  |  |  */
  /* ----------------------  */
  /* |1 |  |  |  |  |  |  |  */
  /* ----------------------  */
  

  /* clears the terminal with 50 carriage returns */
  /* for( int i=0;i<50; i++ ) printf( "\n" ); */
  printf( "-----------------------------\n" );
  printf( "| 0 | 1 | 2 | 3 | 4 | 5 | 6 |\n" );
  printf( "=============================\n" );
  printf( "| %c | %c | %c | %c | %c | %c | %c |\n", p(gb[0]), p(gb[1]), p(gb[2]), p(gb[3]), p(gb[4]), p(gb[5]), p(gb[6]) );
  printf( "-----------------------------\n" );
  printf( "| %c | %c | %c | %c | %c | %c | %c |\n", p(gb[7]), p(gb[8]), p(gb[9]), p(gb[10]), p(gb[11]), p(gb[12]), p(gb[13]) );
  printf( "-----------------------------\n" );
  printf( "| %c | %c | %c | %c | %c | %c | %c |\n", p(gb[14]), p(gb[15]), p(gb[16]), p(gb[17]), p(gb[18]), p(gb[19]), p(gb[20]) );
  printf( "-----------------------------\n" );
  printf( "| %c | %c | %c | %c | %c | %c | %c |\n", p(gb[21]), p(gb[22]), p(gb[23]), p(gb[24]), p(gb[25]), p(gb[26]), p(gb[27]) );
  printf( "-----------------------------\n" );
  printf( "| %c | %c | %c | %c | %c | %c | %c |\n", p(gb[28]), p(gb[29]), p(gb[30]), p(gb[31]), p(gb[32]), p(gb[33]), p(gb[34]) );
  printf( "-----------------------------\n" );
  printf( "| %c | %c | %c | %c | %c | %c | %c |\n", p(gb[35]), p(gb[36]), p(gb[37]), p(gb[38]), p(gb[39]), p(gb[40]), p(gb[41]) );
  printf( "=============================\n" );
  printf( "| e n t e r   c o l u m n # |\n" );
  printf( "|    to drop a gamepiece    |\n" );
  printf( "-----------------------------\n" );
  
  printf( "\n\n" );
  
  return 0;
}

int main()
{
  /* initialize the array */
  for( int i=0; i<42; i++ )
    {
      gb[i] = 0;
    }

  /* start off with player 1 */
  whos_move = 1;

  /* initialize the variable that gets which column  */
  /* the player will be dropping the game-piece into */
  int player_move = 0;

  /* at the start of the game, there is no winner so */
  /* set winner equal to zero */
  int winner=0;

  
  while( winner == 0 )
    {
      displayBoard();
      int bad_move=0; /* if the column is full or the user enters a value that's out of range bad_move=1 */
      
      printf( "It's player %i's move.\n", whos_move );
      printf( "Where to? (Column 0-6): " );
      scanf( "%i", &player_move );

      /* place a game-piece in the correct spot */
      bad_move=drop_game_piece( player_move );
      
      /* if it was a bad move, don't switch who's turn it was */
      /* and tell the user that the move was bad */
      /* otherwise DO switch who's turn it was */
      winner=check_for_winner();
      
      if( bad_move != 0 )
	{
	  printf( "\n\n*** sorry bub - that's a bad move - try again ***\n\n" );
	}
      else if( winner==0 )
	{
	  if( whos_move == 1 )
	    {
	      whos_move=2;
	    }
	  else
	    {
	      whos_move=1;
	    }
	}
      

    }
  
  displayBoard();
  if( winner == -1 )
    {
      /* then there was a tie */
      printf( "\n\n*** The Game (sadly) ended in a tie - how futile! ***\n\n" );
    }
  else
    {
      printf( "\n\n*** Found a winner... it's player %i! ***\n\n", check_for_winner() );
    }
  return(0);
}
