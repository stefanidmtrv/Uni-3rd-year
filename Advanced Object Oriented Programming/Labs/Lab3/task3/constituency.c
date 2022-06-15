#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./constituency.h"

void constructConstituency(
    struct Constituency *const obj,
    char const *name,
    unsigned int *const neighbours,
    unsigned int const numNeighbours)
{
  obj->name = NULL;
  obj->neighbours = NULL;
  obj->numNeighbours = 0;

  int len = strlen(name) + 1;
  obj->name = (char *)malloc(len * sizeof(char));
  memcpy(obj->name, name, len * sizeof(char));

  if (numNeighbours > 0)
  {
    obj->numNeighbours = numNeighbours;
    obj->neighbours = (unsigned int *)malloc(numNeighbours * sizeof(unsigned int));

    memcpy(obj->neighbours, neighbours, numNeighbours * sizeof(unsigned int));
  }
}

void destructConstituency(struct Constituency *const obj)
{
  if (obj->name)
  {
    free(obj->name);
    obj->name = NULL;
  }

  if (obj->neighbours)
  {
    free(obj->neighbours);
    obj->neighbours = NULL;
  }

  obj->numNeighbours = 0;
}

void printConstituency(struct Constituency *const obj)
{

  printf("%s | %d neighbours | ", obj->name, obj->numNeighbours);

  int i;
  for (i = 0; i < obj->numNeighbours; i++)
  {
    printf("%d ", obj->neighbours[i]);
  }
  printf("\n");
}

struct Constituency *copyConstituencies(struct Constituency *const constituencies,
                                        unsigned int const numNeighbours)
{
  struct Constituency *newConstituencies = malloc(sizeof(struct Constituency) * numNeighbours);

  int i;
  for (i = 0; i < numNeighbours; i++)
  {
    struct Constituency *copy = &constituencies[i];

    constructConstituency(
        &newConstituencies[i],
        copy->name,
        copy->neighbours,
        copy->numNeighbours);
  }

  return newConstituencies;
}
// gcc --std=c99 task3.c constituency.c -o task3