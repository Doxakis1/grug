#include "../lib/grug.h"
#include <string.h>

int main(int argc, char **argv){
	(void)argc;
	(void)argv;
	printf("Grug says chess is cool\n");
	int has_started = 0;
	while(1) {
		char *input = get_next_line(0);
		input = trim_and_free(input);
		if ((has_started == 0 && strncmp(input, "isready", sizeof("isready") - 1) == 0)\
				|| (strncmp(input, "setoption", sizeof("setoption") - 1) == 0)) {
			has_started = 1;
			printf("Grug is ready to play chess!\n");
			free(input);
			exit(0);
		}
		fprintf(stdout, "We got input:%s", input);
		free(input);
	}
	return 0;
}

