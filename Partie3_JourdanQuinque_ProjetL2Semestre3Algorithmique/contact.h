#ifndef CONTACT_H
#define CONTACT_H
#include <stdio.h>

// Structure pour un contact
typedef struct {
    char* nom;
    char* prenom;
} Contact;

Contact createContact();

#endif /* CONTACT_H */
