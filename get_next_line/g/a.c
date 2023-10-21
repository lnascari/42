#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int fd = open("b", O_CREAT | O_RDONLY);
    char *s = malloc(120);
    char *x = malloc(134);
    char *y = malloc(134);
    printf("%d ", read(fd, s, 12));
    printf("%d ", read(fd, x, 42));
    printf("%d", read(fd, y, 40));
    printf("\n%s-----%s---%s--", s, x, y);
    printf("\n%p\n", y);
    return 0;
}
