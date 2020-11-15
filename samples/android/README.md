# Sample Android Application for [Wallet-Core](https://github.com/Khaos-Labs/khaos-wallet-core)

## Overview

This folder contains a simple but complete **Android** sample application, for demonstrating usage of the
[Wallet Core](https://github.com/Khaos-Labs/khaos-wallet-core) library (part of [Khaos Wallet](https://khaoswallet.com)).

## DISCLAIMER

> This is a sample application with demonstration purpose only,
> do not use it with real addresses, real transactions, or real funds.
> Use it at your own risk.

## Documentation

See the official [Khaos Wallet developer documentation here](https://developer.khaoswallet.com).

See especially Wallet Core
[Integration Guide](https://developer.khaoswallet.com/wallet-core/integration-guide),
and [Build Instructions](https://developer.khaoswallet.com/wallet-core/building).

## Building and Running

Open in Android Studio and run. Result will appear in logs output and on device screen.

The relevant source code is in [`samples/android/app/src/main/java/com/trust/walletcore/example/MainActivity.kt`](https://github.com/Khaos-Labs/khaos-wallet-core/blob/master/samples/android/app/src/main/java/com/trust/walletcore/example/MainActivity.kt).

# What it Does

An overview of the operations done in the sample app is as follows.

* Import a wallet
  * Create a wallet by importing an existing recovery phrase (mnemonic), using HDWallet.
* Derive address
  * Address is derived from the HD wallet.
* Create send transaction
  * put together a send transaction (contains sender and receiver address, amount, etc.)
  * sign this transaction (using the private key)

See the [Integration Guide](https://developer.khaoswallet.com/wallet-core/integration-guide).
