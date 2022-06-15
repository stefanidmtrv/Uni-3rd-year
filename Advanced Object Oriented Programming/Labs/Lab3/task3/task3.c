// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// 
// (c) Martin Porcheron
//     m.a.w.porcheron@swansea.ac.uk
// -----------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include "constituency.h"

int main() {
  const int numConstituencies = 5;
  struct Constituency constituencies[numConstituencies];

  constructConstituency(
    &constituencies[0], "Swansea East",
    (unsigned int[]){1,2,3,4}, 4);

  constructConstituency(
    &constituencies[1], "Swansea West",
    (unsigned int[]){0,2}, 2);

  constructConstituency(
    &constituencies[2], "Gower",
    (unsigned int[]){0,1,3}, 3);

  constructConstituency(
    &constituencies[3], "Neath",
    (unsigned int[]){0,2,4}, 3);

  constructConstituency(
    &constituencies[4], "Aberavon",
    (unsigned int[]){0,3}, 2);

  struct Constituency * copy = copyConstituencies(constituencies, numConstituencies);

  int i = 0;
  for (i = 0; i < numConstituencies; i++) {
    destructConstituency(&constituencies[i]);
  }
  
  int largestInd = 0;
  int largest = 0;
  int smallInd = 0;
  int smallSize;
  
  for (i = 0; i < numConstituencies; i++) {
    struct Constituency curConstit = copy[i];

    if (largest < curConstit.numNeighbours) {
      largest = curConstit.numNeighbours;
      largestInd = i;
    } else if (smallSize > curConstit.numNeighbours || !smallSize) {
      smallSize = curConstit.numNeighbours;
      smallInd = i;
    }
    printConstituency(&curConstit);
  }

  struct Constituency cLargest = copy[largestInd];
  printf("%s has the most bordering constituencies:", cLargest.name);
  for (i=0; i < cLargest.numNeighbours; i++) {
    printf("\n %s", copy[cLargest.neighbours[i]].name);
  }

    printf("\n");


  struct Constituency cSmallest = copy[smallInd];
  printf("\n%s has the most bordering constituencies:", cSmallest.name);
  for (i=0; i < cSmallest.numNeighbours; i++) {
    printf("\n%s", copy[cSmallest.neighbours[i]].name);
  }

  printf("\n");

  free(copy);

  return 0;
}