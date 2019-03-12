
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, const char* argv[]) {

  const char* from = argv[1];
  const char* to = argv[2];
  char map[256] = {'\0'};

  // Buffers for read and write
  char c[1];
  char output[1];

  // Check whether number of input arguments is valid
  if (argc != 3) {
    write(STDERR_FILENO, "Error: Invalid number of arguments.\n", 36);
    exit(1);
  }

  // Check whether byte strings are the same length
  if (strlen(from) != strlen(to)) {
    write(STDERR_FILENO, "Error: Strings are not the same length.\n", 40);
    exit(1);
  }

  // Map each character in 'from' to each in 'to'
  // Check for duplicates in 'from'
  int i;
  for (i = 0; i < strlen(from); i++) {
    if (map[from[i]] != '\0') {
      write(STDERR_FILENO, "Error: Duplicates detected.\n", 28);
      exit(1);
    }
    map[from[i]] = to[i];
  }

  while(read(0, c, 1) > 0) {
    if (map[c[0]] != '\0') {
      output[0] = map[c[0]];
      if (write(1, output, 1) < 0) {
	write(2, "Error outputting characters.\n", 29);
	exit(1);
      }
    }
    else {
      if (write(1, c, 1) < 0) {
	write(2, "Error outputting characters.\n", 29);
	exit(1);
      }
    }

  }

}
