#include	<iostream>

using namespace std;

void	func_throw(void)
{
	cout << "\nfunc_throw() 함수 내부\n";
	cout << "throw -1\n";
	throw -1;
	cout << "after throw -1\n";
}

void	func_2(void)
{
	cout << "\nfunc_2() 함수 내부\n";
	cout << "func_throw() 호출\n";
	func_throw();
	cout << "after func_throw()\n";
}

void	func_1(void)
{
	cout << "\nfunc_1() 함수 내부\n";
	cout << "func_2() 호출\n";
	func_2();
	cout << "after func_2()\n";
}

int	main(void)
{
	cout << "main 함수 내부\n";

	try
	{
		cout << "func_1() 호출\n";
		func_1();
	}
	catch(int exec)
	{
		cout << "\ncatch " << exec << "\n";
	}
	return (0);
}
