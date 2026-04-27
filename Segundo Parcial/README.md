Esteban Javier Antonio Alarcon Herrera
9941-16-13183
Es un programa que permite el ingreso de forma dinamica de numeros enteros positivos y negativos y los clasifica automaticamante en distintas estructuras, segun si son pares o impares o negativos.
Los numeros pares se van a una cola.
Los numeros impares se van a una pila.
Los negativos en una lista enlazada.
Y el 0 simplemente no se almacena, es invalido.
El programa tambien funciona con un nodo arbol para la facilidad de acceso y verificacion.

Las estructuras utilizadas fueron Punteros y memoria dinamica como base para todo el programa, en base a estructuras.
Entre las estructuras utilizadas tenemos cola, pila, lista enlzada y arbol.
El arbol trabaja con los tres tipos de ordenes que hay.


Hablando de la logica utilizada, se le da al usuario la opcion de ingresar la cantidad de "n" numeros, para luego verificar y trabajarlo enviandolo a una cola, pila o lista enlazada, como se hablaba anteriormente.
El arbol no se construye mientras se ingresan los datos, utiliza el historial para mostrar los datos positivos.
Para la eliminacion, se utiliza un margen de entre -10 a 10 para eliminar los nodos cuyo valor este dentro de los rangos dichos, esto fue asi por no ser capaz de adaptar alguna libreria para adaptar el programa a ilimitado.

Para la reorganizacion de estructuras vacia una pila o la cola hacia una lista auxiliar y muestra ambas, luego se reconstruye el arbol con estos datos.
El programa tambien lleva durante todo el tiempo que este corriendo control de: 
Cantidad de pares positivos.
Cantidad de impares positivos.
Cantidad de negativos.
Cantidad de ceros rechazados.
Total de valores validos.
Valor mayor.
Valor menor.

Al finalizar el programa libera la memoria dinamica utilizada.
