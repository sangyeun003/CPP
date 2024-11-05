#include	<iostream>

using namespace std;

int	main(void)
{
	int	*dynamic_arr = new int[5];

	for (int i = 0; i < 5; i++)
		dynamic_arr[i] = i + 1;
	
	for (int i = 0; i < 5; i++)
		cout << "Dynamic Array[" << i << "]: " << dynamic_arr[i] << "\n";
	
	delete[] dynamic_arr;

	return (0);
}
