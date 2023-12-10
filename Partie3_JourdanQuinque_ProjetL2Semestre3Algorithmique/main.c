#include <stdio.h>
#include <stdlib.h>
#include "contact.h"
#include "agenda.h"
#include "rendez-vous.h"

int main() {
    int choice;

    int maxLevels = 3;
    AgendaList* agendaList = createEmptyAgendaList(maxLevels);
    AgendaEntry *entry;
    Contact contact;
    RendezVous* rendezvous;
    char nom;
    char prenom;

    do {
        // Afficher le menu et lire le choix de l'utilisateur
        printf("Menu:\n");
        printf("1. Rechercher un contact\n");
        printf("2. Afficher les rendez-vous d'un contact\n");
        printf("3. Creer un contact\n");
        printf("4. Creer un rendez-vous pour un contact\n");
        printf("5. Supprimer un rendez-vous\n");
        printf("0. Quitter\n");

        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Rechercher un contact
                // ...
                break;
            case 2:
                // Afficher les rendez-vous d'un contact
                // ...
                break;
            // Créer un contact //
            case 3:
                // Créer une instance de Contact
                contact = createContact();
                // Créer une instance de AgendaEntry et y insérer le contact
                entry = createAgendaEntry(contact, rendezvous);
                // Insérer l'entrée dans la liste d'agenda
                insertAgendaEntry(agendaList, entry);
                break;
           // Créer un rendez-vous pour un contact
            case 4:
                // Créer une instance de Contact
                contact = createContact();
                rendezvous = createRendezVous();
                // Créer une instance de AgendaEntry et y insérer le contact
                entry = createAgendaEntry(contact, rendezvous);
                // Insérer l'entrée dans la liste d'agenda
                insertAgendaEntry(agendaList, entry);

                break;
            case 5:
                // Supprimer un rendez-vous
                // ...
                break;
            case 0:
                // Quitter le programme
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choice != 0);

    return 0;
}