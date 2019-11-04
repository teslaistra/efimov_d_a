#pragma once

class StackL {
public:	
	StackL();
	StackL(const StackL&);
	StackL& operator=(const StackL&);
	~StackL();
	void pop();
	void push(const float v);
	bool is_empty() const;
	float& top();
	const float& top() const;

	struct Node {

		float value{ 0.0 };
		Node* next{ nullptr };

	};

	Node* head{ nullptr };

};