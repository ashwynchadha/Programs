//Ashwyn Singh Chadha
//Ning Zhao

#include <iostream>
#include "circular_queue.h"
using namespace std;
typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() 
{
    head_=-1;
	tail_=-1;
    capacity_=16;
    size_=0;
    items_ = new QueueItem[capacity_];
}

CircularQueue::CircularQueue(unsigned int capacity) 
{
    head_=-1;
	tail_=-1;
    capacity_= capacity;
    size_=0;
    items_ = new QueueItem[capacity];
}

CircularQueue::~CircularQueue() 
{
	delete [] items_;
}

int CircularQueue::size() const 
{
	return size_;
}

bool CircularQueue::empty() const
{
	if (size_==0)
		return true;
	return false;
}

bool CircularQueue::full() const
{
	if (size_ == capacity_)
		return true;
	return false;
}

void CircularQueue::print() const
{
	if (size_ == 0)
		cout << "The queue is empty.\n";
	else
		for (int i = head_; i<= tail_; i++)
			cout << items_[i] << ' ';
}

QueueItem CircularQueue::peek() const
{
	if (this->empty())
		return EMPTY_QUEUE;
	else
		return items_[head_];
}

bool CircularQueue::enqueue(QueueItem value)
{
	if (full())
		return false;
	
	else if(empty())
	{
		head_ = 0;
		tail_ = 1;
		items_[head_] = value;
	}
	
	else
	{
		items_[tail_] = value;
		tail_ = (tail_+1)%capacity_;
	}
	
	size_++;
	return true;
}

QueueItem CircularQueue::dequeue()
{
	if (this->empty())
		return EMPTY_QUEUE;
	else
	{
		int temp = head_;
		head_ = (head_+1)%capacity_;
		size_--;
		return items_[temp];
	}
		
}
