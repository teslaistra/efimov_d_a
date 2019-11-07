#include "StackL.h"
#include <iostream>

StackL copy(const StackL& a) {
	StackL b;
	StackL::Node* t = a.head;
	while (t != nullptr) {
		b.push(t->value);
		t = t->next;
	}
	return b;
}

StackL::StackL(const StackL& a)
{
	StackL b = copy(a);
	head = nullptr;
	Node*t = b.head;

	while (t != nullptr) {
		std::cout << (int(t->value));
		push(t->value);
		t = t->next; 
	}

	b.~StackL();
}

StackL::~StackL()
{
	Node* t = head;        
	while (t != nullptr)
	{
		t = head->next;   
		delete(head);       
		head = t;           
	}
}

StackL& StackL::operator=(const StackL&a)
{
	StackL b = copy(a);
	//std::cout << b.top();

	head = nullptr;
	Node* t = b.head;

	while (t != nullptr) {
		std::cout << (int(t->value));
		push(t->value);
		t = t->next;
	}

	b.~StackL();

	return *this;
}

void StackL::pop()
{
	if (!is_empty()) {
		Node* t = head;
		head = head->next;
		delete(t);
	}
}
StackL::StackL() {
	head = nullptr;
}

void StackL::push(const float v) {
	head = new Node {v, head};
}

bool StackL::is_empty() const {
	return nullptr == head;
	
}

float& StackL::top() {
	if (is_empty()) {
		throw new std::exception("stack is empty");
	}
	return head->value;
}

const float& StackL::top() const {
	if (is_empty()) {
		throw new std::exception("stack is empty");
	}
	return head->value;
}



