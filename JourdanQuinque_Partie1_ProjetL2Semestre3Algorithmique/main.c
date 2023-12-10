#include <stdio.h>
#include "liste.h"
#include "cellule.h"

int main() {
    // Créer une liste avec 3 niveaux
    t_d_list* my_list = create_empty_list(3);

    // Créer quelques cellules
    t_d_cell* cell1 = create_cell(5, 2);
    t_d_cell* cell2 = create_cell(10, 1);
    t_d_cell* cell3 = create_cell(3, 2);
    t_d_cell* cell4 = create_cell(7, 2);

    // Insérer les cellules dans la liste
    insert_cell(my_list, cell1);
    insert_sorted_cell(my_list, cell2);
    insert_sorted_cell(my_list, cell3);
    insert_sorted_cell(my_list, cell4);

    // Afficher le niveau 1 de la liste
    display_level(my_list,1);
    printf("\n");

    // Afficher tous les niveaux de la liste
    display_all_levels(my_list);

    // Libérer la mémoire (assurez-vous d'implémenter la libération de la mémoire dans vos fonctions)
    // libérer_liste(my_list);
    return 0;
}