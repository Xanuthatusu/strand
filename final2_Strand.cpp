#include "Strand.h"
#include "Strand.h"
#include <iostream>
#include <string>

void test_string1(const char *original)
{
  const std::string soriginal(original);
  const Strand s(original);
  const Strand t(soriginal);

  if(s == t && s == t)
    {
      std::cout << "OK '" << original << "' == '" << soriginal << "'" << std::endl;
    }
  else
    {
      std::cout << "** '" << original << "' == '" << soriginal << "'" << std::endl;
    }
}

int main()
{
  const char *cases[] = { "HELLO WORLD", "OL", "HE WRD",
                          "XY",
                          " ", "HELLOWORLD",
                          "",
                          "DLROW EH", "",
  };
  size_t i;
  for(i = 0; i < sizeof(cases)/sizeof(cases[0]); i++)
    {
      test_string1(cases[i]);
    }
  return 0;
}
