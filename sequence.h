#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

#include <vector>
#include "Strand.h"

std::vector<Strand> sequence(std::vector<Strand> strands, const size_t minimum_overlap_size);

#endif // _SEQUENCE_H_

