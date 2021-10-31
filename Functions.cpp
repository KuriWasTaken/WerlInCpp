#include <iostream>
#include <string>

void splitStrByDelimeter(std::string str, char delimeter, std::string arr[]) {
	str += delimeter;
	int inCounter = 0;
	std::string currentStr;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == delimeter) {
			arr[inCounter] = currentStr;
			inCounter += 1;
			currentStr = "";
		}
		else {
			currentStr += str[i];
		}
	}
}

std::string removeFinalCharOfType(std::string str, char delimeter) {
	std::string newStr = str;
	if (newStr[newStr.length()-1] == delimeter) {
		newStr[newStr.length()-1] = *"";
	}
	return newStr;
}

std::string removeFirstCharOfType(std::string str, char delimeter) {
	std::string newStr = str;
	for (int i = 0; i < str.length(); i++) {
		if (i != 0) {
			newStr += str[i];
		}
	}
	return newStr;
}

std::string removeParameters(std::string str) {
	std::string newStr;
	for (int i = 0; i < str.length(); i++) {
		if (i == 0 || i == str.length() - 1);
		else {
			newStr += str[i];
		}
	}
	return newStr;
}

std::string removeChar(std::string str, char del) {
	std::string newStr;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != del) {
			newStr += str[i];
		}
	}
	return newStr;
}
