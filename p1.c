//
// Created by shinigami on 30/12/17.
//
#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main (int argc, char **argv, char **envp) {
    int i;

    printf("Srodowisko procesu:\n");
    for (i = 0; envp[i] != NULL;i++)
        printf("%s\n", envp[i]);

    return(0);
}


