#pragma once
#include "Component.h"
#include "TextComponent.h"
#include <cstring>
#include <sstream>

using namespace std;

class Pontuacao
{
public:
	Pontuacao(TextComponent *text);
	void incrementar_pontuacao(int value);
	void incrementar_pontuacao();
	const int get_score();
	~Pontuacao();
private:
	string to_string(int value);
	int score_;
	string text_score_;
	TextComponent *text_;
};

