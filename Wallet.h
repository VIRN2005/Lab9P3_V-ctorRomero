#ifndef WALLET_H
#define WALLET_H

#include <iostream>
#include <string>
#include "paypal.h"

class Wallet {
private:
    string nombreUsuario;
    Paypal* paypal;
    string contrasena;
    float dogeCoin;
    float etherium;
    float walterCoin;

public:
    Wallet();
    Wallet(string nombreUsuario, Paypal* paypal, string contrasena);

    const string& GetNombreUsuario() const;
    float GetDogeCoin() const;
    float GetEtherium() const;
    float GetWalterCoin() const;

    void CrearWallet(Paypal* paypal);
    void AccederWallet(UsuarioPaypal* usuario);
    string GetNombreUsuario();
    bool ComprobarContrasena(string);
    void ComprarCryptos();
    void VenderCryptos();
};

#endif


