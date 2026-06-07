#include "../lib/grug.h"
#define BUFFER_SIZE 1024
char *left_over = NULL;

char *trim_left_over(size_t pos, size_t size) {
	char *trim_left_over = NULL;
	// if existing left_over ends with a '\n' --> size - pos == 1
	if (size - pos == 1){
		trim_left_over = left_over;
		left_over = NULL;
		return trim_left_over;
	}
	char *new_left_over = malloc(size - pos + 1);
	for (size_t i = pos; i <= size; i++) {
		new_left_over[i - pos] = left_over[pos + i];
	}
	left_over[pos] = '\0';
	trim_left_over = left_over;
	left_over = new_left_over;
	return trim_left_over;
}

char *get_next_chunk(int fd){
	// Handle existing left_over before reading next input
	char *new_buffer = NULL;
	if (left_over != NULL) {
		size_t left_over_len = strlen(left_over);
		size_t pos = 0;
		while (pos < left_over_len) {
			if (left_over[pos] == '\n') {
				break ;
			}
			++pos;
		}
		if (pos != left_over_len) {
			new_buffer = trim_left_over(pos, left_over_len);
			return new_buffer;
		}
	}
	new_buffer = malloc(BUFFER_SIZE + 1);
	if (new_buffer == NULL) {
		return NULL;
	}
	ssize_t bytes_read = read(fd, new_buffer, 13); //TODO: change this to BUFFER_SIZE once bug is fixed
	if (bytes_read == -1) {
		free(new_buffer);
		return NULL;
	}
	new_buffer[bytes_read] = '\0';
	return new_buffer;
}

ssize_t check_has_nl(char *str) {
	if (str == NULL) {
		return -1;
	}
	size_t str_len = strlen(str);
	for (size_t i = 0; i < str_len; i++) {
		if (str[i] == '\n')
			return 0;
	}
	return -1;
}

char *append_and_free(char *string1, char *string2){
	if (string1 == NULL) {
		__builtin_unreachable();
		return NULL; // should never be reached
	}
	if (string2 == NULL) {
		return string1;
	}
	size_t string1_len = strlen(string1);
	size_t string2_len = strlen(string2);
	char *con_string = malloc(string1_len + string2_len);
	if (con_string == NULL) {
		free(string1);
		free(string2);
		return NULL;
	}
	size_t pos = 0;
	while (pos < string1_len) {
		con_string[pos] = string1[pos];
		pos++;
	}
	while (pos - string1_len < string2_len) {
		con_string[pos] = string2[pos - string1_len];
		pos++;
	}
	con_string[pos] = '\0';
	return con_string;
}

static char *strip_left_overs(char *string){
	if (left_over != NULL) {
		__builtin_unreachable();
		free(string);
		return NULL;
	}
	char *stripped = NULL;
	size_t string_len = strlen(string);
	size_t pos = 0;
	while (pos < string_len) {
		if (string[pos] == '\n') {
			break;
		}
		pos++;
	}
	if (pos != string_len) {
		left_over = string;
		stripped = trim_left_over(pos, string_len);
	}
	return stripped;
}

char *get_next_line(int fd){
	char *next_line = get_next_chunk(fd);
	if (next_line == NULL) {
		return NULL;
	}
	while (check_has_nl(next_line) == -1) {
		next_line = append_and_free(next_line, get_next_chunk(fd));
		if (next_line == NULL) {
			// This only happens if malloc fails #TODO: maybe assert
			return NULL;
		}
	}
	next_line = strip_left_overs(next_line);
	return next_line;
}
