#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
  char *word;			//word and corresponding hint
  char *clue;
  int x;			//Starting x and y positions
  int y;
  char direction;		//H for horizontal, V for vertical
  int f;			//solved or not
} Word_t;

Word_t *loadTextFile (FILE * myFile, int nrWords);
void displayBoard (int rows, int cols, char **myBoard);
int isBoardFilled (int rows, int cols, char **myBoard);
char **createArray (int rows, int cols);
int findIndex (int arr[], int size, int val);
void playGame (char **myBoard, int words, Word_t * word, int x, int y,
	       int countToFinish);
char **updateBoard (char **myBoard, Word_t * words, int solve);

int
main ()
{
  char **board;
  Word_t *words;
  FILE *fileptr;
  int rows, cols, nrWords;
  char filename[100];

  do
    {
      printf ("Please enter a file name:");
      scanf ("%s", filename);
      fileptr = fopen (filename, "r");
      if (fileptr == NULL)
	{
	  printf
	    ("\nPlease enter a valid file name! This \'%s\' could not be found!!\n\n",
	     filename);

	}
      else
	{
	  fscanf (fileptr, "%d%d%d\n", &rows, &cols, &nrWords);
	  printf ("\nGame is %d rows x %d cols with %d words\n", rows, cols,
		  nrWords);
	  board = createArray (rows, cols);
	  //displayBoard(rows,cols,board);
	  words = loadTextFile (fileptr, nrWords);
	  printf ("Words and clues are read!\n");
	  board = updateBoard (board, words, 0);
	  //displayBoard(rows,cols,board);
	  playGame (board, nrWords, words, rows, cols, 0);
	  free (board);
	  free (words);
	}
    }
    while (fileptr == NULL);
  return 0;
}

/**
 * This function reads file and it stores the our struct type array then returns it.
 * @param myFile File pointer.
 * @param nrWords Number of words.
 * @return Word_t type dynamic array.
 */
Word_t *
loadTextFile (FILE * myFile, int nrWords)
{
  //Create a temp array that based on Word_t struct type and allocate memory for it.
  Word_t *temp = (Word_t *) malloc (sizeof (Word_t) * nrWords);

  //Whole line except direction, x and y;
  char wholeline[1024];

  for (int i = 0; i < nrWords; i++)
    {
      //Allocate memory for word.
      temp[i].word = (char *) malloc (sizeof (char ) * 32);
      //Allocate memory for clue.
      temp[i].clue = (char *) malloc (sizeof (char ) * 256);
      fscanf (myFile, "%c %d %d ", &temp[i].direction, &temp[i].x,
	      &temp[i].y);
      //printf("%c %d %d\n",temp[i].direction,temp[i].x,temp[i].y);
      //fgets(wholeline,1024,myFile);
      int j = 0;
      do
	{
	  fscanf (myFile, "%c", &wholeline[j]);

	}
      while (wholeline[j++] != '\n');
      //printf("%s",wholeline);
      wholeline[j - 1] = 0;
      j--;
      int k;
      for (k = 0; k < j && wholeline[k] != ' '; k++)
	{
	  temp[i].word[k] = wholeline[k];

	}
      temp[i].word[j] = 0;
      int l = 0;
      for (; k < j; k++)
	{
	  temp[i].clue[l++] = wholeline[k];
	}
      temp[i].clue[l] = 0;


    }
  return temp;

}

/**
 * This function creates a dynamic array that is in a matrix type.
 * Its dimensions are rows and cols variables.
 * @param rows  number of rows.
 * @param cols  number of columns.
 * @return 2D char array.
 */
char **
createArray (int rows, int cols)
{
  //temprorary dynamic array to return.
  char **temp;
  //Allocate memory for rows.
  temp = (char **) malloc (sizeof (char *) * rows);
  //Allocate memory for columns.
  for (int i = 0; i < rows; i++)
    {

      temp[i] = (char *) malloc (sizeof (char) * cols);
    }

  //Initialize all elements to '#'.
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
	{
	  temp[i][j] = '#';
	}

    }

  return temp;
}

/**
  * This function display the board that is created by createArray function.
  * @param rows  number of rows.
  * @param cols  number of columns.
  * @param myBoard 2D char array.
*/
void
displayBoard (int rows, int cols, char **myBoard)
{
  printf ("Current puzzle :\n\n");
  printf ("\t ");

  for (int i = 0; i < cols; i++)
    {
      printf ("%d  ", i + 1);
    }

  printf ("\n\t ");
  for (int i = 0; i < cols; i++)
    {
      if (i >= 9)
	{
	  printf ("--  ");
	}
      else
	{
	  printf ("-- ");
	}

    }
  printf ("\n");


  for (int i = 0; i < rows; i++)
    {
      printf ("%d\t| ", i + 1);
      for (int j = 0; j < cols; j++)
	{
	  if (j >= 9)
	    {
	      printf ("%c   ", myBoard[i][j]);
	    }
	  else
	    {
	      printf ("%c  ", myBoard[i][j]);
	    }

	}
      printf ("\n");
    }




}

/**
 * This function checks is there any space in the board.
 * @param rows  number of rows.
 * @param cols  number of columns.
 * @param myBoard 2D char array.
 * @return '1' is board full otherwise return '0'.
*/
int
isBoardFilled (int rows, int cols, char **myBoard)
{
  //Until find any '_' search.
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
	{
	  if (myBoard[i][j] == '_')
	    {
	      return 0;
	    }
	}

    }
  return 1;

}

