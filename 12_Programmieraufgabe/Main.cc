#include <iostream>
#include <memory>

// Aufgabe 1
template <typename T>
struct Node
{
	T value;
	std::shared_ptr<Node> next;
	std::shared_ptr<Node> prev;
};

typedef Node<int> IntNode;

int main()
{
	// Aufgabe 2
	// Anlegen der Nodes
	std::shared_ptr<IntNode> n1 = std::make_shared<IntNode>();
	std::shared_ptr<IntNode> n2 = std::make_shared<IntNode>();
	std::shared_ptr<IntNode> n3 = std::make_shared<IntNode>();
	std::shared_ptr<IntNode> n4 = std::make_shared<IntNode>();
	std::shared_ptr<IntNode> n5 = std::make_shared<IntNode>();

	// Werte , next/prev für die Nodes
	n1->value = 6;
	n1->prev = nullptr;
	n1->next = n2;

	n2->value = 12;
	n2->prev = n1;
	n2->next = n3;

	n3->value = 42;
	n3->prev = n2;
	n3->next = n4;

	n4->value = -7;
	n4->prev = n3;
	n4->next = n5;

	n5->value = 13;
	n5->prev = n4;
	n5->next = nullptr;

	// Aufgabe 3
	std::shared_ptr<IntNode> n = n1;

	std::cout << std::endl << "Head to Tail" << std::endl;
	while (n != nullptr)
	{
		std::cout << "Node Value: " << n->value << std::endl;
		n = n->next;
	}

	// Aufgabe 4
	n = n5;

	std::cout << std::endl << "Tail to Head" << std::endl;
	std::cout << "Node Value: " << n->value << std::endl;

	while (n != nullptr)
	{
		std::cout << "Node Value: " << n->value << std::endl;
		n = n->prev;
	}

	return 0;
}