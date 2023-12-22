#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
  char str[10];
  int value;
} lookup_t;

lookup_t nTable[] = {
  {"one", 1},
  {"two", 2},
  {"three", 3},
  {"four", 4},
  {"five", 5},
  {"six", 6},
  {"seven", 7},
  {"eight", 8},
  {"nine", 9},
};

int startsWith(char* f_str, char* s_str) {
  int isMatch = 1;
  for(int i = 0; i < strlen(s_str); i++)
  {
    if(f_str[i] == s_str[i]) isMatch = 1;
    else {
      isMatch = 0;
      break;
    }
  }
  return isMatch;
}

void lookupMatch(char* slice, int curr_p, int* leftmost, int* rightmost) {
  size_t nTableSize = sizeof(nTable) / sizeof(nTable[0]);

  for(int i = 0; i < nTableSize; i++)
  {
    if(startsWith(slice, nTable[i].str)) {
      if(*leftmost == -1) *leftmost = nTable[i].value;
      *rightmost = nTable[i].value;
    }
    else if(isdigit(slice[0])) {
      if(*leftmost == -1) *leftmost = slice[0] - '0';
      *rightmost = slice[0] - '0';
    }
  } 
  return;
}

char* substr(const char word[], int idx) {
  // Moves values 'idx' amount to the right
  int len = strlen(word) - idx + 1;
  char* result = malloc(len * sizeof(char));

  for(int i = 0; i < len; i++) {
    result[i] = word[idx + i];
  }
  // printf("%s\n", result);
  return result;
}

int main() {
  FILE *fin = fopen("input", "r");
  char input[1000][50]; 
  int sum = 0;

  for(int i = 0; fscanf(fin, "%s", input[i]) == 1; i++)
  {
    int leftmost = -1;
    int rightmost = -1; 
    
    for(int j = 0; j < strlen(input[i]); j++) {
      lookupMatch(substr(input[i], j), j, &leftmost, &rightmost);
    }
    
    printf("%d - %d\n", leftmost, rightmost);
    sum += leftmost * 10 + rightmost;
  }

  // ans
  printf("%d\n", sum);

  fclose(fin);
  return 0;
}