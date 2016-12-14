#ifndef _STRAND_H_
#define _STRAND_H_

#include <cstdlib>
#include <string>

class Strand {
public:
  Strand();
  Strand(const std::string string);
  Strand(const char *src);
  Strand(const Strand &src);
  ~Strand();

  // operator overloading
  Strand &operator=(const Strand &rhs);
  Strand operator+(const Strand &rhs) const;
  //Strand operator-(const Strand &rhs) const;
  Strand &operator+=(const Strand &rhs);
  bool operator==(const Strand &rhs) const;
  bool operator!=(const Strand &rhs) const;
  bool operator<(const Strand &rhs) const;
  bool operator>(const Strand &rhs) const;

  char* getString() const;
  size_t size() const;
  Strand substrand(size_t i, size_t j) const;
  Strand merge(size_t i, const Strand &rhs) const;
  size_t overlap(const Strand &rhs) const;
private:
  void setString(const char *string);
  char *mString;
};

#endif // _STRAND_H_

