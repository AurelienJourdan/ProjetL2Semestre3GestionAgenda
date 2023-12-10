#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "cellule.h"
#include "timer.h"

int main() {
    // Créer une liste avec 3 niveaux
    t_d_list* my_list = create_empty_list(3);

    // Créer quelques cellules
    t_d_cell* cell1 = create_cell(5, 2);
    t_d_cell* cell2 = create_cell(109, 1);
    t_d_cell* cell3 = create_cell(3, 1);
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
    printf("\n");

    // Créer une liste avec 3 niveaux
    t_d_list* my_list_3 = create_empty_list(3);

    // Remplir la liste avec des valeurs de 1 à 2^n-1
    fill_list(my_list_3);

    // Afficher tous les niveaux de la liste
    display_all_levels(my_list_3);

    // Exemple de recherche de la valeur 3
    int result1 = search_value_start_high(my_list_3, 3);
    printf("Recherche de 3 : %d\n", result1);


    // Créer une liste avec 3 niveaux
    t_d_list* my_list_search = create_empty_list(15);

    // Remplir la liste avec des valeurs de 1 à 2^n-1
    fill_list(my_list_search);

    // Exemple de recherche de 1000 valeurs aléatoire entre 0 et 1000
    startTimer();
    for (int i=0;i<1000;i++) {
        int searchedValue = rand() % 1001;
        int result = search_value_start_high(my_list_search, searchedValue);
        //printf("Recherche de %d : %d", searchedValue, result);
    }
    stopTimer();
    displayTime();
    // Exemple de recherche de 10000 valeurs aléatoire entre 0 et 1000
    startTimer();
    for (int i=0;i<10000;i++) {
        int searchedValue = rand() % 1001;
        int result = search_value_start_high(my_list_search, searchedValue);
        //printf("Recherche de %d : %d", searchedValue, result);
    }
    stopTimer();
    displayTime();
    // Exemple de recherche de 100000 valeurs aléatoire entre 0 et 1000
    startTimer();
    for (int i=0;i<100000;i++) {
        int searchedValue = rand() % 1001;
        int result = search_value_start_high(my_list_search, searchedValue);
        //printf("Recherche de %d : %d", searchedValue, result);
    }
    stopTimer();
    displayTime();

    printf("\n");

    // Exemple de recherche de 1000 valeurs aléatoire entre 0 et 1000
    startTimer();
    for (int i=0;i<1000;i++) {
        int searchedValue = rand() % 1001;
        int result = search_value_start_0(my_list_search, searchedValue);
        //printf("Recherche de %d : %d", searchedValue, result);
    }
    stopTimer();
    displayTime();
    // Exemple de recherche de 10000 valeurs aléatoire entre 0 et 1000
    startTimer();
    for (int i=0;i<10000;i++) {
        int searchedValue = rand() % 1001;
        int result = search_value_start_0(my_list_search, searchedValue);
        //printf("Recherche de %d : %d", searchedValue, result);
    }
    stopTimer();
    displayTime();
    // Exemple de recherche de 100000 valeurs aléatoire entre 0 et 1000
    startTimer();
    for (int i=0;i<100000;i++) {
        int searchedValue = rand() % 1001;
        int result = search_value_start_0(my_list_search, searchedValue);
        //printf("Recherche de %d : %d", searchedValue, result);
    }
    stopTimer();
    displayTime();

    return 0;
}