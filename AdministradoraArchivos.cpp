#include "administradoraarchivos.h"
#include <fstream>
#include <iostream>

using namespace std;

void AdministradoraArchivos::GuardarUsuarioPaypal(UsuarioPaypal* usuario) {
    string nombreArchivo = usuario->GetNumeroIdentidad() + ".lab";
    ofstream archivo(nombreArchivo, ios::binary);
    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<const char*>(usuario), sizeof(UsuarioPaypal));
        archivo.close();
    }
    else {
        cout << "No se pudo crear el archivo." << endl;
    }
}

vector<UsuarioPaypal*> AdministradoraArchivos::CargarInformacion() {
    vector<UsuarioPaypal*> usuarios;
    ifstream archivo("usuarios.lab", ios::binary);
    if (archivo) {
        UsuarioPaypal* usuario = new UsuarioPaypal();
        while (archivo.read(reinterpret_cast<char*>(usuario), sizeof(UsuarioPaypal))) {
            usuarios.push_back(usuario);
            usuario = new UsuarioPaypal();
        }
        archivo.close();
    }
    else {
        cout << "No se encontró el archivo." << std::endl;
    }
    return usuarios;
}

bool AdministradoraArchivos::ExisteUsuario(string nombreUsuario) {
    ifstream archivo;
    archivo.open("usuarios.lab", ios::binary);
    if (archivo.is_open()) {
        UsuarioPaypal* usuario = new UsuarioPaypal();
        while (archivo.read(reinterpret_cast<char*>(usuario), sizeof(UsuarioPaypal))) {
            if (usuario->GetNombreUsuario() == nombreUsuario) {
                archivo.close();
                delete usuario;
                return true;
            }
            delete usuario;
            usuario = new UsuarioPaypal();
        }
        archivo.close();
        delete usuario;
    }
    return false;
}

