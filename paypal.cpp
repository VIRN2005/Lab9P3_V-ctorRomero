#include "paypal.h"
#include "AdministradoraArchivos.h"
using namespace std;

void Paypal::CrearCuenta() {
    string nombreUsuario, numeroIdentidad, contrasena;
    cout << "Ingrese el nombre de usuario: ";
    cin >> nombreUsuario;
    cout << "Ingrese el n�mero de identidad: ";
    cin >> numeroIdentidad;
    cout << "Ingrese la contrase�a: ";
    cin >> contrasena;

    if (!AdministradoraArchivos::ExisteUsuario(numeroIdentidad)) {
        UsuarioPaypal* nuevoUsuario = new UsuarioPaypal(nombreUsuario, numeroIdentidad, contrasena);
        usuarios_PayPal.push_back(nuevoUsuario);
        AdministradoraArchivos::GuardarUsuarioPaypal(nuevoUsuario);
        cout << "Cuenta de PayPal creada exitosamente." << endl;
    }
    else {
        cout << "Ya existe una cuenta de PayPal asociada al n�mero de identidad ingresado." << endl;
    }
}

UsuarioPaypal* Paypal::IniciarSesion() {
    string numeroIdentidad, contrasena;
    cout << "Ingrese su n�mero de identidad: ";
    cin >> numeroIdentidad;
    cout << "Ingrese su contrase�a: ";
    cin >> contrasena;

    for (const auto& usuario : usuarios_PayPal) {
        if (usuario->GetNumeroIdentidad() == numeroIdentidad && usuario->GetContrasena() == contrasena) {
            return usuario;
        }
    }

    cout << "Credenciales inv�lidas." << endl;
    return nullptr;
}

void Paypal::CargarInformacion() {
    vector<UsuarioPaypal*> usuarios = AdministradoraArchivos::CargarInformacion();
    usuarios_PayPal = usuarios;
}


void Paypal::AgregarUsuario(UsuarioPaypal* usuario) {
    usuarios_PayPal.push_back(usuario);
}








