#ifndef CONSTITUANCY_H
#define CONSTITUANCY_H

/*
 * Using a pragma pack 1 here would mean the structure is packed
 * in words with 1 byte instead of the default 4. This would mean we
 * save structure packing space potentially, however, on my x64 system
 * with pointer addresses of 8bytes it will not be helpful.
 *
 * Will be bad for some RISC processors (apparently).
 *
*/

struct Constituency {
  char *name;
  unsigned int *neighbours;
  unsigned int numNeighbours;
};

void constructConstituency(
  struct Constituency * const obj,
  char const *name,
  unsigned int* const neighbours,
  unsigned int const numNeighbours
);

void destructConstituency(struct Constituency * const obj);

void printConstituency(struct Constituency * const obj);

struct Constituency * copyConstituencies(
    struct Constituency* const constituencies,
    unsigned int const numNeighbours
);

# endif