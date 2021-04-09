#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sample.h"

sample_t * sample_new_with_cstr(char *key, char *val) {
    sample_t *ret = (sample_t *) calloc(1, sizeof(sample_t));
    if (!ret) {
        return NULL;
    }

    ret->key_length = strlen(key) + 1;
    ret->val_length = strlen(val) + 1;

    ret->key = (uint8_t *) calloc(ret->key_length, sizeof(char));
    if (!ret->key) {
        goto cleanup_ret;
    }
    strncpy((char *)ret->key, key, ret->key_length);


    ret->val = (uint8_t *) calloc(ret->val_length, sizeof(char));
    if (!ret->val) {
        goto cleanup_key;
    }
    strncpy((char *)ret->val, val, ret->val_length);

    return ret;

cleanup_key:
    free(ret->key);
cleanup_ret:
    free(ret);
    return NULL;
}

void sample_print_cstr(sample_t *sample) {
    printf("key: %s (%lu bytes)\n", sample->key, sample->key_length);
    printf("val: %s (%lu bytes)\n", sample->val, sample->val_length);
}

void sample_free(sample_t *sample) {
    if (sample != NULL) {
        if (sample->key != NULL) {
            free(sample->key);
        }
        if (sample->val != NULL) {
            free(sample->val);
        }
        free(sample);
    }
}
