#include "nonFungiableToken.h"
#include <iostream>
#include <sstream>
#include <iomanip>

NfToken::NfToken(const std::string& tokenName, const std::string& assetString) : name(tokenName){
  // generate hash value using SHA-256
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, assetString.c_str(), assetString.size());
  SHA256_Final(hash, &sha256);
  
  // convert hash to hex string
  std::stringstream ss;
  for(int i = 0; i < SHA256_DIGEST_LENGTH; i++){
    ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
  }
  hashValue = ss.str();
}

std::string NfToken::getName() const{
  return name;
}

std::string NfToken::getHashValue() const{
  return hashValue;
}

void NfToken::display() const{
  std::cout << "Token: " << name << "\nHash: " << hashValue << std::endl;
}