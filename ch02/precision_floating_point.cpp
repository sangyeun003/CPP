#include	<iostream>
#include	<iomanip>

using namespace std;

int	main(void)
{
	float		float_val = 9.87654321f;
	double		double_val = 9.87654321987654321;
	long double	long_double_val = 9.87654321987654321l;

	cout << "float : " << sizeof(float) << "bytes" << endl;
	cout << "float_value : " << setprecision(numeric_limits<float>::digits10 + 1) << float_val << endl << endl;		// 기본 정밀도를 특정 자료형이 표현할 수 있는 유효 자릿수만큼 조절

	cout << "double : " << sizeof(double) << "bytes" << endl;
	cout << "double_value : " << setprecision(numeric_limits<double>::digits10 + 1) << double_val << endl << endl;

	cout << "long double : " << sizeof(long double) << "bytes" << endl;
	cout << "long_double_value : " << setprecision(numeric_limits<long double>::digits10 + 1) << long_double_val << endl << endl;

	return (0);
}
