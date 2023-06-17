#include "wallet.h"
#include <iostream>
using namespace std;

Wallet::Wallet() {
}

Wallet::Wallet(string nombreUsuario, Paypal* paypal, string contrasena) {
    this->nombreUsuario = nombreUsuario;
    this->paypal = paypal;
    this->contrasena = contrasena;
    dogeCoin = 0.0f;
    etherium = 0.0f;
    walterCoin = 0.0f;
}

const string& Wallet::GetNombreUsuario() const {
    return nombreUsuario;
}

float Wallet::GetDogeCoin() const {
    return dogeCoin;
}

float Wallet::GetEtherium() const {
    return etherium;
}

float Wallet::GetWalterCoin() const {
    return walterCoin;
}

string Wallet::GetNombreUsuario() {
    return nombreUsuario;
}

bool Wallet::ComprobarContrasena(string contrasena) {
    return this->contrasena == contrasena;
}

void Wallet::ComprarCryptos() {
    float precio;
    string cryptocoin;
    
    cout << "Seleccione la criptomoneda que desea comprar:" << endl;
    cout << "1) DogeCoin" << endl;
    cout << "2) Etherium" << endl;
    cout << "3) WalterCoin" << endl;

    int opcion_Coin;
    cout << "Seleccione una opcion de Criptomoneda: ";
    cin >> opcion_Coin;

    float monto;
    cout << "Ingrese el monto a comprar: $";
    cin >> monto;

    switch (opcion_Coin) {
    case 1:
        precio = 0.6f;
        cryptocoin = "DogeCoin";
        break;
    case 2:
        precio = 1000.0f;
        cryptocoin = "Etherium";
        break;
    case 3:
        precio = 5.0f;
        cryptocoin = "WalterCoin";
        break;
    default:
        cout << "Opción inválida de Bitcoin" << endl;
        return;
    }

    float total = monto * precio;

    if (paypal->IniciarSesion()->GetSaldo() >= total) {
        switch (opcion_Coin) {
        case 1:
            dogeCoin += monto;
            break;
        case 2:
            etherium += monto;
            break;
        case 3:
            walterCoin += monto;
            break;
        }

        paypal->IniciarSesion()->Retirar(total);
        cout << "Compra exitosa. Ha adquirido $" << monto << " de " << cryptocoin << "!!!" << endl;
    }
    else {
        cout << "Saldo insuficiente en su cuenta de PayPal para realizar la compra, Intenta aumentar el saldo de la cuenta..." << endl;
    }
}

void Wallet::CrearWallet(Paypal* paypal) {
    UsuarioPaypal* usuario = paypal->IniciarSesion();
    if (usuario != nullptr) {
        cout << "¡Wallet creado exitosamente!" << endl;
    }
    else {
        cout << "Debe iniciar sesión en PayPal antes de crear un Wallet." << endl;
    }
}

void Wallet::AccederWallet(UsuarioPaypal* usuario) {
    cout << "Accediendo al Wallet del usuario: " << usuario->GetNombreUsuario() << endl;
}

