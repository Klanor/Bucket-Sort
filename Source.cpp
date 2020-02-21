#include <iostream>
#include "Header.h"
#include <vector>

using namespace std;

int main()
{
	vector<BinaryTree>* vec = new vector<BinaryTree>(10);
	float value;
	int point;

	cout << "Auto-1, by hand-any" << endl;
	cin >> point;
	if (point == 1)
	{
		vec->resize(100);
		for (int i = 0; i < 50; ++i)
		{
			value = (float)(rand()) / RAND_MAX * (100.0 - 0.1) + 0.1;
			cout << value << " ";
			point = value;
			vec->at(point).add(value);
		}
		cout << endl << endl;
	}
	else
	{
		cout << "Enter positive float number(0 to break):" << endl;
		while (cin >> value, value != 0)
		{
			point = value;
			if (point > vec->size())
				vec->resize(point + 10);
			vec->at(point).add(value);
		}
	}
	size_t bigest_bucket = 0;
	size_t tmp;

	for (int i = 0; i < vec->size(); ++i)
	{
		tmp = vec->at(i).printAndGetSum();
		if (tmp > bigest_bucket)
			bigest_bucket = tmp;
	}

	cout << endl << "Max sum in one bucket: "<< bigest_bucket << endl;

	return 0;
}