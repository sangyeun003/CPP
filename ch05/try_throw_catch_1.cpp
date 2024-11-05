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
	catch (float b)
	{
		cout << "catch " << b << "\n";
	}
	catch (char c)
	{
		cout << "catch " << c << "\n";
	}
	cout << "catch 이후에는 프로그램 잘 실행되네\n";
	return (0);
}
