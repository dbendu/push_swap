#include <iostream>
#include <vector>

void sort_array(int *arr, size_t size)
{
	size_t	min;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min])
				min = j;
			++j;
		}
		if (i != min)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
		++i;
	}
}

#define SZ 300

int main(void)
{
	std::vector<int> a;
	for (int i = 0; i < SZ; ++i)
		a.push_back(i);
	std::random_shuffle(a.begin(), a.end());
	for (int i = 0; i < SZ; ++i)
		std::cout << a[i] << ' ';
	std::cout << std::endl;
	return (0);
}