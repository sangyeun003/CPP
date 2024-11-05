#include	<iostream>

using namespace std;

void	func_throw(void)
{
	cout << "func_throw()\n";
	cout << "throw -1\n";
	throw -1;
	cout << "after throw -1\n";
}

int	main(void)
{
	try
	{
		func_throw();
	}
	catch (int exec)
	{
		cout << "catch " << exec << "\n";
	}
	return (0);
}
