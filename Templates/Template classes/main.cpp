#include "TemplateLinkedStack.h"
#include <memory>
#include <iostream>
using namespace std;

int main() {
	TemplateLinkedStack<int> s;
	s.Push(5);
	s.Push(4);
	s.Push(3);
	s.Push(2);
	s.Push(1);
	int a = s.Pop();
	int b = s.Pop();
	cout << a << " " << b << endl;

	TemplateLinkedStack<string> s2;
	s2.Push("Hello!");
	s2.Push("Goodbye!");

	TemplateLinkedStack<unique_ptr<string>> s3;
	s3.Push(std::make_unique<string>("Test"));
}