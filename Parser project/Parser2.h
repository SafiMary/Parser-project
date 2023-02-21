#pragma once
#include <map>
#include <string>
#include "Parser.h"
class Parser2: public Parser{
public:
Parser2(std::fstream& File);
~Parser2();
void addPath(std::string Path)override;
void Clear()override;
size_t GetSize() const override;

void View()override;
bool WriteINI(const std::string& path)override;

bool ReadConfig(const std::string& filename, std::map<std::string, std::string> content,const char* section)override;


private:
	std::map<std::string, std::map<std::string, std::string>> _Map;//мапа мап, где хранится номер секции и вектор с ключом значения
	//std::map<std::string, std::string> _sections;//мапа ключ значение
	std::fstream& File;
};

