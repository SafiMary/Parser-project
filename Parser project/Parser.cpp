#include "Parser.h"
#include "IParser.h"



Parser::~Parser() {//����������
	Clear();
}
void Parser::Clear() { Map.clear(); }//������� ����


std::string& Parser::replace_all(std::string& str, const std::string& old_value, const std::string& new_value)//������ ������� �������� �����
{
	while (true)
	{
		std::string::size_type pos = 0;
		pos = str.find(old_value);
		if (pos == std::string::npos) break;

		str.replace(pos, old_value.length(), new_value);
	}
	return str;
}


static void TrimString(std::string& str)//������� ������
{
	str.erase(0, str.find_first_not_of(' '));//������� ������� ������� ������
	str.erase(str.find_last_not_of(' ') + 1);//������� ������� � ����� ������
}
std::string Parser::getStringFromFile(const std::string& file) {//������� ������ �� �����
	char* buffer = nullptr;//�����
	size_t size = 0;
	size_t readsize;
	FILE* fp = nullptr;//��������� �� ����
	fopen_s(&fp, file.c_str(), "r+");//��������� ��� ������ � ������. ���� ������ ������������.
	if (fp == nullptr)
	{
		return "���� ������\n";
	}
	fseek(fp, 0, SEEK_END);//����������� ��������� �� ��� ���� , �� 0 �� �����
	size = ftell(fp); //�������� ������ �����
	fseek(fp, 0, SEEK_SET);//����������� ��������� � ������ �����

	buffer = (char*)malloc(sizeof(char) * (size + 1));//�������� ������������ ������ ��� ������
	buffer[size] = '\0';

	readsize = fread(buffer, sizeof(char), size, fp);//������� ���� ���� � �����
	fclose(fp);//������� ����

	if (readsize < size)
	{
		buffer[readsize] = '\0';
	}

	std::string str((char*)buffer);
	free(buffer);//���������� ���������� ������
	return str;
}

bool Parser::ReadINI(const std::string& fileName)//������ ��� � ���������
{
	std::stringstream in_file;

	std::string content = getStringFromFile(fileName);
	if (content.empty()) return false;
	in_file << content;
	std::string line = "";
	std::map<std::string, std::string>* minimap = nullptr;
	size_t left;
	size_t right;
	size_t equal;

	while (getline(in_file, line))
	{
		if (line.empty()) continue;
		if ((std::string::npos != (left = line.find("["))) &&
			(line.npos != (right = line.find("]"))))
		{

			std::string root = line.substr(left + 1, right - left - 1);
			TrimString(root);
			if (!root.empty())
			{
				Map[root] = std::map<std::string, std::string>{};
				minimap = &(Map[root]);
			}
		}
		else if (std::string::npos != (equal = line.find("=")))
		{
			std::string key = line.substr(0, equal);
			size_t notePos = line.find(";");
			std::string value;
			if (std::string::npos != notePos)
			{
				value = line.substr(equal + 1, notePos - equal - 1);
			}
			else
			{
				value = line.substr(equal + 1, line.size() - 1);
			}
			TrimString(key);
			TrimString(value);
			if (minimap != nullptr && !key.empty())
			{
				(*minimap)[key] = value;
			}
		}
	}
	return true;
}


void Parser::PrintINI()//������� ������ �� ����� ��� �� ���
{
	for (auto it = Map.begin(); it != Map.end(); ++it)
	{
		std::cout << it->first.c_str() << std::endl;
		std::cout << '\n' << std::endl;
		for (auto vit = it->second.begin(); vit != it->second.end(); ++vit)
		{
			std::cout << vit->first.c_str() << std::endl;
			std::cout << " = " << std::endl;
			std::cout << vit->second.c_str() << std::endl;
			std::cout << '\n' << std::endl;
		}
	}
}

bool Parser::WriteINI(const std::string& path)//�������� ��� � ���
{
	std::ofstream out_file(path.c_str());
	if (!out_file) return false;

	for (auto itr = Map.begin(); itr != Map.end(); ++itr)
	{
		out_file << "[" << itr->first << "]" << std::endl;
		for (std::map<std::string, std::string>::iterator sub_itr = itr->second.begin();
			sub_itr != itr->second.end(); ++sub_itr)
		{
			out_file << sub_itr->first << "=" << sub_itr->second << std::endl;
		}
	}

	out_file.close();
	out_file.clear();
	return true;
}

void Parser::SaveINIfromFILE() {//������� ���������� ��� � ����
	std::string pathfile;
	std::fstream outfile;
	std::cout << "������� ���� ��� ���������� ������!" << std::endl;
	std::cin >> pathfile;
	outfile.open(pathfile, std::ios::binary | std::ios::in | std::ios::out);
	if (!outfile.is_open()) {
		std::cout << "File not open!!" << std::endl;
	}
	else {
		std::cout << "���� ��������!" << std::endl;
		for (auto itr = Map.begin(); itr != Map.end(); ++itr) {

			outfile << "[" << itr->first << "]" << std::endl;
			for (std::map<std::string, std::string>::iterator sub_itr = itr->second.begin();
				sub_itr != itr->second.end(); ++sub_itr)
			{
				outfile << sub_itr->first << "=" << sub_itr->second << std::endl;
			}
		}
	}
}


