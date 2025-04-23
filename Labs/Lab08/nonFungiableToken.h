#ifndef NON_FUNGIABLE_TOKEN_H
#define NON_FUNGIABLE_TOKEN_H

#include <string>
#include <openssl/sha.h>

class NfToken{
private:
  std::string name;
  std::string hashValue;
public:
  // constructor to create a token with a name and asset string
  NfToken(const std::string& tokenName, const std::string& assetString);
  
  // getters for name and hash value
  std::string getName() const;
  std::string getHashValue() const;
  
  // function to display token
  void display() const;
};

#endif