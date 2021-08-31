#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ROWS 4
#define NUM_COLS 3
#define STRING_MAX_LENGTH 100

typedef char String[STRING_MAX_LENGTH];
typedef String Matrix[NUM_ROWS][NUM_COLS];

void copy(Matrix t, const Matrix m, const int n_rows, const int n_cols) {
  for (int i = 0; i < n_rows; i++) {
    for (int j = 0; j < n_cols; j++) {
      strcpy(t[i][j], m[i][j]);
    }
  }
}

int isSorted(String strings[], const int n) {
  bool isSorted = true;

  for (int i = 0; i < n - 1; i++) {
    if (strcmp(strings[i], strings[i + 1]) > 0) {
      isSorted = false;
      break;
    }
  }
}

void swap(char* str1, char* str2) {
  String temp;
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
}

void shuffle(String strings[], const int n) {
  for (int i = 0; i < n; i++)
    swap(strings[i], strings[rand() % n]);
}

void bogoSort(String strings[], const int n) {
  while (!isSorted(strings, n)) {
    for (int i = 0; i < n; i++) {
      shuffle(strings, n);
    }
  }
}

void Rowsort(Matrix t, const Matrix m, const int n_rows, const int n_cols) {
  copy(t, m, n_rows, n_cols);

  for (int i = 0; i < n_rows; i++) {
    bogoSort(t[i], n_cols);
  }
}

void filter(const char* filter,
            Matrix t,
            const Matrix m,
            const int n_rows,
            const int n_cols) {
  for (int i = 0; i < n_rows; i++) {
    for (int j = 0; j < n_cols; j++) {
      bool isFound;
      for (int k = 0; k < strlen(filter); k++) {
        isFound = false;
        for (int l = 0; l < strlen(m[i][j]); l++) {
          if (filter[k] == m[i][j][l]) {
            isFound = true;
            break;
          }
        }
        if (!isFound) {
          break;
        }
      }
      String symbol;
      strcpy(symbol, isFound ? "+" : "-");
      strcpy(t[i][j], symbol);
      strcat(strcat(t[i][j], m[i][j]), symbol);
    }
  }
}

int main(void) {
  Matrix t;
  Matrix m = {{"DOG", "NEKO", "CAT"},
              {"HELLO", "GOODBYE", "WELCOME"},
              {"GREEN", "RED", "BLUE"},
              {"CODE", "PROGRAMMER", "SYNAX"}};
  filter("EO", t, m, NUM_ROWS, NUM_COLS);
  return 0;
}
