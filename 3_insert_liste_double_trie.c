#include <stdio.h>
#include <stdlib.h>

// Définition de la structure 

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev; 
} Node;


Node* createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL; 
    return newNode;
}

Node* insertSorted(Node* head, int value) {
    
    Node *newNode = createNode(value);
    
    if (head == NULL || value <= head->data) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode; 
    }

    Node *current = head;
    
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    
    newNode->next = current->next;
    newNode->prev = current;
    
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;

    return head;
}


void displayList(Node *head) {
    Node *current = head;
    if (head == NULL) {
        printf("Liste est vide.\n");
        return;
    }
    
    // Affichage dans l'ordre 
    printf("Ordre  : ");
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
    
    // Affichage dans l'ordre inverse , pour la vérification
    if (head != NULL) {
        current = head;
        // Aller jusqu'à la fin de la liste
        while (current->next != NULL) {
            current = current->next;
        }
        
        printf("Ordre inverse ");
        while (current != NULL) {
            printf("%d ", current->data);
            if (current->prev != NULL) {
                printf(" ");
            }
            current = current->prev;
        }
        printf("\n");
    }
}

void freeList(Node *head) {
    Node *current = head;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}


int main() {
    Node *head = NULL;
    int n, value;

    printf("--- CREATION ET TRI DE LA LISTE DOUBLEMENT CHAINÉE INITIALE ---\n");
    
    // 1. Lire le nombre d'éléments (n)
    printf("Entrez le nombre d'éléments (n) de la liste initiale : ");
    if (scanf("%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Erreur : Nombre d'éléments invalide.\n");
        return 1;
    }
    
    // 2. Lire les n éléments et les insérer de manière triée
    printf("Veuillez entrer les %d éléments :\n", n);
    for (int i = 0; i < n; i++) {
        printf("Élément %d : ", i + 1);
        if (scanf("%d", &value) != 1) {
            fprintf(stderr, "Erreur : Entrée invalide.\n");
            freeList(head);
            exit(EXIT_FAILURE); 
        }
        // L'insertion triée est utilisée pour créer la liste DÈS LE DÉPART triée
        head = insertSorted(head, value);
    }
    
    printf("\n--- RESULTAT INTERMÉDIAIRE ---\n");
    printf("Liste initiale triée (%d éléments) :\n", n);
    displayList(head);

    // 3. Demander à l'utilisateur d'insérer le nouvel élément
    printf("\n--- INSERTION DU NOUVEL ÉLÉMENT ---\n");
    printf("Entrez le NOUVEL élément à insérer dans la liste triée : ");
    if (scanf("%d", &value) != 1) {
        fprintf(stderr, "Erreur : Entrée invalide pour le nouvel élément.\n");
        // Nettoyage avant de quitter si l'entrée est mauvaise
        freeList(head);
        return 1;
    }

    // Insertion du nouvel élément
    head = insertSorted(head, value);
    
    printf("\n--- RESULTAT FINAL ---\n");
    printf("Liste finale triée après l'ajout de %d :\n", value);
    displayList(head);

    // 4. Nettoyage de la mémoire
    freeList(head);

    return 0;
}