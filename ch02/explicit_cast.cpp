#include	<iostream>

using namespace std;

int	main(void)
{
	int	a = 10;
	int	b = 5;
	int	int_avg = (a + b) / 2;
	float	float_avg1 = (a + b) / 2;
	float	float_avg2 = float(a + b) / 2;
	float	float_avg3 = (float)(a + b) / 2;

	cout << "int_avg: " << int_avg << endl;
	cout << "float_avg1: " << float_avg1 << endl;
	cout << "float_avg2: " << float_avg2 << endl;
	cout << "float_avg3: " << float_avg3 << endl;

	return (0);
}
