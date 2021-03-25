// Linux C Program

// main [-a] [-b x] [-c xx]

// -Use getopt for command line arguments

// -a – Prints hey then terminates

// -b x – Inputs number into x

// -c xx – Inputs name of file into xx

/**
 * importing the header files
*/
#include <stdio.h>
#include <unistd.h>
#include <string>

/**
 * print function for command a
*/
void printtext(){
    printf ("hey!! \n");
}

/**
 * Pass the arguments
*/
int main(int argc, char** argv)
{
    int command, opt;

    int x;

    char xx[100];

    /**
     * Loop through all the commands.
     * Ends if it gets -1 internally.
     * commands eligible are "a, b, c".
     * use optind as index(in-built) and argv to get the parameters
    */
    while ((opt = getopt(argc, argv, ":if:abc")) != -1)
    {
        switch(opt){

            case 'a' :
            printtext();
            break;

            case 'b' :
            printf("Input parameter is: %s \n", argv[optind]);
            x = atoi(argv[optind]);
            optind++;
            break;

            case 'c' :
            printf("file name is: %s \n", argv[optind]);
            strcpy(xx, argv[optind]);
            break;

        }
    }
    return 0;
}