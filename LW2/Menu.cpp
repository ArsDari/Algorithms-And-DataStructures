#include "Menu.hpp"

static int readInt() {
	int input;
	std::cin >> input;
	return input;
}

StackMenuCommands getStackMenuChoice() {
	int userInput = readInt();
	switch (userInput) {
	case 0:
		return StackMenuCommands::PushElement;
	case 1:
		return StackMenuCommands::PopElement;
	case 2:
		return StackMenuCommands::PrintElement;
	case 3:
		return StackMenuCommands::ReturnToMainMenu;
	default:
		return StackMenuCommands::InvalidCommand;
	}
}

MainMenuCommands getMenuChoice() {
	int userInput = readInt();
	switch (userInput) {
	case 0:
		return MainMenuCommands::EnqueueStack;
	case 1:
		return MainMenuCommands::DequeueStack;
	case 2:
		return MainMenuCommands::PrintQueue;
	case 3:
		return MainMenuCommands::ManageStack;
	case 4:
		return MainMenuCommands::Exit;
	default:
		return MainMenuCommands::InvalidCommand;
	}
}

void printQueueOptions() {
	std::puts(
		"1. Enqueue stack\n"
		"2. Dequeue stack\n"
		"3. Print queue\n"
		"4. Manage stack\n"
		"5. Exit"
	);
}

void printStackOptions() {
	std::puts(
		"1. Push element\n"
		"2. Pop element\n"
		"3. Print stack\n"
		"4. Return to main menu"
	);
}

void handleMenuQueue(MainMenuCommands& userCommand) {
	userCommand = getMenuChoice();
	switch (userCommand) {
	case MainMenuCommands::EnqueueStack: {
		int element = 0;
		if (std::cin >> element) {
			queue.enqueue(element);
			break;
		}
		std::puts("Invalid argument. Please enter the number");
		break;
	}
	case MainMenuCommands::DequeueStack: {
		int element = 0;
		if (queue.dequeue(element)) {
			std::cout << "Dequeued element: " << element << std::endl;
			break;
		}
		std::puts("Queue is empty");
		break;
	}
	case MainMenuCommands::PrintQueue: {
		int topElement = 0;
		if (queue.peek(topElement)) {
			std::cout << "Top element: " << topElement << std::endl;
		}
		else {
			std::puts("Queue is empty");
		}
		break;
	}
	case MainMenuCommands::ManageStack: {
		queue.printQueue();
		break;
	}
	case MainMenuCommands::Exit:
		break;
	default:
		std::puts("Please write the number of command you want to execute");
	}
}