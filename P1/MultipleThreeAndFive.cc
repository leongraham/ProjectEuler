/* Program returns the set of all integers within a range set by 'start' and 'end',
   that are multiples of 4 or 6.
   Leon Graham, 2014
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//finds intergers that are multiples of 4 or 6
vector<int> multi(const int& start, const int& end, const int& multi1, const int& multi2, int& sum)
{
	int counter = start;
	vector<int> multiple_list;

	//check for valid search range
	if (start > end)
	{
		cout << "Warning: start number greater than end number." << endl;
	}
	if (start == end)
	{
		cout << "Warning: start number equal to end number." << endl;
	}
	if ((start < 0) || (end < 0))
	{
		cout << "Warning: negative search range." << endl;
	}

	//iterate through range
	while (counter < end)
	{
		//determine if interger is a multiple, include it in list and add to sum
		if (((counter % multi1)==0) || ((counter % multi2)==0))
		{
			multiple_list.push_back(counter);
			sum = sum + counter;
		}
		++counter;
	}
	return multiple_list;
}

int main()
{
	//multiples
	int multi1 = 3;
	int multi2 = 5;

	//set search range
	int start = 1;
	int end = 1000;

	int sum = 0;

    vector<int> list;

	//retrive list of multiples
	list = multi(start, end, multi1, multi2, sum);

	//print multiple list
	for (int i = 0; i < list.size(); ++i)
	{
		cout << list[i] << endl;
	}
	cout << "Sum: " << sum << endl;

	return 0;
}
