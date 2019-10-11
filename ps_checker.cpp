#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

#define	L	1
#define	M	2
#define	H	4
#define	O	8
#define	A	16

using namespace std;

ptrdiff_t myrandom (ptrdiff_t i) { return rand()%i;}
ptrdiff_t (*p_myrandom)(ptrdiff_t) = myrandom;

void usage(void)
{
	setlocale(LC_ALL, "rus");
	cout << "Чтобы запустить чекер с готовыми тестами, используй флаги:\n"
		<< "\t-l -- легкие тесты (до 30-ти элемементов),\n"
		<< "\t-m -- средние тесты (30-150 элементов),\n"
		<< "\t-h -- сложные тесты (150-500 элементов),\n"
		<< "\t-o -- тесты на 500-1000 элементов или\n"
		<< "\t-a -- запустить все тесты выше.\n\n"
		<< "Или ты можешь сам задать кол-во элементов во входном массиве\n"
		<< "(числа больше 10000 будут обрезаться) так:\n"
		<< "./test кол-во_символов кол-во повторений." << endl;
}

void run_easy(void)
{

}

void run_medium(void)
{

}

void run_hard(void)
{

}

void run_fun(void)
{

}

void run_tests(char flags)
{
	if (flags & A)
	{
		run_easy();
		run_medium();
		run_hard();
	}
	else if (flags & L)
		run_easy();
	else if (flags & M)
		run_medium();
	else if (flags & H)
		run_hard();
	else if (flags & A)
		run_fun();
}

int main(int argc, const char **argv)
{
	int		size;
	char	flags;

	if (argc == 1)
		usage();
	flags = 0;
	if (strstr(argv[1], "-l"))
		flags |= L;
	if (strstr(argv[1], "-M"))
		flags |= M;
	if (strstr(argv[1], "-H"))
		flags |= H;
	if (strstr(argv[1], "-O"))
		flags |= O;
	if (strstr(argv[1], "-A"))
		flags |= A;
	
	run_tests(flags);




	// srand(time(0));
	// if (argc == 2 && (size = atoi(argv[1])) > 0)
	// {
	// 	vector<int> v;
	// 	for (int i = 0; i < size; ++i)
	// 		v.push_back(i);
	// 	random_shuffle(v.begin(), v.end(), p_myrandom);
	// 	for (int i = 0; i < size; ++i)
	// 		cout << v[i] << ' ';
	// }
	// else
	// 	cout << "Error\n" << endl;
	return (0);
}