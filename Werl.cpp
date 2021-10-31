#include <iostream>
#include <fstream>
#include <string>
#include "llex.h"


inline bool fileExists(const std::string& name) {
	std::ifstream f(name.c_str());
	return f.good();
}

int main(int arg, char** argO)
{
	bool fileOpend = false;
	for (int i = 0; i < arg; i++) {
		std::string x = argO[i];
		if (x.find(".werl") != std::string::npos) {
			if (fileExists(x)) {
				LLEX(x);
				fileOpend = true;
			}
		}
	}
	if (fileOpend == false) {
		std::cout << "File does not exist!" << std::endl;
	}
}
