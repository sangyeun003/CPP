#include	<iostream>

using namespace std;

int	main(void)
{
	int	a = 0;
	int	*const ptr = &a;	// 포인터를 상수화

	a = 1;
	ptr = &b;		// 컴파일 error 발생

	return (0);
}

int	value = 10;
int	value2 = 20;
int	&ref_val = value;

ref_val = value2;