#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


int main() {
  char *path = "/tmp/flag.txt";
  int fd  = open(path, O_RDONLY, 0644);
  if (fd == -1) {
    perror("open");
    return -1;
  }

  struct stat flagStat = {0};
  if (fstat(fd, &flagStat) < 0) {
    perror("fstat");
    close(fd);
    return -1;
  }
  char f[flagStat.st_size];
  if (read(fd, &f, (int) flagStat.st_size) < 0) {
    perror("read");
    close(fd);
    return -1;
  }

  printf("%s", f);
  close(fd);

  return 0;
}
