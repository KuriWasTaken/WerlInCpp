#include <iostream>
#include <string>
#include <fstream>
#include "Functions.h"


std::string tokens[2] = {"output", "define"};
using namespace std;
void LLEX(std::string File) {
	std::string vars[9999] = {};
	int lineCounter = 0;
	int varCount = 0;
	std::ifstream file(File);
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			lineCounter += 1;
			std::string x = line.c_str();
			if (x.find(tokens[0]) != std::string::npos && x.find("(") != std::string::npos && x.find(")") != std::string::npos && x.find(";") != std::string::npos) { //Output
				if (x.find('"') != std::string::npos || x.find("'") != std::string::npos) { //String
					std::string xX = x.replace(x.find("("), 1, "-"); xX = xX.replace(xX.find(")"), 1, "-"); xX = removeFinalCharOfType(xX, *";");
					std::string arr[3];
					splitStrByDelimeter(xX, *"-", arr);
					std::cout << removeParameters(arr[1]) << std::endl;
				}
				else if (x.find("{") != std::string::npos && x.find("}") != std::string::npos) {
					std::string xX = x.replace(x.find("("), 1, "-"); xX = xX.replace(xX.find(")"), 1, ""); xX = removeFinalCharOfType(xX, *";");
					std::string arr[2];
					splitStrByDelimeter(xX, *"-", arr);
					bool varExists = false;
					for (int i = 0; i < 9999; i++) {
						std::string arrT[2];
						splitStrByDelimeter(vars[i], *":", arrT);
						std::string newName = removeChar(arr[1], *"{"); newName = removeChar(newName, *"}"); newName = removeChar(newName, *" ");
						std::string something = arr[1];
						if (something.find("{" + arrT[0] + "}") != std::string::npos) {
							if (arrT[1][0] == '"' && arrT[1][0] == '"') {
								std::cout << removeParameters(arrT[1]) << std::endl;
								varExists = true;
								break;
							}
							else if (arrT[1][arrT[1].length() - 1] == *"'" && arrT[1][arrT[1].length() - 1] == *"'") {
								std::cout << removeParameters(arrT[1]) << std::endl;
								varExists = true;
								break;
							}
						}
					}
					if (varExists == false) {
						std::cout << "ERROR! Variable does not exist at line:" << lineCounter << std::endl;
						exit(3);
					}
				}
				else {//Some other data type

				}
			}
			else if (x.find(tokens[1]) != std::string::npos && x.find("=") != std::string::npos && x.find(";") != std::string::npos) {
				std::string xX = x.replace(x.find("="), 1, "-"); xX = "-" + xX; xX = removeFinalCharOfType(xX, *";"); xX =  xX.replace(xX.find("define"), 6, "define -");
				std::string arr[4];
				splitStrByDelimeter(xX, *"-", arr);
				std::string var = removeParameters(arr[2]) + ":" + removeParameters(arr[3]);
				bool passed = true;
				for (int i = 0; i < 9999; i++) {
					std::string arrT[2];
					splitStrByDelimeter(vars[i], *":", arrT);
					if (removeParameters(arr[2]) == arrT[0]) {
						passed = false;
						break;
					}
				}
				if (passed) {
					vars[varCount] = var;
					varCount += 1;
				}
				else {
					std::cout << "ERROR! Variable already exists at line:" << lineCounter << std::endl;
					exit(3);
				}
			}
			else if (x.find("{") != std::string::npos && x.find("}") != std::string::npos && x.find("=") != std::string::npos && x.find(";") != std::string::npos) {
				std::string xX = x.replace(x.find("{"), 1, ""); xX = xX.replace(xX.find("}"), 1, ""); xX = removeFinalCharOfType(xX, *";");
				std::string arr[2];
				splitStrByDelimeter(xX, *"=", arr);
				for (int i = 0; i < 9999; i++) {
					std::string arrT[2];
					splitStrByDelimeter(vars[i], *":", arrT);
					if (arrT[0] + " " == arr[0] || arrT[0] == arr[0]) {

						break;
					}
				}
			}
		}
	}
}
