#include <iostream>
#include "btree.h"

using namespace std;

int main()
{
	btree t(8);

	t.insert_left(t.root(), 3);
	t.insert_right(t.root(), 10);

	node* c = t.get_right_child(t.root());
	t.insert_right(c, 14);

	node* d = t.get_right_child(c);
	t.insert_right(c, 13);

	node* e = t.get_left_child(c);
	t.insert_left(d, 1);
	t.insert_right(d, 6);

	node* f = t.get_left_child(e);
	t.insert_left(e, 4);
	t.insert_right(e, 7);

	t.preorder(t.root());

	return 0;
}