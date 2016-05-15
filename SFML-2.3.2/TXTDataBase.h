#pragma once
#include <iostream>
#include <fstream>
#include "GameDataBase.h"

class TXTDataBase :
	public GameDataBase
{
public:
	TXTDataBase();
	bool open(const char* file_name) override;
	bool save_data(const char* name, const char* data) override;
	std::string load_data(const char* name) override;
	bool close() override;
	~TXTDataBase();
private:
	std::string getValue(const char*name);
	std::fstream file_;
};

