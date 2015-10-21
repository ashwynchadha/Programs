//Ashwyn Singh Chadha
//Ning Zhao
#include <iostream>
#include "dynamic_stack.h"

using namespace std;

typedef DynamicStack::StackItem StackItem; 
const StackItem DynamicStack::EMPTY_STACK = -999;


DynamicStack::DynamicStack() 
{
	init_capacity_= capacity_ =16;
	items_ = new StackItem[16];
    size_ = 0;
}

DynamicStack::DynamicStack(unsigned int capacity)
{
	init_capacity_ = capacity_ = capacity;
	items_ = new StackItem[capacity];
	size_ = 0; 
}

DynamicStack::~DynamicStack() 
{
	delete [] items_;
}

int DynamicStack::size() const
{
	return size_;
}

bool DynamicStack::empty() const 
{
	if(size_==0)
		return true;
	return false;
}

void DynamicStack::print() const
{
	if (size_ == 0)
		cout << "Stack is empty. \n";
	else
	{
		for(int i=0; i<size_;i++)
			cout << items_[i] << endl;
	}
}

StackItem DynamicStack::peek() const 
{
	if(size_ == 0)
		return EMPTY_STACK;
	else
		return items_[size_-1];
}

void DynamicStack::push(StackItem value)
{
	if(size_ < capacity_)
		items_[size_] = value;
	else
	{
		StackItem *Temp = items_;														
		items_ = new StackItem[2*capacity_];
		for(int i=0; i < size_; i++)
			items_[i] = Temp[i];
		items_[size_] = value;
		delete [] Temp;
		capacity_ *= 2;
	}
	size_++;
}

StackItem DynamicStack::pop()
{
	if(size_ == 0)
		return EMPTY_STACK;
	size_--;
	
	
	if(size_ <= capacity_/4)
	{
		StackItem * Temp = items_;
		items_ = new StackItem[capacity_/2];
		for (int i=0; i <= size_; i++)
			items_[i] = Temp[i];
		delete [] Temp;
		capacity_/=2;
	}
	return items_[size_];
}
