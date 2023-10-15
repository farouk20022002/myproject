#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ref;
    int tailleMemoir;
    int tailleDisque;
    char sysExp[20];
    char marque[20];
} ordinateur;

typedef struct {
    int ref;
    char marque[20];
    char typeMoteur[20];
    int vitesseMax;
    int prix;
} voiture;

void ajouterOrd(ordinateur[], int *);
void ajouterVoit(voiture[], int *);
void afficherVoit(voiture[], int, int);
void afficherOrd(ordinateur[], int, int);

int main(){
    int choixRefProduit;
    int nbVoit = 0;
    int nbOrd = 0;
    int choix;
    ordinateur stockOrd[50];
    printf("La capacité maximale de votre stockage d'ordinateur est de 50\n");
    voiture stockVoit[50];
    printf("La capacité maximale de votre stockage de voiture est de 50\n");

    do {
        /* Display the main menu */
        printf("##### Menu Principal #####\n");
        printf("1. Ajouter un produit\n");
        printf("2. Supprimer un produit\n");
        printf("3. Afficher les caractéristiques d'un produit\n");
        printf("Pour arrêter le programme, tapez 0\n");

        /* Get the user's choice */
        printf("Donnez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: /* Choice to add */
                printf("1. Ajouter une voiture\n");
                printf("2. Ajouter un ordinateur\n");
                int choixAjouter;
                scanf("%d", &choixAjouter);

                switch (choixAjouter) {
                    case 1:
                        ajouterVoit(stockVoit, &nbVoit);
                        break;
                    case 2:
                        ajouterOrd(stockOrd, &nbOrd);
                        break;
                    default:
                        printf("Choix invalide\n");
                        break;
                }
                break;

            case 2: /* Choice to delete - You need to implement this function */
                printf("1. Supprimer une voiture\n");
                printf("2. Supprimer un ordinateur\n");
                int choixSupprimer;
                scanf("%d", &choixSupprimer);

                switch (choixSupprimer) {
                    // Implement the deletion logic
                }
                break;

            case 3: /* Choice to display */
                printf("1. Afficher une voiture\n");
                printf("2. Afficher un ordinateur\n");
                int choixAfficher;
                scanf("%d", &choixAfficher);

                switch (choixAfficher) {
                    case 1:
                        scanf("%d", &choixRefProduit);
                        afficherVoit(stockVoit, choixRefProduit, nbVoit);
                        break;
                    case 2:
                        scanf("%d", &choixRefProduit);
                        afficherOrd(stockOrd, choixRefProduit, nbOrd);
                        break;
                    default:
                        printf("Choix invalide\n");
                        break;
                }
                break;

            case 0: /* Exit the program */
                break;

            default:
                printf("Choix invalide\n");
                break;
        }
    } while (choix != 0);

    return 0;
}

void ajouterOrd(ordinateur stockOrd[], int *PnbOrd) {
    if (*PnbOrd == 50) {
        printf("Stock est plein\n");
    } else {
        printf("Donnez la référence de l'ordinateur: ");
        scanf("%d", &stockOrd[*PnbOrd].ref);
        printf("Donnez la taille mémoire de l'ordinateur: ");
        scanf("%d", &stockOrd[*PnbOrd].tailleMemoir);
        printf("Donnez la taille disque de l'ordinateur: ");
        scanf("%d", &stockOrd[*PnbOrd].tailleDisque);
        printf("Donnez la marque de l'ordinateur: ");
        scanf("%19s", stockOrd[*PnbOrd].marque);
        printf("Donnez le système d'exploitation de l'ordinateur: ");
        scanf("%19s", stockOrd[*PnbOrd].sysExp);
        (*PnbOrd)++;
    }
}

void ajouterVoit(voiture stockVoit[], int *PnbVoit) {
    if (*PnbVoit == 50) {
        printf("Stock est plein\n");
    } else {
        printf("Donnez la référence de la voiture: ");
        scanf("%d", &stockVoit[*PnbVoit].ref);
        printf("Donnez le type du moteur de la voiture: ");
        scanf("%19s", stockVoit[*PnbVoit].typeMoteur);
        printf("Donnez la vitesse maximale de la voiture: ");
        scanf("%d", &stockVoit[*PnbVoit].vitesseMax);
        printf("Donnez le prix de la voiture: ");
        scanf("%d", &stockVoit[*PnbVoit].prix);
        printf("Donnez la marque de la voiture: ");
        scanf("%19s", stockVoit[*PnbVoit].marque);
        (*PnbVoit)++;
    }
}

void afficherVoit(voiture stockVoit[], int reff, int PnbVoit) {
    int test = 0;
    if (PnbVoit == 0) {
        printf("Il faut d'abord ajouter des voitures\n");
    }

    for (int i = 0; i < PnbVoit; i++) {
        if (stockVoit[i].ref == reff) {
            printf("La référence est : %d\nLa vitesse maximale est : %d\nLe prix est : %d\nLa marque est : %s\nLe type moteur est : %s\n",
                stockVoit[i].ref, stockVoit[i].vitesseMax, stockVoit[i].prix, stockVoit[i].marque, stockVoit[i].typeMoteur);
            test = 1;
            break;
        }
    }

    if (test == 0) {
        printf("La référence n'existe pas\n");
    }
}

void afficherOrd(ordinateur stockOrd[], int reff, int PnbOrd) {
    int test = 0;
    if (PnbOrd == 0) {
        printf("Il faut d'abord ajouter des ordinateurs\n");
    }

    for (int i = 0; i < PnbOrd; i++) {
        if (stockOrd[i].ref == reff) {
            printf("La référence est : %d\nLa mémoire est : %d\nLe taille disque est : %d\nLa marque est : %s\nLe système d'exploitation est : %s\n",
                stockOrd[i].ref, stockOrd[i].tailleMemoir, stockOrd[i].tailleDisque, stockOrd[i].marque, stockOrd[i].sysExp);
            test = 1;
            break;
        }
    }

    if (test == 0) {
        printf("La référence n'existe pas\n");
    }
}
