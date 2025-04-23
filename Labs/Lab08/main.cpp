#include "nonFungiableToken.h"
#include "manageTokens.h"
#include <iostream>

int main() {
  // create token manager
  ManageTokens manager;
  
  // we have our mint tokens
  manager.mintToken("ArtPiece", "bananaDuctTape123");
  manager.mintToken("VirtualLand", "myHouseInTheClouds456");
  
  // display initial wallet states
  std::cout << "Initial wallet states:\n" << std::endl;
  std::cout << "Wallet 1:" << std::endl;
  manager.displayWallet1();
  std::cout << "Wallet 2:" << std::endl;
  manager.displayWallet2();
  
  // transfer a token
  manager.walletTransfer(0);
  
  // display final wallet states
  std::cout << "\n--------------------" << std::endl;
  std::cout << "After transfer:\n" << std::endl;
  std::cout << "Wallet 1:" << std::endl;
  manager.displayWallet1();
  std::cout << "Wallet 2:" << std::endl;
  manager.displayWallet2();
  
  return 0;
}