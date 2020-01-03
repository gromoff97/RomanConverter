#ifndef _CNVTOROM_H_
#define _CNVTOROM_H_

#include <stdint.h>

#define BUFFS_SIZE 13
#define LAST_INDEX (BUFFS_SIZE - 1)
#define INPUT_MAX_SIZE 32
#define ROMAN_BUFFER_MAX_SIZE 256

char* strtorom(const char*);
void print_roman(int32_t);
int is_positive_number(const char*);

extern const int NUMBERS_BUFFER[BUFFS_SIZE];
extern const char* const SYMBOLS_BUFFER[BUFFS_SIZE];

#endif