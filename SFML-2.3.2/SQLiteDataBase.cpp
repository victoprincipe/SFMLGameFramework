#include "SQLiteDataBase.h"

using namespace std;


SQLiteDataBase::SQLiteDataBase()
{	
	create_table();
}

string toString(int data_int) {
	string result;
	stringstream convert;

	convert << data_int;

	return convert.str();
}

string toString(float data_float) {
	string result;
	stringstream convert;

	convert << data_float;

	return convert.str();
}

string toString(double data_double) {
	string result;
	stringstream convert;

	convert << data_double;
	
	return convert.str();
}

void SQLiteDataBase::update_row(string key, string values) {
	string sqlCommand = "UPDATE Data SET " + values + " WHERE Name = " + key + ";";

	const char *sqlUpdate = sqlCommand.c_str();

	if (sqlite3_exec(db, sqlUpdate, NULL, NULL, &error) != 0) {
		cerr << "Erro ao executar o comando SQL: " << sqlite3_errmsg(db) << endl << endl;
		sqlite3_free(error); //libera recursos
	} else {
		cout << "registro com chave " << key << " alterado com sucesso\n";
	}
}

void SQLiteDataBase::save_data(const char * name, int data_int, float data_float, double data_double)
{	
	string key = "'" + string(name) + "'";
	string values = 		  
		toString(data_int) + ", "
		+ toString(data_float) + ", "
		+ toString(data_double) + ");";
	string sqlCommand = "INSERT INTO Data VALUES(" + key + ", "+ values;
	
	const char *sqlInsert = sqlCommand.c_str();	

	if (sqlite3_exec(db, sqlInsert, NULL, NULL, &error) != 0)
	{
		// update row
		values = "DATA_INT = " + toString(data_int) + ", " +
			"DATA_FLOAT = " + toString(data_float) + ", " +
			"DATA_DOUBLE = " + toString(data_double);
		update_row(key,values);		
	}
	else
	{
		cout << "Registro inserido com sucesso\n";
	}
}

void SQLiteDataBase::save_data(const char * name, int data_int)
{
	string key = "'" + string(name) + "'";
	string values =
		toString(data_int) + ", "
		+ toString(0.0f) + ", "
		+ toString(0.0) + ");";
	string sqlCommand = "INSERT INTO Data VALUES(" + key + ", " + values;

	const char *sqlInsert = sqlCommand.c_str();

	if (sqlite3_exec(db, sqlInsert, NULL, NULL, &error) != 0)
	{
		// update row
		values = "DATA_INT = " + toString(data_int) + ", " +
			"DATA_FLOAT = " + toString(0.0f) + ", " +
			"DATA_DOUBLE = " + toString(0.0);
		update_row(key, values);
	}
	else
	{
		cout << "Registro inserido com sucesso\n";
	}
}

bool is_equal(string str1, string str2) {	
	return str1.compare(str2) == 0 ? true : false;
}

int callback(void *NotUsed, int argc, char **argv,
	char **azColName) {

	NotUsed = 0;

	for (int i = 0; i < argc; i++) {

		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");

	return 0;
}

bool SQLiteDataBase::find_row(const char * name) {	
	string str1(name);
	string str2;
	bool row_founded;
	int rc; 		
	row_founded = false;		

	// imprime os dados da tabela
	//rc = sqlite3_exec(db, "SELECT * FROM Data", callback, 0, &error);

	rc = sqlite3_prepare_v2(db, "SELECT * FROM Data", -1, &stmt, 0);

	if (rc != SQLITE_OK) {
		cout << "Falha na busca do dado %s", sqlite3_errmsg(db);
	}	

	do {
		rc = sqlite3_step(stmt);

		if (rc == SQLITE_ROW) {			
			str2 = string((const char*)sqlite3_column_text(stmt, 0));			
			row_founded = is_equal(str1, str2);						
		}
		else {						
			break;
		}

	} while (!row_founded);

	return row_founded;
}

int SQLiteDataBase::load_int_data(const char * name)
{	
	int value_fetched = 0;	
	
	if (find_row(name)) {
		value_fetched = sqlite3_column_int(stmt, 1);
	} else {
		cout << "Data " + string(name) + " not found\n";
	}
			
	return value_fetched;
}

float SQLiteDataBase::load_float_data(const char * name)
{	
	float value_fetched = 0;	

	if (find_row(name)) {
		value_fetched = (float) sqlite3_column_double(stmt, 2);
	}
	else {
		cout << "Data " + string(name) + " not found\n";
	}

	return value_fetched;
}

double SQLiteDataBase::load_double_data(const char * name)
{
	float value_fetched = 0;

	if (find_row(name)) {		
		value_fetched = sqlite3_column_double(stmt, 3);
	}
	else {
		cout << "Data " + string(name) + " not found\n";
	}	

	return value_fetched;
}

void SQLiteDataBase::close()
{
	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

void SQLiteDataBase::open()
{
	if (sqlite3_open(file_name_, &db) == 0)
	{
		cout << "Conexão realizada com sucesso\n";
	}
	else
	{
		cerr << "Erro ao abrir o banco de dados SQLite3: " << sqlite3_errmsg(db) << endl << endl;
		sqlite3_close(db);		
	}
}

void SQLiteDataBase::create_table()
{
	const char *sqlCreateTable = "CREATE TABLE IF NOT EXISTS Data (Name TEXT PRIMARY KEY, DATA_INT INT, DATA_FLOAT REAL, DATA_DOUBLE REAL);";

	if (sqlite3_exec(db, sqlCreateTable, NULL, NULL, &error) != 0)
	{
		cerr << "Erro ao executar o comando SQL: " << sqlite3_errmsg(db) << endl << endl;
		sqlite3_free(error); //libera recursos
	}
	else
	{
		cout << "Tabela criada com sucesso\n";
	}
}

SQLiteDataBase::~SQLiteDataBase()
{
	sqlite3_finalize(stmt);
	sqlite3_close(db);
}