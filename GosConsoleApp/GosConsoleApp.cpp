#include <iostream>
#include "TicketExample.cpp"
using namespace std;
/// <summary>
/// Структура данных имеющая поля
/// </summary>

struct combo
{
	string characterName;
	string enemyName;
	int comboPoints;
	float damageDealt;
	string StyleRank;
};
/// <summary>
/// Значение Ноды(Узла списка)
/// Указатель на следующий элемент
/// Конструктор, для создания Ноды
/// </summary>
struct Node
{
	string val;
	Node* next;
	Node(string _val) : val(_val), next(nullptr) {}
};

/// <summary>
/// first-первый узел списка
/// last-последний узел списка
/// push_back-вставка в конец списка
/// print-вывод списка
/// find-поиск узла по значению в списке
/// remove_first-удаление первого узла
/// remove_last-удаление последнего узла
/// remove-удаление узла по значению
/// operator-обращение к узлу по индексу
/// </summary>
struct SingleList
{
	Node* first;
	Node* last;
	SingleList() : first(nullptr), last(nullptr) {}

	bool is_empty() {
		return first == nullptr;
	}
	void push_back(string _val)
	{
		Node* p = new Node(_val);
		if (is_empty()) {
			first = p;
			last = p;
			return;
		}
		last->next = p;
		last = p;
	}
	void print() {
		if (is_empty()) return;
		Node* p = first;
		while (p) { // p != nullptr
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
	Node* find(string _val) {
		Node* p = first;
		while (p && p->val != _val) p = p->next;
		return (p && p->val == _val) ? p : nullptr;
	}
	void remove_first() {
		if (is_empty()) return;
		Node* p = first;
		first = p->next;
		delete p;
	}
	void remove_last() {
		if (is_empty()) return;
		if (first == last) {
			remove_first();
			return;
		}
		Node* p = first;
		while (p->next != last) p = p->next;
		p->next = nullptr;
		delete last;
		last = p;
	}
	void remove(string _val) {
		if (is_empty()) return;
		if (first->val == _val) {
			remove_first();
			return;
		}
		else if (last->val == _val) {
			remove_last();
			return;
		}
		Node* slow = first;
		Node* fast = first->next;
		while (fast && fast->val != _val) {
			fast = fast->next;
			slow = slow->next;
		}
		if (!fast) {
			cout << "This element does not exist" << endl;
			return;
		}
		slow->next = fast->next;
		delete fast;
	}
	Node* operator[] (const int index) {
		if (is_empty()) return nullptr;
		Node* p = first;
		for (int i = 0; i < index; i++) {
			p = p->next;
			if (!p) return nullptr;
		}
		return p;
	}
	int length()
	{
		Node* p = first;
		int count = 0;
		if (is_empty())
		{
			return count;
		}
		while (p->next != nullptr)
		{
			count++;
			p = p->next;
		}
		return count;
	}
	void insert_middle(string _val)
	{
		Node* pTemp = first;
		Node* pTempPrev;
		if (length() == 0)
		{
			return;
		}
		int count = length() / 2;
		for (int i = 0; i < count; i++)
		{
			if (i == count - 1)
			{
				pTempPrev = pTemp;
			}
			pTemp = pTemp->next;
		}
		Node* p = new Node(_val);
		pTempPrev->next = p;
		p->next = pTemp;
	}
};
struct NodeTwo
{
	string val;
	NodeTwo* next;
	NodeTwo* previos;
	NodeTwo(string _val) : val(_val), next(nullptr), previos(nullptr) {}
};
struct TwoList
{
	NodeTwo* first;
	NodeTwo* last;
	TwoList() : first(nullptr), last(nullptr) {}

	bool is_empty() {
		return first == nullptr;
	}
	void push_back(string _val)
	{
		NodeTwo* p = new NodeTwo(_val);
		if (is_empty()) {
			first = p;
			last = p;
			p->previos = nullptr;
			return;
		}
		last->next = p;
		last->previos = last;
		last = p;
	}
	void print() {
		if (is_empty()) return;
		NodeTwo* p = first;
		while (p) { // p != nullptr
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
	NodeTwo* find(string _val) {
		NodeTwo* p = first;
		while (p && p->val != _val) p = p->next;
		return (p && p->val == _val) ? p : nullptr;
	}
	void remove_first() {
		if (is_empty()) return;
		NodeTwo* p = first;
		first = p->next;
		first->previos == nullptr;
		delete p;
	}
	void remove_last() {
		if (is_empty()) return;
		if (first == last) {
			remove_first();
			return;
		}
		NodeTwo* p = first;
		while (p->next != last) p = p->next;
		p->next = nullptr;
		delete last;
		last = p;
	}
	void remove(string _val) {
		if (is_empty()) return;
		if (first->val == _val) {
			remove_first();
			return;
		}
		else if (last->val == _val) {
			remove_last();
			return;
		}
		NodeTwo* slow = first;
		NodeTwo* fast = first->next;
		while (fast && fast->val != _val) {
			fast = fast->next;
			slow = slow->next;
		}
		if (!fast) {
			cout << "This element does not exist" << endl;
			return;
		}
		slow->next = fast->next;
		delete fast;
	}
	NodeTwo* operator[] (const int index) {
		if (is_empty()) return nullptr;
		NodeTwo* p = first;
		for (int i = 0; i < index; i++) {
			p = p->next;
			if (!p) return nullptr;
		}
		return p;
	}
	int length()
	{
		NodeTwo* p = first;
		int count=0;
		if (is_empty())
		{
			return count;
		}
		while (p->next != nullptr)
		{
			count++;
			p = p->next;
		}
		return count;
	}
	void insert_middle(string _val)
	{
		NodeTwo* pTemp = first;
		if (length() == 0)
		{
			return;
		}
		int count = length()/2;
		for (int i = 0; i < count; i++)
		{
			pTemp = pTemp->next;
		}
		NodeTwo* p = new NodeTwo(_val);
		p->previos = pTemp->previos;
		pTemp->previos->next = p;
		p->next = pTemp;
		pTemp->previos = p;
	}
};


/// <summary>
/// Для заполнения на русском: setlocale(LC_ALL, "rus");
/// </summary>
/// <returns>
/// </returns>
int main()
{
	setlocale(LC_ALL, "rus");
	RegistrationForm form;
	form.Number = 123;
	form.Surname = "Эгов";
	form.Name = "Евгений";
	form.Partonimyc = "Николаевич";
	TwoListExample list;
	list.push_back(form);
	form.Name = "Женя";
	list.push_back(form);
	form.Name = "Женек";
	list.push_back(form);
	form.Name = "Брух";
	list.insert_middle(form);
	list.print();
	return 0;
}


