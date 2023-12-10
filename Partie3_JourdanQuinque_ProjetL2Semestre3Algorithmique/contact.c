#include "contact.h"
#include "agenda.h"
#include "rendez-vous.h"


// Fonction pour créer un contact
Contact createContact() {
    Contact contact;
    printf("Saisir le nom du contact : ");
    contact.nom = scanString();
    printf("Saisir le prenom du contact : ");
    contact.prenom = scanString();

    return contact;
}
