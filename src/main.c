#include "generate.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
        char *LookUp[3] = {"help" , "generate" , "exit"};
        if(argc == 1){
                printf("information_here\n");
                return 0;
        }
        if(strcmp(argv[1],"generate") == 0){
                printf("generate\n");
                printf("password is: %s\n",generate(8));
        }
        printf("finished!\n");
        return 0;
}
