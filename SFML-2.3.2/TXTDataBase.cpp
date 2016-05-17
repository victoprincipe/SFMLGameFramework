#include "TXTDataBase.h"
#include <sstream>
#include <vector>


TXTDataBase::TXTDataBase()
{
}

bool TXTDataBase::open(const char* file_name) {
	file_.open(file_name, std::fstream::in | std::fstream::out | std::fstream::app);

	return file_.is_open();
}

bool TXTDataBase::close() {
	file_.close();

	return !file_.is_open();
}

bool is_equals(const char* name1, const char* name2) {
	std::string str1(name1);
	std::string str2(name2);
	bool is_equal = false;

	if (str1.compare(str2) == 0) {
		is_equal = true;
	}
	return is_equal;
}

bool contains_name(const char * file_name, const char * name) {
	std::ifstream load(file_name, std::ifstream::in);
	bool contains = false;

	char temp[256];

	if (load.is_open()) {

		while (load.good()) {
			load.getline(temp, 256, ':');
			if (is_equals(temp, name)) {
				contains = true;
				break;
			}
			else {
				load.getline(temp, 256);
			}
		}
		load.close();
	}

	return contains;
}

/*
long erase_line(std::fstream& overrided, const char * name) {
long pos;
char temp[256];
while (overrided.good()) {
overrided.getline(temp, 256, ':');
if (is_equals(temp, name)) {
long numb_character = 0;
char c;
while ((c = overrided.get()) != '\n') {
numb_character++;
}
numb_character += std::string(name).size();
pos = overrided.tellp();
pos -= numb_character;
break;
}
}
return pos;
}
void override_data(const char * file_name, const char * name, void * data) {
std::fstream overrided(file_name, std::fstream::out | std::fstream::in);
if (overrided.is_open()) {
overrided.seekg(erase_line(overrided, name));
overrided << name << ':' << data << '\n';
}
}*/



bool TXTDataBase::save_data(const char * name, const char* data)
{
	bool success = false;
	if (file_.is_open()) {
		file_ << name << ":" << data << "\n";
		success = true;
	}

	return success;
}



std::vector<std::string> split(std::string str, char delimiter) {
	std::vector<std::string> internal;
	std::stringstream ss(str);
	std::string tok;

	while (getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}

	return internal;
}

std::string TXTDataBase::getValue(const char * name) {
	bool has_read = false;
	char temp[256];

	std::string value_str, name_str;
	if (file_.is_open()) {
		while (!file_.eof()) {

			file_.getline(temp, 256, '\n');
			std::vector<std::string> vector = split(std::string(temp), ':');
			if (vector.size() == 2) {
				name_str = vector.at(0);
				value_str = vector.at(1);
				if (name_str.compare(name) == 0) {
					has_read = true;
					break;
				}
			}
		}
	}

	if (!has_read) {
		value_str = "not read";
	}

	return value_str;
}

std::string TXTDataBase::load_data(const char * name)
{
	file_.clear();
	file_.seekp(0, file_.beg);
	return getValue(name);
}


TXTDataBase::~TXTDataBase()
{
}