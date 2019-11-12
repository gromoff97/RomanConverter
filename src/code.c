#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#define LAST_INDEX 12
#define INPUT_MAX_SIZE 32

int numbers_buffer[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
char* symbols_buffer[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

char* strtorom(const char* input_buffer);
void print_roman(int32_t input_number);
int is_number(const char* input_buffer);

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

int is_number(const char* input_buffer)
{
  size_t input_buffer_length;
  size_t char_counter;
  size_t start_index;

  if (NULL == input_buffer)
    return -1;

  input_buffer_length = strlen(input_buffer);

  if (0 == input_buffer_length)
    return -2;

  if ('-' == input_buffer[0] && 1 == input_buffer_length)
    return -3;

  start_index = ('-' == input_buffer[0]) ? 1 : 0;

  for (char_counter = start_index; char_counter < input_buffer_length; char_counter++)
    if (0 == isdigit(input_buffer[char_counter]))
      return -4;

  return 0;
}

/* Function for converting string to Roman Numerals. */
char* strtorom(const char* input_buffer)
{
  /* Represents pointer to buffer which possibly will contain string in Roman Numerals. */
  char* result_buffer;

  /* Represents the offset in result buffer. */
  size_t result_counter;

  /* Represents the integer value whis is got from function's argument */
  int64_t input_number;

  /* Represents the offset in buffers describing relation between decimal numbers and roman numbers. */
  size_t numbers_index;

  /* Validating function's argument. */
  if (0 != is_number(input_buffer))
    return NULL;

  /* Converting char buffer to integer. */
  input_number = strtol(input_buffer, NULL, 10);

  /* Allocating enough memory for result. */
  result_buffer = malloc(sizeof(char) * 1024);

  /* If converted number equals to 0 then there is no point to continue main loop. */
  if (input_number == 0)
  {
    result_buffer = "0\0";
    return result_buffer;
  }

  /* If converted number is less than zero then add 'minus'-symbol to start of result buffer before main loop. */
  if (input_number < 0)
  {
    result_buffer[0] = '-';
    input_number = -input_number;
  }

  /* Assigning to last element's index because this is how main loop works.*/
  numbers_index = LAST_INDEX;

  /* If 'minus'-symbol exists in result buffer then set offset to 1. Otherwise set to 0 */
  result_counter = (result_buffer[0] == '-') ? 1 : 0;

  /* Main loop. */
  while (input_number > 0)
  {
    int64_t div = input_number / numbers_buffer[numbers_index];

    while (div != 0)
    {
      strcat(&result_buffer[result_counter], symbols_buffer[numbers_index]);
      result_counter += strlen(symbols_buffer[numbers_index]);
      div--;
    }

    input_number = input_number % numbers_buffer[numbers_index];
    numbers_index--;
  }

  return result_buffer;
}
