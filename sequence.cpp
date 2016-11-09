#include "sequence.h"
#include "Strand.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

std::vector<Strand> sequence(std::vector<Strand> strands, const size_t minimum_overlap_size) {
  bool foundOverlap = true;

  while (foundOverlap) {
    foundOverlap = false;

    //std::vector<Strand>::iterator it;
    //for (it=strands.begin(); it != strands.end() - 1; it++) {
      //std::cout << it->getString() << std::endl << "Next: ";
      //std::cout << (it + 1)->getString() << std::endl;
      //size_t overlapIndex = 1;
      //overlapIndex = it->overlap(*(it + 1));
      //std::cout << overlapIndex << std::endl;
    //}
    
    size_t i;
    for (i=0; i < strands.size() - 1; i++) {
      std::cout << strands[i].getString() << std::endl;
      std::cout << "Next: " << strands[i + 1].getString() << std::endl;
      size_t overlapIndex = strands[i].overlap(strands[i + 1]);
      std::cout << overlapIndex << std::endl;
    }

    std::sort(strands.begin(), strands.end());
  }
  
  std::vector<Strand> returnVector;
  Strand null;
  returnVector.push_back(null);
  return returnVector;
}
