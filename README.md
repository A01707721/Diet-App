# Diet-App
Este proyecto simula una aplicación para contar calorias
## Contexto
Este proyecto simula una aplicación para contar calorias de un usuario, en este puedes ir registrando los alimentos consumidos durante el día, consultar sus calorias
y compararlo con tus metas personales
## Funcionalidad
El código solicita al usuario que ingrese su datos.
Posteriormente imprime este menu:
What do you wanna consult
1. Food eaten through the day
2. Status of you calory goal
3. Add food to the list
4. Find a food based on the amount of calories
5. Exit
   
A partir de este menú el usuario puede consultar datos de los diferentes alimentos,
además de registrar más de estos, buscar un alimento en base a su nuumero calorico y salir del programa.
## Consideraciones
Programa hecho en C++ standard, con una interfaz del usuario en inglés
- Compilar en terminal con g++ main.cpp App.h User.h
- Windows a.exe
- Linux ./a.out
  Debiod a la implementacion de el BTS no es posible agregar 2 comidas con el mismo valor calorico
## SICT0302 Toma decisiones 
### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
En este programa se utilizo el algoritmo MergeSort implementado sobre un vector para ordenar los alimentos consumidos
en orden alfabetico, esto ya que este metodo presenta una complejidad temporal baja y es poco posible que me encuentre 
su peor caso, debido a que se espera que el vector este desordenado.
### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.
Como estructura adicional utize un BST ubicado en el archivo Bst.h
para poder localizar alimentos especificos en base a su valor calorico y poder imprimir de menor a mayor. 
Utilice esta estructura para reducir el tiempo de busqueda a logaritmico en vez de lineal de un elemento en especifico, ademas debido a que es
poco probable que los alimentos consumidos a traves de dia esten ordenados de menor a mayor o alguna configuracion similar, el arbol no deberia deformarse.
## SICT0301 Evalúa los componentes
### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Merge Sort <br>
Time Complexity O(nLog(n)) <br>
Space Complexity O(n) Tiene esta complejidad ya que es necesario un arreglo auxiliar del que copiar <br>
### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa.
BST <br>
Insertion O(log(n)) <br>
Access O(log(n)) <br>
Search O(log(n)) <br>
<br>
Aunque el peor de los casos es tecnicamente O(n) como se menciono anteriormente debido a la 
aletoriedad de los valores de comida, el arbol no deberia deformarse y por lo tanto mantener una complejidad logaritmica
para añadir, buscar o consultar un nodo. 

Vector <br>
Insertion O(n) ya que es necesario recorrer el vector para añadir el valor al final de este. <br> 
Access O(1) ya que puedo acceder al vector directamente con su indice. <br>
Search O(n) de igual forma en el peor de los casos seria necesario recorrer todo el vector. <br>
<br>
Debido a la alta complejidad temporal es por ello que unicamnte utilizo el vector para ordenar de forma alfabetica, 
y el resto de operaciones es hecho mediante el BST.
## SICT0303 Implementa acciones científicas
### Implementa mecanismos para consultar información de las estructras correctos
Mediante las opciones del menu es posible agregar nuevos objetos a las estructuras, ademas de poder consultarlas en base a los
diferentes valores de sus atributos.
