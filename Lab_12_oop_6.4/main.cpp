#include <iostream>
#include <string>
using namespace std;

template<typename T> int search(T* arr, int size, T key, int& count)
{
	count = 0;
	int index = -1;
	for (size_t i = 0; i < size; i++)
	{
		if (key == arr[i])
		{
			index = index == -1 ? i : index;
			count++;
		}
	}
	return index;
}

int main()
{
	string arr[4]{ "test", "arr", "bla-bla", "test" };
	int c;
	cout << search<string>(arr, 4, "test", c) << endl;
	cout << c << endl;

	return 0;
}