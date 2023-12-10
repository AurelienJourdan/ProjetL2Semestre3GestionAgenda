#include "agenda.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction de saisie pour les chaînes de caractères dynamiques
char* scanString(void) {
    char buffer[256];
    scanf("%255s", buffer);
    // Allouer dynamiquement la mémoire pour la chaîne de caractères
    char* str = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
    // Copier les caractères dans la mémoire allouée dynamiquement
    strcpy(str, buffer);

    return str;
}

AgendaList* createEmptyAgendaList(int max_levels) {
    AgendaList* newAgendaList = (AgendaList*)malloc(sizeof(AgendaList));
    if (newAgendaList != NULL) {
        newAgendaList->heads = (AgendaEntry**)malloc(max_levels * sizeof(AgendaEntry*));
        for (int i = 0; i < max_levels; ++i) {
            newAgendaList->heads[i] = NULL;
        }
        newAgendaList->max_levels = max_levels;
    }
    return newAgendaList;
}

AgendaEntry *createAgendaEntry(Contact contact, RendezVous *rendezvous) {

    AgendaEntry* newAgendaEntry = (AgendaEntry*)malloc(sizeof(AgendaEntry));

    if (newAgendaEntry != NULL) {
        // Initialize the Contact
        newAgendaEntry->contact.nom = contact.nom;
        newAgendaEntry->contact.prenom = contact.prenom;

        // Initialize the RendezVous head to NULL
        newAgendaEntry->rendezvous_head = rendezvous;
    }

    return newAgendaEntry;
}


void insertAgendaEntry(AgendaList* agendaList, AgendaEntry* entry) {
    if (agendaList == NULL || entry == NULL) {
        printf("Invalid agenda or entry.\n");
        return;
    }
    AgendaEntry* current = agendaList->heads[0];
    AgendaEntry* previous = NULL;

    while (current != NULL && strcmp(current->contact.nom, entry->contact.nom) < 0) {
        previous = current;
        current = current->next;
    }
    // Si pas d'entrée dans l'agenda ou arrivé à la fin de l'agenda
    if (previous == NULL || current == NULL) {
        agendaList->heads[0] = entry;
    }
        // Si l'AgendaEntry existe déjà
    else if (strcmp(current->contact.nom, entry->contact.nom) == 0) {
        entry->next = current->next;
        previous->next = entry;
        free(current);
    }
        // Si c'est la bonne place
    else {
        entry->next = current;
        previous->next = entry;
    }
}

// Fonction pour afficher une entrée de l'agenda
void displayAgendaEntry(AgendaEntry* entry) {
    if (entry != NULL) {
        printf("Contact : %s %s\n", entry->contact.nom, entry->contact.prenom);

        RendezVous* currentRdv = entry->rendezvous_head;
        while (currentRdv != NULL) {
            printf("Rendez-vous :\n");
            displayRendezVous(currentRdv);
            currentRdv = currentRdv->next;  // Passer au prochain rendez-vous dans la liste
        }
        printf("\n");
    }
}

void displayAgendaList(AgendaList* agendaList) {
    if (agendaList == NULL) {
        return;
    }
    // Afficher les entrées de l'agenda
    for (int level = 0; level < agendaList->max_levels; ++level) {
        displayAgendaEntry(agendaList);
    }
}