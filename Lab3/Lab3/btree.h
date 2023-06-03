#ifndef _BINARNO_STABLO_H_
#define _BINARNO_STABLO_H_

#include <string>
using namespace std;

struct node 
{
	int element;
	node* left_child;
	node* right_child;
};

class btree 
{
private:
	node* root_node;
	node* create_new_node(int element);

public:
	btree(int element);
	void insert_left(node* parent, int element);
	void insert_right(node* parent, int element);
	node* root();
	node* get_left_child(node* parent);
	node* get_right_child(node* parent);
	void preorder(node* current);
};

#endif