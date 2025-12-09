#include <stdio.h>
#include <string.h>

const char* HELP = "./<program> dbfile (read|write) [write-info]";

int main(int argc, char** argv)
{
  // read from file and write to file
  if (argc < 3) {
    printf("%s\n", HELP);
    return 1;
  }
  char *dataFile = argv[1];
  char *command= argv[2];

  if (strcmp(command, "read")) {

  } else if (strcmp(command, "write")) {
    if (argc == 3) {
      printf("[write-info] is in need for write\n");
      return 1;
    }
  }

  return 0;
}
