
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>
#include <string.h>

static void sighandler(int signo){
    
    if(signo == SIGINT){
        
        int batman = open("bat.txt",O_APPEND | O_RDWR);
        write(batman,"Exited because of a SIGINT\n", 30);
        close(batman);
        
        printf("Oh no! A SIGINT!\n");
        exit(1);
    }
    
    if(signo == SIGUSR1){
        printf("Parent PID: %d\n", getppid());
    }
}

int main(){
    
    signal( SIGINT, sighandler );
    signal( SIGUSR1, sighandler );
    
    while(1){
        printf("PID: %d\n", getpid());
        sleep(1);
    }
}
