#include	<iostream>

using namespace std;

int	value = 1;

int	main(void)
{
	int	value = -1;

	cout << value << endl;
	cout << ::value << endl;	// 전역 범위 연산자

	return (0);
}
