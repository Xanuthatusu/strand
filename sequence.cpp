#include "sequence.h"
#include "Strand.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

std::vector<Strand> sequence(std::vector<Strand> strands, const size_t minimum_overlap_size) {
  bool foundOverlap = true;

  while (foundOverlap) {
    foundOverlap = false;

    std::vector<Strand>::iterator it;
    for (it=strands.begin(); it != strands.end(); it++) {
      std::cout << it->getString() << std::endl;
    }

    std::sort(strands.begin(), strands.end());
  }
  
  std::vector<Strand> returnVector;
  Strand null;
  returnVector.push_back(null);
  return returnVector;
}
