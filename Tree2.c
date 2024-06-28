#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    char *B = "TESTTP";

    printf("Parent: ");
    fflush(stdout);

    for ( int i = 3, x = 0; i; --i, x += 2 ){

        if ( fork() == 0 ) {

            printf("%c", B[x]);
            fflush(stdout);

            if ( fork() == 0 ) {
                printf("%c", B[++x]);

                if ( i == 2 )
                    printf(" ");
            } else
                wait (0);
            
            exit (0);
        }

        wait(0);
    }

    exit (0);
}
