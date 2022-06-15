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


    int largestInd = 0;
    int largest = 0;
    int smallInd = 0;
    int smallSize = 0;

    int i;
    for(i=0; i < numConstituencies; i++){
      struct Constituency numConst = constituencies[i];

      if(largest < numConst.numNeighbours){
        largest = numConst.numNeighbours;
        largestInd = i;
      }else if(smallSize > numConst.numNeighbours || !smallSize ){
        smallSize = numConst.numNeighbours;
        smallInd= i;
      }
        printConstituency(&numConst);
        printf("\n");

    }

    printf("\n");

    struct Constituency cLargest = constituencies[largestInd];
    printf("%s has the most bordering const:" , cLargest.name);    
    for(i=0; i<cLargest.numNeighbours; i++){
      printf("\n %s", constituencies[cLargest.neighbours[i]].name);
    }
    
    printf("\n");

    struct Constituency cSmallest = constituencies[smallInd];
    printf("%s has the fewest bordering const:" , cSmallest.name); 
    for(i=0; i<cSmallest.numNeighbours; i++){
      printf("\n %s", constituencies[cSmallest.neighbours[i]].name);
    
    }
    printf("\n");
  return 0;

}