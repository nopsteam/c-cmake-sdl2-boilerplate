#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

#include <stdint.h>

typedef struct example_s {
    uint8_t *key;
    uint8_t *val;
    size_t key_length;
    size_t val_length;
} example_t;

example_t * example_new_with_cstr(char *key, char *val);

void example_print_cstr(example_t *example);

void example_free(example_t *example);

#endif // __EXAMPLE_H__
