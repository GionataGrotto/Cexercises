#include <stdio.h>
#include <stdlib.h>

struct node {
    int n;
    struct node *prev;
    struct node *next;
};

void createList(struct node *head, struct node *tail);


int main() {
    struct node *start, *end;
    
}