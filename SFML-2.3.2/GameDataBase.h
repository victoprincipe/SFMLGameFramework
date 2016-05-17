#pragma once
#include <string>
class GameDataBase
{
public:
	virtual bool open(const char* file_name) = 0;
	virtual bool save_data(const char* name, const char* value) = 0;
	virtual std::string load_data(const char* name) = 0;
	virtual bool close() = 0;
};
