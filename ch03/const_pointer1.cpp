#include	<iostream>

using namespace std;

int	main(void)
{
	int	a = 0;
	const int	*ptr = &a;	// 포인터변수가 가리키는 "값"을 상수화

	a = 1;
	*ptr = 2;		// 컴파일 error 발생

	return (0);
}
