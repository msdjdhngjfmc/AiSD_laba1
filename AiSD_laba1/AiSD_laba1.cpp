#include <iostream>

using namespace std;

class Node
{
public:
	Node(int initdata) {
		data = initdata;
		next = NULL;
	}
	int getData() {
		return data;
	}
	Node* getNext() {
		return next;
	}
	void setData(int newData) {
		data = newData;
	}
	void setNext(Node* newnext) {
		next = newnext;
	}
	Node* getLast(Node* head)
	{
		Node* node = head;
		while (head->getNext() != NULL)
			head = head->getNext();
		return head;
	}


private:
	int data;
	Node* next;
};

class UnorderedList
{
public:
	UnorderedList() {
		head = NULL;

	}

	bool isEmpty() {                                         /*Проверка на пустоту списка*/
		return head == NULL;
	}

	void push_front(int item) {                              /*Добавление в начало списка*/
		Node* temp = new Node(item);
		temp->setNext(head);
		head = temp;
	}

	void push_back(int item) {                               /*Добавление в конец списка*/
		Node* current = new Node(item);
		Node* previous = new Node(item);
		current = current->getLast(head);
		current->setNext(previous);
		head = head;
	}

	void clear() {                                           /*Удаление всех элементов списка*/
		Node* current = head;
		while (head != NULL)
		{
			current = head->getNext();
			delete head;
			cout << "!";
			head = current;
		}
	}



	void pop_front() {                                       /*Удаление первого элемента*/
		Node* current = head;
		head = current->getNext();
		delete current;
	}
	void pop_back() {                                        /*Удаление последнего элемента*/
		Node* current = head;
		Node* previous = head;
		current = current->getLast(head);
		while (previous->getNext() != current)
		{
			previous = previous->getNext();

		}
		previous->setNext(current->getNext());
		delete current;
	}

	void print() {                                            /*Вывод списка на экран*/
		Node* current = head;
		while (current != NULL)
		{
			cout << current->getData() << ", ";
			current = current->getNext();
		}
		cout << endl;
	}

	int get_size() {                                          /*Получение размера списка*/
		Node* current = head;
		int count = 0;
		while (current != NULL) {
			count++;
			current = current->getNext();
		}
		return count;
	}

	bool search(int item) {                                   /*Поиск элемента списка*/
		Node* current = head;
		while (current != NULL) {
			if (current->getData() == item) {
				return true;
			}
			else {
				current = current->getNext();
			}

		}
		return false;
	}
	void remove(int item) {                                   /*Удаление элемента по индексу*/
		Node* current = head;
		Node* previous = NULL;
		bool found = false;
		while (!found)
		{
			if (current->getData() == item) {
				found = true;
			}
			else
			{
				previous = current;
				current = current->getNext();
			}
		}
		if (previous == NULL)
		{
			head = current->getNext();
		}
		else
		{
			previous->setNext(current->getNext());
		}
	}
	int at(int size_t) {                                            /*Получение элемента по индексу*/
		Node* current = head;
		int count = 1;
		while (current != NULL)
		{
			if (count == size_t) {
				return current->getData();
			}
			current = current->getNext();
			count++;
		}
		return 0;
	}
	void insert(int item, int size_t) {                               /*Добавление элемента по индексу*/
		Node* current = head;
		Node* previous = new Node(item);
		int count = 1;
		while (current != NULL)
		{
			if (count == size_t) {
				previous->setNext(current->getNext());
				current->setNext(previous);
				break;
			}
			current = current->getNext();
			count++;
		}
	}

	void set(int item, int size_t) {                                  /*Замена элемента по индексу на передаваемый элемент*/
		Node* current = head;
		int count = 1;
		while (current != NULL)
		{
			if (count == size_t) {
				current->setData(item);
				break;
			}
			current = current->getNext();
			count++;
		}
	}
	void push_front2(int amount) {
		int item = 0;
		for (int i = 1; i <= amount; i++) {
			cout << amount - i + 1 << ".";
			cin >> item;
			Node* temp = new Node(item);
			temp->setNext(head2);
			head2 = temp;

		}


	}

	int find_list(int amount) {                            /*Поиск последнего вхождения другого списка в список*/
		head2 = NULL;

		push_front2(amount);
		int kek(0);
		int lol(0);
		Node* current = head;
		Node* temp = head2;
		int numberOfTrueList = 0;
		bool checker(false);
		while (current->getNext() != NULL) {
			numberOfTrueList++;
			if (current->getData() == temp->getData())
			{
				cout << "числа равны, начинаю проверку\n";
				while (temp->getNext() != NULL && current->getNext() != NULL)
				{
					if (current->getData() != temp->getData()) {
						temp = head2;
						continue;
					}
					cout << "числа опять совпало\n";
					current = current->getNext();
					temp = temp->getNext();
					if (temp->getNext() == NULL)
					{
						kek = numberOfTrueList;
						checker = true;
						continue;
					}
					else
					{
						lol = 0;
					}
				}
				temp = head2;
			}
			current = current->getNext();
			if (current == NULL) break;
		}
		if (checker == 1)
			return kek;
		numberOfTrueList = numberOfTrueList - 2;
		cout << endl;
		if (lol != 0)
		{
			return numberOfTrueList;
		}
		else
		{
			return -1;
		}

	}

private:
	Node* head;
	Node* head2;
};



int main()
{
	setlocale(LC_ALL, "Rus");

	int amount;
	int number, numberSearch, size_t;


	UnorderedList myList;
	cout << "Сколько будет чисел в списке: ";
	cin >> amount;
	cout << "Введите числа списка: \n";
	for (int i = 0; i < amount; i++) {
		cout << amount - i << ".";
		cin >> number;
		myList.push_front(number);
		//cout << ", ";
	}
	cout << "\n";
	//cin >> numberSearch;
	//cout << myList.search(numberSearch);
	myList.print();
	//cout << "\n" << myList.isEmpty() << "\n";
	//cout << "\nКол-во чисел в списке: " << myList.get_size() << "\n";
	//cin >> number;
 //   myList.push_back(number);
	//cout << "\nКол-во чисел в списке: " << myList.get_size() << "\n";

	//myList.print();
	//cout << "\nКол-во чисел в списке: " << myList.get_size() << "\n";
	//myList.pop_front();
	//myList.print();
	//myList.pop_back();
	//
	//myList.print();
	//myList.clear();// удаление всех элементов списка
	//cin >> size_t;
	//cout << myList.at(size_t);
	//cout << "Number: ";
	//cin >> number;
	//cout << "Size: ";
	//cin >> size_t;
	/*myList.insert(number, size_t);*/
	//myList.set(number, size_t);
	//myList.print();
	cout << "Второй список \n";
	cout << "Сколько будет чисел в списке: ";
	cin >> amount;
	//for (int i = 0; i < amount; i++) {
	//	cout << i + 1 << ".";
	//	cin >> number;
	//	myList.push_front2(number);
	//	//cout << ", ";
	//}

	cout << endl;

	cout << "Индекс первого элемента последнего вхождения другого списка в список: " << myList.find_list(amount);
	cout << endl;
}

