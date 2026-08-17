#include "../lib/grug.h"
#include <stdio.h>

// This file handles all the board mechanisms like setting up the board and printing the board
u8 validate_board(const char *input) {
	(void)input;
	return 42;
}

void init(const char *input) {
	size_t input_len = strlen(input);
	size_t lane = 8;
	size_t pos = 0;
	size_t pieces_black = 0;
	size_t pieces_white = 0;
	size_t kings = 0;
	for (size_t i = 0; i < input_len ; i++) {
		while (lane < 8) {
			if ((pos == 8 && input[i] != '/') || kings > 2 || pieces_white > 16 || pieces_black > 16){
					fprintf(stderr, "Incorrect FEN format");
					exit(1);
			}
			switch (input[i]) {
				case 'r':
					board_occupancy |= (1 << pos);
					rook_positions |= (1 << pos);
					color_occupancy |= (1 << pos);
					pieces_black++;
					pos++;
					break ;
				case 'R':
					board_occupancy |= (1 << pos);
					rook_positions |= (1 << pos);
					pieces_white++;
					pos++;
					break ;
				case 'n':
					board_occupancy |= (1 << pos);
					knight_positions |= (1 << pos);
					color_occupancy |= (1 << pos);
					pieces_black++;
					pos++;
					break ;
				case 'N':
					board_occupancy |= (1 << pos);
					knight_positions |= (1 << pos);
					pieces_white++;
					pos++;
					break ;
				case 'b':
					board_occupancy |= (1 << pos);
					bishop_positions |= (1 << pos);
					color_occupancy |= (1 << pos);
					pieces_black++;
					pos++;
					break ;
				case 'B':
					board_occupancy |= (1 << pos);
					bishop_positions |= (1 << pos);
					pieces_white++;
					pos++;
					break ;
				case 'q':
					board_occupancy |= (1 << pos);
					queen_positions |= (1 << pos);
					color_occupancy |= (1 << pos);
					pieces_black++;
					pos++;
					break ;
				case 'Q':
					board_occupancy |= (1 << pos);
					queen_positions |= (1 << pos);
					pieces_white++;
					pos++;
					break ;
				case 'k':
					board_occupancy |= (1 << pos);
					rook_positions |= (1 << pos);
					color_occupancy |= (1 << pos);
					pieces_black++;
					kings++;
					pos++;
					break ;
				case 'K':
					board_occupancy |= (1 << pos);
					rook_positions |= (1 << pos);
					pieces_white++;
					kings++;
					pos++;
					break ;
				case 'p':
					board_occupancy |= (1 << pos);
					pawn_positions |= (1 << pos);
					color_occupancy |= (1 << pos);
					pieces_black++;
					pos++;
					break ;
				case 'P':
					board_occupancy |= (1 << pos);
					pawn_positions |= (1 << pos);
					pieces_white++;
					pos++;
					break ;
				case '1':
					pos += 1;
					break ;
				case '2':
					pos += 2;
					break ;
				case '3':
					pos += 3;
					break ;
				case '4':
					pos += 4;
					break ;
				case '5':
					pos += 5;
					break ;
				case '6':
					pos += 6;
					break ;
				case '7':
					pos += 7;
					break ;
				case '8':
					pos += 8;
					break ;
				case '/':
					lane++;
					pos = 0;
					break ;
				default:
					fprintf(stderr, "Incorrect FEN format");
					exit(1);
			}
		}
	}
	return ;
}
