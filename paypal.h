#ifndef PAYPAL_H
#define PAYPAL_H

#include <iostream>
#include <string>
#include <vector>
#include "usuario_paypal.h"

class Paypal {
private:
    vector<UsuarioPaypal*> usuarios_PayPal;

public:
    void CrearCuenta();
    UsuarioPaypal* IniciarSesion();
    void CargarInformacion();
    void AgregarUsuario(UsuarioPaypal* usuario);
};

#endif



