#ifndef LISTE_H
#define LISTE_H
#include "cellule.h"

typedef struct s_d_list {
    t_d_cell** heads;
    int max_level;
} t_d_list;

t_d_list* create_empty_list(int max_level);
void insert_cell(t_d_list* list, t_d_cell* cell);
void display_level(t_d_list* list, int level);
void display_all_levels(t_d_list* list);
void insert_sorted_cell(t_d_list* list, t_d_cell* cell);
void fill_list(t_d_list* list);
int search_value_start_0(t_d_list* list, int target);
int search_value_start_high(t_d_list* list, int target);

#endif /* LISTE_H */
