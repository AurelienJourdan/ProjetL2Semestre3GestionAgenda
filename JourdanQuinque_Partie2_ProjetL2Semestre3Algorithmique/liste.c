#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

t_d_list* create_empty_list(int max_level) {
    t_d_list* new_list = (t_d_list*)malloc(sizeof(t_d_list));
    if (new_list != NULL) {
        new_list->heads = (t_d_cell**)malloc(max_level * sizeof(t_d_cell*));
        for (int level = 0; level < max_level; ++level) {
            new_list->heads[level] = NULL;
        }
        new_list->max_level = max_level;
    }
    return new_list;
}

void insert_cell(t_d_list* list, t_d_cell* cell) {
    // Gestion des cas d'entrée invalide
    if (list == NULL || cell == NULL || cell->levels >= list->max_level) {
        return;
    }
    cell->next = list->heads[0];
    // Insérer la cellule à la tête de chaque niveau
    for (int level = 0; level < cell->levels; ++level) {
        list->heads[level] = cell;
    }
}

void insert_sorted_cell(t_d_list* list, t_d_cell* cell) {
    // Gestion des cas d'entrée invalide
    if (list == NULL || cell == NULL || cell->levels >= list->max_level) {
        return;
    }

    t_d_cell* current = list->heads[0];
    t_d_cell* previous = NULL;

    // Trouver l'emplacement approprié pour insérer la cellule
    while (current != NULL && current->value < cell->value) {
        previous = current;
        current = current->next;
    }

    // Insérer la cellule à la bonne position
    if (previous == NULL) {
        // Insérer en tête de liste
        cell->next = list->heads[0];
        list->heads[0] = cell;

    } else {
        // Insérer ailleurs dans la liste
        cell->next = current;
        previous->next = cell;
    }

    // Mettre à jour heads des niveaux si c'est la première cellule avec le niveau
    for (int level = 0; level <= cell->levels; ++level) {
        if (list->heads[level] == NULL) {
            list->heads[level] = cell;
        }
    }
}


// Affiche les cellules au niveau demandé en alignant verticalement
void display_level(t_d_list* list, int level) {
    // Gestion des cas d'entrée invalide
    if (list == NULL || level < 0 || level >= list->max_level) {
        return;
    }

    printf("Niveau %d: ", level);
    t_d_cell* current = list->heads[0];
    while (current != NULL) {
        if (current->levels < level){
            int i = current->value;
            while (i >=10) {
                i = i/10;
                printf("-");
            }
            printf("------- --> ");
        }
        else {
            printf("[ %d|@ ] --> ", current->value);
        }
        current = current->next;
    }
    printf("NULL\n");
}

void display_all_levels(t_d_list* list) {
    // Gestion des cas d'entrée invalide
    if (list == NULL) {
        return;
    }

    // Afficher les niveaux
    for (int level = 0; level < list->max_level; ++level) {
        display_level(list, level);
    }
}

void fill_list(t_d_list* list) {
    if (list == NULL || list->max_level <= 0) {
        return;
    }

    // Remplir la liste avec des cellules de valeur de 1 à 2^maxLevel-1
    for (int value = 1; value < pow(2, list->max_level); ++value) {
        // Calculer le niveau pour cette cellule
        int levels = 0;
        int levelValue = value;
        while (levelValue % 2 == 0 && levels < list->max_level) {
            levelValue /= 2;
            levels++;
        }

        // Créer la cellule avec le niveau calculé
        t_d_cell* cell = create_cell(value, levels);

        // Insérer la cellule dans la liste
        insert_sorted_cell(list, cell);
    }
}

int search_value_start_0(t_d_list* list, int target) {
    // Gestion des cas d'entrée invalide
    if (list == NULL) {
        return 0;
    }

    // Initialiser la cellule de départ
    t_d_cell* currentCell = list->heads[0];

    // Parcourir la liste au niveau 0 pour trouver la valeur cible
    while (currentCell != NULL) {
        if (currentCell->value == target) {
            // La valeur cible a été trouvée dans le niveau 0
            return 1;
        }
        currentCell = currentCell->next;
    }

    // La valeur cible n'a pas été trouvée dans le niveau 0
    return 0;
}


int search_value_start_high(t_d_list* list, int target) {
    // Gestion des cas d'entrée invalide
    if (list == NULL) {
        return 0;
    }

    // Commencer la recherche au niveau le plus élevé
    int currentLevel = list->max_level - 1;

    // Initialiser la cellule de départ
    t_d_cell* currentCell = list->heads[currentLevel];

    while (currentLevel >= 0) {
        // Parcourir la liste au niveau actuel pour trouver la valeur cible
        while (currentCell != NULL && currentCell->value < target) {
            currentCell = currentCell->next;
        }

        // Si la valeur cible est trouvée, retourner 1
        if (currentCell != NULL && currentCell->value == target) {
            return 1;
        }

        // Si la valeur cible est plus grande, descendre d'un niveau
        currentLevel--;
        if (currentLevel >= 0) {
            currentCell = list->heads[currentLevel];  // Repartir de la cellule à laquelle on était arrivé
        }
    }

    // La valeur cible n'a pas été trouvée, retourner 0
    return 0;
}