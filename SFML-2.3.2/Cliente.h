#pragma once
#include <string>

using namespace std;

class Cliente
{
public:
	Cliente();
	virtual ~Cliente();

	string &getNome() { return this->nome; };
	void setNome(string n) { this->nome = n; };

	int getIdade() { return this->idade; };
	void setIdade(int i) { this->idade = i; };
private:
	string nome;
	int idade;
};