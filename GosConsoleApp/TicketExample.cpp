#include "TicketExample.h"
#include <string>
#include <iostream>
using namespace std;

/// <summary>
/// Кароче, ебать структура с данными по билету
/// </summary>
struct RegistrationForm
{
	int Number;
	string Surname;
	string Name;
	string Partonimyc;
};
//Это наша Нода, ебать, узел, если ты русский
struct NodeTwoExample :RegistrationForm
{
	//Это значение ноды
	RegistrationForm val;
	//Указатель на следующую ноду
	NodeTwoExample* next;
	//Указатель на предыдущую
	NodeTwoExample* previos;
	//Я в ахуе, но это конструктор, в который будут совать свои грязные данные н'вахи(другие структуры или кому там это надо)
	NodeTwoExample(RegistrationForm _val)  : val(_val), next(nullptr), previos(nullptr) {}
};
//Структура самого двусвязного списка
struct TwoListExample
{
	//Это у нас первый парень на вписке
	NodeTwoExample* first;
	//Это у нас последний парень на вписке
	NodeTwoExample* last;
	//Тоже конструктор, ага
	TwoListExample() : first(nullptr), last(nullptr) {}
	//Проверка на то, пустой ли список или нет
	bool is_empty() {
		return first == nullptr;
	}
	//Вставка в конец вписки
	void push_back(RegistrationForm _val)
	{
		//Создаём новую ноду
		NodeTwoExample* p = new NodeTwoExample(_val);
		//Если список пустой, не ебёмся, просто вставляем
		if (is_empty()) {
			first = p;
			last = p;
			p->previos = nullptr;
			p->next = nullptr;
			return;
		}
		//Ставим у старого последнего следующим новый
		last->next = p;
		//У нового предыдущего старый
		p->previos = last;
		//Говорим всем, что последний ЛОХ!ПИДОР!
		last = p;
	}
	//печатаем чо у нас в списке
	void print() {
		//Если пусто, то ничего не печатаем
		if (is_empty()) return;
		//Ставим во главу пересчёта первого на вписке
		NodeTwoExample* p = first;
		//Циклим, выписываем, чо там было в стракте
		while (p) { // p != nullptr
			cout << "Number: " << p->val.Number << " ";
			cout << "Surname: " << p->val.Surname << " ";
			cout << "Name: " << p->val.Name << " ";
			cout << "Partonimyc: " << p->val.Partonimyc << endl;
			p = p->next;
		}
		cout << endl;
	}
	//Возвращаем длину списка
	int length()
	{
		//Первый во главе угла опять
		NodeTwoExample* p = first;
		int count = 0;
		//Если пусто, то пусто, похуй, я не тестил
		if (is_empty())
		{
			return count;
		}
		//Пока-пока-покачивая считаем сколько
		while (p != nullptr)
		{
			count++;
			p = p->next;
		}
		return count;
	}
	//А вот и вставочка в середину
	void insert_middle(RegistrationForm _val)
	{
		//Если пусто, то просто вставляем
		if (is_empty())
		{
			push_back(_val);
			return;
		}
		//Снова во главе угла первый чел, видимо самый позитивный
		NodeTwoExample* pTemp = first;
		//Узнаём, где там середина
		int count = length() / 2;
		//Двигаемся в середину
		for (int i = 0; i < count; i++)
		{
			pTemp = pTemp->next;
		}
		//Создаём ноду
		NodeTwoExample* p = new NodeTwoExample(_val);
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