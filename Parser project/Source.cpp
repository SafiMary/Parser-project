#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <memory>
#include <windows.h>
#include <fstream>
#include "Parser.h"
#include "Parser2.h"

int main(int argc, char** argv) {//argc counter  и сами аргументы
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc > 1) {
		std::string filename = std::string(argv[1]);//если аргументов больше 1, бери по индексу 1
		std::cout << filename << std::endl;//выводим
		std::ifstream fin(filename);//открываем файл ини
	}
	else {
		std::cout << "Only one argument was provaded" << std::endl;
	}
	std::fstream fin;
	std::string path = "parser.ini";
	std::string path2 = "output.txt";
	std::map<std::string, std::string> name;
	std::map<std::string, std::map<std::string, std::string>> Map;


	Parser2* parser = new Parser2(fin);
	
	parser->addPath(path);
	parser->ReadConfig("parser.ini",name, "Section1");
	parser->WriteINI("parser.ini");
	parser->View();





	delete parser;
	//std::string line;//строка куда будет записываться файл
	//std::string path = "parser.ini";//путь к файлу
	//std::string path2 = "output.txt";//путь к файлу, в который будем записывать
	//std::fstream fin;
	//std::fstream fout;
	//fin.open(path, std::fstream::in);//открыли файл для чтения
	//if (!fin.is_open()) {
	//	std::cout << "File not open!!" << std::endl;
	//}
	//else {
	//	std::cout << "File is open!!" << std::endl;//если файл открыт
	//	while (!fin.eof()) { //пока файл не кончился
	//		std::getline(fin, line);//читаем все строки файла 
	//		std::cout << line << std::endl;//функция getline(), которая принимает поток для чтения и переменную
	//	}//вывели на экран что считали
	//}
	//fout.open(path2, std::fstream::out);//открыли файл для записи
	//if (!fout.is_open()) {
	//	std::cout << "File not open!!" << std::endl;
	//}
	//else {
	//	std::cout << "File is open!!" << std::endl;//если файл открыт
	//	fout << line << std::endl;
	//}
	//fin.close();//закрываем файл
	//fout.close();//закрываем файл
	


	//std::ifstream fin("parser.ini");
	//if (!fin) {
	//	std::cerr << "Failed to open\n";
	//}
	//std::string section;
	//fin >> section;
	//bool foundSection = (section[0] = '[');
	////] != section.size();
	//char c = fin.get();//считали секцию
	//std::string keyvalue;
	//fin >> keyvalue;//считали слово
	////разделить на две строки key value
	//fin.close();//не забывать закрывать файл


	//std::ifstream fin("output.txt");
	//if (!fin) {
	//	std::cerr << "Failed to open\n";
	//}
	//std::string section;
	//fin >> section;
	//bool foundSection = (section[0] = '[');
	////] != section.size();
	//char c = fin.get();//считали секцию
	//std::string keyvalue;
	//fin >> keyvalue;//считали слово
	////разделить на две строки key value
	//fin.close();//не забывать закрывать файл

	//std::ofstream fout("output.txt");
	//fout << section << "\n" << keyvalue << "\n";
	//fout.close();

}
