#include "../lib/grug.h"

static inline u8 is_white_space(char c) {
	const char white_space_chars[] = "\t \v\r\f";
	for (size_t i = 0; i < strlen(white_space_chars); i++) {
		if (c == white_space_chars[i]) {
			return 1;
		}
	}
	return 0;
}

char *trim_and_free(char *input) {
	if (input == NULL) {
		return NULL;
	}
	size_t string_len = strlen(input);
	char *trimmed_string = malloc(string_len + 1);
	size_t index = 0;
	char prev = ' ';
	char current = 0;
	size_t trimmed_index = 0;
	u8 is_first_char = 1;
	while (index < string_len) {
		 current = input[index];
		 if (prev != ' ' && !is_white_space(current)) {
		 	trimmed_string[trimmed_index++] = current;
			is_first_char = 0;
		 } else {
			if (is_white_space(current)) {
				if (!is_first_char && prev != ' ') {
					prev = ' ';
		 			trimmed_string[trimmed_index++] = ' ';
				}
			} else {
		 		trimmed_string[trimmed_index++] = current;
				prev = current;
			}
		 }
		 index++;
	}
	trimmed_string[trimmed_index] = '\0';
	free(input);
	return trimmed_string;
}
