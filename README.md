

# RSA

RSA es uno de los primeros criptosistemas de clave pública (asimétrica) y se usa ampliamente para la transmisión segura de datos.  RSA son las siglas de Rivest-Shamir-Adleman, letras iniciales de los apellidos de sus creadores.  Esta asimetría se basa en la dificultad práctica de la factorización del producto de dos números primos grandes, el "problema de factorización".

 Así es como funciona la generación de claves:

 1 - Elija dos números primos distintos, `p`  y `q` .

 2 - Calcule `n = p * q`.  `n`  se utiliza como módulo para las claves pública y privada.  Su longitud, normalmente expresada en bits, es la longitud de la clave
 
 3 - Calcule  `λ(n) = mínimo_común_múltiplo(p − 1, q − 1).`  Este valor es privado.

 4 - Elija un número entero e tal que `1 < e < λ(n), e y λ(n)` sean coprimos.

 5 - Determine `d` a partir de `d * e ≡ 1 (mod λ(n))`.

 `e` se libera como exponente de clave pública.
 `d` se mantiene como el exponente de clave privada.

 Par de claves:

-  clave pública: (e, n)
-  clave privada: (d, n)

 Actualmente, los tamaños estándar de las claves RSA son los siguientes:

```
 512 bits: clave de baja potencia
 1024 bits: clave de resistencia media
 2048 bits: clave de alta resistencia
 4096 bits: clave de muy alta resistencia
```

## Ejercicio:

 Supongamos que __Bob__ quiere enviar información a __Alice__.  Si deciden usar RSA, __Bob__  debe conocer la clave pública de Alice para cifrar el mensaje y __Alice__ debe usar su clave privada para descifrar el mensaje.  Para permitir que __Bob__ envíe sus mensajes cifrados, __Alice__ transmite su clave pública `(n, e)` a __Bob__ a través de un canal confiable (no necesariamente secreto).  La clave privada de Alice `(d)` nunca se distribuye.

 Intentemos generar un par de claves muy simple:

 1. p = 61 y q = 53
 2. n = 61 * 53 = 3233
 3. λ(n) = mcm(p-1, q-1) = mcm(60, 52) = 780
 4. e = 17 (1 < e < λ(n), e y λ(n) son coprimos)
 5. d = 413 (d * e mod λ(n) = 1)


 clave pública: (n = 3233, e = 17)
 clave privada: (n = 3233, d = 413)

 Generamos el par de claves.  Necesitamos la clave pública `(n, e)` para cifrar texto sin formato.  Asignemos texto sin formato a m y texto cifrado a `c` ;  entonces el texto cifrado será:
 `c = metro ^ e mod n`

 Por ejemplo, si nuestro texto sin formato `m = 65`, entonces:
 `c(m) = 65 ^ 17` módulo 3233 = 2790

 Para descifrar el texto cifrado con la clave privada `(n, d)`, debemos usar esto:
 `m(c) = c ^ d módulo n = 2790 ^ 413 módulo 3233 = 65`
