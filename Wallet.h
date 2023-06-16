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
    Wallet(string nombreUsuario, Paypal* paypal, string contrasena);

    string GetNombreUsuario();
    bool ComprobarContrasena(string);
    void ComprarCryptos();
    void VenderCryptos();
};

#endif


