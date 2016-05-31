#include "Pontuacao.h"


Pontuacao::Pontuacao(TextComponent * text)
{
	score_ = 0;
	text_ = text;
	text_score_ = text->get_text();
}

string Pontuacao::to_string(int value) {
	stringstream ss;
	ss << value;
	return ss.str();
}

void Pontuacao::incrementar_pontuacao(int value)
{
	score_ += value;

	text_->set_string(text_score_ + to_string(value));
}

void Pontuacao::incrementar_pontuacao()
{
	score_++;
	text_->set_string(text_score_ + to_string(score_));
}

const int Pontuacao::get_score()
{
	return score_;
}


Pontuacao::~Pontuacao()
{
}
