//
// Created by shinigami on 30/12/17.
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

int main (int argc, char **argv, char **envp) {
    int p=0;

    printf("%s[%d]: Poczatek procesu glownego...\n",
           *argv, getpid());
    p = fork();
    if (p == -1)
        printf("%s[%d]: BLAD! Nie moge stworzyc procesu!\n",
               *argv, getpid());
    else if ( p > 0) {
        printf("%s[%d]: To dalej ja, proces glowny...\n",
               *argv, getpid());
       /* sleep(5);*/
        //jeżeli to jest zakomentowane , to rodzic może zakończyć przed dzieckiem, i wtedy dziecko
        // zostanie przypisany do inita

    }
    else if ( p == 0 ) {
        printf("%s[%d]: Jestem procesem potomnym, moj rodzic to: [%d]...\n",
               *argv, getpid(), getppid());
        exit (0);
    }
    printf("%s[%d]: Koniec procesu glownego...\n",
           *argv, getpid());
    exit (0);
    return(0);
}


