#ifndef CONSTANTS_H
#define CONSTANTS_H

//Screen dimension constants
#define SCREEN_WIDTH  800 
#define SCREEN_HEIGHT  800

#define TILE_SIZE (SCREEN_HEIGHT / 8)

#define L_RGB_RED 118
#define L_RGB_GREEN 150
#define L_RGB_BLUE 86

#define D_RGB_RED 238
#define D_RGB_GREEN 238
#define D_RGB_BLUE 210
// #define TILE_SIZE 80
#define DARK_COLOR 0xEEEED2 // rgb: 118,150,86
#define LIGHT_COLOR 0x769656 // 238,238,210

#define MAX_HISTORY_MOVES 500 // TODO: Check what's the max move rule in FIDE
#define MAX_LEGAL_MOVES 27	  // queen can move to a max of 27 squares. there certainly is a better way of doing this, for now, lets get this working

#define PIECE_TYPE_COUNT 6


#endif