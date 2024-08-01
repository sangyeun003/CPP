#include	<iostream>

// int	main(void)
// {
// 	int	i;
// 	int	j;

// 	std::cout << "Enter num_1: ";	// 문자열 출력
// 	std::cin >> i;	// 정수 입력 받아서 i에 저장

// 	std::cout << "Enter num_2: ";
// 	std::cin >> j;

// 	std::cout << "num_1 + num_2 = " << i + j << std::endl;	// 두 수의 합 출력

// 	return (0);
// }

using namespace std;	// namespace 사용 선언

int	main(void)
{
	int	i;
	int	j;

	cout << "Enter num_1: ";	// 문자열 출력
	cin >> i;	// 정수 입력 받아서 i에 저장

	cout << "Enter num_2: ";
	cin >> j;

	cout << "num_1 + num_2 = " << i + j << std::endl;	// 두 수의 합 출력

	return (0);
}
