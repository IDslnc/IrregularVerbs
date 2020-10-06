#include <ctest.h>
#include <function.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

CTEST(INPUT_SIMPLE_WORD, FIRST_TEST)
{
    char* word = "cut";
    char* filename = "test.txt";
    int result = input_simple_word(word, filename);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(INPUT_SIMPLE_WORD, SECOND_TEST)
{
    char* word = "chaos";
    char* filename = "test.txt";
    int result = input_simple_word(word, filename);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(INPUT_SIMPLE_WORD, THIRD_TEST)
{
    char* word = "random2@";
    char* filename = "test.txt";
    int result = input_simple_word(word, filename);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(INPUT_PARTICIPLE_WORD, FIRST_TEST)
{
    char* word = "cut";
    char* filename = "test.txt";
    int result = input_participle_word(word, filename);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(INPUT_PARTICIPLE_WORD, SECOND_TEST)
{
    char* word = "cat";
    char* filename = "test.txt";
    int result = input_participle_word(word, filename);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(INPUT_PARTICIPLE_WORD, THIRD_TEST)
{
    char* word = "under_tree";
    char* filename = "test.txt";
    int result = input_participle_word(word, filename);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}
