#include "sequence.h"
#include "Strand.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

std::vector<Strand> sequence(std::vector<Strand> strands, const size_t minimum_overlap_size) {
  bool foundOverlap = true;

  while (foundOverlap) {
    foundOverlap = false;

    std::sort(strands.begin(), strands.end());

    std::pair<Strand, Strand> bestOverlap;

    for (auto && strand1: strands) {
      for (auto && strand2: strands) {
        if (strand1 == strand2) {
          continue;
        }
        size_t overlap = strand1.overlap(strand2);
        if (overlap < strand1.size() && strand1.size() - overlap >= minimum_overlap_size) {
          bestOverlap = std::make_pair(strand1, strand2);
          foundOverlap = true;
        }
      }
    }

    if (foundOverlap) {
      Strand strand1 = bestOverlap.first;
      Strand strand2 = bestOverlap.second;
      Strand newStrand = strand1.merge(strand1.overlap(strand2), strand2);
      strands.erase(std::remove(strands.begin(), strands.end(), strand1), strands.end());
      strands.erase(std::remove(strands.begin(), strands.end(), strand2), strands.end());
      strands.push_back(newStrand);
    }
  }
  
  return strands;
}
