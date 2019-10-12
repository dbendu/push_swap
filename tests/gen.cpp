#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <fcntl.h>
#include "unistd.h"
#include <string.h>

using namespace std;

ptrdiff_t myrandom (ptrdiff_t i) { return rand()%i;}
ptrdiff_t (*p_myrandom)(ptrdiff_t) = myrandom;

int main(int argc, const char **argv)
{
	size_t size;
	
	srand(time(0));
	if (argc == 2 && (size = atoi(argv[1])) > 0)
	{
		vector<int> v;
		for (size_t i = 0; i < size; ++i)
			v.push_back(i);
		random_shuffle(v.begin(), v.end(), p_myrandom);
		for (size_t i = 0; i < size; ++i)
			cout << v[i] << ' ';
	}
	else
		cout << "Error\n" << endl;
	return (0);
}
