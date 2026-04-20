Esteban Javier Antonio Alarcón Herrera
9941-16-13183

PREGUNTAS: 
1.	¿Qué errores presentaba el código original?
Presentaba varios errores, de compilación y lógica, entre los que más pude ver fueron malas igualaciones en varios de los “if” del programa, también al momento de declarar estructuras o inclusive una estructura de más que no estaba bien realizada, luego algunos punteros no se actualizaban de forma correcta.
2.	¿Qué problemas tenía la versión sin tail al recorrer hacia atrás?
La versión sin tail tenía el problema de que para mostrar la lista hacia atraás primero debía recorrer toda la lista desde head hasta llegar al ultimo nodo, lo que hacia que cada vez que se quería imprimir para atrás se hacía un recorrido completo de más, lo cual no es óptimo.
3.	¿Qué ventaja aporta usar tail?
La ventaja es que hay un acceso directo al último nodo y nos permite optimizar el programa.
4.	¿Qué operaciones mejoran con esta modificación?
Serían la de insertar al final, la de la eliminación del ultimo nodo, o la de imprimir hacia atrás.
5.	¿Qué cuidados adicionales deben tenerse al eliminar nodos cuando existe tail?
En general el cuidado que se tiene con el puntero de head, transferir por ejemplo tail al siguiente en caso de ser eliminado, o que no se pierda el acceso al mismo y actualizarlo cuando sea necesario.
