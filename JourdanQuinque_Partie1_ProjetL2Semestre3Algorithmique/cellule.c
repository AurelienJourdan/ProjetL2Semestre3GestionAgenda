#include "cellule.h"
#include <stdio.h>
#include <stdlib.h>

t_d_cell* create_cell(int value, int levels) {
    t_d_cell* new_cell = (t_d_cell*)malloc(sizeof(t_d_cell));
    if (new_cell != NULL) {
        new_cell->value = value;
        new_cell->levels = levels;
        new_cell->next = (t_d_cell*)malloc(levels * sizeof(t_d_cell*));
        for (int i = 0; i < levels; ++i) {
            new_cell->next = NULL;
        }
    }
    return new_cell;
}
