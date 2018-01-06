//
// Created by shinigami on 30/12/17.
//

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>

#include <errno.h>
#include <stdlib.h>
#include <time.h>


void errorExit(int error,char * c){

    printf("ErrorCode [%d] - %s\n", error,strerror(error));
    if(c != NULL)
        printf("%s\n",c);

    exit(error);
}

void handleOpenDir(int opendirE){
    switch (opendirE) {
        case EACCES:
            errorExit(opendirE, "opendir:Brak odpowiednich praw dostępu");
        case EBADF:
            errorExit(opendirE,"opendir:niepoprawny file descriptor");
        case EMFILE:
            errorExit(opendirE,"opendir:osiągnięto limit filedescriporów dla procesu");
        case ENFILE:
            errorExit(opendirE,"opendir:osiągnięto limit filedescriporów dla systemu");
        case ENOENT:
            errorExit(opendirE,"opendir:plik nie istnieje");
        case ENOMEM:
            errorExit(opendirE,"opendir:brak pamięci potrzebnej do wykonania operacji");
        case ENOTDIR:
            errorExit(opendirE,"opendir:Spróbuj otworzyć plik będący folderem ");
    }
}

void handleStat(int statE){
    switch (statE){
        case EACCES:
            errorExit(statE, "stat:Brak odpowiednich praw dostępu w którymś z katalogów powyżej");
        case EBADF:
            errorExit(statE, "stat:niepoprawny file descriptor");
        case EFAULT:
            errorExit(statE, "stat:niepoprawny adres");
        case ELOOP:
            errorExit(statE,"stat:napotkano zbyt wiele linków symbolicznych w drodze do pliku");
        case ENAMETOOLONG:
            errorExit(statE,"stat:nazwa pliku jest za długa");
        case ENOENT:
            errorExit(statE, "stat:część ścieżki pliku nie istnieje");
        case ENOMEM:
            errorExit(statE, "stat:Brak pamięci");
        case ENOTDIR:
            errorExit(statE, "stat:ostatni plik w pah nie jest katalogiem");
        case EOVERFLOW:
            errorExit(statE, "stat;rozmiar pliku, numer inode lub ilość bloków nie może być poprawnie zareprezentowana");
    }
}

#define MAX_CHAR 200
void handleReadDir(int readDirE){
    switch (readDirE){
        case EBADF:
            errorExit(readDirE,"readdir:niepoprawny file descriptor");
    }
}
void printDir(char * path){
    DIR *d; //directory stream
    d = opendir(path);

    if( d ==NULL) //wystąpił błąd i kod błąd został wpisany do errno
        handleOpenDir(errno);

    struct direct *e; //dlaczego nie dirent?
    char p[MAX_CHAR]; //bufor linijki wyjścia

    while ((e = readdir(d)) != 0)  {
        if (e == NULL) /*wystąpił błąd w readdir*/
            handleReadDir(errno);
        printFileInDir(e,p,path);

    }
    closedir(d);

}

void printFileInDir( struct direct *e ,char *p, char *argv1){

    p[0] = 0;//resetowanie bufora ścieżki
    //tworzenie relatywnej ścieżki pliku
    strcat(p, argv1);
    strcat(p, "/");
    strcat(p, e->d_name);

    struct stat s; // dane (stat o pliku)
    int t = stat(p, &s); //odczytanie dodatkowych informacji
    if( t==-1) //w przypadku gdy nastąpi błąd w czytania stat
        handleStat(errno);

    //type
    char type = '?'; //nieznany typ pliku
    switch(s.st_mode & S_IFMT){ //uzyskujemy samedane o typie
        case S_IFBLK: type='B'; break;
        case S_IFCHR: type='C'; break;
        case S_IFIFO: type='P'; break;
        case S_IFSOCK: type='S'; break;

        case S_IFLNK: type='L'; break;
        case S_IFDIR: type='/'; break;
        case S_IFREG: type=' '; break;
    }
    //mode
    char mode[10];
    for(int i=0;i<9;i++ ) {
        mode[i] = '-';
    }
    mode[9]='\0';

    if (s.st_mode & S_IRUSR)
        mode[0+3*0]='r';
    if (s.st_mode & S_IWUSR)
        mode[1+3*0]='w';
    if (s.st_mode & S_IXUSR)
        mode[2+3*0]='x';

    if (s.st_mode & S_IRGRP)
        mode[0+3*1]='r';
    if (s.st_mode & S_IWGRP)
        mode[1+3*1]='w';
    if (s.st_mode & S_IXGRP)
        mode[2+3*1]='x';

    if (s.st_mode & S_IROTH)
        mode[0+3*2]='r';
    if (s.st_mode & S_IWOTH)
        mode[1+3*2]='w';
    if (s.st_mode & S_IXOTH)
        mode[2+3*2]='x';

    if (s.st_mode & S_ISUID )
        mode[2+3*0]=(s.st_mode & S_IXUSR)?'s':'S';
    if (s.st_mode & S_ISGID )
        mode[2+3*1]=(s.st_mode & S_IXGRP)?'s':'S';
    if (s.st_mode & S_ISVTX )
        mode[2+3*2]=(s.st_mode & S_IXOTH)?'t':'T';

    //size
    off_t size = s.st_size;
    blksize_t blksize = s.st_blksize;     /* Block size for filesystem I/O */
    blkcnt_t  blocks  = s.st_blocks;      /* Number of 512B blocks allocated */

    //device
    dev_t dev = s.st_dev;

    //number of harlinks
    nlink_t nlink = s.st_nlink;

    //inode
    ino_t inode = s.st_ino;

    uid_t uid = s.st_uid;         /* User ID of owner */
    gid_t gid = s.st_gid;         /* Group ID of owner */
    dev_t did = s.st_rdev;        /* Device ID (if special file) */

    char date[25*3];
    size_t offset =0;
    size_t i = strftime(date+offset,25,"%a %b %d %H:%M:%S %Y",localtime(&s.st_atim.tv_sec));/* Access Time */
    if(i ==0)
        errorExit(-2,"data zajmuje za dużo miejsca (do 25 znaków)");
    date[offset+i]=':';
    offset += i+1;
    i =strftime((date+offset),25,"%a %b %d %H:%M:%S %Y",localtime(&s.st_mtim.tv_sec));/* Time of last modification */
    if(i ==0)
        errorExit(-2,"data zajmuje za dużo miejsca (do 25 znaków)");
    date[offset+i]=':';
    offset += i+1;
    i =strftime((date+offset),25,"%a %b %d %H:%M:%S %Y",localtime(&s.st_ctim.tv_sec));/* Time of last status change */
    if(i ==0)
        errorExit(-2,"data zajmuje za dużo miejsca (do 25 znaków)");

    /* mode nlik gid uid size(blksize,blocks) atim mtim ctim (did path) type @ device inode*/
    printf("%9s %3ld %4d %4d %6ld(%4ld,%3ld) %75s (%2ld:%-65s) %c @ %5lx %lx\n", mode,nlink,gid,uid,size,blksize,blocks,date, did,p,type,dev,inode);

    if(S_ISDIR(s.st_mode) && strcmp(e->d_name,"..") != 0 && strcmp(e->d_name,".") != 0)
        printDir(p);
}
int main(int argc, char **argv) {

    if(argc!=2){
        errorExit(-1,"Błędna ilość argumentów\n"
                       "d2 directory");
    }

    printDir(argv[1]);


    return 0;
}

