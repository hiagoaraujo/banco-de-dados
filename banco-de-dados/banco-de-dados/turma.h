#pragma once
#include "curso.h"

class turma
{
	curso *MyCurso;
	int codTurma, quantidade_alunos;
	int data;

public:
	turma(void);
	~turma(void);
	void insert_aluno();
	void remove_aluno();
	void update_aluno();
	void imprime(int);//imprime de acordo com o código de alunos
};

