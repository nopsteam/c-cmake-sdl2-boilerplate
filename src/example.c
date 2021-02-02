#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "example.h"

example_t * example_new_with_cstr(char *key, char *val) {
    example_t *ret = (example_t *) calloc(1, sizeof(example_t));
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

void example_print_cstr(example_t *example) {
    printf("key: %s (%lu bytes)\n", example->key, example->key_length);
    printf("val: %s (%lu bytes)\n", example->val, example->val_length);
}

void example_free(example_t *example) {
    if (example != NULL) {
        if (example->key != NULL) {
            free(example->key);
        }
        if (example->val != NULL) {
            free(example->val);
        }
        free(example);
    }
}
