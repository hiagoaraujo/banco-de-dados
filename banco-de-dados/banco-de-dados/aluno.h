#pragma once
#include "turma.h"
#include <string>
using namespace std;


class aluno
{
	turma *MyTurma;
	string nome_aluno, rua, bairro, cidade, email;
	int matricula, telefone, cpf;

public:
	aluno(void);
	~aluno(void);
	void imprime();// imprime parametros.
};

