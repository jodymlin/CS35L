#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]) {

  const char* from = argv[1];
  const char* to = argv[2];
  char map[256] = {'\0'};

  // Check whether number of input arguments is valid
  if (argc != 3) {
    fprintf(stderr, "Error: Invalid number of arguments.\n");
    exit(1);
  }

  // Check whether byte strings are the same length
  if (strlen(from) != strlen(to)) {
    fprintf(stderr, "Error: Strings are not the same length.\n");
    exit(1);
  }

  // Map each character in 'from' to each in 'to'
  // Check for duplicates in 'from'
  int i;
  for (i = 0; i < strlen(from); i++) {
    if (map[from[i]] != '\0') {
      fprintf(stderr, "Error: Duplicates detected.\n");
      exit(1);
    }
    map[from[i]] = to[i];
  }

  while (!feof(stdin)) {
    char c = getchar();

    if (c == EOF) { break; }

    // Check for error in reading from stdin
    if (ferror(stdin)) {
      fprintf(stderr,"Error reading from standard input.\n");
      exit(1);
    }

    if (map[c] != '\0') {
      char output = map[c];
      putchar(output);
      if (ferror(stdout)) {
	fprintf(stderr,"Error outputting characters.\n");
	exit(1);
      }
    }
    else {
      putchar(c);
      if (ferror(stdout)) {
	fprintf(stderr,"Error outputting characters.\n");
	exit(1);
      }
    }

  }

}
