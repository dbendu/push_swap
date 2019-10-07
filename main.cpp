#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> a;
	for (int i = 0; i < 500; ++i)
		a.push_back(i);
	std::random_shuffle(a.begin(), a.end());
	for (int i = 0; i < 500; ++i)
		std::cout << a[i] << ' ';
	std::cout << std::endl;
	return (0);
}