//
// Created by TeKTeam on 2020-05-26.
//
#include "unity/unity.h"
#include "../src/solution_c_bas_niveau.h"
#include "test_solution_bas_niveau.h"

void setUp(void){
    // Run before each test
}

void tearDown(void){
    // Run after each test
}

int main(void){

    UNITY_BEGIN();

    RUN_TEST(test_strlen);
    RUN_TEST(test_strcpy);

    return UNITY_END();

}

// Tests

void test_strlen(void){

    TEST_ASSERT_EQUAL(0, strlen(""));
    TEST_ASSERT_EQUAL(1, strlen("a"));
    TEST_ASSERT_EQUAL(5, strlen("abcde"));
    TEST_ASSERT_EQUAL(10, strlen("abcdeabcde"));

}

void test_strcpy(void){

    char s[11] = {0};

    TEST_ASSERT_EQUAL_STRING("a", strcpy(s, "a"));
    TEST_ASSERT_EQUAL_STRING("abc", strcpy(s, "abc"));
    TEST_ASSERT_EQUAL_STRING("abcde", strcpy(s, "abcde"));
    TEST_ASSERT_EQUAL_STRING("abcdeabcde", strcpy(s, "abcdeabcde"));

}

void test

