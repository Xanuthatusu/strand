#include "Strand.h"
#include <cstring>
#include <iostream>

Strand::Strand() : mString(0) { }

Strand::Strand(const char *src) : mString(0) {
  setString(src);
}

Strand::Strand(const std::string string) : mString(0) {
  char *newString = new char[1024];
  strncpy(newString, string.c_str(), 1024);
  newString[1024 - 1] = 0;

  mString = newString;
}

Strand::Strand(const Strand &src) : mString(0) {
  *this = src;
}

Strand::~Strand() {
  if (mString) {
    delete [] mString;
    mString = 0;
  }
}

Strand &Strand::operator=(const Strand &rhs) {
  setString(rhs.getString());
  return *this;
}

Strand &Strand::operator+=(const Strand &rhs) {
  char *added = new char [std::strlen(getString()) + std::strlen(rhs.getString()) + 1];
  std::strcpy(added, getString());
  std::strcat(added, rhs.getString());
  setString(added);
  delete [] added;
  return *this;
}

Strand Strand::operator+(const Strand &rhs) const {
  // Compute the new string
  char *added = new char [std::strlen(getString()) + std::strlen(rhs.getString()) + 1];
  std::strcpy(added, getString());
  std::strcat(added, rhs.getString());

  Strand newInstance(added);
  delete[] added;
  return newInstance;
}

//Strand Strand::operator-(const Strand &rhs) const {
  //char *toRemove = rhs.getString();
  //char *newS = new char [std::strlen(getString())];
  //int index = 0;
  //bool removing = false;

  //std::cout << std::strlen(getString()) << std::endl;

  //for (size_t i=0; i < std::strlen(getString()); i++) {
    //std::cout << i << std::endl;
    //for (size_t z=0; z < std::strlen(toRemove); z++) {
      //if (getString()[i] == toRemove[z]) {
        //removing = true;
      //}
    //}
    //if (!removing) {
      //newS[index] = getString()[i];
      //index++;
    //}
    //removing = false;
  //}

  //std::cout << newS << std::endl;

  //Strand newInstance;
  //return newInstance;
//}

bool Strand::operator==(const Strand &rhs) const {
  return std::strcmp(getString(), rhs.getString()) == 0;
}

bool Strand::operator!=(const Strand &rhs) const {
  return !(*this == rhs);
}

bool Strand::operator<(const Strand &rhs) const {
  return std::strcmp(getString(), rhs.getString()) < 0;
}

bool Strand::operator>(const Strand &rhs) const {
  return std::strcmp(getString(), rhs.getString()) > 0;
}

char* Strand::getString() const {
  return mString;
}

void Strand::setString(const char *string) {
  if (mString) {
    delete[] mString;
    mString = 0;
  }

  if (string) {
    mString = new char [std::strlen(string) + 1];
    std::strcpy(mString, string);
  }
}

size_t Strand::size() const {
  if (!(mString)) {
    return 0;
  }
  return std::strlen(mString);
}

Strand Strand::substrand(size_t i, size_t j) const {
  // check to see if mString is not null
  if (!(size())) {
    Strand null;
    return null;
  }

  char *newString = new char [j - i + 1];
  size_t index;
  for (index=i; index < j; index++) {
    newString[index-i] = mString[index];
  }
  newString[j - i] = 0;

  Strand newStrand(newString);
  delete[] newString;
  return newStrand;
}

Strand Strand::merge(size_t i, const Strand &rhs) const {
  Strand newStrand = substrand(0, i);
  newStrand += rhs;
  return newStrand;
}

size_t Strand::overlap(const Strand &rhs) const {
  size_t i;
  for (i=0; i < size(); i++) {
    Strand one;
    Strand two;
    size_t b;
    for (b=0; b < rhs.size(); b++) {
      one = substrand(i, size());
      two = rhs.substrand(0, rhs.size()-b);

      if (one == two) {
        return i;
      }
    }
  }
  return size() + 1;
}