/**
  * This function search for a value in the array.
  * @param arr array to search in.
  * @param size the size of the array.
  * @param val the value to look for.
*/
int
findIndex (int arr[], int size, int val)
{
  for (int i = 0; i < size; i++)
    {
      if (arr[i] == val)
	{
	  return 1;
	}
    }
  return 0;
}

/**
 * This method updates the board it fills the board if the word has been solved with word character otherwise fill '_' any blank word space.
 * @param myBoard 2D char array to update.
 * @param words our struct type .
 * @param solve the index of the current word.
 * @return myBoard parameter again but the updated version of it.
 */
char **
updateBoard (char **myBoard, Word_t * words, int solve)
{
  int x = words[solve].x - 1;
  int y = words[solve].y - 1;
  int length = strlen (words[solve].word);

  for (int i = 0; i < length; i++)
    {
      if (words[solve].f == 1)
	{
	  myBoard[x][y] = words[solve].word[i];
	}
      else
	{
	  myBoard[x][y] = '_';
	}
      if (words[solve].direction == 'H')
	{
	  y++;
	}
      else
	{
	  x++;
	}
    }


  return myBoard;
}

int
getCurrentWord (int currentWord, int isThere[], int wasFound[], int words,
		int isValid)
{
  do
    {
      printf ("Enter -1 to exit\n");
      printf ("Which clue do you want to solve?: ");
      int temp;
      isValid = scanf ("%d", &temp);

      if (isValid < 1)
	{
	  currentWord = 0;
	  break;
	}
      else
	{
	  currentWord = temp;
	}

      if (currentWord == -1)
	return currentWord;


      if (findIndex (wasFound, words, currentWord) == 1)
	{
	  printf ("That clue has been solved\n");
	  currentWord = 0;

	}
      else if (findIndex (isThere, words, currentWord) == 0)
	{
	  printf ("That clue is invalid\n");
	  currentWord = 0;
	}

    }
  while (currentWord < 1 || currentWord > words);
  char temp;
  do
    {
      scanf ("%c", &temp);
    }
  while (temp != '\n');
  return currentWord;
}

/**
 * This method for playing the game everything inside this method.
 * @param myBoard 2D char array.
 * @param words number of words in the game.
 * @param word the words list in our struct type.
 * @param x number of rows.
 * @param y number of columns.
 * @param countToFinish when we reach that number all words are solved.
 */
void
playGame (char **myBoard, int words, Word_t * word, int x, int y,
	  int countToFinish)
{
  int isThere[words];
  int wasFound[words];
  int currentWord = 0;
  char currentAnswer[20];
  for (int i = 0; i < words; i++)
    {
      isThere[i] = i + 1;
      wasFound[i] = 0;
    }



  for (int i = 0; i < words; i++)
    {
      myBoard = updateBoard (myBoard, word, i);
    }
  displayBoard (x, y, myBoard);


  do
    {
      printf ("\t");
      for (int i = 0; i < y; i++)
	{
	  if (i > 10)
	    {
	      printf ("****");
	    }
	  else
	    {
	      printf ("***");
	    }
	}

      printf ("\n\nAsk for hint:\n");
      printf ("# Direction\trow  col\n");
      printf ("----------------------------\n");
      for (int i = 1; i <= words; i++)
	{
	  if (findIndex (isThere, words, i) == 1)
	    {
	      if (word[i - 1].direction == 'H')
		{
		  printf ("%d: Horizontal\t%d\t%d\n", i, word[i - 1].x,
			  word[i - 1].y);
		}
	      if (word[i - 1].direction == 'V')
		{
		  printf ("%d: Vertical\t%d\t%d\n", i, word[i - 1].x,
			  word[i - 1].y);
		}

	    }

	}
      printf ("\n");

      int isValid = 0;
      do
	{

	  currentWord =
	    getCurrentWord (currentWord, isThere, wasFound, words, isValid);
	  if (currentWord == -1)
	    {
	      return;
	    }
	  if (isValid < 1)
	    {
	      break;
	    }


	}
      while (1);
      if (currentWord == 0 && isValid < 1)
	{
	  printf ("\nThat clue is invalid\n\n");
	  currentWord =
	    getCurrentWord (currentWord, isThere, wasFound, words, isValid);
	  if (currentWord == -1)
	    {
	      return;
	    }

	}


      printf ("Current hint:  %s\n", word[currentWord - 1].clue);
      printf ("Enter your solution: ");
      scanf ("%s", currentAnswer);
      for (int k = 0; currentAnswer[k]; k++)
	{
	  currentAnswer[k] = toupper (currentAnswer[k]);
	}
      //printf("%s\n",currentAnswer);
      //printf("%s\n",word[currentWord-1].word);
      if (strcmp (currentAnswer, word[currentWord - 1].word) != 0)
	{
	  printf ("WRONG ANSWER\n");
	  displayBoard (x, y, myBoard);
	}
      else
	{

	  printf ("\nCorrect!!\n\n");
	  word[currentWord - 1].f = 1;
	  isThere[currentWord - 1] = 0;
	  wasFound[currentWord - 1] = currentWord;
	  myBoard = updateBoard (myBoard, word, currentWord - 1);
	  displayBoard (x, y, myBoard);
	  countToFinish++;
	}


    }
  while (countToFinish != words && isBoardFilled (x, y, myBoard) == 0);
  printf ("\nCongratulations! You beat the puzzle!\n\n");


}
