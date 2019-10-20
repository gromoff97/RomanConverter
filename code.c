#include <stdio.h>

#define LAST_INDEX 12

int number_buffer[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
char* symbol_buffer[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

void print_roman(int input_number);

/* Driver program */
int main()
{
    print_roman(3549);
    return 0;
}

/* unction to convert decimal to Roman Numerals */
void print_roman(int input_number)
{
    int index = LAST_INDEX;

    if (input_number == 0)
    {
      printf("0");
      return;
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
