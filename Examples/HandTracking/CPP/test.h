#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>

#define TIC() clock_t start_time = clock();

    
#define TOC() clock_t end_time = clock();\
	      double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;\
    	      printT(elapsed_time);

void fatal(char *msg) {
	printf("EXIT WITH: %s", msg);
	exit(1);
}

// t is measured by seconds
void printT(double t) {
    printf("%f milliseconds\n", t * 1000);
}

#endif