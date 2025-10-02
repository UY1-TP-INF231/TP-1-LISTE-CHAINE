#include <stdio.h>
#include <stdlib.h>

struct Cellule {
    int data;
    struct Cellule *prev;
    struct Cellule *next;
};
             
int main() {
    struct Cellule *head = NULL;
    struct Cellule *newCell, *last, *temp;
    int i, n, val;
    
    printf("Donner le nombre initial d'elements de la liste : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Valeur de l'element %d : ", i + 1);
        scanf("%d", &val);
        newCell = (struct Cellule*) malloc(sizeof(struct Cellule));
        newCell->data = val;

        if (head == NULL) {
            newCell->next = newCell;
            newCell->prev = newCell;
            head = newCell;
        } else {
            last = head->prev;
            newCell->next = head;
            newCell->prev = last;
            last->next = newCell;
            head->prev = newCell;
        }
    }    
        
    printf("\nDonner la valeur a inserer en tete : ");
    scanf("%d", &val);
    newCell = (struct Cellule*) malloc(sizeof(struct Cellule));
    newCell->data = val;
    if (head == NULL) {
        newCell->next = newCell;
        newCell->prev = newCell;
        head = newCell;
    } else{ 
        last = head->prev;
        newCell->next = head;
        newCell->prev = last;
        last->next = newCell;
        head->prev = newCell;
        head = newCell;  // Mise à jour de la tête
    }
        
        
    printf("\nListe apres insertion en tete : ");
    if (head != NULL) {
        temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
    
    return 0;
    
}