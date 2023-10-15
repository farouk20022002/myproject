#include <stdio.h>
#include<stdlib.h>

typedef struct {
  int ref;
  int tailleMemoir;
  int tailleDisque;
  char sysExp[20];
  char marque[20];
}ordinateur;

typedef struct 
{
  int ref;
  char marque[20];
  char typeMoteur[20];
  int vitesseMax;
  int prix;
}voiture;
void ajouterOrd(ordinateur[], int * );
void ajouterVoit(voiture[], int *);
void supprimerVoit(voiture[],int,int * );
void supprimerOrd(ordinateur[],int,int * );
void afficherVoit(voiture[],int,int *);
void afficherOrd(ordinateur[],int, int *);

static int i;
int main(){
  int choixRefProduit;
  int nbVoit=0;
  int nbOrd=0;
  int choixAjouter,choixSupprimer,choixAfficher;
  int choix;
  int *PnbVoit=&nbVoit;
  int *PnbOrd=&nbOrd;
  ordinateur stockOrd[50];
  printf("la capacité maximale de votre stockage d'ordinateur est de 50 \n");
  voiture stockVoit[50];
  printf("la capacité maximale de votre stockage de voiture est de 50 \n");
  do
  {
    printf("##### Menu Principal ##### \n");
    printf("1.ajouter un produit \n");
    printf("2.supprimer un produit \n");
    printf("3.afficher les caracteristique d'un produit \n");
    printf("pour arrêter le programme tapez 0 \n");

    do
  {
    printf("donner votre choix :");
    scanf("%d \n",&choix);
    if (choix<1 || choix>4)
    {
      printf("votre choix est invalide \n");
      break;
    }
    
    switch (choix)
    {
    case 1:
      printf("1.ajouter une voiture \n");
      printf("2.ajouter un ordinateur \n");
      scanf("donner votre choix %d \n",&choixAjouter);
      switch (choixAjouter)
      {
      case 1:
        ajouterVoit(stockVoit,PnbVoit);
        break;
      case 2:
         ajouterOrd(stockOrd,PnbOrd);      
      break;
      
      default:
      printf("choix invalide \n");
        break;
      }
      break;
      case 2:
         printf("1.supprimer une voiture \n");
      printf("2.supprimer un ordinateur \n");
      scanf("donner votre choix %d \n",&choixSupprimer);
       switch (choixSupprimer)
       {
       case 1:
        supprimerVoit(stockVoit,nbVoit,PnbVoit);
        break;
        case 2:
        supprimerOrd(stockOrd,nbOrd,PnbOrd);
       
       default:
       printf("choix invalide \n");
        break;
       }
      case 3:
      printf("1.afficher une voiture \n");
      printf("2.afficher un ordinateur \n");
      scanf("donner votre choix %d \n",&choixAfficher);
       switch (choixAfficher)
       {
       case 1:
        scanf("%d",&choixRefProduit);
        afficherVoit(stockVoit,choixRefProduit,PnbVoit);
        break;
        case 2:
        afficherOrd(stockOrd,choixRefProduit,PnbOrd);
       
       default:
        printf("choix invalide \n");
        break;
       }
      break;
    
    default:
       printf("choix invalide \n");
      break;
    }
  } while (choix<1 || choix >4);
  
  } while (choix!=0 && nbOrd<50 && nbVoit<50);
  
  


}


void ajouterOrd(ordinateur stockOrd[], int *PnbOrd ){
  printf("donner reference de l'ordinateur \n");
  scanf("%d",&stockOrd[*PnbOrd].ref);
  printf("donner taille memoire de l'ordinateur \n");
  scanf("%d",&stockOrd[*PnbOrd].tailleMemoir);
  printf("donner taille disque de l'ordinateur \n");
  scanf("%d",&stockOrd[*PnbOrd].tailleDisque);
  printf("donner marque de l'ordinateur \n");
  scanf("%s",&stockOrd[*PnbOrd].marque);
  printf("donner systeme d'exploitation de l'ordinateur \n");
  scanf("%s",&stockOrd[*PnbOrd].sysExp);
  *PnbOrd=*PnbOrd+1;
}
void ajouterVoit(voiture stockVoit[], int *PnbVoit){
   printf("donner reference de la voiture \n");
  scanf("%d",&stockVoit[*PnbVoit].ref);
  printf("donner le type du moteur de la voiture\n");
  scanf("%s",&stockVoit[*PnbVoit].typeMoteur);
  printf("donner la vitesse maximale de la voiture \n");
  scanf("%d",&stockVoit[*PnbVoit].vitesseMax);
  printf("donner le prix de la voiture \n");
  scanf("%d",&stockVoit[*PnbVoit].prix);
  printf("donner la marque de la voiture \n");
  scanf("%s",&stockVoit[*PnbVoit].marque);
  *PnbVoit = *PnbVoit + 1;
}
void afficherVoit(voiture stockVoit[],int reff , int *PnbVoit){
  int test=0;
  if(*PnbVoit==0){
    printf("il faut d'abord ajouter des voitures \n");
  }
  for(i=0;i<*PnbVoit;i++){
    if(stockVoit[i].ref==reff){
      printf("la reference est : %d \n la vitesse maximale est : %d \n le prix est : %d \n la marque est : %s \n le type moteur est : %s \n",stockVoit[i].ref,stockVoit[i].vitesseMax,stockVoit[i].prix,stockVoit[i].marque,stockVoit[i].typeMoteur);
      test=1;
      break;
    }
  }
  if(test==0){
    printf("la reference n'existe pas \n");
  }
}

void afficherOrd(ordinateur stockOrd[],int reff,int *PnbOrd ){
  int test=0;
  if(*PnbOrd==0){
    printf("il faut d'abord ajouter des ordinateurs \n");
  }
  for(i=0;i<*PnbOrd;i++){
    if(stockOrd[i].ref==reff){
      printf("la reference est : %d \n la memoire est : %d \n le taille disque est : %d \n la marque est : %s \n le systeme d'exploitation est : %s \n",stockOrd[i].ref,stockOrd[i].tailleMemoir,stockOrd[i].tailleDisque,stockOrd[i].marque,stockOrd[i].sysExp);
      test=1;
      break;
    }
  }
  if(test==0){
    printf("la reference n'existe pas \n");
  }
}
