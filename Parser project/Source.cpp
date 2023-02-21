#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <memory>
#include <windows.h>
#include <fstream>
#include "Parser.h"
#include "Parser2.h"

int main(int argc, char** argv) {//argc counter  � ���� ���������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc > 1) {
		std::string filename = std::string(argv[1]);//���� ���������� ������ 1, ���� �� ������� 1
		std::cout << filename << std::endl;//�������
		std::ifstream fin(filename);//��������� ���� ���
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
	//std::string line;//������ ���� ����� ������������ ����
	//std::string path = "parser.ini";//���� � �����
	//std::string path2 = "output.txt";//���� � �����, � ������� ����� ����������
	//std::fstream fin;
	//std::fstream fout;
	//fin.open(path, std::fstream::in);//������� ���� ��� ������
	//if (!fin.is_open()) {
	//	std::cout << "File not open!!" << std::endl;
	//}
	//else {
	//	std::cout << "File is open!!" << std::endl;//���� ���� ������
	//	while (!fin.eof()) { //���� ���� �� ��������
	//		std::getline(fin, line);//������ ��� ������ ����� 
	//		std::cout << line << std::endl;//������� getline(), ������� ��������� ����� ��� ������ � ����������
	//	}//������ �� ����� ��� �������
	//}
	//fout.open(path2, std::fstream::out);//������� ���� ��� ������
	//if (!fout.is_open()) {
	//	std::cout << "File not open!!" << std::endl;
	//}
	//else {
	//	std::cout << "File is open!!" << std::endl;//���� ���� ������
	//	fout << line << std::endl;
	//}
	//fin.close();//��������� ����
	//fout.close();//��������� ����
	


	//std::ifstream fin("parser.ini");
	//if (!fin) {
	//	std::cerr << "Failed to open\n";
	//}
	//std::string section;
	//fin >> section;
	//bool foundSection = (section[0] = '[');
	////] != section.size();
	//char c = fin.get();//������� ������
	//std::string keyvalue;
	//fin >> keyvalue;//������� �����
	////��������� �� ��� ������ key value
	//fin.close();//�� �������� ��������� ����


	//std::ifstream fin("output.txt");
	//if (!fin) {
	//	std::cerr << "Failed to open\n";
	//}
	//std::string section;
	//fin >> section;
	//bool foundSection = (section[0] = '[');
	////] != section.size();
	//char c = fin.get();//������� ������
	//std::string keyvalue;
	//fin >> keyvalue;//������� �����
	////��������� �� ��� ������ key value
	//fin.close();//�� �������� ��������� ����

	//std::ofstream fout("output.txt");
	//fout << section << "\n" << keyvalue << "\n";
	//fout.close();

}
