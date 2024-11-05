#include	<iostream>

using namespace std;

void	real_noexcept(void) noexcept
{
	cout << "real_noexcept()\n";
}

void	fake_noexcept(void) noexcept
{
	cout << "fake_noexcept()\n";
	throw 1;
}

int	main(void)
{
	real_noexcept();

	try
	{
		fake_noexcept();
	}
	catch (int exec)
	{
		cout << "catch " << exec << "\n";
	}
	return (0);
}
