#include <iostream>
#include <string>
#include <cstdlib>  
#include <ctime>    

std::string generarContrasenaSegura() {
    const int longitud = 12; 
    const std::string mayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string minusculas = "abcdefghijklmnopqrstuvwxyz";
    const std::string numeros = "0123456789";
    const std::string especiales = "!@#$%^&*()-_=+[]{}|\\;:'\",.<>/?~";

    std::string contrasena;
    contrasena += mayusculas[rand() % mayusculas.size()]; 
    contrasena += minusculas[rand() % minusculas.size()]; 
    contrasena += numeros[rand() % numeros.size()];       
    contrasena += especiales[rand() % especiales.size()]; 

    
    const std::string todos = mayusculas + minusculas + numeros + especiales;
    while (contrasena.size() < longitud) {
        char nuevoCaracter = todos[rand() % todos.size()];

        
        if (contrasena.size() > 1) {
            char penultimoCaracter = contrasena[contrasena.size() - 1];
            char antepenultimoCaracter = contrasena[contrasena.size() - 2];
            if (nuevoCaracter == penultimoCaracter && nuevoCaracter == antepenultimoCaracter) {
                continue; 
            }
        }

        contrasena += nuevoCaracter;
    }

    return contrasena;
}

int main() {
    srand(time(0)); 

    std::string contrasenaSegura = generarContrasenaSegura();
    std::cout << "Contrasena segura generada: " << contrasenaSegura << std::endl;

    return 0;
}

