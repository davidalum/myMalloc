#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#define free(freePtr) myFree(freePtr," mymalloc.c", 67)
#define malloc(inputBytes) myMalloc(inputBytes, "mymalloc.c", 33)
#define ERROR_NOT_ALLOCATED printf("Error: Invalid Pointer in File %s at Line %d \n", "mymalloc.c", 91);
#define ERROR_POINTER_FREE printf("Error: Pointer is already free in File %s at Line %d \n", "mymalloc.c", 81);
char memory[10000]; //creating the arrray that will store the memory 

struct metablock{
	int B_size;
	int isFree;
	struct metablock *next;
};

struct metablock *metaList=(void*)memory;

int nullCount; 
/*
void initialize();
void split(struct metablock *fitting_slot,size_t B_size);
*/
void * myMalloc(int inputBytes, char *file, int line);
void myFree(void *ptr, char *file, int line);
