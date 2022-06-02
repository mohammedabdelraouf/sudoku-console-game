#pragma once

class StackArr
{
	int* arr;
	int elements;
	int capacity;
public:
	StackArr(void);
	int Length();
	void Push(int val);
	void Pop();
	int Top();
	bool empty();
	void Expand();
	~StackArr(void);
};

