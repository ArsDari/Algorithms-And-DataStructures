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
	std::puts("Please write length of left border");
	int leftBorder = readInt();
	std::puts("Please write length of right border");
	int rightBorder = readInt();
	size_t letterCounter = leftBorder;
	std::string tempString;
	std::vector<std::string> tempWords;
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
					std::cout << word << ' ' << std::string(spacesBetween, ' ');
					if (specialSpaces > 0) {
						std::cout << ' ';
						specialSpaces--;
					}
				}
				std::cout << '\n';
				tempWords.clear();
				letterCounter = 0;
			}
			tempWords.push_back(tempWord);
			letterCounter = letterCounter + tempWord.length() + 1;
		}
	}
	for (auto& word : tempWords) {
		std::cout << word << ' ';
	} // сделать вывод в файл
	std::cout << '\n';
	target.close();
	return 0;
}