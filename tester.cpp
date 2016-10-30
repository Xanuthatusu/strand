#include "Strand.h"
#include <iostream>

void test_default_constructor() {
  Strand s;

  if (s.getString() != 0) {
    std::cout << "Returned non-null pointer." << std::endl;
  }
}

void test_assignment_constructor() {
  Strand s("CATGAT");

  if (std::strcmp(s.getString(), "CATGAT") != 0) {
    std::cout << "Assignment contructor failed!" << std::endl;
  }
}

void test_copy_constructor() {
  Strand s;

  s = "CATGAT";

  Strand newS(s);
  if (std::strcmp(newS.getString(), "CATGAT")) {
    std::cout << "Copy constructor failed!" << std::endl;
  }
}

void test_assignment_operator() {
  Strand s;
  s = "CATGCAGT";
  if (std::strcmp(s.getString(), "CATGCAGT")) {
    std::cout << "Something failed in set/get value!" << std::endl;
  }

  s = 0;
  if (s.getString() != 0) {
    std::cout << "Something failed in set/get value of 0!" << std::endl;
  }
}

void test_addition_operator() {
  Strand one("CAT");
  Strand two("GAT");

  one = one + two;

  if (std::strcmp(one.getString(), "CATGAT")) {
    std::cout << "Addition operator failed!" << std::endl;
  }
}

void test_plus_equals_operator() {
  Strand one("CAT");
  Strand two("GAT");

  one += two;

  if (std::strcmp(one.getString(), "CATGAT")) {
    std::cout << "Plus equals operator failed!" << std::endl;
  }
}

void test_equals_operators() {
  Strand one("CAT");
  Strand two("CAT");

  if (!(one == two)) {
    std::cout << "Equals operator failed!" << std::endl;
  }
  if (one != two) {
    std::cout << "Not equals operator failed!" << std::endl;
  }

  two = "GAT";
  if (!(one != two)) {
    std::cout << "Not equals operator failed!" << std::endl;
  }
  if (one == two) {
    std::cout << "Equals operator failed!" << std::endl;
  }

  Strand gat("GAT");
  Strand temp("CATGAT");
  Strand gat2 = temp.substrand(3, 7);
  //std::cout << gat2.getString() << std::endl;
  //std::cout << (gat == gat2) << std::endl;
}

void test_compare_operators() {
  Strand one("CAT");
  Strand two("AGT");

  if (!(one > two)) {
    std::cout << "Greater than operator failed!" << std::endl;
  }
  if (one < two) {
    std::cout << "Less than operator failed!" << std::endl;
  }
}

void test_size() {
  Strand s;
  s = "CATGAT";
  
  if (s.size() != 6) {
    std::cout << "s.size returned " << s.size() << "!" << std::endl;
  }
}

void test_subStrand() {
  Strand s("TAGCATGATCTA");
  Strand catgat = s.substrand(3, 9);

  if (std::strcmp(catgat.getString(), "CATGAT")) {
    std::cout << "Substrand returned " << catgat.getString() << "!" << std::endl;
  }

  Strand n = s.substrand(0, 2);
  if (std::strcmp(n.getString(), "TA")) {
    std::cout << "Substrand returned " << n.getString() << "!" << std::endl;
  }
}

void test_merge() {
  Strand lhs("CATGAT");
  Strand rhs("GATTAG");
  lhs = lhs.merge(3, rhs);

  if (std::strcmp(lhs.getString(), "CATGATTAG")) {
    std::cout << "Merge returned " << lhs.getString() << "!" << std::endl;
  }
}

void test_overlap() {
  Strand one;
  Strand two;

  // medium overlap
  one = "CATGAT";
  two = "GATCAT";
  if (one.overlap(two) != 3) {
    std::cout << "Overlap returned " << one.overlap(two) << std::endl;
  }

  // no overlap
  one = "CATGAT";
  two = "GCTACT";
  if (one.overlap(two) < one.size()) {
    std::cout << "Overlap returned " << one.overlap(two) << std::endl;
  }

  // full overlap
  one = "CATGAT";
  two = "CATGAT";
  if (one.overlap(two)) {
    std::cout << "Overlap returned " << one.overlap(two) << std::endl;
  }

  // mostly overlap
  one = "GATGAC";
  two = "ATGACT";
  if (one.overlap(two) != 1) {
    std::cout << "Overlap returned " << one.overlap(two) << std::endl;
  }
}

int main() {
  test_default_constructor();
  test_copy_constructor();
  test_assignment_operator();
  test_addition_operator();
  test_plus_equals_operator();
  test_equals_operators();
  test_compare_operators();
  test_size();
  test_subStrand();
  test_merge();
  test_overlap();
  return 0;
}

