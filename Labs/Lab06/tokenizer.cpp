#include "tokenizer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <regex>

bool Tokenizer::tokenizeFile(const std::string& filename){
  std::ifstream file(filename);
  std::string line;
  std::regex wordPattern(R"(\b\w+\b)");

  // goes through the file line by line
  while (std::getline(file, line)){
    std::sregex_iterator wordIter(line.begin(), line.end(), wordPattern);
    std::sregex_iterator end;

    for (; wordIter != end; ++wordIter){
      std::string word = wordIter->str();
      if (wordToId.find(word) == wordToId.end()){
        int newId = idToWord.size();
        wordToId[word] = newId;
        idToWord.push_back(word);
      }
    }
  }

  file.close();
  return true;
}

// finds token id for a given word
int Tokenizer::findTokenId(const std::string& word) const{
  auto it = wordToId.find(word);
  if (it != wordToId.end()){
    return it->second;
  }
  // returns -1 if the word is not found
  return -1;
}

// finds word for a given token id
std::string Tokenizer::findWord(int tokenId) const{
  if (tokenId >= 0 && tokenId < static_cast<int>(idToWord.size())){
    return idToWord[tokenId];
  }
  // returns an empty string if the token ID is out of range
  return "";
}

// returns the number of unique tokens
size_t Tokenizer::size() const{
  return idToWord.size();
}