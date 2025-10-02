#include <stdio.h>
#include <stdlib.h>

struct Cellule {
    int data;
    struct Cellule *next; 
};

int main() {
    struct Cellule *head = NULL;
    struct Cellule *newCell, *current, *last;
    int i, n, val;
    
    // 1. INITIALISATION DE LA LISTE
    printf("Donner le nombre initial d'elements de la liste : ");
    if (scanf("%d", &n) != 1) return 1;

    for (i = 0; i < n; i++) {
        printf("Valeur de l'element %d : ", i + 1);
        if (scanf("%d", &val) != 1) return 1;

        newCell = (struct Cellule*) malloc(sizeof(struct Cellule));
        if (newCell == NULL) { perror("Erreur malloc"); return 1; }
        newCell->data = val;

        if (head == NULL) {
            newCell->next = newCell;
            head = newCell;
        } else {
            last = head;
            while (last->next != head) {
                last = last->next;
            }
            
            newCell->next = head;
            last->next = newCell;
            
    }    
    
    // 2. Insertion en Tête
    printf("\n--- Operation Code 1 : Insertion en Tete ---\n");
    printf("Donner la valeur a inserer en tete : ");
    if (scanf("%d", &val) != 1) return 1;
    
    newCell = (struct Cellule*) malloc(sizeof(struct Cellule));
    if (newCell == NULL) { perror("Erreur malloc"); return 1; }
    newCell->data = val;
    
    // Logique d'insertion en tête
    if (head == NULL) {
        newCell->next = newCell;
        head = newCell;
    } else{ 
        // 1. Trouver la queue (le dernier élément)
        last = head;
        while (last->next != head) {
            last = last->next;
        }
        
        newCell->next = head; 
        last->next = newCell; 
        head = newCell;  
    }
        
    printf("Liste apres insertion en tete : ");
    if (head != NULL) {
        current = head;
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
    }
    printf("\n");
    
    // 3. OInsertion en Queue
    printf("\n--- Operation Code 2 : Insertion en Queue ---\n");
    printf("Donner la valeur a inserer en queue : ");
    if (scanf("%d", &val) != 1) return 1;

    newCell = (struct Cellule*) malloc(sizeof(struct Cellule));
    if (newCell == NULL) { perror("Erreur malloc"); return 1; }
    newCell->data = val;
    
    // Logique d'insertion en queue
    if (head == NULL) {
        newCell->next = newCell;
        head = newCell;
    } else {
        // 1. Trouver la queue (le dernier élément)
        last = head;
        while (last->next != head) {
            last = last->next;
        }
        // 2. Chaîner
        newCell->next = head; 
        last->next = newCell; 
    }
    
    printf("Liste apres insertion en queue : ");
    if (head != NULL) {
        current = head;
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
    }
    printf("\n");
                                                    
    return 0;
}