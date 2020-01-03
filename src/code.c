#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* custom header-file */
#include <cnvtorom.h>

/* Driver program */
int main()
{
    /* Here is the place where input is stored. */
    char input[INPUT_MAX_SIZE];

    char* result;

    /* Simplest UI offering to enter something. */
    puts("Please enter value:");

    /* Reading from keyboard (strictly speaking, from standard input). */
    if (NULL == fgets(input, INPUT_MAX_SIZE, stdin))
    {
      fprintf(stderr, "Error occured while reading input.\n");
      return -1;
    }

    /* Removing trailing newline. */
    input[strcspn(input, "\n")] = '\0';

    /* Calling function which converts char */
    result = strtorom(input);

    if (NULL == result)
    {
      fprintf(stderr, "Error occured while converting.\n");
      return -2;
    }

    printf("%s", result);

    /* Should free because strtorom allocates memory for result */
    free(result);

    return 0;
}