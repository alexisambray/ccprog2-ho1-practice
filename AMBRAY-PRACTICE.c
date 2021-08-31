/*
    Skeleton file for the PRACTICE problem.

        lASTNAME, FIRSTNAME: AMBRAY, ALEXIS       SECTION: S13

        Do not forget to ENCODE your name and section in the space indicated
   above.

    DO NOT define a main() function in this file.  The main() function
   definition is already given in the accompanying main.c file.

        Note that if you compile JUST this file only, you will get an error that
   says "undefined reference to WinMain" (for DEVCPP users).

        You'll have to include this file first in main.c via #include, and then
   it is the main.c that you you should compile to produce the main.exe file.

    Violation of any of the RESTRICTIONS or non-compliance with the
   specifications will result to point deductions.
*/

/* DO NOT CHANGE THE #include below.  You are NOT allowed to include other
 * files. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Make sure that you read and understand the contents of practice.h. */
#include "practice.h"

/*
   TO DO #1: implement Populate() as described in the problem specs.

   Use scanf() to input the number of rows, number of columns and the words
   which will be stored in the matrix M.

   DO NOT printf() anything in this function.  Non-compliance will result in
   deduction of points!

   Use input redirection (when you test your solution) to avoid keyboard input.
*/
void Populate(Matrix M, int* ptr_nrows, int* ptr_ncols) {
  // declare your own local variables; fill up the body of this function
  int nRows, nCols, i, j;

  scanf("%d", &nRows);
  scanf("%d", &nCols);

  *ptr_nrows = nRows;
  *ptr_ncols = nCols;

  for (i = 0; i < *ptr_nrows; i++) {
    for (j = 0; j < *ptr_ncols; j++) {
      scanf("%s", M[i][j]);
    }
  }
}

/*
        TO DO #2: implement Search() as described in the problem specs.

        Search key in M. If it is found, set *ptr_row_index and *ptr_col_index
        to the row and column indices where the matching string was found.
        If it is not found, set both of these variables to -1.
*/
void Search(Matrix M,
            int n_rows,
            int n_cols,
            String key,
            int* ptr_row_index,
            int* ptr_col_index) {
  // declare your own local variables; fill up the body of this function
  // do NOT use printf() and scanf() in this function
  int i, j, found = 0;

  for (i = 0; i < n_rows; i++) {
    for (j = 0; j < n_cols; j++) {
      if (strcmp(key, M[i][j]) == 0) {
        found = 1;
        *ptr_row_index = i;
        *ptr_col_index = j;
      } else if (found == 0) {
        *ptr_row_index = -1;
        *ptr_col_index = -1;
      }
    }
  }
}

/*
        TO DO #3: Transpose()

    Copy the elements of M as transpose matrix to T.
*/
void Transpose(Matrix T, Matrix M, int n_rowsM, int n_colsM) {
  // declare your own local variables; fill up the body of this function
  // do NOT use printf() and scanf() in this function
  int i, j;

  for (i = 0; i < n_colsM; i++) {
    for (j = 0; j < n_rowsM; j++) {
      strcpy(T[i][j], M[j][i]);
    }
  }
}

/*
        TO DO #4: implement Filter() as described in the problem specs.
*/
void Filter(char* filter, Matrix T, Matrix M, int n_rowsM, int n_colsM) {
  // declare your own local variables; fill up the body of this function
  // do NOT use printf() and scanf() in this function
  int i, j, k, l;

  for (i = 0; i < n_rowsM; i++) {
    for (j = 0; j < n_colsM; j++) {
      int isFound;
      for (k = 0; k < strlen(filter); k++) {
        isFound = 0;
        for (l = 0; l < strlen(M[i][j]); l++) {
          if (filter[k] == M[i][j][l]) {
            isFound = 1;
            break;
          }
        }
        if (!isFound) {
          break;
        }
      }
      String symbol;
      strcpy(symbol, isFound ? "+" : "-");
      strcpy(T[i][j], symbol);
      strcat(strcat(T[i][j], M[i][j]), symbol);
    }
  }
}

/*
        TO DO #5: implement RowSort() as described in the problem specs.

        Sort the matrix T elements per row in alphabetical (increasing) order.
*/

void RowSort(Matrix T, Matrix M, int n_rowsM, int n_colsM) {
  // declare your own local variables; fill up the body of this function
  // do NOT use printf() and scanf() in this function
  /*
     YOU ARE NOT ALLOWED TO DECLARE/USE AN EXTRA 1D OR 2D ARRAY OF STRINGS in
     this function.

     Your solution should sort the elements of matrix T directly without using
     an extra 1D or 2D array.

     BEWARE: non-compliance with this restriction will render your solution
     incorrect.
  */
  int i, j, k, l;
  for (i = 0; i < n_rowsM; i++) {
    for (j = 0; j < n_colsM; j++) {
      if (j == 0) {
        strcpy(T[i][j], M[i][j]);
      } else {
        int added = 0;
        for (k = 0; k < j; k++) {
          if (strcmp(T[i][k], M[i][j]) > 0) {
            for (l = 0; l < n_colsM - k - 1; l++) {
              strcpy(T[i][n_colsM - 1 - l], T[i][n_colsM - 2 - l]);
            }
            strcpy(T[i][k], M[i][j]);
            added = 1;
            break;
          }
        }
        if (!added) {
          strcpy(T[i][j], M[i][j]);
        }
      }
    }
  }
}

/*******************************************************************************
    WARNING!!!   WARNING!!!   WARNING!!!

        YOU ARE NOT ALLOWED TO DEFINE the main() function in this file.

    The main() is in the accompanying main.c source file.

        VIOLATION OF THIS RESTRICTION WILL RESULT TO A DEDUCTION OF 10 points!
********************************************************************************/
