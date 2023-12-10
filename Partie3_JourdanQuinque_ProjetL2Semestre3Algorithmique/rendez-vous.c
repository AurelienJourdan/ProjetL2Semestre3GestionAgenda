#include "rendez-vous.h"

#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>

// Fonction avec saisies sécurisées pour créer un rendez-vous
RendezVous* createRendezVous() {
    RendezVous* rdv = (RendezVous*)malloc(sizeof(RendezVous));

    if (rdv != NULL) {
        // Saisie de la date
        do {
            printf("Saisir la date du rendez-vous (jour mois annee) : ");
            if (scanf("%d %d %d", &(rdv->date.jour), &(rdv->date.mois), &(rdv->date.annee)) != 3) {
                // Gestion d'une saisie invalide
                printf("Saisie invalide. Veuillez réessayer.\n");
                free(rdv);
                return NULL;
            }

            // Vérification de la validité de la date
            if (rdv->date.jour < 1 || rdv->date.jour > 31 || rdv->date.mois < 1 || rdv->date.mois > 12) {
                printf("Date invalide. Veuillez saisir une date valide.\n");
            } else {
                break;  // Sortir de la boucle si la date est valide
            }
        } while (1);

        // Saisie de l'heure de début
        do {
            printf("Saisir l'heure de debut du rendez-vous (heure minute) : ");
            if (scanf("%d %d", &(rdv->debut.heure), &(rdv->debut.minute)) != 2) {
                printf("Saisie invalide. Veuillez réessayer.\n");
                free(rdv);
                return NULL;
            }

            // Vérification de la validité de l'heure de début
            if (rdv->debut.heure < 0 || rdv->debut.heure > 23 ||
                rdv->debut.minute < 0 || rdv->debut.minute > 59) {
                printf("Heure de début invalide. Veuillez saisir une heure valide.\n");
            } else {
                break;  // Sortir de la boucle si l'heure de début est valide
            }
        } while (1);

        // Saisie de la durée du rendez-vous
        do {
            printf("Saisir l'heure de fin du rendez-vous (heure minute) : ");
            if (scanf("%d %d", &(rdv->fin.heure), &(rdv->fin.minute)) != 2) {
                printf("Saisie invalide. Veuillez réessayer.\n");
                free(rdv);
                return NULL;
            }

            // Vérification de la validité de la durée
            if (rdv->fin.heure < 0 || rdv->fin.heure > 23 || rdv->fin.minute < 0 || rdv->fin.minute > 59) {
                printf("Duree invalide. Veuillez saisir une durée valide.\n");
            } else {
                // Vérification de la cohérence des heures de début et de fin
                if (rdv->fin.heure < rdv->debut.heure || (rdv->fin.heure == rdv->debut.heure && rdv->fin.minute <= rdv->debut.minute)) {
                    printf("Heure de fin invalide. Veuillez saisir une heure de fin ultérieure à l'heure de début.\n");
                } else {
                    break;  // Sortir de la boucle si la durée et l'heure de fin sont valides
                }
            }
        } while (1);

        // Saisie de l'objet du rendez-vous
        printf("Saisir l'objet du rendez-vous : ");
        rdv->objet = scanString();
    }

    return rdv;
}


// Fonction pour comparer deux dates
int compareDates(const Date* date1, const Date* date2) {
    if (date1->annee != date2->annee) {
        return date1->annee - date2->annee;
    }
    if (date1->mois != date2->mois) {
        return date1->mois - date2->mois;
    }
    return date1->jour - date2->jour;
}

// Fonction pour afficher un rendez-vous
void displayRendezVous(RendezVous* rendezvous) {
    if (rendezvous != NULL) {
        printf("Date : %02d/%02d/%04d\n", rendezvous->date.jour, rendezvous->date.mois, rendezvous->date.annee);
        printf("Heure de début : %02d:%02d\n", rendezvous->debut.heure, rendezvous->debut.minute);
        printf("Durée : %02d:%02d\n", rendezvous->fin.heure, rendezvous->fin.minute);
        printf("Objet : %s\n", rendezvous->objet);
    }
};
