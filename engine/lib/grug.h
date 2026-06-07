#pragma once


#define NULL (void *)0
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define u64 unsigned long long 
#define s64 signed long long 
#define u8 unsigned char

extern u64 board_occupancy;
extern u64 color_occupancy;
extern u64 king_positions;
extern u64 pawn_positions;
extern u64 rook_positions;
extern u64 knight_positions;
extern u64 bishop_positions;
extern u64 queen_positions;

// BOARD_LEGAL
// CASTLE_RIGHTS_WHITE_QUEEN_SIDE (CRWQS)
// CASTLE_RIGHTS_WHITE_KING_SIDE (CRWKS)
// CASTLE_RIGHTS_BLACK_QUEEN_SIDE (CRBKS)
// CASTLE_RIGHTS_BLACK_KING_SIDE (CRBKS)
// IS_WHITE_CHECKED (IWC)
// IS_BLACK_CHECKED (IBC)
#define BOARD_LEGAL (u8)(1 << 7)
#define CRWQS (u8)(1 << 6)
#define CRWKS (u8)(1 << 5)
#define CRBQS (u8)(1 << 4)
#define CRBKS (u8)(1 << 3)
#define IWC (u8)(1 << 2)
#define IBC (u8)(1 << 1)
extern u8 board_state;

void init(const char *input);

char *trim_and_free(char *input);
// TODO: Add support for \n\r (microsoft I guess...)
char *get_next_line(int fd);
