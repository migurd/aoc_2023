#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  FILE *fin = fopen("input", "r");
  char input[1000][50]; 
  int sum = 0;

  for(int i = 0; fscanf(fin, "%s", input[i]) == 1; i++)
  {
    int leftmost = -1;
    int rightmost = -1; 
    char resultString[3];

    printf("%s\n", input[i]);
    
    for(int j = 0; j < strlen(input[i]); j++) {
      if(leftmost == -1 && isdigit(input[i][j])) leftmost = input[i][j] - '0';
      if(isdigit(input[i][j])) rightmost = input[i][j] - '0';
    }
    
    snprintf(resultString, sizeof(resultString), "%d%d", leftmost, rightmost);
    printf("%d - %d - %s\n", leftmost, rightmost, resultString);
    sum += atoi(resultString);
  }

  // ans
  printf("%d\n", sum);

  fclose(fin);
  return 0;
}