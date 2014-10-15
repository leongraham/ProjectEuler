/* Determines the maximum prime factor
   Leon Graham, 2014                   */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void primeFactors(vector<int>& list, unsigned long long& number)
{
	//start at 2 since 1 is not a prime number
	unsigned long long counter1 = 2;
	unsigned long long counter2 = 2;
	long int mod_count = 0;
	
	//halve the search by sqrt
	while (counter1 <= sqrt(number))
	{
		//calculate if counter1 is a factor
		if ((number % counter1) == 0)
		{
			//decide if counter1 is a prime number
			//i.e. only can be divide by 1 or itself)
			//start from 2 to the factor number itself-1
			//cout << "Factor: " << counter1 << endl;
			while (counter2 < (counter1-1))
			{
				//if it can be divided by other numbers
				if (counter1 % counter2 == 0)
				{
					++mod_count;
				}
				++counter2;
				
			}
			//add factor number to list if it is a prime number
			if (mod_count > 0)
			{
				//cout << counter1 << " is not a prime number" << endl;
			}
			else
			{
				list.push_back(counter1);
				cout << counter1 << " is a prime number" << endl;
			}
			counter2 = 2;
		}
		mod_count=0;
		++counter1;
	}
}

int main()
{
	//unsigned long long number = 13195;
	unsigned long long number = 600851475143;

	//unsigned long long number = sqrt(number_start);
	vector<int> list;

	primeFactors(list, number);

	if (list.size() > 0)
	{
		cout << "maximum prime factor: " << *max_element(begin(list), end(list)) << endl;
	}
	else
	{
		cout << "no prime factors" << endl;
	}
	return 0;
}
