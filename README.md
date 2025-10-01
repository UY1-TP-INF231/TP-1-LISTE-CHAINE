# TP-1-LISTE-CHAINE 💻
QUELQUE OPERATION SUR LES LISTES CHAINES
BASE LANGUAGE "©️"

## 1- supprimer les occurences d'un élément dans une liste
## 2- 
## 3.1-
## 3.2-
## 4.1-
## 4.2-
## 5.1-insertion d'un élément en tête d'une liste simplement chaînée circulare
```
Algorithme     InsertionTeteListeDoublementChaineeCirculaire 

               Var         cellule :   enregistrement  
                                  val :  entier ; 
                                  suiv : ^cellule ;
                                  prec : ^cellule ;
                             finenreg 

                            Liste tete =^cellule ; 
                              L : liste ; 
                              p : ^cellule ;
                              dernier : ^cellule ;
                                x : entier ; 
            Début 
                    écrire (¨entrer une nouvelle cellule¨) ;
 
                    p ← nouvelle cellule ;
                    p.val← x ;
                      Si L.tete = NULL Alors 
                         p.suiv← p ;
                         p.prec ← p ;
                         L.tete ← p ;
                      Sinon 
                         dernier ← L.tete.prec ;
                          p.suivant ← L.tete ;
                          p.prec ← dernier ; 
                          dernier.suivant ← p ;
                          L.tete.prec ← p ;
                          L.tete ← p ;
                      finSi 
               Fin  

```
## 5.2-insertion d'un élément en queu d'une liste doublement chaînée circulare
```
Algorithme : InsertionEnQueueListeDoublementDhaineeCirculaire
 
                   Var         cellule :   enregistrement  
                                  val :  entier ; 
                                  suiv : ^cellule ;
                                  prec : ^cellule ;
                             finenreg 

                            Liste tete =^cellule ; 
                              L : liste ; 
                              p : ^cellule ;
                              dernier : ^cellule ;
                                x : entier ; 
                Début 
                         écrire (¨entrer une nouvelle cellule¨) ;
 
                          p ← nouvelle cellule ;
                          p.val← x ;
                      Si L.tete = NULL Alors 
                         p.suiv← p ;
                         p.prec ← p ;
                         L.tete ← p ;
                     Sinon
                          dernier ← L.tete.prec ;
                          p.suiv ← L.tete ;
                          p.prec ← dernier ;
                         dernier.suiv ← p ;
                         L.tete.prec ← p ;
                     finSi
                fin 

```
# PLUS ⛓️
Pour de nombreuses informations, n'hésitez pas à contacter de qui avez besoin.



 


