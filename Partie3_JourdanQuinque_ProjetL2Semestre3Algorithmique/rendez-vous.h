#ifndef RENDEZ_VOUS_H
#define RENDEZ_VOUS_H


// Structure pour la date
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

// Structure pour l'heure
typedef struct {
    int heure;
    int minute;
} Heure;

// Structure pour un rendez-vous
typedef struct rendezvous{
    Date date;
    Heure debut;
    Heure fin;
    char* objet;
    struct rendezvous* next;  // Pointeur vers le prochain rendez-vous
} RendezVous;


RendezVous* createRendezVous();
int compareDates(const Date* date1, const Date* date2);
void displayRendezVous(RendezVous* rendezvous);


#endif /* RENDEZ_VOUS_H */