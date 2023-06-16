#include "usuario_paypal.h"
#include "administradora_archivos.h"
using namespace std;

UsuarioPaypal::UsuarioPaypal(string nombreUsuario, string numeroIdentidad, string contrasena) {
    this->nombreUsuario = nombreUsuario;
    this->numeroIdentidad = numeroIdentidad;
    this->contrasena = contrasena;
    this->saldo = 0.0f;
}

string UsuarioPaypal::GetNombreUsuario() {
    return nombreUsuario;
}

string UsuarioPaypal::GetNumeroIdentidad() {
    return numeroIdentidad;
}

string UsuarioPaypal::GetContrasena() {
    return contrasena;
}

float UsuarioPaypal::GetSaldo() {
    return saldo;
}

void UsuarioPaypal::Depositar(float cantidad) {
    saldo += cantidad;
    string mensaje = "Se ha depositado " + to_string(cantidad) + " desde su wallet";
    historialCuenta.push_back(mensaje);
    GuardarEnArchivo();
    cout << "Depósito exitoso. Nuevo saldo: " << saldo << endl;
}

void UsuarioPaypal::Retirar(float cantidad) {
    if (saldo >= cantidad) {
        saldo -= cantidad;
        string mensaje = "Se ha retirado " + to_string(cantidad) + " desde su wallet";
        historialCuenta.push_back(mensaje);
        GuardarEnArchivo();
        cout << "Retiro exitoso. Nuevo saldo: " << saldo << endl;
    }
    else {
        cout << "Saldo insuficiente para realizar el retiro." << endl;
    }
}

void UsuarioPaypal::MostrarHistorialCuenta() {
    cout << "Historial de cuenta:" << endl;
    for (const auto& transaccion : historialCuenta) {
        cout << transaccion << endl;
    }
}

void UsuarioPaypal::GuardarEnArchivo() {
    AdministradoraArchivos::GuardarUsuarioPaypal(this);
}
