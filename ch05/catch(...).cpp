#include	<iostream>

using namespace std;

int	main(void)
{
	try
	{
		int	input;

		cout << "정수를 하나 입력하세요. : ";
		cin >> input;

		if (input > 0)
		{
			cout << "throw 1\n";
			throw 1;
			cout << "after throw 1\n";	// 실행 안됨
		}
		else if (input < 0)
		{
			cout << "throw -1.0f\n";
			throw -1.0f;
			cout << "after throw -1.0f\n";	// 실행 안됨
		}
		else if (input == 0)
		{
			cout << "throw Z\n";
			throw 'Z';
			cout << "after throw Z\n";
		}
	}
	catch (int a)
	{
		cout << "catch " << a << "\n";
	}
	catch (...)
	{
		cout << "catch all\n";
	}

	return (0);
}