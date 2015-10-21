#include "binary_search_tree.h"
#include <iostream>
#include <cstdlib>
#include <cmath>


// Implement the functions here

using namespace std;
typedef BinarySearchTree::DataType DataType;

void deleteBST (BinarySearchTree::Node* N);
unsigned int GetDepth(BinarySearchTree::Node* Check, BinarySearchTree::Node* N);
unsigned int TreeDepth(BinarySearchTree::Node* N);
void Print(BinarySearchTree::Node* N);
bool POS(BinarySearchTree::Node*, DataType);



BinarySearchTree::Node::Node(DataType newval)
{
	val = newval;
	left = NULL;
	right = NULL;
}

BinarySearchTree::BinarySearchTree()
{
	root_ = NULL;
	size_ = 0;
}

BinarySearchTree::~BinarySearchTree()
{
	deleteBST(root_);
}


unsigned int BinarySearchTree::size() const
{
	return size_;
}


DataType BinarySearchTree::max() const
{
	Node *Temp = root_;
	while(Temp->right != NULL)
		Temp = Temp->right;
		
	return Temp->val; 
}


DataType BinarySearchTree::min() const
{
	Node *Temp = root_;
	while(Temp->left != NULL)
		Temp = Temp->left;
		
	return Temp->val; 
}

int BinarySearchTree::getNodeDepth(Node* N) const
{
	return GetDepth(root_, N);
}

unsigned int BinarySearchTree::depth() const
{
	return TreeDepth(root_);	
}

void BinarySearchTree::print() const
{
	Print(root_);
	cout << endl;
}

bool BinarySearchTree::exists(DataType val) const
{
	Node *Temp = root_;
	while(Temp != NULL)
	{
		if(Temp->val == val)
			return true;
		else if(val > Temp->val)
			Temp = Temp->right;
		else
			Temp = Temp->left;
	}
	return false;
}
 
bool BinarySearchTree::insert(DataType val)
{
	if(root_ == NULL)
	{
		root_= new Node(val);
		size_++;
		return true;
	}

	size_++;
	if(POS(root_, val))
		return true;
		
	return false;
}
  
bool BinarySearchTree::remove(DataType val)
{
	Node *T_DEL = root_;
	Node *PREV = NULL;
	while(T_DEL != NULL)
	{
		if(T_DEL->val == val)
		{
			if(T_DEL->right !=NULL && T_DEL->left !=NULL) 
			{
				Node *Temp = T_DEL;
				Temp = Temp->left;
				while(Temp->right != NULL)
					Temp = Temp->right;
				DataType newval = Temp->val;
				
				(*this).remove(newval);
				T_DEL->val = newval;
				size_--;
				return true;
			}
	
			else if(T_DEL->right != NULL || T_DEL->left != NULL)
			{
				if(T_DEL->left == NULL)
				{
					if(PREV == NULL)
						root_ = root_->right;
					else
					{
						if(PREV->left == T_DEL)
							PREV->left = T_DEL->right;
						else
							PREV->right = T_DEL->right;
					}
				}
				
				if(T_DEL->right == NULL)
				{
					if(PREV == NULL)
						root_ = root_->left;
					else
					{
						if(PREV->left == T_DEL)
							PREV->left = T_DEL->left;
						else
							PREV->right = T_DEL->left;
					}
				}
			}
			size_--;
			delete T_DEL;
			return true;
		}
		
		PREV = T_DEL;
		if(val > T_DEL->val)
			T_DEL = T_DEL->right;
		else
			T_DEL = T_DEL->left;
	}
	return false;
}

void deleteBST (BinarySearchTree::Node *N)
{	if(!N)
	return;
		
	if(N->left != NULL)
		deleteBST(N->left);
	if(N->right != NULL)	
		deleteBST(N->right);
		
	delete N;
}

unsigned int GetDepth(BinarySearchTree::Node *Check, BinarySearchTree::Node *N)
{
	if(N->val == Check->val)
		return 0;
	
	if(N->val > Check->val)
		return 1 + GetDepth(Check->right, N);
	
	else
		return 1 + GetDepth(Check->left, N);
}

unsigned int TreeDepth(BinarySearchTree::Node *N)
{
	if(N->left == NULL && N->right == NULL)
		return 0;
	int L,R;	
	if(N->left != NULL)
		L = 1+TreeDepth(N->left);
		
	if(N->right != NULL)
		R = 1+TreeDepth(N->right);
	if (L>R)
		return L;
	return R;
}

void Print(BinarySearchTree::Node* N)
{
	if (N->left != NULL)
		Print(N->left);
	cout << N->val << " ";
	if (N->right != NULL)
		Print(N->right);
}

bool POS(BinarySearchTree::Node *pos, DataType val)
{
	if(val > pos->val)
	{
		if(pos->right == NULL)
		{
			pos->right = new BinarySearchTree::Node(val);
			return true;
		}
		else
			return POS(pos->right, val);
	}
	
	else if(val < pos->val)
	{
		if(pos->left == NULL)
		{
			pos->left = new BinarySearchTree::Node(val);
			return true;
		}
		else
			return POS(pos->left, val);
	}
	
	return false;	
} 

























