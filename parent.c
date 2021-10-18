#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "child.c"


void *pause(void*);

int main() {
	pthread_t tid;
	pthread_create(&tid, NULL, pause, NULL);
	pthread_join(tid, NULL);

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
