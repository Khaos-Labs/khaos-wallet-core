# Sample macOS Application for [Wallet-Core](https://github.com/Khaos-Labs/khaos-wallet-core)

## Overview

This folder contains a simple but complete **iOS/macOS** sample application, for demostrating usage of the
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

## Prerequisites

* [*CocoaPods*](https://cocoapods.org/).  If you don't have it, install it by
`gem install cocoapods`.
* *Xcode* toolchain

## Building and Running

Go to the **samples/osx/cocoapods** folder within wallet core repo:

```shell
git clone https://github.com/Khaos-Labs/khaos-wallet-core.git
cd wallet-core/samples/osx/cocoapods
```

Install dependencies with CocoaPods:

```shell
pod install
```

* Open the following workspace with Xcode: `osx/cocoapods/WalletCoreExample.xcworkspace` 
* Build and Run

The relevant sample code is in the file [`WalletCoreExample/ViewController.swift`](https://github.com/Khaos-Labs/khaos-wallet-core/blob/master/samples/osx/cocoapods/WalletCoreExample/ViewController.swift).
Output appears in Output window (or stdout).

```
├── Podfile
├── Podfile.lock
├── WalletCoreExample
│   ├── AppDelegate.swift
│   ├── Info.plist
│   ├── ViewController.swift
│   └── WalletCoreExample.entitlements
├── WalletCoreExample.xcodeproj
└── WalletCoreExample.xcworkspace
```


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
