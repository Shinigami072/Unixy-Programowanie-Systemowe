//
// Creasted by shinigami on 29/12/17.
//
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFSIZE 1024

int main (int argc, char **argv) {
    int f1, f2, c;
    char b[BUFSIZE], *n1, *n2;

    c = 10;
    n1 = argv[1];
    n2 = argv[2];

    f1 = open (n1, O_RDONLY);
    int i=read (f1, b, c);
    b[i]='\0';

    printf("%s: Przeczytano %d znaków z pliku %s: \"%s\"\n",
           argv[0], i, n1, b);

    f2 = open (n2, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    write (f2, b, c);
    printf("%s: Zapisano %d znaków do pliku %s: \"%s\"\n",
           argv[0], c, n2, b);

    close(f1);
    close(f2);

    return(0);
}

