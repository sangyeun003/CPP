#include	<iostream>
#include	<cstdlib>

using namespace std;

void	myterminate(void)
{
	cout << "myterminate called\n";
	exit(-1);
}

int	main(void)
{
	set_terminate(myterminate);
	throw 1;

	return (0);
}
