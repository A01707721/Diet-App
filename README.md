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
## SICT0302 Toma decisiones 
### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
En este programa se utilizo el algoritmo MergeSort implementado sobre un vector para ordenar los alimentos consumidos
de menor valor calorico a mayor, esto ya que este metodo presenta una complejidad espacial baja y es poco posible que me encuentre 
su peor caso, debido a que se espera que la lista este desordenada.
### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.
Como estructura adicional utize un BST para poder localizar alimentos especificos en base a su valor calorico, 
utilice esta estructura para reducir el tiempo de busqueda de un elemento en especifico, ademas debido a que es
poco probable que los alimentos consumidos a traves de dia esten ordenados de menor a mayor, el arbol no deberia deformarse.
## SICT0301 Evalúa los componentes
### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Merge Sort 
Time Complexity O(nLog(n))
Space Complexity O(n)
### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa.
BST 
Insertion O(log(n))
Delete O(log(n))
Insertion O(log(n))

