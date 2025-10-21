#pragma once
#include <iostream>

enum class MainMenuCommands : int {
	EnqueueStack = 0,
	DequeueStack = 1,
	PrintQueue = 2,
	ManageStack = 3,
	Exit = 4,
	InvalidCommand = 5
};

enum class StackMenuCommands : int {
	PushElement = 0,
	PopElement = 1,
	PrintElement = 2,
	ReturnToMainMenu = 3,
	InvalidCommand = 4
};

MainMenuCommands getMenuChoice();

StackMenuCommands getStackMenuChoice();

void printQueueOptions();

void printStackOptions();

void handleMenuQueue(MainMenuCommands& userCommand);