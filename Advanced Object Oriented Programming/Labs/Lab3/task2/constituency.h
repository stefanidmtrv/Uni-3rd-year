#ifndef CONSTITUENCY_H
#define CONSTITUENCY_H

struct Constituency {
  char *name;
  unsigned int *neighbours;
  unsigned int numNeighbours;
};

void constructConstituency(struct Constituency * const obj, char * const name,
                           unsigned int * const neighbours, unsigned int const numNeighbours);
void destructConstituency(struct Constituency * const obj);
void printConstituency(struct Constituency * const obj);

#endif

// #pragma pack instructs the compiler to pack
//  structure members with particular alignment. 
//  Most compilers, when you declare a struct, will 
//  insert padding between members to ensure that they are 
//  aligned to appropriate addresses in memory (usually a
//   multiple of the type's size). This avoids the performance
//    penalty (or outright error) on some architectures
//     associated with accessing variables that are not aligned properly.
// The most common use case for the #pragma (to my
//  knowledge) is when working with hardware devices where
//   you need to ensure that the compiler does not insert 
//   padding into the data and each member follows the previous one. 
// https://stackoverflow.com/questions/3318410/pragma-pack-effect