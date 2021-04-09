#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "sample.h"

static char *key = "test_key";
static char *val = "test_val";
static sample_t *sample = NULL;

void setUp(void) {
  // set stuff up here
  sample = sample_new_with_cstr(key, val);
}

void tearDown(void) {
  // clean stuff up here
  if (sample) {
    sample_free(sample);
  }
}

void test_function_should_doAlsoDoBlah(void) {
  TEST_ASSERT_EQUAL_STRING(key, sample->key);
  TEST_ASSERT_EQUAL_STRING(val, sample->val);
}

void test_function_should_doAlsoDoBlah_non_static(void) {
  sample_t *sample2 = sample_new_with_cstr(key, val);
  sample_print_cstr(sample2);
  TEST_ASSERT_EQUAL_STRING(key, sample2->key);
  TEST_ASSERT_EQUAL_STRING(val, sample2->val);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_should_doAlsoDoBlah);
    RUN_TEST(test_function_should_doAlsoDoBlah_non_static);
    return UNITY_END();
}
