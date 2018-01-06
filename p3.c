#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main (int argc, char **argv, char **envp) {
    int p=0;

    printf("Poczatek procesu...\n");
    p = fork();//W tym momencie jest tworzona kopia programu
    //kopia ta ma te same wartości zmiennychco program wyjściowy,
    //jednak modyfikacja zmiennych w jednym programie nie zmienia ich w drogim
    //oba programy dochodzą do tej linijki
    printf("Tu jestem: %d\n", p);
    //i wyświetlają swoją wartość p
    //w przypadku programu rodzicielskiego jest to PID programu dziecięcego
    //a w przypadku programu dziecięcego 0


    return(0);
}


