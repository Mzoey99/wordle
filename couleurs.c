#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define nbre_l 5 //nombre de lettres du mot qu'on cherche 

// Sélection de couleurs
#define couleur(param) printf("\033[%sm",param)
/*   param devant être un const char *, vide (identique à "0") ou formé
     d'une où plusieurs valeurs séparées par des ; parmi
         0  réinitialisation         1  haute intensité (des caractères)
         5  clignotement             7  video inversé
         30, 31, 32, 33, 34, 35, 36, 37 couleur des caractères
         40, 41, 42, 43, 44, 45, 46, 47 couleur du fond
            les couleurs, suivant la logique RGB, étant respectivement
               noir, rouge, vert, jaune, bleu, magenta, cyan et blanc */

//PARTIE CLAVIER :
char* creation_tab(){
    char* clavier=malloc(sizeof(char)*26);
    //en ASCII la lettre A commence à 17
    for (int i=17;i<43;i++){
        clavier[i-17]=i+'0';
    }
    return clavier;
};

void affichage_tableau(char* clavier){
    printf("\n");
    for (int j=0;j<3;j++){ //pour faire un affichage comme sur un clavier d'ordi c'est 10 caractères par ligne
        for (int i=0;i<10;i++){
            if (10*j+i<26){ //attention à ne pas dépasser 20
            printf("%c  ",clavier[10*j+i]);
            }
        }
        printf("\n");
    }
}

//Fonction qui remplace une lettre par un point
void remplace(char c, char* clavier){
    int i=c;
    clavier[i-65]='.';
}

bool colorie(char* tentative, char* mot, char* clavier){ //attention nouveau paramètre, il y a le clavier qui se rajoute !
    bool found = true;
    for (int i = 0; i < nbre_l; i++)
    {
        int temoin =0;
        if (tentative[i]==mot[i]){
            couleur("42");
            printf("%c",tentative[i]);  
            couleur("0"); 
            temoin=1;  
        }
        //sinon on cherche si la lettre est présente dans le mot
        else { 
            found = false;
            int j = 0;
            while (j<nbre_l){
                if (tentative[i]==mot[j]){
                couleur("43");
                printf("%c",tentative[i]); 
                couleur("0"); 
                j=nbre_l; //on clôt la boucle
                temoin =1;
                }
                j++;
            }
            if (temoin==0){ //si la lettre n'est pas présente
                printf("%c",tentative[i]);
                remplace(tentative[i],clavier);
            }
        
        
        }    
    }
    return found;
}