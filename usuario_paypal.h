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
    UsuarioPaypal(std::string nombreUsuario, std::string numeroIdentidad, std::string contrasena);

    string GetNombreUsuario();
    string GetNumeroIdentidad();
    string GetContrasena();
    float GetSaldo();

    void Depositar(float cantidad);
    void Retirar(float cantidad);
    void MostrarHistorialCuenta();
    void GuardarEnArchivo();
};

#endif // USUARIO_PAYPAL_H

