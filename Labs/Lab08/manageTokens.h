#ifndef MANAGE_TOKENS_H
#define MANAGE_TOKENS_H

#include "nonFungiableToken.h"
#include <vector>
#include <memory>

class ManageTokens{
private:
  // Two wallets to hold tokens
  std::vector<std::unique_ptr<NfToken>> wallet1;
  std::vector<std::unique_ptr<NfToken>> wallet2;

  // Transfer a token from one vector to another
  void transferNftVector( std::vector<std::unique_ptr<NfToken>>& toVector, 
                          std::vector<std::unique_ptr<NfToken>>& fromVector, 
                          std::vector<std::unique_ptr<NfToken>>::iterator pos);

public:
  // Constructor
  ManageTokens() = default;

  // Mint a new token and add it to wallet1
  void mintToken(const std::string& name, const std::string& assetString);

  // Transfer a token from wallet1 to wallet2
  bool walletTransfer(int tokenIndex);

  // Display wallets
  void displayWallet1() const;
  void displayWallet2() const;

  // Get sizes of wallets
  size_t getWallet1Size() const;
  size_t getWallet2Size() const;
};

#endif