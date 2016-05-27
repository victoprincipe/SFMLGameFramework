#pragma once
class GameDataBase
{
public:	
	virtual void open() = 0;
	virtual void save_data(const char* name, int data_int, float data_float, double data_double) = 0;
	virtual void save_data(const char* name, int data_int) = 0;	
	virtual int load_int_data(const char* name) = 0;
	virtual float load_float_data(const char* name) = 0;
	virtual double load_double_data(const char* name) = 0;				
	virtual void close() = 0;
};

