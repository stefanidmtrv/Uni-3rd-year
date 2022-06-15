// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// 
// (c) Martin Porcheron
//     m.a.w.porcheron@swansea.ac.uk
// -----------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include "timestables.h"

int main(int argc , char *argv[]) {
	int* tables[MAX_TABLE_SIZE]; 

	int i;
	for (i = 0; i < MAX_TABLE_SIZE; i++) {
		// Request allocation of calculated size on heap.
		int *V = (int*) malloc(MAX_TABLE_SIZE * sizeof(int));

		// Generate the table.
		generateTable(i, V);

		tables[i] = V;
	}
	
	printTables(tables);

	for (i = 0; i < MAX_TABLE_SIZE; i++) {
		// Release resources, and clearing its value.
		free(tables[i]);
		tables[i] = NULL;
	}

	return 0;
}
