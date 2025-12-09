#include <stdio.h>

const char* HELP = "./<program> dbfile";

int main(int argc, char** argv)
{
  // read from file and write to file
  if (argc != 2) {
    printf("%s\n", HELP);
    return 1;
  }
  return 0;
}
