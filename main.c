#include "push_swap.h"

int main(void)
{
	int a = 3;

	char *str = ft_itoa(a, NULL, 10, 0);
	printf("%s\n", str);
	free(str);


	return (0);
}