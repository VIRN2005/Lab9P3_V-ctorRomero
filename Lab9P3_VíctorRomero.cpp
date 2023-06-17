#include <iostream>
#include "paypal.h"
#include "Wallet.h"
#include "AdministradoraArchivos.h"

using namespace std;

void mostrarMenuPaypal(Paypal* paypal) {
    int opcion;
    while (true) {
        cout << "\n--- Menú de PayPal ---" << endl;
        cout << "1) Ver estado de cuenta" << endl;
        cout << "2) Hacer depósito a mi cuenta" << endl;
        cout << "3) Hacer retiro de mi cuenta" << endl;
        cout << "4) Ver historial de cuenta" << endl;
        cout << "5) Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Saldo actual: $" << paypal->IniciarSesion()->GetSaldo() << endl;
            break;
        case 2: {
            float cantidad;
            cout << "Ingrese la cantidad a depositar: $";
            cin >> cantidad;
            paypal->IniciarSesion()->Depositar(cantidad);
            break;
        }
        case 3: {
            float cantidad;
            cout << "Ingrese la cantidad a retirar: $";
            cin >> cantidad;
            paypal->IniciarSesion()->Retirar(cantidad);
            break;
        }
        case 4:
            paypal->IniciarSesion()->MostrarHistorialCuenta();
            break;
        case 5:
            return;
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
        }
    }
}

void mostrarMenuWallet(Wallet* wallet) {
    int opcion;
    while (true) {
        cout << "\n--- Menú de Wallet ---" << endl;
        cout << "1) Ver estado de cuenta" << endl;
        cout << "2) Comprar Cryptos" << endl;
        cout << "3) Vender Cryptos" << endl;
        cout << "4) Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Estado de cuenta de " << wallet->GetNombreUsuario() << ":" << endl;
            cout << "DogeCoin: " << wallet->GetDogeCoin() << endl;
            cout << "Etherium: " << wallet->GetEtherium() << endl;
            cout << "WalterCoin: " << wallet->GetWalterCoin() << endl;
            break;
        case 2:
            wallet->ComprarCryptos();
            break;
        case 3:
            // Implementar función de vender cryptos
            cout << "Función de vender cryptos aún no implementada." << endl;
            break;
        case 4:
            return;
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
        }
    }
}
void mostrarMenuPrincipal() {
    cout << "=== Menú Principal ===" << endl;
    cout << "1) Crear cuenta de PayPal" << endl;
    cout << "2) Crear Wallet" << endl;
    cout << "3) Cargar Info" << endl;
    cout << "4) Acceder PayPal" << endl;
    cout << "5) Acceder a Wallet" << endl;
    cout << "6) Salir" << endl;
    cout << "Seleccione una opción: ";
}

void mostrarMenuPaypal() {
    cout << "=== Menú PayPal ===" << endl;
    cout << "1) Ver estado de Cuenta" << endl;
    cout << "2) Hacer depósito a mi propia cuenta" << endl;
    cout << "3) Hacer retiro de mi cuenta" << endl;
    cout << "4) Ver historial de cuenta" << endl;
    cout << "5) Salir" << endl;
    cout << "Seleccione una opción: ";
}

void mostrarMenuWallet() {
    cout << "=== Menú Wallet ===" << endl;
    cout << "1) Ver estado de cuenta" << endl;
    cout << "2) Comprar Cryptos" << endl;
    cout << "3) Vender Cryptos" << endl;
    cout << "4) Salir" << endl;
    cout << "Seleccione una opción: ";
}

void menuPrincipal() {
    Paypal paypal;
    Wallet wallet;
    AdministradoraArchivos admin;
    bool salir = false;

    while (!salir) {
        mostrarMenuPrincipal();
        int opcionPrincipal;
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
        case 1: {
            paypal.CrearCuenta();
            break;
        }
        case 2: {
            wallet.CrearWallet(&paypal);
            break;
        }
        case 3: {
            admin.CargarInformacion(&paypal, &wallet);
            break;
        }
        case 4: {
            UsuarioPaypal* usuario = paypal.IniciarSesion();
            if (usuario != nullptr) {
                bool salirPaypal = false;
                while (!salirPaypal) {
                    mostrarMenuPaypal();
                    int opcionPaypal;
                    cin >> opcionPaypal;

                    switch (opcionPaypal) {
                    case 1: {
                        cout << "Saldo actual: $" << usuario->GetSaldo() << endl;
                        break;
                    }
                    case 2: {
                        float cantidad;
                        cout << "Ingrese la cantidad a depositar: $";
                        cin >> cantidad;
                        usuario->Depositar(cantidad);
                        break;
                    }
                    case 3: {
                        float cantidad;
                        cout << "Ingrese la cantidad a retirar: $";
                        cin >> cantidad;
                        usuario->Retirar(cantidad);
                        break;
                    }
                    case 4: {
                        usuario->MostrarHistorialCuenta();
                        break;
                    }
                    case 5: {
                        salirPaypal = true;
                        break;
                    }
                    default: {
                        cout << "Opción inválida." << endl;
                        break;
                    }
                    }
                }
            }
            break;
        }

        case 5: {
            UsuarioPaypal* usuario = paypal.IniciarSesion();
            if (usuario != nullptr) {
                bool salirWallet = false;
                while (!salirWallet) {
                    mostrarMenuWallet();
                    int opcionWallet;
                    cin >> opcionWallet;

                    switch (opcionWallet) {
                    case 1: {
                        wallet.AccederWallet(usuario);
                        break;
                    }
                    case 2: {
                        wallet.ComprarCryptos();
                        break;
                    }
                    case 3: {
                        // Vender Cryptos
                        break;
                    }
                    case 4: {
                        salirWallet = true;
                        break;
                    }
                    default: {
                        cout << "Opción inválida." << endl;
                        break;
                    }
                    }
                }
            }
            break;
        }
        case 6: {
            salir = true;
            break;
        }
        default: {
            cout << "Opción inválida." << endl;
            break;
        }
        }
    }
}

int main() {
    menuPrincipal();
    return 0;
}

