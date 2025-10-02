
#include <stdio.h>
#include <stdlib.h>

typedef struct cellule
{
    float a;
    struct cellule *next;
}cellule, *list;

//Ajout d'éléments à la liste
void initList (list *head , float v) {
    list n = (list)malloc(sizeof(list));
    if ((!n))
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    n->a = v;
    n->next = *head;
    *head = n;
    
}

//Afficheur de liste 
void affich_list(list head){
    list p = head;
    do
    {
        printf("%.2f -> ", p->a);
        p = p->next;
    } while (p != NULL);
    printf("NULL\n");
    
}

//Suppresion des occurence de x
void delet_occ(list *head, float x){
    list L = *head;
    list p = NULL;

    while (L != NULL)
    {
        if (L->a == x)
        {
            list tmp = L;
            if (p == NULL)//sup head
            {
                *head = L->next;
                L = *head;
            }else{
                p->next = L->next;// sup milieu or end
                L = p->next;
            }
            free(tmp);
        }
        else
        {
            p = L;
            L = L->next;
        }
        
    }
    
}


int main() {

    int n, i;
    float x, v;
    list l = NULL;

    printf("Entrer le nombre de valeur a ajouter à la liste.\n");
    do
    {
        scanf("%d", &n);
    } while (n<0);

    // remplissage de la liste 
    if (n == 0)
    {
        printf("[ERROR] : Pas d'élément a ajouter,\n");
    }
    else
    {
        printf("Entrer les valeurs :\n");
        i = 0;
        do
        {
            scanf("%f", &v);
            initList (&l, v);
            i++;
        } while (i<n);
        
    }
    
    //
    if (l == NULL)
    {
        printf("\n\tListe vide .\n");
        
    }
    else
    {
        printf("\n#### les éléments de la liste sont  ####\n");
        affich_list(l);

    // suppression des occurences
    printf("#### Entrer l'élément dont on doit supprimer les occurences ####\n");
    if (scanf("%f", &x) != 1)
    {
        fprintf(stderr, "Entrée invalide");
        return EXIT_FAILURE;
    }

    delet_occ(&l, x);

    // Affichage de la liste
    printf("\n#### les éléments de la nouvelle liste sont  ####\n");
    affich_list(l);

    //libere toute la memoir occupé
    while (l)
    {
        list tmp = l;
        l= l->next;
        free(tmp);
    }
}
    
    return 0;

}