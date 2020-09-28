#include <iostream>
#include <memory>

// Aufgabe 1
template <typename T>
struct Node
{
	T value;
	std::weak_ptr<Node<T>> prev;
	std::shared_ptr<Node<T>> next;

	Node() : value(T()), prev(nullptr), next(nullptr)
	{

	}
};

typedef Node<int> IntNode;

int main()
{
	// Aufgabe 2
	// Anlegen der Nodes
	std::unique_ptr<IntNode> n1 = std::make_unique<IntNode>();
	std::unique_ptr<IntNode> n2 = std::make_unique<IntNode>();
	std::unique_ptr<IntNode> n3 = std::make_unique<IntNode>();
	std::unique_ptr<IntNode> n4 = std::make_unique<IntNode>();
	std::unique_ptr<IntNode> n5 = std::make_unique<IntNode>();

	// Werte , next/prev für die Nodes
	n1->value = 6;
	n1->next = std::make_shared<IntNode>(n2);

	n2->value = 12;
	n2->prev = n1;
	n2->next = std::make_shared<IntNode>(n3);

	n3->value = 42;
	n3->prev = n2;
	n3->next = std::make_shared<IntNode>(n4);

	n4->value = -7;
	n4->prev = n3;
	n4->next = std::make_shared<IntNode>(n5);

	n5->value = 13;
	n5->prev = n4;

	return 0;
}