#include <stdio.h>
#include <unistd.h>

int main(void) {
  FILE *f;

  /* chroot */
  chdir("/tmp");
  if (chroot("/tmp") != 0) {
    perror("chroot /tmp");
    return 1;
  }

  /* do something after chrooting */
  f = fopen("/etc/passwd", "r");
  if (f == NULL) {
    perror("/etc/passwd");
    return 1;
  } else {
    char buf[100];
    while (fgets(buf, sizeof(buf), f)) {
      printf("%s", buf);
    }
  }
  return 0;
}
