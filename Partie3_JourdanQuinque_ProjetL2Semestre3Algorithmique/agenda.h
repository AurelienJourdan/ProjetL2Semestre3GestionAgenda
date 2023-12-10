#ifndef AGENDA_H
#define AGENDA_H

#include "rendez-vous.h"
#include "contact.h"
// Structure pour une entrée de l'agenda
typedef struct agenda_entry {
    Contact contact;
    RendezVous* rendezvous_head;
    struct agenda_entry* next;
} AgendaEntry;

// Structure pour la liste à niveaux avec un agenda
typedef struct {
    AgendaEntry** heads;
    int max_levels;
} AgendaList;

char* scanString(void);
AgendaEntry* createAgendaEntry(Contact contact, RendezVous* rendezvous) ;
AgendaList* createEmptyAgendaList(int max_levels);
void insertAgendaEntry(AgendaList* agendaList, AgendaEntry* entry);
void displayAgendaList(AgendaList* agendaList);
void displayAgendaEntry(AgendaEntry* entry);

#endif /* AGENDA_H */