#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

/* custom header-file */
#include <cnvtorom.h>

const int numbers_buffer[BUFFS_SIZE] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
const char* const symbols_buffer[BUFFS_SIZE] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

int is_positive_number(const char* input_buffer)
{
  size_t input_buffer_length;
  size_t char_counter;

  if (NULL == input_buffer)
    return -1;

  input_buffer_length = strlen(input_buffer);

  if (0 == input_buffer_length)
    return -2;

  for (char_counter = 0; char_counter < input_buffer_length; char_counter++)
    if (0 == isdigit(input_buffer[char_counter]))
      return -3;

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
  size_t numbers_counter;

  /* Validating function's argument. */
  if (0 != is_positive_number(input_buffer))
    return NULL;

  /* Converting char buffer to integer. */
  input_number = strtol(input_buffer, NULL, 10);

  /* If number is greater than 3999 then exit. */
  if (input_number > 3999)
    return NULL;

  /* Assigning to last element's index because this is how main loop works.*/
  numbers_counter = LAST_INDEX;

  /* Allocating enough memory for result. */
  result_buffer = malloc(sizeof(char) * ROMAN_BUFFER_MAX_SIZE);

  if (NULL == result_buffer)
    return NULL;

  /* Setting start index for result buffer */
  result_counter = 0;

  /* Main loop. */
  while (input_number > 0)
  {
    int64_t div = input_number / numbers_buffer[numbers_counter];

    while (div != 0)
    {
      strcat(&result_buffer[result_counter], symbols_buffer[numbers_counter]);
      result_counter += strlen(symbols_buffer[numbers_counter]);
      div--;
    }

    input_number = input_number % numbers_buffer[numbers_counter];
    numbers_counter--;
  }

  return result_buffer;
}