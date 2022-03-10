#include <stdio.h>
#include <stdlib.h>

struct node {
    int n;
    struct node *next;
};

// Crea una lista
struct node * createList(int n);

// Stampa la lista
void displaylist(struct node *l);

// Conta i nodi nella lista
int countNodes(struct node *l);

// Inserisci nodo in cima alla lista. Ritorna il primo elemento della lista
struct node * addNodeStart(struct node *l);

// Inserisci nodo in fondo alla lista. Ritorna il primo elemento della lista
struct node * addNodeEnd(struct node *l);

int main() {
    struct node *lista, *newlista;
    int n;
    printf("Number of nodes: ");
    scanf("%d",&n);

    lista = createList(n);

    displaylist(lista);

    printf("Numero nodi nella lista: %d\n",countNodes(lista));

    newlista = addNodeStart(lista);
    displaylist(newlista);

    newlista = addNodeEnd(lista);
    displaylist(newlista);


    return 0;
}

struct node * createList(int n) {
    struct node *first, *tmp, *oth;
    int v;
    first = (struct node *)malloc(sizeof(struct node));
    if (first == NULL) {
        printf("Error 1");
    } else {
        printf("Insert value: ");
        scanf("%d",&v);
        first->n = v;
        first->next = NULL;
        tmp = first;

        for (int i = 2; i <= n; i++) {
            oth = (struct node *)malloc(sizeof(struct node));
            if (oth == NULL) {
                printf("Error 2");
                break;
            } else {
                printf("Insert value: ");
                scanf("%d",&v);
                oth->n = v;
                oth->next = NULL;
                tmp->next = oth;
                tmp = tmp->next;
            }
        }
    }
    return first;
}


void displaylist(struct node *l) {
    struct node *tmp = l;
    do {
        printf("%d ",tmp->n);
        tmp = tmp->next;
    } while (tmp != NULL);
    printf("\n");
}

int countNodes(struct node *l) {
    struct node *tmp = l;
    int nodes = 1;
    while (tmp->next != NULL) {
        nodes++;
        tmp = tmp->next;
    }
    return nodes;
}

struct node * addNodeStart(struct node *l) {
    int v;
    struct node *new;
    printf("Add value: ");
    scanf("%d", &v);
    new = (struct node *)malloc(sizeof(struct node));
    new->n = v;
    new->next = l;
    return new;
}

struct node * addNodeEnd(struct node *l) {
    int v;
    struct node *new, *tmp;
    tmp = l;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    printf("Add value: ");
    scanf("%d", &v);
    new = (struct node *)malloc(sizeof(struct node));
    new->n = v;
    new->next = NULL;
    tmp->next = new;
    return l;
}


