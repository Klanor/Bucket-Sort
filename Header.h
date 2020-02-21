#pragma once
#include<iostream>

class BinaryTree
{
	bool empty;
	float _value;

	BinaryTree* left;
	BinaryTree* right;

	void _print_this();

public:
	BinaryTree();
	BinaryTree(float value);

	void add(float value);

	size_t printAndGetSum();

	~BinaryTree();

};