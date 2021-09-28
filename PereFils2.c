#include <errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void erreurFin(const char* msg){
    perror(msg);
}

int main(void){
    pid_t pid;
    int status;

    pid = fork();
    switch (pid)
    {
    case -1:
        erreurFin("erreur de fork");
        exit(1);
    case 0:
    printf("je suis le fils  %d et le pid de mon père est %d \n",getpid(), getppid());
    exit(127);
    
    default:
        printf(" je suis le père : mon pid est %d \n", getpid());
        wait(&status);
        if(WIFEXITED(status)){
            printf(" le fils est mort normalement et le code retour est %d est %d \n", WEXITSTATUS(status),pid);
        }
    }
}