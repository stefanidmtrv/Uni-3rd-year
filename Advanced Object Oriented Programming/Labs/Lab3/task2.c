// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// 
// (c) Martin Porcheron
//     m.a.w.porcheron@swansea.ac.uk
// -----------------------------------------------------

#include <stdio.h>

#include "constituency.h"

int main() {
  const int numConstituencies = 5;
  struct Constituency constituencies[numConstituencies];

  // Constructing our data.
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
  
  // Loop through printing each constituency and potentially updating the
  // constituency with the lowest/highest number of neighbours.
  int i = 0;
  int largestIndex = 0;
  int largestSize = 0;
  int smallestIndex = 0;
  int smallestSize;
  for (i = 0; i < numConstituencies; i++) {
    struct Constituency curConstit = constituencies[i];

    if (largestSize < curConstit.numNeighbours) {
      largestSize = curConstit.numNeighbours;
      largestIndex = i;
    } else if (!smallestSize || smallestSize > curConstit.numNeighbours) {
      smallestSize = curConstit.numNeighbours;
      smallestIndex = i;
    }
    printConstituency(&curConstit);
  }

  printf("\nLargest at index: %d, smallest at index: %d", largestIndex, smallestIndex);

  // Print the largest to the console.
  struct Constituency largestConst = constituencies[largestIndex];
  printf("%s has the most bordering constituencies", largestConst.name);
  for (i=0; i < largestConst.numNeighbours; i++) {
    printf("\n\t%s", constituencies[largestConst.neighbours[i]].name);
  }

  // Print the smallest to the console.
  struct Constituency smallestConst = constituencies[smallestIndex];
  printf("\n\n%s has the most bordering constituencies", smallestConst.name);
  for (i=0; i < smallestConst.numNeighbours; i++) {
    printf("\n\t%s", constituencies[smallestConst.neighbours[i]].name);
  }

  printf("\n");

  // Destructing all our constituencies.
  for (i = 0; i < numConstituencies; i++) {
    destructConstituency(&constituencies[i]);
  }

  return 0;
}
