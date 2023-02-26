#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <memory>
#include <windows.h>
#include <mutex>
#include <cstdlib>
#include <map>
#include <algorithm>
#include "IParser.h"
#include "Parser.h"

int main(int argc, char** argv) {//argc counter  и сами аргументы
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	if (argc > 1) {
		std::string filename = std::string(argv[0]);//если аргументов больше 1, бери по индексу 1
		std::cout << filename << std::endl;//выводим
		std::ifstream fin(filename);//открываем файл ини
	}
	else {
		std::cout << "Only one argument was provaded" << std::endl;
	}
	std::string file = "parser.ini";
	std::string file2 = "text.ini";
	Parser ini;
	std::cout << ini.getStringFromFile(file).c_str() << std::endl;
	std::cout << "\n" << std::endl;

	ini.ReadINI(file);
	ini.PrintINI();
	Sleep(2000);
	system("cls");
	ini.WriteINI(file);
	Sleep(3000);
	system("cls");
	ini.ALLMethod();





}
