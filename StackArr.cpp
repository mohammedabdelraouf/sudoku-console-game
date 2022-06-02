#include "StackArr.h"
#include <assert.h>


StackArr::StackArr(void)
{
	elements=0;
	capacity=10;
	arr=new int[capacity];

}

int StackArr::Length()
{
	return elements;
}

void StackArr::Push(int val)
{
	if(elements==capacity)
		Expand();
	arr[elements]=val;
	elements++;
}

void StackArr::Pop()
{
	assert(!empty());
	elements--;
}

int StackArr::Top()
{
	//assert(!empty());
	return arr[elements-1];

}


bool StackArr::empty()
{
	return (elements==0);
}

void StackArr::Expand()
{
	capacity=capacity*2;
	int *tmp=new int[capacity];
	for(int i=0;i<elements;i++)
		tmp[i]=arr[i];
	delete [] arr;
	arr=tmp;
}

StackArr::~StackArr(void)
{
	delete [] arr;
}
