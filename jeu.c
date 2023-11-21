#include <stdio.h> 
#include <stdbool.h>
#include "utils.h"

#define ESSAI_TOTAUX 6

void simuler_essai(char mot_cherche[], char essai[], char reponse[]) {
    
    for (int i = 0; i < 5; i++) {
        if (essai[i] == mot_cherche[i]) {
            reponse[i] = 'v';
            mot_cherche[i] = '0';
        }
    }

    for (int i = 0; i < 5; i++) {
        if (reponse[i] == 'g') {
            if (char_in_str(mot_cherche, essai[i]))
                reponse[i] = 'o';
        }
    }

    return;
}

int main() {
    char mot_cherche[6];
    char essai[6];
    char reponse[6];
    int nbEssaisRestant = ESSAI_TOTAUX;
    bool enCours = true;

    for (int i = 0; i < 5; i++) 
        reponse[i] = 'g';
    reponse[5] = '\0';

    scanf("%s", mot_cherche);

    while (enCours && nbEssaisRestant > 0) {
        printf("Il reste %d essais :\n", nbEssaisRestant);
        scanf("%s", essai);
        simuler_essai(mot_cherche, essai, reponse);
        printf("%s\n", reponse);
        printf("Retour: %d, %s, %s\n", est_egal(essai, mot_cherche), essai, mot_cherche);
        if (est_egal(essai, mot_cherche)) {
            enCours = false;
        }
        nbEssaisRestant--;
    }

    if (nbEssaisRestant > 0) {
        printf("Vous avez gagné !");
    }
    else {
        printf("Vous avez perdu, le mot était : %s\n", mot_cherche);
    }

    return 0;
}