#ifndef USUARIO_PAYPAL_H
#define USUARIO_PAYPAL_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class UsuarioPaypal {
private:
    string nombreUsuario;
    string numeroIdentidad;
    string contrasena;
    float saldo;
    vector<string> historialCuenta;

public:
    UsuarioPaypal(string nombreUsuario, string numeroIdentidad, string contrasena);

    string GetNombreUsuario();
    string GetNumeroIdentidad();
    string GetContrasena();
    float GetSaldo();

    void Depositar(float);
    void Retirar(float);
    void MostrarHistorialCuenta();
    void GuardarEnArchivo();
};

#endif

