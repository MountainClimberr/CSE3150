#include "nonFungiableToken.h"
#include "manageTokens.h"
#include <cassert>
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("NfToken tests") {
  SUBCASE("token creation and hash generation") {
    NfToken token("TestToken", "testAsset123");

    // check that name is set correctly
    CHECK(token.getName() == "TestToken");

    // check that hash is not empty
    CHECK(token.getHashValue() != "");

    // check that hash is unique for different asset strings
    NfToken tokenA("TokenA", "sameAsset");
    NfToken tokenB("TokenB", "sameAsset");
    CHECK(tokenA.getHashValue() == tokenB.getHashValue());

    // creating tokens with different asset strings should give different hashes
    NfToken tokenC("TokenC", "differentAsset");
    CHECK(tokenA.getHashValue() != tokenC.getHashValue());
  }
}

TEST_CASE("ManageTokens functionality tests") {
  ManageTokens manager;

  SUBCASE("minting tokens") {
    // check initial wallet sizes
    CHECK(manager.getWallet1Size() == 0);
    CHECK(manager.getWallet2Size() == 0);

    // mint a token to wallet1
    manager.mintToken("Token1", "testAsset1");
    CHECK(manager.getWallet1Size() == 1);
    CHECK(manager.getWallet2Size() == 0);

    // mint another token
    manager.mintToken("Token2", "testAsset2");
    CHECK(manager.getWallet1Size() == 2);
  }

  SUBCASE("transferring tokens") {
    // mint two tokents 
    manager.mintToken("Token1", "testAsset1");
    manager.mintToken("Token2", "testAsset2");
    CHECK(manager.getWallet1Size() == 2);
    CHECK(manager.getWallet2Size() == 0);

    // transfer first token
    bool success = manager.walletTransfer(0);
    CHECK(success == true);
    CHECK(manager.getWallet1Size() == 1);
    CHECK(manager.getWallet2Size() == 1);

    // transfer second token
    success = manager.walletTransfer(0);
    CHECK(success == true);
    CHECK(manager.getWallet1Size() == 0);
    CHECK(manager.getWallet2Size() == 2);

    // transfer an empty wallet 
    success = manager.walletTransfer(0);
    CHECK(success == false);
  }
}