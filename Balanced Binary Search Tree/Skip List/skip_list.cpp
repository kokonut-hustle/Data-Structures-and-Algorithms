#include "skip_list.hpp"
#include <iostream>

using namespace std;

// skip list is actually not a balanced bst
// but can be used as an alternative solution
// refer to this leetcode problem: https://leetcode.com/problems/design-skiplist/

namespace dsa
{
class Skiplist
{
private:
	struct Node
	{
		int val;
		Node *right, *down;
		Node() : val(0), right(nullptr), down(nullptr)
		{
		}
		Node(int _val, Node *_right, Node *_down) : val(_val), right(_right), down(_down)
		{
		}
	};
	Node *head;

public:
	Skiplist()
	{
		head = new Node();
	}

	bool search(int target)
	{
		Node *p = head;
		while (p)
		{
			while (p->right && p->right->val < target)
				p = p->right;
			if (p->right && p->right->val == target)
				return true;
			else
				p = p->down;
		}
		return false;
	}

	void add(int num)
	{
		Node *p = head;
		vector< Node * > vn;
		while (p)
		{
			while (p->right && p->right->val < num)
				p = p->right;
			vn.push_back(p);
			p = p->down;
		}

		Node *downNode = nullptr;
		bool add = true;
		while (add && !vn.empty())
		{
			Node *p = vn.back();
			vn.pop_back();
			Node *next = p->right;
			p->right = new Node(num, next, downNode);
			downNode = p->right;
			add = (rand() & 1) == 0;
		}
		if (add) head = new Node(0, new Node(num, nullptr, downNode), head);
		return;
	}

	bool erase(int num)
	{
		bool seen = false;
		Node *p = head;
		while (p)
		{
			while (p->right && p->right->val < num)
				p = p->right;
			if (p->right && p->right->val == num)
			{
				seen = true;
				Node *temp = p->right;
				p->right = p->right->right;
				delete temp;
			}
			p = p->down;
		}
		return seen;
	}
};
} // namespace dsa
