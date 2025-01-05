#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
  const char *shared_file = "/tmp/shared_memory";
  int SIZE = 1024;

  int fd = open(shared_file, O_RDONLY);

  if (fd == -1) {
    perror("Failed to open shared memory file");
    return 1;
  }

  char *data = mmap(NULL, SIZE, PROT_READ, MAP_SHARED, fd, 0);
  if (data == MAP_FAILED) {
    perror("Failed to map shared memory");
    close(fd);
    return 1;
  }

  printf("Data from shared memory: %s\n", data);

  munmap(data, SIZE);

  return 0;
}
