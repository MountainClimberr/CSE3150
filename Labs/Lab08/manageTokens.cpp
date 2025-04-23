#include "manageTokens.h"
#include <iostream>

//mMint a new token and add it to wallet1
void ManageTokens::mintToken(const std::string& name, const std::string& assetString){
  wallet1.push_back(std::unique_ptr<NfToken>(new NfToken(name, assetString)));
}

// transfer a token from wallet1 to wallet2
bool ManageTokens::walletTransfer(int tokenIndex){
  if (tokenIndex < 0 || tokenIndex >= wallet1.size()){
    return false;
  }

  auto pos = wallet1.begin() + tokenIndex;
  transferNftVector(wallet2, wallet1, pos);
  return true;
}

// display wallet1
void ManageTokens::displayWallet1() const{
  std::cout << "Wallet 1 contains " << wallet1.size() << " tokens:" << std::endl;
  for (size_t i = 0; i < wallet1.size(); i++){
    std::cout << "Token " << i << ":" << std::endl;
    wallet1[i]->display();
    std::cout << std::endl;
  }
}

// display wallet2
void ManageTokens::displayWallet2() const{
  std::cout << "Wallet 2 contains " << wallet2.size() << " tokens:" << std::endl;
  for (size_t i = 0; i < wallet2.size(); i++){
    std::cout << "Token " << i << ":" << std::endl;
    wallet2[i]->display();
    std::cout << std::endl;
  }
}

// get size of wallet1
size_t ManageTokens::getWallet1Size() const{
  return wallet1.size();
}

// get size of wallet2
size_t ManageTokens::getWallet2Size() const{
  return wallet2.size();
}

// transfer a token from one vector to another
void ManageTokens::transferNftVector( std::vector<std::unique_ptr<NfToken>>& toVector,
                                      std::vector<std::unique_ptr<NfToken>>& fromVector,
                                      std::vector<std::unique_ptr<NfToken>>::iterator pos){
  toVector.push_back(std::move(*pos));
  (*pos).release();
  fromVector.erase(pos);
}