#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "example.h"

static char *key = "test_key";
static char *val = "test_val";
static example_t *example = NULL;

void setUp(void) {
  // set stuff up here
  example = example_new_with_cstr(key, val);
}

void tearDown(void) {
  // clean stuff up here
  if (example) {
    example_free(example);
  }
}

void test_function_should_doAlsoDoBlah(void) {
  TEST_ASSERT_EQUAL_STRING(key, example->key);
  TEST_ASSERT_EQUAL_STRING(val, example->val);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_should_doAlsoDoBlah);
    return UNITY_END();
}
