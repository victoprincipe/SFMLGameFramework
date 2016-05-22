#pragma once
#include <string>
#include "GameDataBase.h"
#include "sqlite3.h"

class SQLiteDataBase :
	public GameDataBase
{
public:
	SQLiteDataBase();	
	virtual void save_data(const char* name, int data_int, float data_float, double data_double) override;
	virtual int load_int_data(const char* name) override;
	virtual float load_float_data(const char* name) override;
	virtual double load_double_data(const char* name) override;
	~SQLiteDataBase();
private:
	void open();
	void create_table();	
	bool find_row(const char* name);
	void update_row(std::string key, std::string values);
	sqlite3 * db;	
	sqlite3_stmt * stmt;
	const char * file_name_ = "game_data.db";
	char *error;
};

