/* Calculates the sum of even Fibonacci series
   Leon Graham, 2014.                          */

#include <iostream>
#include <vector>

using namespace std;

bool isFirstTime = true;

void fib(vector<int>& list, const int& max_value, int& index)
{
    if (isFirstTime)
	{
		list.push_back(1);
		list.push_back(2);
		index=index+1;
		isFirstTime = false;
	}
	else
	{
		list.push_back(list[index - 1] + list[index]);
		++index;
	}

	while (list[index] < max_value)
	{
		fib(list, max_value, index);
	}	
}

int main()
{
	int index = 0;
	int max_value = 4000000;
	int sum=0;
	vector<int> list;

	fib(list, max_value, index);
	
	for (size_t i = 0; i < (list.size()-1); ++i)
	{
		cout << list[i] << " ";
		if (list[i] % 2 == 0)
		{
			sum = sum + list[i];
		}
	}
	cout << endl;
	cout << "Sum of even Fibonacci numbers:" << sum << endl;

	return 0;
}
