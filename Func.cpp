#include "Header.h"

BinaryTree::BinaryTree()
{
	empty = true;
	_value = 0;
	left = nullptr;
	right = nullptr;
}

BinaryTree::BinaryTree(float value)
{
	empty = false;
	_value = value;
	left = nullptr;
	right = nullptr;
}

void BinaryTree::_print_this()
{
	std::cout << _value << " ";
}

void BinaryTree::add(float value)
{
	if (value > 0)
	{
		if (empty)
		{
			_value = value;
			empty = false;
		}
		else {
			if (_value == value)
				return;
			else if (value > _value)
			{
				if (right == nullptr)
				{
					right = new BinaryTree(value);
				}
				else
				{
					right->add(value);
				}
			}
			else
			{
				if (left == nullptr)
				{
					left = new BinaryTree(value);
				}
				else
				{
					left->add(value);
				}
			}
		}
	}
}

//решил что будет логично за один проход по дереву 
//выводить значение и считать количество елментов, 
//но не знаю правильно ли так делать?
size_t BinaryTree::printAndGetSum()
{
	size_t sum = 0;
	if (!empty)
	{
		++sum;
		if (left != nullptr)
		{
			sum+=left->printAndGetSum();
		}
		_print_this();
		if (right != nullptr)
		{
			sum+=right->printAndGetSum();
		}
	}
	return sum;
}

BinaryTree::~BinaryTree()
{
	if (left != nullptr)
		delete left;
	if (right != nullptr)
		delete right;
}
