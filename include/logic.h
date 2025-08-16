#ifndef LOGIC_H
#define LOGIC_H

int is_valid_first_click(Gamestate *state, int file, int rank);
void generate_legal_moves(Gamestate *state);
int is_legal_move(Gamestate *state, int clicked_square_index);
void make_move(Gamestate *state, int current_square, int new_square);

#endif