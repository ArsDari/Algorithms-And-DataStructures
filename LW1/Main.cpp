/*

Visual Studio 2022

20. В  текстовом  файле записан отдельный абзац.  Переносов
слов нет.  Выровнять строки абзаца по ширине.  Иными  словами,
правые границы строк выравниваются по заданной позиции за счет
вставки дополнительных пробелов между словами.  Первая  строка
абзаца должна иметь заданный отступ, а остальные строки должны
начинаться  с  первой  позиции.  Последняя  строка  абзаца  по
правому  краю  не  выравнивается.  Число  строк  в  исходном и
конечном файлах может отличаться (8).

Дарижапов Арсалан ПС-21

*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

static std::vector<std::string> split(const std::string& target, const char delimeter) {
	std::vector<std::string> result;
	std::stringstream ss(target);
	std::string temp;
	while (std::getline(ss, temp, delimeter)) {
		result.push_back(temp);
	}
	return result;
}

static const std::string readString() {
	std::string input;
	std::cin >> input;
	return input;
}

static const int readInt() {
	int input;
	std::cin >> input;
	return input;
}

int main() {
	std::system("chcp 1251");
	std::puts("Please write filename");
	std::ifstream target(readString());
	if (!target.is_open()) {
		std::puts("File cannot be open");
		return 1;
	}
	std::puts(
		"Save output in a file?\n"
		"Y (y) to save"
	);
	std::string userInput(readString());
	std::ofstream output;
	bool isSavingInFile = false;
	if (userInput == "Y" || userInput == "y") {
		std::puts("Please write the name of file to save. Beware that old content of the file will be overwritten");
		std::string outputFilename(readString());
		output.open(outputFilename, std::ios::out);
		if (!output.is_open()) {
			std::puts("Unexpected error occured. Exiting...");
			return 1;
		}
		isSavingInFile = true;
	}
	else {
		std::puts("Output will be in console");
	}
	std::puts("Please write length of left border");
	int leftBorder = readInt();
	std::puts("Please write length of right border");
	int rightBorder = readInt();
	size_t letterCounter = leftBorder;
	std::string tempString;
	std::vector<std::string> tempWords;
	isSavingInFile ?
		output << std::string(letterCounter, ' ') :
		std::cout << std::endl << std::string(letterCounter, ' ');
	while (std::getline(target, tempString)) {
		for (auto& tempWord : split(tempString, ' ')) {
			if (tempWord.length() == 0) {
				continue;
			}
			if (letterCounter + tempWord.length() > rightBorder) {
				size_t spacesBetween = 0;
				size_t specialSpaces = 0;
				if (tempWords.size() > 1) {
					spacesBetween = (rightBorder - letterCounter + 1) / (tempWords.size() - 1);
					specialSpaces = (rightBorder - letterCounter + 1) % (tempWords.size() - 1);
				}
				for (auto& word : tempWords) {
					isSavingInFile ?
						output << word << ' ' << std::string(spacesBetween, ' ') :
						std::cout << word << ' ' << std::string(spacesBetween, ' ');
					if (specialSpaces > 0) {
						isSavingInFile ?
							output << ' ' :
							std::cout << ' ';
						specialSpaces--;
					}
				}
				isSavingInFile ?
					output << '\n' :
					std::cout << '\n';
				tempWords.clear();
				letterCounter = 0;
			}
			tempWords.push_back(tempWord);
			letterCounter = letterCounter + tempWord.length() + 1;
		}
	}
	for (auto& word : tempWords) {
		isSavingInFile ?
			output << word << ' ' :
			std::cout << word << ' ';
	}
	isSavingInFile ?
		output << '\n' :
		std::cout << '\n';
	target.close();
	output.close();
	return 0;
}