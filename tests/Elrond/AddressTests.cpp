// Copyright © 2017-2020 Khaos Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <gtest/gtest.h>
#include <vector>

#include "HexCoding.h"
#include "PublicKey.h"
#include "PrivateKey.h"
#include "Elrond/Address.h"
#include "TestAccounts.h"

using namespace TW;
using namespace TW::Elrond;


TEST(ElrondAddress, Valid) {
    ASSERT_TRUE(Address::isValid(ALICE_BECH32));
    ASSERT_TRUE(Address::isValid(BOB_BECH32));
    ASSERT_TRUE(Address::isValid(CAROL_BECH32));
}

TEST(ElrondAddress, Invalid) {
    ASSERT_FALSE(Address::isValid(""));
    ASSERT_FALSE(Address::isValid("foo"));
    ASSERT_FALSE(Address::isValid("10z9xdugayn528ksaesdwlhf006fw5sg2qmmm0h52fvxczwgesyvq5pwemr"));
    ASSERT_FALSE(Address::isValid("xerd10z9xdugayn528ksaesdwlhf006fw5sg2qmmm0h52fvxczwgesyvq5pwemr"));
    ASSERT_FALSE(Address::isValid("foo10z9xdugayn528ksaesdwlhf006fw5sg2qmmm0h52fvxczwgesyvq5pwemr"));
    ASSERT_FALSE(Address::isValid(ALICE_PUBKEY_HEX));
}

TEST(ElrondAddress, FromString) {
    Address alice, bob, carol;
    ASSERT_TRUE(Address::decode(ALICE_BECH32, alice));
    ASSERT_TRUE(Address::decode(BOB_BECH32, bob));
    ASSERT_TRUE(Address::decode(CAROL_BECH32, carol));
    
    ASSERT_EQ(ALICE_PUBKEY_HEX, hex(alice.getKeyHash()));
    ASSERT_EQ(BOB_PUBKEY_HEX, hex(bob.getKeyHash()));
    ASSERT_EQ(CAROL_PUBKEY_HEX, hex(carol.getKeyHash()));
}

TEST(ElrondAddress, FromData) {
    const auto alice = Address(parse_hex(ALICE_PUBKEY_HEX));
    const auto bob = Address(parse_hex(BOB_PUBKEY_HEX));
    const auto carol = Address(parse_hex(CAROL_PUBKEY_HEX));
    
    ASSERT_EQ(ALICE_BECH32, alice.string());
    ASSERT_EQ(BOB_BECH32, bob.string());
    ASSERT_EQ(CAROL_BECH32, carol.string());
}

TEST(ElrondAddress, FromPrivateKey) {
    auto aliceKey = PrivateKey(parse_hex(ALICE_SEED_HEX));
    auto alice = Address(aliceKey.getPublicKey(TWPublicKeyTypeED25519));
    ASSERT_EQ(ALICE_BECH32, alice.string());

    auto bobKey = PrivateKey(parse_hex(BOB_SEED_HEX));
    auto bob = Address(bobKey.getPublicKey(TWPublicKeyTypeED25519));
    ASSERT_EQ(BOB_BECH32, bob.string());

    auto carolKey = PrivateKey(parse_hex(CAROL_SEED_HEX));
    auto carol = Address(carolKey.getPublicKey(TWPublicKeyTypeED25519));
    ASSERT_EQ(CAROL_BECH32, carol.string());
}

TEST(ElrondAddress, FromPublicKey) {
    auto alice = PublicKey(parse_hex(ALICE_PUBKEY_HEX), TWPublicKeyTypeED25519);
    ASSERT_EQ(ALICE_BECH32, Address(alice).string());

    auto bob = PublicKey(parse_hex(BOB_PUBKEY_HEX), TWPublicKeyTypeED25519);
    ASSERT_EQ(BOB_BECH32, Address(bob).string());

    auto carol = PublicKey(parse_hex(CAROL_PUBKEY_HEX), TWPublicKeyTypeED25519);
    ASSERT_EQ(CAROL_BECH32, Address(carol).string());
}