void Parser::FindKeyinSection() {//����� ����� � ������
	std::string  key;
	std::cout << "������� ����, ������� ������ �����: \n";
	std::cin >> key;
	for (auto itr = Map.begin(); itr != Map.end(); itr++) {
		for (std::map<std::string, std::string>::iterator sub_itr = itr->second.begin(); sub_itr != itr->second.end(); sub_itr++) {
			if (sub_itr->first == key) {
				std::cout << "���� ��������� � ��������� " << itr->first << std::endl;
			}
		}
	}
}
bool Parser::ExistSectionname() {//���������� �� ������
	std::string  sec;
	std::cout << "������� �������� ���������, ����� ������ ���������� �� �� � ����� \n";
	std::cin >> sec;
	if (Map.count(sec)) {
		std::cout << "����� ��������� ����������!" << std::endl; return 0;
	}
	else {
		std::cout << "��������� �� ����������!" << std::endl; return 0;
	}
}
bool Parser::ExistKey() {//  ���������� �� ����
	std::string  key;
	std::cout << "������� �������� �����, ����� ������ ���������� �� �� � ����� \n";
	std::cin >> key;
	for (auto itr = Map.begin(); itr != Map.end(); itr++) {
		for (std::map<std::string, std::string>::iterator sub_itr = itr->second.begin(); sub_itr != itr->second.end(); sub_itr++) {
			if (sub_itr->first == key) {
				std::cout << "����� ���� ����������!" << std::endl;
				return 0;
			}
		}
	}
	return 0;
}
bool Parser::ExistValue() {//���������� �� ��������
	std::string  value;
	std::cout << "������� �������� ��������, ����� ������ ���������� �� ��� � �����  \n";
	std::cin >> value;
	for (auto itr = Map.begin(); itr != Map.end(); itr++) {
		for (std::map<std::string, std::string>::iterator sub_itr = itr->second.begin(); sub_itr != itr->second.end(); sub_itr++) {
			if (sub_itr->second == value) {
				std::cout << "����� �������� ����������!" << std::endl;
				return 0;
			}

		}
	}
	return 0;
}
bool Parser::FindValueKeysinSec() {//����� �������� ����� � ������
	std::string root, key, value;
	std::cout << "������� ����: \n";
	std::cin >> key;
	std::cout << "������� ������: \n";
	std::cin >> root;
	for (auto itr = Map.begin(); itr != Map.end(); itr++) {
		for (std::map<std::string, std::string>::iterator sub_itr = itr->second.begin(); sub_itr != itr->second.end(); sub_itr++) {
			if (sub_itr->first == key) {
				std::cout << "�������� � ����� � ������ ������: " << sub_itr->second << std::endl; return 0;
			}
			else if (sub_itr->first != key) {
				{
					std::cout << "���� �� ���������� " << std::endl; return 0;
				}
			}
		}
	}
	return 0;
}
void Parser::ChangeKeyValue() {//�������� �������� ����� �� ����� ��� �������
	std::string root, key, value;
	std::cout << "������� ������: \n";
	std::cin >> root;
	std::cout << "������� ����: \n";
	std::cin >> key;
	std::cout << "������� ��������, ������� ������ ��������: \n";
	std::cin >> value;
	auto itr = Map.find(root);
	if (Map.end() != itr)
	{
		std::map<std::string, std::string>::iterator it = itr->second.find(key);
		if (it != itr->second.end())
		{
			it->second = value;
		}
		else
		{
			itr->second[key] = value;
		}
	}
	else
	{
		std::map<std::string, std::string> m;
		m[key] = value;
		Map[root] = std::move(m);
	}
	std::cout << "��������� �������!" << std::endl;
}

void Parser::ALLMethod() {
	do {
		std::cout << "�������� ����������� ��������: " << std::endl;
		std::cout << "1. � ����� ��������� ����� ����?" << std::endl;
		std::cout << "2. ���������� �� ���������? " << std::endl;
		std::cout << "3. ���������� �� ���� � �����?" << std::endl;
		std::cout << "4. ���������� �� �������� � �����?" << std::endl;
		std::cout << "5. ����� �������� � �����  � ������ ?" << std::endl;
		std::cout << "6. ���������� � ������ X � ��������� ����� Y �������� Z?" << std::endl;
		std::cout << "7. ��������� ����" << std::endl;
		size_t input;
		std::cin >> input;
		switch (input) {
		case 1: FindKeyinSection(); Sleep(3000); system("cls");
			break;
		case 2: ExistSectionname(); Sleep(3000); system("cls");
			break;
		case 3: ExistKey(); Sleep(3000); system("cls");
			break;
		case 4: ExistValue(); Sleep(3000); system("cls");
			break;
		case 5: FindValueKeysinSec(); Sleep(3000); system("cls");
			break;
		case 6: ChangeKeyValue(); Sleep(3000); system("cls");
			break;
		case 7: SaveINIfromFILE(); Sleep(3000); system("cls");
			break;
		default:
			std::cout << "Error!!"; Sleep(3000); system("cls");
			break;
		}
	} while (true);
}