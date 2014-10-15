//Calculates the largest palindrome product
//Leon Graham, 2014

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void lpq(const int& num_digits)
{
  int multiple;
  int number_size;
  int number_length;
  int max_number=0;

  stringstream sstring_number;
  string string_number;
 
  switch (num_digits)
  {
    case 1: number_size=9;
    break;
    case 2: number_size=99;
    break;
    case 3: number_size=999;
    break;
    default: number_size=999;
    break;
  }

  for (int i=0; i<=number_size; ++i)
  {
      for (int j=0; j<=number_size; ++j)
      {
          multiple=i*j;
          sstring_number << multiple;
          sstring_number >> string_number;

          number_length=string_number.size();
         
          if (number_length>=(num_digits*2))
          {
             if ((string_number[0]==string_number[5])&&(string_number[1]==string_number[4])&&(string_number[2]==string_number[3]))
             {
                if (max_number < multiple) 
                {
                   max_number = multiple;
                }
             }
          }

          sstring_number.clear();
      }
  }
  cout << "largest palindrome from " << num_digits << " digits: "<< max_number << endl;
}

int main()
{
   int num_digits=3;

   lpq(num_digits);

   return 0;
}
