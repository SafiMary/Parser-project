#include "Parser2.h"
#include "Parser.h"
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

Parser2::Parser2(std::fstream& File): File(File){} //конструктор

Parser2::~Parser2() {//деструктор
    File.close();
}
void Parser2::addPath(std::string Path) { //добавить путь к файлу
	std::cout << "Путь к файлу определен" << std::endl;
	
}
void Parser2::Clear() {  //очистка мапы
	_Map.clear();
}      

size_t Parser2::GetSize() const {//геттер размера мап
	return _Map.size();
}


bool Parser2::ReadConfig(const std::string& filename, std::map<std::string, std::string> content, const char* section)//читать ини файл
{
	std::fstream infile(filename.c_str());
	if (!infile.is_open()) {
		std::cout << "File not open!!" << std::endl;
	}
	else {
		std::string line, key, value;
		int pos = 0;
		std::string Tsection = std::string("[") + section + "]";
		bool flag = false;
		while (getline(infile, line))
		{
			if (!flag)
			{
				pos = line.find(Tsection, 0);
				if (-1 == pos)
				{
					continue;
				}
				else
				{
					flag = true;
					getline(infile, line);
				}
			}
			if (0 < line.length() && '[' == line.at(0))
			{
				break;
			}
			if (value.length() > 0)
			{
				if (value[value.size() - 1] == '\r')
				{
					value[value.size() - 1] = '\0';
				}
			}
			content[key] = value;
		}
		infile.close();
		return true;
	}
}






void Parser2::View()//функция вывода на экран ини из мап
{
	for (auto it = _Map.begin(); it != _Map.end(); ++it)
	{
		std::cout << it->first.c_str() << std::endl;
		std::cout << '\n' << std::endl;
		for (auto v = it->second.begin(); v != it->second.end(); ++v)
		{
			std::cout << v->first.c_str() << std::endl;
			std::cout << " = " << std::endl;
			std::cout << v->second.c_str() << std::endl;
			std::cout << '\n' << std::endl;
		}
	}
}

bool Parser2::WriteINI(const std::string& path)//записать ини в мап
{
	std::fstream out_conf_file(path.c_str());
	if (!out_conf_file.is_open()) {
		std::cout << "File not open!!" << std::endl;
	}
	else {
		for (auto itr = _Map.begin(); itr != _Map.end(); ++itr)
		{
			out_conf_file << "[" << itr->first << "]" << std::endl;
			for (std::map<std::string, std::string>::iterator sub_itr = itr->second.begin();
				sub_itr != itr->second.end(); ++sub_itr)
			{
				out_conf_file << sub_itr->first << "=" << sub_itr->second << std::endl;
			}
		}

		out_conf_file.close();
		out_conf_file.clear();
		return true;
	}
}







