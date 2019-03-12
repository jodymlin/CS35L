// Kathy Daniels
// 404887687
// Assignment 4
// sfrob.c - reads frobnicated text lines from standard input,
// and writes a sorted version to standard output in frobnicated form

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// returns an int result that is negative, zero, or positive
// depending on whether a is less than, equal to, or greater than b
int frobcmp(char const * a, char const * b) {

  // check that each argument points to
  // non-space bytes
  while (*a != ' ' && *b != ' ') {
    
    // unfrobnicate byte by byte (XOR with 42)
    char a1 = *a ^ 42;
    char b1 = *b ^ 42;
    
    // if a1 is smaller than b1
    // OR
    // a is shorter than b
    // return -1
    if (a1 < b1 || *a == ' ') { return -1; }
    
    // if a1 is larger than b1
    // OR
    // b is shorter than a
    // return 1
    if (a1 > b1 || *b == ' ') { return 1; }

    // increment index in byte array
    a++;
    b++;
  }

  // if a and b are equal                                                     
  // return 0                                                                 
  return 0;

}
   
// comparator function to pass into qsort in main
int cmp(const void * a, const void * b) {

  return frobcmp(*(char**) a, *(char**) b);

}

int main() {

  char newChar;

  // allocate memory for array of strings (char arrays)
  // check for memory error
  char** strArray = (char**) malloc(sizeof(char*));
  if (strArray == NULL) {
    fprintf(stderr, "Error allocating memory.");
    exit(1);
  }

  // index of string in strArray
  // set as -1 since s is incremented on first iteration
  int s = -1;

  // allocate memory for new string (or char array)
  // check for memory error
  char* newString = (char*) malloc(sizeof(char)); 
  if (newString == NULL) {
    fprintf(stderr, "Error allocating memory.");
    exit(1);
  }

  // index of char in newString
  int c = 0;

  // set temporary string to first index in string array
  strArray[0] = newString;

  // set to TRUE if program must create a new string
  // set to FALSE if program is adding to existing string
  bool addNewString = true;

  // continue collecting input until end of file is reached
  while (true) {

    // read text from standard input
    // print message to stderr if program has error reading input
    newChar = getchar();
    if (ferror(stdin)) {
      fprintf(stderr, "Error reading standard input.");
      exit(1);
    }

    // break from reading input if reaches end of file
    if (feof(stdin)) { break; }
    
    // if program is still adding characters to existing string
    if (!addNewString) {
      
      // reallocates memory for new character in growing string
      newString  = (char*) realloc(newString, (c+1) * sizeof(char));
        
      // checks for memory error
      if (newString == NULL) {
	fprintf(stderr, "Error allocating memory.");
	exit(1);
      }

      // updates growing string to reallocated string
      newString[c] = newChar;
      strArray[s] = newString;
      c++;

      // space byte signals the end of a text line
      // program should start on a new string
      if (newChar == ' ') {
	// ignore multiple spaces
	addNewString = true;
      }
      
    }

    // if program must create a new string
    else {
      
      // reset new string length
      c = 0;

      // account for multiple spaces in input
      if (newChar == ' ' && c == 0) { continue; };

      // increment index in string array
      s++;

      // reallocates memory for growing string array
      strArray = (char**) realloc(strArray, (s+1) * sizeof(char*));

      // checks for memory error
      if (strArray == NULL) {
	fprintf(stderr, "Error allocating memory.");
	exit(1);
      }

      // allocate memory for new string in array
      newString = (char*) malloc(sizeof(char));

      if (newString == NULL) {
	fprintf(stderr, "Error allocating memory.");
	exit(1);
      }

      // updates growing string to reallocated string
      newString[c] = newChar;
      strArray[s] = newString;
      c++;

      // program can start adding characters to this new string
      // since the appropiate memory has been allocated
      addNewString = false;

    }
    
  }

  // if standard input does not have a trailing space
  // append space to the very end
  if (s != -1 && strArray[s][c-1] != ' ') {

    newString = (char*) realloc(newString, (c+1) * sizeof(char));
    newString[c] = ' ';
    strArray[s] = newString;
    
  }

  // use frobcomp to sort array of strings
  qsort(strArray, s+1, sizeof(char*), cmp);
 
  // print every character in every string to stdout
  int i;
  for (i = 0; i < s+1; i++) {

    int j = 0;
    while(true) {
      
      // print character by character and catch any errors
      if (putchar(strArray[i][j]) == EOF) {
	  fprintf(stderr, "Error printing characters.");
	  exit(1);
      }

      // skip to the next string if space byte is detected
      if (strArray[i][j] == ' ') { break; }

      j++;

    } 

    // free memory holding each string
    free(strArray[i]);
  }

  // free memory holding array of strings
  free(strArray);

  exit(0);
}
