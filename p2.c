//
// Created by shinigami on 30/12/17.
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

int main (int argc, char **argv, char **envp) {

    printf("Poczatek procesu.\n");

    system("echo ala ma kota");
    //użyty jest fork i program czeka na zwrócenie kodu błędu uruchamianego programu
    //dodatkowo porgram do uruchominia jest podawany w jednym argumencie
    //jest równoznaczny z
    // execl("/bin/sh", "sh", "-c", command, (char *) 0);
    //pod względem uruchomionego programu

    printf("Dalszy ciag kodu...\n");

    execl("/bin/echo", "echo", "jakis napis", NULL);//uruchamiany program zastępuje właśnie uruchomiony
    //execl zwraca -1 tylko i wyłącznie jeśli program nie zakończy poprawnie i zwróci kod błędu
    printf("%dKoniec kodu...\n");

    return(0);
}


