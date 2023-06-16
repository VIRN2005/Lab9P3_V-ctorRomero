#include "wallet.h"
#include <iostream>
using namespace std;

Wallet::Wallet(string nombreUsuario, Paypal* paypal, string contrasena) {
    this->nombreUsuario = nombreUsuario;
    this->paypal = paypal;
    this->contrasena = contrasena;
    dogeCoin = 0.0f;
    etherium = 0.0f;
    walterCoin = 0.0f;
}

string Wallet::GetNombreUsuario() {
    return nombreUsuario;
}

bool Wallet::ComprobarContrasena(string contrasena) {
    return this->contrasena == contrasena;
}

