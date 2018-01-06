#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/file.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

#define BUFSIZE 1024
#define CPC 6
#define NC 6

extern char **environ;

int main (int argc, char **argv, char **envp) {
    int p=0, p1=0, f, n=6, c, i, j;
    char *b, *n1;

    c = NC;
    n1 = argv[1];
    f = open ("test", O_WRONLY|O_CREAT|O_TRUNC);
   /* for (int i=0;i<n*NC;i++)
        if((i-(NC-1))%NC ==0)
            write(f,"\n",1);
        else
        write(f,"-",1);
   */ remove("test");

    close(f);

    printf("%s[%d]: Poczatek procesu glownego...\n",
           *argv, getpid());
    f = open (n1, O_RDONLY);
    for (i=0; i<n; i++) {
        p = fork();
        if (p == -1)
            printf("%s[%d]: BLAD! Nie moge stworzyc procesu!\n",
                   *argv, getpid());
        else if ( p > 0) {
            printf("%s[%d]: To dalej ja, proces glowny...\n",
                   *argv, getpid());
        }
        else if ( p == 0 ) {
            sleep(2);
            printf("%s[%d]: Jestem procesem potomnym, moj rodzic to: [%d]...\n",
                   *argv, getpid(), getppid());

            b = malloc(sizeof(char)*c+1);
            lseek(f, i*CPC, SEEK_SET);
            flock(f,LOCK_EX);
            j = read (f, b, c);
            flock(f,LOCK_UN);
            b[c+1]='\0';
            printf("%s[%d]: Read  %d %d, \"%s\"\n",
                   argv[0],getpid(), j, i*CPC, b);
            f=open("test",O_RDWR |O_CREAT|O_SYNC,0600);
            if(f == -1)
                printf("%s[%d]: %s\n",*argv,getpid(),strerror(errno));

            printf("%s[%d]: Write %d %d %s\n", *argv,getpid(),j,i*CPC,b);
            lseek(f, i*CPC, SEEK_SET);
            write(f,b,j);

            fsync(f);
            close(f);
            free(b);
            exit(0);
        }
    }

    p1=wait(NULL);
    printf("%s[%d]: Jestem bezdzietny, ostatnie dziecko to: %d :(\n",
           *argv, getpid(), p1);
    close(f);
    printf("%s[%d]: Koniec procesu glownego.\n",
           *argv, getpid());
    exit (0);
    return(0);
}

