/*

19. Организовать  в основной  памяти  с помощью указателей
очередь  из  стеков. Обеспечить  операции  ведения  стека  из
начала  очереди, дополнения  и  продвижения  очереди,  выдачи
содержимого очереди (9).

Дарижапов Арсалан ПС-21
Visual Studio 2022

*/

#include <iostream>
#include "Menu.hpp"

struct Stack {
	int value;
	Stack* next;
};

struct Node {
	Node() : stack(nullptr), next(nullptr) {};
	Stack* stack;
	Node* next;
};

class Queue
{
public:
	Queue() : head(nullptr), tail(nullptr) {};

	void enqueue() {
		Node* temp = new Node;
		if (head == nullptr) {
			head = temp;
			tail = temp;
			return;
		}
		tail->next = temp;
		tail = temp;
	}

	bool dequeue() {
		if (head == nullptr) {
			return false;
		}
		// очистить стек в очереди
		Node* temp = head;
		head = head->next;
		if (head == nullptr) {
			tail = nullptr;
		}
		delete temp;
		return true;
	}

	bool peek(int& value) {
		if (head == nullptr) {
			return false;
		}
		value = head->value;
		return true;
	}

	void printQueue() {
		const Stack* temp = head;
		std::puts(
			"Top starts from here.\n"
			"V"
		);
		while (temp != nullptr) {
			std::cout << temp->value << std::endl;
			temp = temp->next;
		}
	}
private:
	Node* head;
	Node* tail;
};



static void handleMenuStack() {

}

int main()
{
	Queue queue;
	MainMenuCommands userCommand = MainMenuCommands::EnqueueStack;
	do {
		printQueueOptions();
		handleMenuQueue(userCommand);
	} while (userCommand != MainMenuCommands::Exit);
}