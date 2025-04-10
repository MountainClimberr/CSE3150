#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <unordered_map>
#include <vector>

class Tokenizer{
private:
    std::unordered_map<std::string, int> wordToId;
    std::vector<std::string> idToWord;

public:
    bool tokenizeFile(const std::string& filename);
    int findTokenId(const std::string& word) const;
    std::string findWord(int tokenId) const;
    size_t size() const;
};

#endif