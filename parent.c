#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "child.c"


void *pause(void*);

typedef struct {
	pid_t id = rand() % 4 + 6;
} child;

int main() {
	pthread_t tid;
	pthread_create(&tid, NULL, pause, NULL);
	pthread_join(tid, NULL);

	time_t t;
	int i;
	for(i=0; i<5; i++) {
		srand((unsigned) time(&t));
		FILE *file;
		pid_t num = child -> id;
		file = fopen("schedule.txt", "w");
		fprintf(file, num);
		fclose(file);
	}

	return EXIT_SUCCESS;
}

void *pause(void *args) {
	struct timespec ts;
	ts.tv_sec = 0;
	ts.tv_nsec = 100000;
	while {
		nanosleep(&ts, NULL);
	}
}
