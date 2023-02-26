#pragma once
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

class Parser: public IParser{
public:
~Parser();
void Clear();
std::string getStringFromFile(const std::string& file);
bool ReadINI(const std::string& fileName);
bool WriteINI(const std::string& path);
void PrintINI();
void SaveINIfromFILE();
void ALLMethod();
void FindKeyinSection();
bool ExistSectionname();
bool ExistKey();
bool ExistValue();
bool FindValueKeysinSec();
void ChangeKeyValue();

private:
	std::map<std::string, std::map<std::string, std::string>> Map;
	std::string& replace_all(std::string& str, const std::string& old_value, const std::string& new_value);
};

