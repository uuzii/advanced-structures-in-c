#include <stdio.h>
#include <stdlib.h>
// Definir un nodo
typedef struct Node {
  int number; // lista
  struct Node * next; // estructura autoreferenciada
} NODE;
// función que crea nodos
NODE * createNode(int number) {
  NODE * newNode;
  newNode = malloc(sizeof(NODE));
  newNode->next = NULL; // por default el siguiente nodo será NULL
  newNode->number = number; // asignar el argumento a number
  return newNode;
}
int main(int argc, char * argv[]) {
  // creando una lista
  NODE * start = NULL, * current;
  // bandera que nos indicará si continuamos
  char goOn;
  // tamaño de la lista
  int listSize = 0, number;
  // pedimos inputs al usuario
  do {
    printf("La lista contiene %d nodos, Ingrese el siguiente numero (0 para finalizar)\n", listSize);
    scanf("%d", &number);
    // si el número es distinto de cero...
    if (number) {
      // si start es igual a NULL, crea el nodo
      if(!start) {
        start = createNode(number);
        printf("Primer nodo start->number %d\n", start->number);
        printf("Primer nodo start->next %p\n", start->next);
        listSize++;
      } else { // si start no es igual a NULL...
        current = start; // usamos current como auxiliar para no perder el inicio
        printf("Primer nodo start->number %d\n", start->number);
        printf("Primer nodo start->next %p\n", start->next);
        // mientras current tenga algo en next:
        while(current->next) {
          printf("while antes de asignar current->number %d\n", current->number);
          printf("while antes de asignar current->next %p\n", current->next);
          current = current->next;
          printf("while después de asignar current->number %d\n", current->number);
          printf("while después de asignar current->next %p\n", current->next);
        }
        // se crea el siguiente nodo
        current->next = createNode(number);
        listSize++;
      }
      goOn = 1;
    } else {
      goOn = 0;
    }  
  } while(goOn);
  // inicia current con el start
  current = start;
  printf("Inicializa current->number %d\n", current->number);
  printf("Inicializa current->next %p\n", current->next);
  printf("La lista tiene los numeros: \n");
  // mientras current no sea NULL
  while(current) {
    // desreferencía current y accede a number
    printf("%d %p", current->number, current->next);
    // si existe un siguiente...
    printf(current->next ? ", " : " \n");
    // para iterar
    current = current->next;
  }
  return 0;
}