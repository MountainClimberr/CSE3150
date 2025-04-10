#include "tokenizer.h"
#include <iostream>

int main(){
  Tokenizer tokenizer;

  // process input file
  std::cout << "File: verdict.txt" << std::endl;
  if (!tokenizer.tokenizeFile("verdict.txt")){
    return 1;
  }

  // show the tokenizer size
  std::cout << "\nFound " << tokenizer.size() << " unique words" << std::endl;

  // show token lookups
  std::cout << "\nToken lookups:" << std::endl;
  std::cout << "'Jack' token ID: " << tokenizer.findTokenId("Jack") << std::endl;
  std::cout << "'eye' token ID: " << tokenizer.findTokenId("eye") << std::endl;
  std::cout << "'laugh' token ID: " << tokenizer.findTokenId("laugh") << std::endl;

  // show word lookuos
  std::cout << "\nWord lookups:" << std::endl;
  std::cout << "Token ID 0: " << tokenizer.findWord(0) << std::endl;
  std::cout << "Token ID 10: " << tokenizer.findWord(10) << std::endl;
  std::cout << "Token ID 20: " << tokenizer.findWord(20) << std::endl;

  // edge cases
  std::cout << "\nEdge cases:" << std::endl;
  std::cout << "Nonexistent word 'xyz123': " << tokenizer.findTokenId("xyz123") << std::endl;
  std::cout << "Nonexistent token ID 9999: '" << tokenizer.findWord(9999) << "'" << std::endl;

  return 0;
}