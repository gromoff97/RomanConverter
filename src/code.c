#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#define LAST_INDEX 12
#define INPUT_MAX_SIZE 32

int number_buffer[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
char* symbol_buffer[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

void print_roman(int32_t input_number);
int is_number(const char* input_buffer);

/* Driver program */
int main()
{
    char input[INPUT_MAX_SIZE];
    int64_t input_int;

    puts("Please enter value:");
    if (NULL == fgets(input, INPUT_MAX_SIZE, stdin))
    {
      fprintf(stderr, "Error occured while reading input.\n");
      return -1;
    }

    /* removing trailing newline */
    input[strcspn(input, "\n")] = '\0';

    if (0 != is_number(input))
    {
      fprintf(stderr, "Error occured while validating: '%s' is not a number.\n", input);
      return -2;
    }

    input_int = strtol(input, NULL, 10);
    print_roman(input_int);
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

/* function to convert decimal to Roman Numerals */
void print_roman(int32_t input_number)
{
    size_t index = LAST_INDEX;

    if (input_number == 0)
    {
      printf("0");
      return;
    }

    if (input_number < 0)
    {
      printf("-");
      input_number = -input_number;
    }

    while (input_number > 0)
    { 
      int div = input_number / number_buffer[index];

      while (div != 0)
      {
        printf("%s", symbol_buffer[index]);
        div--;
      }

      input_number = input_number % number_buffer[index];
      index--;
    }
}
