#ifndef ADMINISTRADORAARCHIVOS_H
#define ADMINISTRADORAARCHIVOS_H

#include <iostream>
#include "paypal.h"
using namespace std;

class AdministradoraArchivos {
public:
    static void GuardarUsuarioPaypal(UsuarioPaypal* usuario);
    static vector<UsuarioPaypal*> CargarInformacion();
    static bool ExisteUsuario(string nombreUsuario);
};

#endif


