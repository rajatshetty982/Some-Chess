#ifndef LOGIC_H
#define LOGIC_H
#include "../include/models.h"

void generate_legal_moves(Gamestate *state);
int is_legal_move(Gamestate *state, int clicked_square_index);
void make_move(Gamestate *state, int current_square, int new_square);

#endif