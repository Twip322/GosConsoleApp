#include <iostream>
#include "TicketExample.cpp"
using namespace std;

/// <summary>
/// 
/// Конструктор, для создания Ноды
/// </summary>
struct Node
{
	//Значение Ноды(Узла списка)
	string val;
	//Указатель на следующий элемент
	Node* next;
	//Конструктор, для создания Ноды
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
	//Первая нода
	Node* first;
	//Последняя нода
	Node* last;
	//Конструктор
	SingleList() : first(nullptr), last(nullptr) {}
	//Проверка на пустоту
	bool is_empty() {
		return first == nullptr;
	}
	//Вставка в зад
	void push_back(string _val)
	{
		//Новая нода
		Node* p = new Node(_val);
		//Если пусто-то хуюсто
		if (is_empty()) {
			first = p;
			last = p;
			return;
		}
		//Ставим у последнего следующим новый
		last->next = p;
		//Последний теперь новый
		last = p;
	}
	//Принтуем
	void print() {
		if (is_empty()) return;
		Node* p = first;
		while (p) { // p != nullptr
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
	//Поиск ноды по значению
	Node* find(string _val) {
		//Ебашим первого
		Node* p = first;
		//Ищем по значению ноды нужную нам
		while (p && p->val != _val) p = p->next;
		//Возвращаем значение ноды
		return (p && p->val == _val) ? p : nullptr;
	}
	//Удаление первого
	void remove_first() {
		//если ноль то нахуй
		if (is_empty()) return;
		//Первую ноду выбираем
		Node* p = first;
		//Первой нодой ставим следующую
		first = p->next;
		//Удаляем
		delete p;
	}
	//Удаление в конце
	void remove_last() {
		//если ноль то нахуй
		if (is_empty()) return;
		//Если первый последний, то удаляем первый
		if (first == last) {
			remove_first();
			return;
		}
		//Выбираем первую ноду
		Node* p = first;
		//Пока у нынешней ноды следующая не последняя то проходим
		while (p->next != last) p = p->next;
		//У этой ноды убираем следующего
		p->next = nullptr;
		//Удаляем последнего
		delete last;
		//Последним ставим нынешний
		last = p;
	}
	//Удаление по значению
	void remove(string _val) {
		//если пусто, то нахуй, нечего удалять
		if (is_empty()) return;
		//Если это первый, удаляем первый
		if (first->val == _val) {
			remove_first();
			return;
		}
		//Также с последним
		else if (last->val == _val) {
			remove_last();
			return;
		}
		//Так а тут сложно, тут у нас медленный и быстрый проход, который на одну ноду быстрее, чтобы мы могли среагировать и не напороться когда будем ставить ссылки
		Node* slow = first;
		Node* fast = first->next;
		//Собственно ищем
		while (fast && fast->val != _val) {
			fast = fast->next;
			slow = slow->next;
		}
		//Если нету такого то пишем что нихуя нету
		if (!fast) {
			cout << "This element does not exist" << endl;
			return;
		}
		//Ставим у медленного следующим следующего для быстрого
		slow->next = fast->next;
		//Удаляем быстрого
		delete fast;
	}
	//Это оператор для того, чтобы выводить по индексу
	Node* operator[] (const int index) {
		//если пусто, то возвращаем нихуя
		if (is_empty()) return nullptr;
		//Снова первый, да ёбаный
		Node* p = first;
		//Пока не дойдём до индекса пинаем следующих
		for (int i = 0; i < index; i++) {
			p = p->next;
			if (!p) return nullptr;
		}
		return p;
	}
	//Узнаём длину
	int length()
	{
		//Первого пинаем
		Node* p = first;
		int count = 0;
		//Если пусто то грустно
		if (is_empty())
		{
			return count;
		}
		//Пока-пока-покачивая считаем
		while (p->next != nullptr)
		{
			count++;
			p = p->next;
		}
		return count;
	}
	//Вставка, ебать
	void insert_middle(string _val)
	{
		//Снова первый
		Node* pTemp = first;
		//Создаём ещё ноду, чтобы иметь пердыдущую ноду
		Node* pTempPrev;
		//Если длина ноль, то нахуй
		if (is_empty())
		{
			push_back(_val);
			return;
		}
		//Находим середину
		int count = length() / 2;
		//ищем середину
		for (int i = 0; i < count; i++)
		{
			//Если нода нужная нам следующая то запоминаем предыдущую перед переходом
			if (i == count - 1)
			{
				pTempPrev = pTemp;
			}
			pTemp = pTemp->next;
		}
		//Новую ноду создаём
		Node* p = new Node(_val);
		//Ставим у предыдущей следующей новую
		pTempPrev->next = p;
		//У нового следующая на которую ставим
		p->next = pTemp;
	}
};
//Ноды для двусвязного списка
struct NodeTwo
{
	//Это значение ноды
	string val;
	//Указатель на следующую ноду
	NodeTwo* next;
	//Указатель на предыдущую
	NodeTwo* previos;
	//Я в ахуе, но это конструктор
	NodeTwo(string _val) : val(_val), next(nullptr), previos(nullptr) {}
};
//Структура самого двусвязного списка
struct TwoList
{
	//Это у нас первый парень на вписке
	NodeTwo* first;
	//Это у нас последний парень на вписке
	NodeTwo* last;
	//Тоже конструктор, ага
	TwoList() : first(nullptr), last(nullptr) {}
	//Проверка на то, пустой ли список или нет
	bool is_empty() {
		return first == nullptr;
	}
	//Вставка в конец вписки
	void push_back(string _val)
	{
		//Создаём новую ноду
		NodeTwo* p = new NodeTwo(_val);
		//Если список пустой, не ебёмся, просто вставляем
		if (is_empty()) {
			first = p;
			last = p;
			p->previos = nullptr;
			return;
		}
		//Ставим у старого последнего следующим новый
		last->next = p;
		//У нового предыдущего старый
		last->previos = last;
		//Говорим всем, что последний ЛОХ!ПИДОР!
		last = p;
	}
	//печатаем чо у нас в списке
	void print() {
		//Если пусто, то ничего не печатаем
		if (is_empty()) return;
		//Ставим во главу пересчёта первого на вписке
		NodeTwo* p = first;
		//Циклим, выписываем, чо там было в стракте
		while (p) { // p != nullptr
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
	//Поиск ноды по значению
	NodeTwo* find(string _val) {
		//Берём первую
		NodeTwo* p = first;
		//пока не тот который нам нужен 
		while (p && p->val != _val) p = p->next;
		//возвращаем найденный или нихуя, как повезёт, тут рандом
		return (p && p->val == _val) ? p : nullptr;
	}
	//Удаляем первого
	void remove_first() {
		//Если пусто, то грустно
		if (is_empty()) return;
		//Первого выбираем
		NodeTwo* p = first;
		//У первого ставим следующего
		first = p->next;
		//У первого предыдущего ебашим нулом
		first->previos == nullptr;
		//удаляем выбранного
		delete p;
	}
	//Удаляем с конце
	void remove_last() {
		//Если пусто, то грустно
		if (is_empty()) return;
		//Если первый последний то последний первый, бля, я заебался, удаляем первого
		if (first == last) {
			remove_first();
			return;
		}
		//Ебурим последнего
		NodeTwo* p = last;
		//у предыдущего ебашим следующим нихуя
		p->previos->next = nullptr;
		//Ставим последним предпоследний
		last = p->previos;
		//Удаляем выбранный
		delete p;
	}
	//Удаление по значению
	void remove(string _val) {
		//Если пусто, то грустно
		if (is_empty()) return;
		//Дважды проверяем что ни первый ни последний не нужны нам
		if (first->val == _val) {
			remove_first();
			return;
		}
		else if (last->val == _val) {
			remove_last();
			return;
		}
		//Ебашим первого
		NodeTwo* node = first;
		while (node->val != _val) {
			node->next;
		}
		//Если не нода то хуёда
		if (!node) {
			cout << "This element does not exist" << endl;
			return;
		}
		//Вместо нашей ноды ебашим ссылки на те, что слева и справа
		node->previos->next = node->next;
		node->next->previos = node->previos;
		delete node;
	}
	//Оператор-доебатор по индексу
	NodeTwo* operator[] (const int index) {
		//пусто-грустно, да
		if (is_empty()) return nullptr;
		//Берём первую ноду
		NodeTwo* p = first;
		//Ищем
		for (int i = 0; i < index; i++) {
			p = p->next;
			if (!p) return nullptr;
		}
		return p;
	}
	//Возвращаем длину списка
	int length()
	{
		//Первый во главе угла опять
		NodeTwo* p = first;
		int count = 0;
		//Если пусто, то пусто, похуй, я не тестил
		if (is_empty())
		{
			return count;
		}
		//Пока-пока-покачивая считаем сколько
		while (p->next != nullptr)
		{
			count++;
			p = p->next;
		}
		return count;
	}
	//А вот и вставочка в середину
	void insert_middle(string _val)
	{
		//Снова во главе угла первый чел, видимо самый позитивный
		NodeTwo* pTemp = first;
		//Если пусто, то просто вставляем
		if (is_empty())
		{
			push_back(_val);
			return;
		}
		//Узнаём, где там середина
		int count = length() / 2;
		//Двигаемся в середину
		for (int i = 0; i < count; i++)
		{
			pTemp = pTemp->next;
		}
		//Создаём ноду
		NodeTwo* p = new NodeTwo(_val);
		//Указываем что у нового предыдущий тот же что и у старого
		p->previos = pTemp->previos;
		//У старого предыдущий новый
		pTemp->previos->next = p;
		//У нового следующий старый
		p->next = pTemp;
		//У старого предыдущий это новый
		pTemp->previos = p;
	}
};


/// <summary>
/// Для заполнения на русском: setlocale(LC_ALL, "rus");
/// Ну тут и так понятно, что и зачем
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


