#include <cstddef>

template <typename DAT>
struct listNode
{
	//constructor:
	listNode(DAT data, listNode* next=NULL) : next(next), data(data) {};

	listNode* next;
	DAT data;
};

class LinkedList
{

};
