#include <iostream>
#include <string>
#include "btree.h"

using namespace std;

int main()
{
	btree t("a");

	t.insert_left(t.root(), "b");
	t.insert_right(t.root(), "c");

	node* c = t.get_right_child(t.root());
	t.insert_right(c, "d");
	
	node* d = t.get_right_child(c);
	t.insert_left(d, "e");
	t.insert_right(d, "f");

	node* e = t.get_left_child(d);
	t.insert_left(e, "g");
	t.insert_right(e, "h");

	node* f = t.get_right_child(d);
	t.insert_right(f, "i");

	t.preorder(t.root());

	return 0;
}