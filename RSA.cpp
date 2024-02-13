/*
 * Algoritmos
 Empezar

 1. Elige dos números primos p y q.
 2. Calcule n = p*q.
 3. Calcular phi = (p-1) * (q-1).
 4. Elija un número entero e tal que 1 < e < phi(n) y mcd(e, phi(n)) = 1;  es decir, e y phi(n) son coprimos.
 5. Calcular d como d ≡ e−1 (mod phi(n));  aquí, d es el inverso multiplicativo modular de e módulo phi(n).
 6. Para el cifrado, c = me mod n, donde m = mensaje original.
 7. Para el descifrado, m = c d mod n.

Final
*/

#include <iostream>
#include <numeric>


// Función para calcular el mínimo común múltiplo
int mcm(int a, int b) {
    return a * b / std::gcd(a, b);
}

// Función para calcular el inverso modular
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1;
}

int main() {
    // Paso 1: Elegir dos números primos distintos
    int p = 61;
    int q = 53;

    // Paso 2: Calcular n = p * q
    int n = p * q;

    // Paso 3: Calcular λ(n) = mcm(p-1, q-1)
    int lambda = mcm(p - 1, q - 1);

    // Paso 4: Elegir un número entero e tal que 1 < e < λ(n) y e, λ(n) sean coprimos
    int e = 17;

    // Paso 5: Calcular d a partir de d * e ≡ 1 (mod λ(n))
    int d = modInverse(e, lambda);

    // Mostrar las claves generadas
    std::cout << "Clave pública: (n = " << n << ", e = " << e << ")" << std::endl;
    std::cout << "Clave privada: (n = " << n << ", d = " << d << ")" << std::endl;

    // Cifrado y descifrado de ejemplo
    int mensajeOriginal = 65;
    int mensajeCifrado = std::pow(mensajeOriginal, e);
    mensajeCifrado = mensajeCifrado % n;
    std::cout << "Mensaje cifrado: " << mensajeCifrado << std::endl;

    int mensajeDescifrado = std::pow(mensajeCifrado, d);
    mensajeDescifrado = mensajeDescifrado % n;
    std::cout << "Mensaje descifrado: " << mensajeDescifrado << std::endl;

    return 0;
}
