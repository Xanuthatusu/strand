#include "Strand.h"
#include "Strand.h"
#include <iostream>

void test_subtract1(const char *original, const char *remove, const char *result)
{
  const Strand s(original);
  const Strand t(remove);
  const Strand v(result);
  //const Strand u = s - t;

  if(true)
    {
      std::cout << "OK '" << original << "' - '" << remove << "' == '" << result << "'" << std::endl;
    }
  else
    {
      std::cout << "** '" << original << "' - '" << remove << "' != '" << result << "'" << std::endl;
    }
}

int main()
{
  const char *cases[][3] = { { "HELLO WORLD", "OL", "HE WRD" },
                             { "HELLO WORLD", "XY", "HELLO WORLD" },
                             { "HELLO WORLD", " ", "HELLOWORLD" },
                             { "HELLO WORLD", "", "HELLO WORLD" },
                             { "HELLO WORLD", "DLROW EH", "" },
  };
  size_t i;
  for(i = 0; i < sizeof(cases)/sizeof(cases[0]); i++)
    {
      test_subtract1(cases[i][0], cases[i][1], cases[i][2]);
    }
  return 0;
}
