#include <stdint.h>

typedef struct sample_s {
    uint8_t *key;
    uint8_t *val;
    size_t key_length;
    size_t val_length;
} sample_t;

sample_t * sample_new_with_cstr(char *key, char *val);

void sample_print_cstr(sample_t *sample);

void sample_free(sample_t *sample);
