#ifndef ADMINISTRADORAARCHIVOS_H
#define ADMINISTRADORAARCHIVOS_H

#include <iostream>
#include "paypal.h"
#include "Wallet.h"
using namespace std;

class AdministradoraArchivos {
public:
    static void GuardarUsuarioPaypal(UsuarioPaypal* usuario);
    static vector<UsuarioPaypal*> CargarInformacion();
    static bool ExisteUsuario(string nombreUsuario);
    static void GuardarInformacion(Paypal* paypal, Wallet* wallet);
    void GuardarWallet(Wallet* wallet);
    void CargarInformacion(Paypal* paypal, Wallet* wallet);
    void CargarUsuariosPaypal(UsuarioPaypal* paypal);
    void CargarWallet(Wallet* wallet);
    void GuardarUsuarioPaypal(Paypal* usuario);
    void CargarUsuariosPaypal(Paypal* paypal);
};

#endif


