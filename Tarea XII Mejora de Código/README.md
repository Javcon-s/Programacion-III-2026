Esteban Javier Antonio Alarcón Herrera
Problemas del código:

1. Se están cargando todos los clientes a la memoria, que por el tipo de estructura que presentan y la cantidad de clientes que son pueden causar un problema en la RAM, por ejemplo en mi computadora, nisiquiera llegan a correr.

2. La busqueda es líneal, lo que haría un tiempo de espera demasiado largo al momento de buscar algún resultado que no sea facilmente localizable.
3. Se utiliza un json pesado y que posiblemente es evitable.
4. Se utilizan dos listas paralelas, que podría generar dificultades en un futuro y es evitable.
