/*

19. Организовать  в основной  памяти  с помощью указателей
очередь  из  стеков. Обеспечить  операции  ведения  стека  из
начала  очереди, дополнения  и  продвижения  очереди,  выдачи
содержимого очереди (9).

Дарижапов Арсалан ПС-21
Visual Studio 2022

*/

#include <iostream>
constexpr int ENQUEUE_ELEMENT = 1;
constexpr int DEQUEUE_ELEMENT = 2;
constexpr int PEEK_TOP = 3;
constexpr int PRINT_QUEUE = 4;
constexpr int EXIT = 5;

struct Stack {
	Stack(int value) : value(value), next(nullptr) {};
	int value;
	Stack* next;
};

class Queue
{
public:
	Queue() : head(nullptr), tail(nullptr) {};

	void enqueue(int element) {
		Stack* temp = new Stack{ element };
		if (head == nullptr) {
			head = temp;
			tail = temp;
			return;
		}
		tail->next = temp;
		tail = temp;
	}

	bool dequeue(int& element) {
		if (head == nullptr) {
			return false;
		}
		Stack* temp = head;
		element = temp->value;
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
	Stack* head;
	Stack* tail;
};

static void printWelcomingMessage() {
	std::puts(
		"1. Enqueue element\n"
		"2. Dequeue element\n"
		"3. Peek top\n"
		"4. Print queue\n"
		"5. Exit"
	);
}

int main()
{
	Queue queue;
	int userCommand = 0;
	while (userCommand != EXIT) {
		printWelcomingMessage();
		std::cin >> userCommand;
		switch (userCommand) {
		case ENQUEUE_ELEMENT: {
			int element = 0;
			if (std::cin >> element) {
				queue.enqueue(element);
				break;
			}
			std::puts("Invalid argument. Please enter the number");
			break;
		}
		case DEQUEUE_ELEMENT: {
			int element = 0;
			if (queue.dequeue(element)) {
				std::cout << "Dequeued element: " << element << std::endl;
				break;
			}
			std::puts("Queue is empty");
			break;
		}
		case PEEK_TOP: {
			int topElement = 0;
			if (queue.peek(topElement)) {
				std::cout << "Top element: " << topElement << std::endl;
			}
			else {
				std::puts("Queue is empty");
			}
			break;
		}
		case PRINT_QUEUE: {
			queue.printQueue();
			break;
		}
		case EXIT:
			break;
		default:
			std::puts("Please write the number of command you want to execute");
		}
	}
	return 0;
}