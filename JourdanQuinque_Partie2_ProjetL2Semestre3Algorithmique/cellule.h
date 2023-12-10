#ifndef CELLULE_H
#define CELLULE_H

typedef struct s_d_cell {
    int value;
    int levels;
    struct s_d_cell* next;
} t_d_cell;

t_d_cell* create_cell(int value, int levels);

#endif /* CELLULE_H */
