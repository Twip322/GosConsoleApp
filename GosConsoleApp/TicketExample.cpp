#include "TicketExample.h"
#include <string>
#include <iostream>
using namespace std;


struct RegistrationForm
{
	int Number;
	string Surname;
	string Name;
	string Partonimyc;
};
struct NodeTwoExample :RegistrationForm
{
	RegistrationForm val;
	NodeTwoExample* next;
	NodeTwoExample* previos;
	NodeTwoExample(RegistrationForm _val)  : val(_val), next(nullptr), previos(nullptr) {}
};
struct TwoListExample
{
	NodeTwoExample* first;
	NodeTwoExample* last;
	TwoListExample() : first(nullptr), last(nullptr) {}

	bool is_empty() {
		return first == nullptr;
	}
	void push_back(RegistrationForm _val)
	{
		NodeTwoExample* p = new NodeTwoExample(_val);
		if (is_empty()) {
			first = p;
			last = p;
			p->previos = nullptr;
			p->next = nullptr;
			return;
		}
		last->next = p;
		p->previos = last;
		last = p;
	}
	void print() {
		if (is_empty()) return;
		NodeTwoExample* p = first;
		while (p) { // p != nullptr
			cout << "Number: " << p->val.Number << " ";
			cout << "Surname: " << p->val.Surname << " ";
			cout << "Name: " << p->val.Name << " ";
			cout << "Partonimyc: " << p->val.Partonimyc << endl;
			p = p->next;
		}
		cout << endl;
	}
	
	int length()
	{
		NodeTwoExample* p = first;
		int count = 0;
		if (is_empty())
		{
			return count;
		}
		while (p != nullptr)
		{
			count++;
			p = p->next;
		}
		return count;
	}
	void insert_middle(RegistrationForm _val)
	{
		if (is_empty())
		{
			push_back(_val);
			return;
		}
		NodeTwoExample* pTemp = first;
		int count = length() / 2;
		for (int i = 0; i < count; i++)
		{
			pTemp = pTemp->next;
		}
		NodeTwoExample* p = new NodeTwoExample(_val);
		p->previos = pTemp->previos;
		pTemp->previos->next = p;
		p->next = pTemp;
		pTemp->previos = p;
	}

};