#include "../src/function.h"
#define CATCH_CONFIG_MAIN
#include "../thirdparty/catch.hpp"

TEST_CASE("Past Simple form is guessed")
{
    char* word = "cut";
    char* filename = "test.txt";
    int result = input_simple_word(word, filename);
    int expected_simple = 1;
    REQUIRE(expected_simple == result);
}

TEST_CASE("Past Simple form isn't guessed �1")
{
    char* word = "chaos";
    char* filename = "test.txt";
    int result = input_simple_word(word, filename);
    int expected_simple = 0;
    REQUIRE(expected_simple == result);
}

TEST_CASE("Past Simple form isn't guessed �2")
{
    char* word = "random_ch@r@ct3r5";
    char* filename = "test.txt";
    int result = input_simple_word(word, filename);
    int expected_simple = 0;
    REQUIRE(expected_simple == result);
}

TEST_CASE("Past Participle form is guessed")
{
    char* word = "cut";
    char* filename = "test.txt";
    int result = input_participle_word(word, filename);
    int expected_participle = 1;
    REQUIRE(expected_participle == result);
}

TEST_CASE("Past Participle form isn't guessed �1")
{
    char* word = "cat";
    char* filename = "test.txt";
    int result = input_participle_word(word, filename);
    int expected_participle = 0;
    REQUIRE(expected_participle == result);
}

TEST_CASE("Past Participle form isn't' guessed �2")
{
    char* word = "unexpectable_word";
    char* filename = "test.txt";
    int result = input_participle_word(word, filename);
    int expected_participle = 0;
    REQUIRE(expected_participle == result);
}
