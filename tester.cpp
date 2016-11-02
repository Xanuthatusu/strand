#include "Strand.h"
#include <cstring>
#include <iostream>
#include <cassert>

void test_default_constructor() {
  Strand s;

  assert(s.getString() == 0);
}

void test_assignment_constructor() {
  Strand s("CATGAT");

  assert(std::strcmp(s.getString(), "CATGAT") == 0);
}

void test_copy_constructor() {
  Strand s;

  s = "CATGAT";

  Strand newS(s);
  assert(std::strcmp(newS.getString(), "CATGAT") == 0);
}

void test_assignment_operator() {
  Strand s;
  s = "CATGCAGT";

  assert(std::strcmp(s.getString(), "CATGCAGT") == 0);

  s = 0;
  assert(s.getString() == 0);
}

void test_addition_operator() {
  Strand one("CAT");
  Strand two("GAT");

  one = one + two;

  assert(std::strcmp(one.getString(), "CATGAT") == 0);
}

void test_plus_equals_operator() {
  Strand one("CAT");
  Strand two("GAT");

  one += two;

  assert(std::strcmp(one.getString(), "CATGAT") == 0);
}

void test_equals_operators() {
  Strand one("CAT");
  Strand two("CAT");

  assert(one == two);
  assert(!(one != two));

  two = "GAT";
  assert(one != two);
  assert(!(one == two));
}

void test_compare_operators() {
  Strand one("CAT");
  Strand two("AGT");

  assert(one > two);
  assert(!(one < two));
}

void test_size() {
  Strand s;
  assert(s.size() == 0);
  
  s = "CATGAT";
  assert(s.size() == 6);

  s = "";
  assert(s.size() == 0);
}

void test_substrand() {
  Strand s("TAGCATGATCTA");

  Strand catgat = s.substrand(3, 9);
  assert(std::strcmp(catgat.getString(), "CATGAT") == 0);

  Strand n = s.substrand(0, 2);
  assert(std::strcmp(n.getString(), "TA") == 0);

  Strand null;
  Strand null_sub = null.substrand(0, 1);
  assert(null_sub.getString() == 0);
}

void test_merge() {
  Strand lhs("CATGAT");
  Strand rhs("GATTAG");

  lhs = lhs.merge(3, rhs);
  assert(std::strcmp(lhs.getString(), "CATGATTAG") == 0);
}

void test_overlap() {
  Strand one;
  Strand two;

  // medium overlap
  one = "CATGAT";
  two = "GATCAT";
  assert(one.overlap(two) == 3);

  // no overlap
  one = "CATGAT";
  two = "GCTACT";
  assert(one.overlap(two) > one.size());

  // full overlap
  one = "CATGAT";
  two = "CATGAT";
  assert(one.overlap(two) == 0);

  // mostly overlap
  one = "GATGAC";
  two = "ATGACT";
  assert(one.overlap(two) == 1);
}

int main() {
  test_default_constructor();
  test_assignment_constructor();
  test_assignment_operator();
  test_copy_constructor();
  test_addition_operator();
  test_plus_equals_operator();
  test_equals_operators();
  test_compare_operators();
  test_size();
  test_substrand();
  test_merge();
  test_overlap();
  return 0;
}

