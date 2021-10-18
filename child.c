#include <stdlib.h>

int child() {
	int num;
	FILE *file;
	file = fopen("schedule.txt", "r");

	num = fgetc(file);
	fclose(file);
}
