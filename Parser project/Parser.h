#pragma once
#include <iostream>
#include <map>
class Parser{
public:
	Parser() = default;
	virtual ~Parser() = default;
	virtual void addPath(std::string Path) = 0;
	virtual void Clear() = 0;
	virtual size_t GetSize() const = 0;

	
	virtual void View() = 0;
	virtual bool WriteINI(const std::string& path) = 0;
	
	virtual bool ReadConfig(const std::string& filename, std::map<std::string, std::string> content, const char* section) = 0;
};

