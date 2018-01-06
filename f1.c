//
// Created by shinigami on 29/12/17.
//
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 1024


int main (int argc, char **argv) {
    if(argc != 2) {//w argc znajduje się ilość argumetów w argv
        printf("Błędna ilość argumentów\n", argc);
        return -3;
    }
    int f1, c;
    char b[BUFSIZE], *n1;

    c = 10;
    n1 = argv[1];

    f1 = open (n1, O_RDONLY);
    if(f1 == -1) {
        printf("Nie znaleźiono pliku\n");
        return -1;
    }

    int i = read (f1, b, c);
    if( i == -1){
        printf("brak odczytanych danych / koniec pliku do pliku pliku %s\n",n1);
        return -2;
    }else {

        b[i] = '\0';//wstawienie null terminatora na koniec odczytanego stringa
        //w i znajduje się
        printf("%s: Przeczytano %d/%d znaków z pliku %s(%d): \"%s\"\n",
               argv[0], i,c, n1,f1, b);
    }
    close(f1);

    return(0);
}

