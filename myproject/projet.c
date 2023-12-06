#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void afficherVoit(int );
void afficherOrd(int);
void supprimerVoit(int);
void supprimerOrd(int);
void afficherVoitPrix(int);
void afficherOrdMemoire(int);
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
               
                case 2: /* Choice to delete */
                    printf("1. Supprimer une voiture\n");
                    printf("2. Supprimer un ordinateur\n");
                    int choixSupprimer;
                   scanf("%d", &choixSupprimer);

                    switch (choixSupprimer) {
                       case 1:
                         printf("Donnez la référence de la voiture à supprimer: \n");
                         scanf("%d", &choixRefProduit);
                         supprimerVoit( choixRefProduit);
                         break;
                      case 2:
                         printf("Donnez la référence de l'ordinateur à supprimer: \n");
                         scanf("%d", &choixRefProduit);
                         supprimerOrd( choixRefProduit);
                        break;
                      default:
                         printf("Choix invalide\n");
                        break;
                  }    
             break;
            case 3: /* Choice to display */
                printf("1. Afficher une voiture\n");
                printf("2. Afficher un ordinateur\n");
                printf("3. afficher les voitures dont le prix est inferieur a x\n");
                printf("4. afficher les ordinateurs dont la taille memoire est inferieur a x\n");
                int choixAfficher;
                scanf("%d", &choixAfficher);

                switch (choixAfficher) {
                    case 1:
                        printf("Donnez la référence de la voiture à afficher: \n");
                        scanf("%d", &choixRefProduit);
                        afficherVoit( choixRefProduit);
                        break;
                    case 2:
                        printf("Donnez la référence de l'ordinateur à afficher: \n");
                        scanf("%d", &choixRefProduit);
                        afficherOrd( choixRefProduit);
                        break;
                    case 3:
                        int prixMax;
                        printf("donner le prix maximal \n");
                        scanf("%d",&prixMax);
                        afficherVoitPrix(prixMax);
                    break;
                    case 4:
                      int memMax;
                      printf("donner la taille de memoire maximale");
                      scanf("%d",&memMax);
                      afficherOrdMemoire(memMax);
                     break;
                    default:
                        printf("Choix invalide\n");
                        break;
                }
                break;
                default:
                printf("Choix invalide\n");
                break;
        }
    } while (choix != 0);
    return 0;
}

void ajouterOrd(ordinateur stockOrd[], int *PnbOrd) {
    FILE *o;
    int test=0;
    o=fopen("fichier_de_sauvgarde_ordinateur.txt","a");
    if (*PnbOrd == 50 ) {
        printf("Stock est plein\n");
    } else {
        
        printf("Donnez la référence de l'ordinateur: ");
        scanf("%d", &stockOrd[*PnbOrd].ref);
        for(int i=0;i<*PnbOrd;i++){if(stockOrd[*PnbOrd].ref==stockOrd[i].ref){test=1;}}
        
        printf("Donnez la taille mémoire de l'ordinateur: ");
        scanf("%d", &stockOrd[*PnbOrd].tailleMemoir);
        printf("Donnez la taille disque de l'ordinateur: ");
        scanf("%d", &stockOrd[*PnbOrd].tailleDisque);
        printf("Donnez la marque de l'ordinateur: ");
        scanf("%19s", stockOrd[*PnbOrd].marque);
        printf("Donnez le système d'exploitation de l'ordinateur: ");
        scanf("%19s", stockOrd[*PnbOrd].sysExp);
        
   
    fprintf(o,"%d %s %s %d %d \n",stockOrd[*PnbOrd].ref,stockOrd[*PnbOrd].marque, stockOrd[*PnbOrd].sysExp,stockOrd[*PnbOrd].tailleMemoir,stockOrd[*PnbOrd].tailleDisque);
    (*PnbOrd)++;
             }
    fclose(o);
}

void ajouterVoit(voiture stockVoit[], int *PnbVoit) {
    FILE *v;
    v=fopen("fichier_de_sauvgarde_voiture.txt","a");
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
        
    
    fprintf(v,"%d %s %d %d %s \n",stockVoit[*PnbVoit].ref,stockVoit[*PnbVoit].typeMoteur,stockVoit[*PnbVoit].vitesseMax,stockVoit[*PnbVoit].prix,stockVoit[*PnbVoit].marque);
    (*PnbVoit)++;
            }
    fclose(v);
}

 void afficherVoit(int reff) {
    int test = 0;
    FILE *v;
    v = fopen("fichier_de_sauvgarde_voiture.txt", "r");

    if (v == NULL) {
        printf("Erreur lors de l'ouverture du fichier de sauvegarde des voitures.\n");
        return;
    }

    int ref, vit_max, prix;
    char type_moteur[20], marque[20];

    while (fscanf(v, "%d %s %d %d %s", &ref, type_moteur, &vit_max, &prix, marque) == 5) {
        if (ref == reff) {
            printf("Référence : %d\nType moteur : %s\nVitesse maximale : %d\nPrix : %d\nMarque : %s\n", ref, type_moteur, vit_max, prix, marque);
            test = 1;
            break;
        }
    }

    fclose(v);

    if (test == 0) {
        printf("La référence n'existe pas dans le stock de voitures.\n");
    }
}

