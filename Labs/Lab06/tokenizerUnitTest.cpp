#include "tokenizer.h"
#include <cassert>
#include <iostream>
#include <fstream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("tokenizer functionality tests"){
  Tokenizer tokenizer;
  bool loaded = tokenizer.tokenizeFile("verdict.txt");
  REQUIRE(loaded == true);

  SUBCASE("check token IDs"){
    // The first few words in the-verdict.txt should have these tokens
    CHECK(tokenizer.findTokenId("I") == 0);
    CHECK(tokenizer.findTokenId("HAD") == 1);
    CHECK(tokenizer.findTokenId("always") == 2);
    CHECK(tokenizer.findTokenId("thought") == 3);
    CHECK(tokenizer.findTokenId("Jack") == 4);

    CHECK(tokenizer.findTokenId("She") != -1);
    CHECK(tokenizer.findTokenId("raised") != -1);
    CHECK(tokenizer.findTokenId("her") != -1);
    CHECK(tokenizer.findTokenId("eyebrows") != -1);
  }

  SUBCASE("check token words"){
    CHECK(tokenizer.findWord(0) == "I");
    CHECK(tokenizer.findWord(1) == "HAD");
    CHECK(tokenizer.findWord(2) == "always");
    CHECK(tokenizer.findWord(3) == "thought");
    CHECK(tokenizer.findWord(4) == "Jack");


    int raisedToken = tokenizer.findTokenId("raised");
    CHECK(tokenizer.findWord(raisedToken) == "raised");
    int eyebrowsToken = tokenizer.findTokenId("eyebrows");
    CHECK(tokenizer.findWord(eyebrowsToken) == "eyebrows");
  }

  SUBCASE("check invalid inputs"){
    // test for non-existent words
    CHECK(tokenizer.findTokenId("asdfg") == -1);

    // test for out of range token IDs
    CHECK(tokenizer.findWord(-1) == "");
    CHECK(tokenizer.findWord(9999) == "");
  }
}