void afficherOrd(int reff) {
    int test = 0;
    FILE *o;
    o = fopen("fichier_de_sauvgarde_ordinateur.txt", "r");

    if (o == NULL) {
        printf("Erreur lors de l'ouverture du fichier de sauvegarde des ordinateurs.\n");
        return;
    }

    int ref, taille_mem, taille_disk;
    char sys_exp[20], marque[20];

    while (fscanf(o, "%d %s %s %d %d", &ref, marque, sys_exp, &taille_mem, &taille_disk) == 5) {
        if (ref == reff) {
            printf("Référence : %d\nMarque : %s\nSystème d'exploitation : %s\nTaille mémoire : %d\nTaille disque : %d\n", ref, marque, sys_exp, taille_mem, taille_disk);
            test = 1;
            break;
        }
    }

    fclose(o);

    if (test == 0) {
        printf("La référence n'existe pas dans le stock d'ordinateurs.\n");
    }
}

void supprimerVoit(int reff) {
    int i;
    int found = 0;
    FILE *v;
    v = fopen("fichier_de_sauvgarde_voiture.txt", "r");
    FILE *n;
    n = fopen("temporaire.txt", "w");
    
    if (v == NULL || n == NULL) {
        printf("Erreur lors de l'ouverture des fichiers.\n");
        return;
    }

    int ref, vit_max, prix;
    char type_moteur[20], marque[20];
while (!feof(v))
{
   
    while (fscanf(v, "%d %s %d %d %s", &ref, type_moteur, &vit_max, &prix, marque) == 5) {
        if (ref != reff) {
            fprintf(n, "%d %s %d %d %s \n", ref, type_moteur, vit_max, prix, marque);
        } else {
            found = 1;
        }
    }
}
 if (!found) {
        printf("La référence n'existe pas dans le stock de voitures.\n");
    }
 fclose(v);
    fclose(n);
    remove("fichier_de_sauvgarde_voiture.txt");
    rename("temporaire.txt", "fichier_de_sauvgarde_voiture.txt");

   

   
}


void supprimerOrd(int reff) {
    int i;
    int found = 0;
    FILE *o;
    o=fopen("fichier_de_sauvgarde_ordinateur.txt","r");
    FILE *n;
    n=fopen("temporaireordinateur.txt","w");
     if (o == NULL || n == NULL) {
        printf("Erreur lors de l'ouverture des fichiers.\n");
        return;
    }
    int ref,taille_mem,taille_disk;
    char sys_exp[20],marque[20];
    while (!feof(o))
    {
       while(fscanf(o,"%d %s %d %d %s",&ref,&taille_mem,sys_exp,&taille_disk,marque)==5){
                if(ref!=reff){
               fprintf(n,"%d %s %d %d %s \n",&ref,sys_exp,&taille_mem,&taille_disk,marque);
                }
                if (ref==reff)
                {
                    found=1;
                }             
    } }
    if (!found) {
        printf("La référence n'existe pas dans le stock d'ordinateurs'.\n");
    }
    fclose(n);
    fclose(o);
    remove("fichier_de_sauvgarde_ordinateur.txt");
    rename("temporaireordinateur.txt", "fichier_de_sauvgarde_ordinateur.txt");
   
    
   
}

void afficherVoitPrix(int prixRef){
int test = 0;
    FILE *v;
    v = fopen("fichier_de_sauvgarde_voiture.txt", "r");

    if (v == NULL) {
        printf("Erreur lors de l'ouverture du fichier de sauvegarde des voitures.\n");
        return;
    }

    int ref, vit_max, prix;
    char type_moteur[20], marque[20];

    while (fscanf(v, "%d %s %d %d %s", &ref, type_moteur, &vit_max, &prix, marque) == 5) {
        if (prix <= prixRef) {
            printf("Référence : %d\nType moteur : %s\nVitesse maximale : %d\nPrix : %d\nMarque : %s\n", ref, type_moteur, vit_max, prix, marque);
            test = 1;
        }
    }

    fclose(v);

    if (test == 0) {
        printf("La référence n'existe pas dans le stock de voitures.\n");
    }
}

void afficherOrdMemoire(int memMax){
    int test = 0;
    FILE *o;
    o = fopen("fichier_de_sauvgarde_ordinateur.txt", "r");

    if (o == NULL) {
        printf("Erreur lors de l'ouverture du fichier de sauvegarde des ordinateurs.\n");
        return;
    }

    int ref, taille_mem, taille_disk;
    char sys_exp[20], marque[20];

    while (fscanf(o, "%d %s %s %d %d", &ref, marque, sys_exp, &taille_mem, &taille_disk) == 5) {
        if (taille_mem <= memMax) {
            printf("Référence : %d\nMarque : %s\nSystème d'exploitation : %s\nTaille mémoire : %d\nTaille disque : %d\n", ref, marque, sys_exp, taille_mem, taille_disk);
            test = 1;
           
        }
    }

    fclose(o);

    if (test == 0) {
        printf("La référence n'existe pas dans le stock d'ordinateurs.\n");
    }
}