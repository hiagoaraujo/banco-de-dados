#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


	struct aluno
	{
		string NomeAluno, Rua, Bairro, Cidade, Email;
		int Matricula, Telefone, Cpf, CodTurma, position;
	};

	struct turma
	{
		int CodTurma, Data, position, CodCurso;
		string NomeTurma;
	};

	struct curso
	{
		int CodCurso, position;
		string NomeCurso;
	};

//variaveis 
int a=0;//variavel de contador de alunos
int t=0;//variavel de contador de turmas
int c=0;//variavel de contador de cursos

aluno alunos[60];
turma turmas[20];
curso cursos[10];

int find_aluno(int mat)
{
	int temp = -1;
	for(int i=0; i<a; i++)
	{ 
		if(mat==alunos[i].Matricula && alunos[i].Matricula != -1)
			temp= i;
	
	}
	return temp;
}

int find_turma(int cod)
{
	int temp = -1;
	for(int i=0; i<t; i++)
	{ 
		if(cod==turmas[i].CodTurma )
			temp= i;

	}
	return temp;
}

int find_curso(int cod)
{
	int temp=-1;
	for(int i=0; i<c; i++)
	{ 
		if(cursos[i].CodCurso == cod)
			temp =i;
	}
	return temp;
}


void insert_aluno()
{
	cout << "Numero de matricula do aluno: "<<a<<endl;
	alunos[a].Matricula=a;
	fflush(stdin); // LIMPAR O CACHE DE ENTRADA;
	cout << "\nDigite o nome do aluno a ser inserido: ";
	getline(cin, alunos[a].NomeAluno);
	cout << "Digite o cpf do aluno: ";
	cin >> alunos[a].Cpf;
	cout << "Digite o email do aluno: ";
	cin >> alunos[a].Email;
	fflush(stdin); // LIMPAR O CACHE DE ENTRADA;
	cout << "Digite a rua do aluno: ";
	getline(cin, alunos[a].Rua);
	cout << "Digite o bairro do aluno: ";
	getline(cin, alunos[a].Bairro);
	cout << "Digite a cidade do aluno: ";
	getline(cin, alunos[a].Cidade);
	fflush(stdin); // LIMPAR O CACHE DE ENTRADA;
	cout << "Digite o telefone do aluno:";
	cin >> alunos[a].Telefone;
	cout << "Informe o codigo da turma a qual esse aluno pertence :";
	cin >>	alunos[a].CodTurma;
	alunos[a].position = a;
	a++;
}
void insert_turma()
{
	fflush(stdin);
	cout << "codigo desta turma: "<<t<<endl;;
	turmas[t].CodTurma = t;
	fflush(stdin);
	cout << "\nDigite o nome da turma a ser inserida: ";
	getline(cin, turmas[t].NomeTurma);
	cout << "Digite a data da criacao dessa turma (DDMMAAAA): ";
	cin >> turmas[t].Data;
	cout << "Informe o codigo do curso a que esta turma pertence :";
	cin  >>turmas[t].CodCurso;
	turmas[t].position = t;
	t++;
}
void insert_curso()
{
	cout << "Pronto para criar um novo curso? Siga as instrucoes:\n";
	cout << "Codigo do novo curso: "<<c<<endl;;
	cursos[c].CodCurso = c;
	fflush(stdin);  // LIMPAR O CACHE DE ENTRADA;
	cout<<"Digite o nome do novo curso:"<<endl;
	getline(cin, cursos[c].NomeCurso);
	cursos[c].position = c;
	c++;
}



/* 
 * Funcao responsavel por remover um aluno do vetor alunos. Recebe como argumento
 * o inteiro Compara que eh utilizado para localizar o aluno no vetor e o char op
 * que indica com que informacao o Compara esta comparando. Caso op seja igual a 'm'
 * a funcao esta localizando o aluno pelo seu numero de matricula, caso op seja igual
 * a 't'  funcao esta localizando o aluno pela sua turma.
 */

void
remove_aluno(int Compara, char op)
{
	int localizado = 0;

	for (int i = 0; i < a; i++)
	{
		if (op == 'm')
		{
			if (Compara == alunos[i].Matricula)
			{
				localizado = 1;
			}
		}

		if (op == 't')
		{
			if (Compara == alunos[i].CodTurma)
			{
				localizado = 1;
			}
		}
		
		if (localizado == 1)
		{
			 for (int j = i; j < a - 1; j++)
			 {
				 alunos[j].Matricula = alunos[j+1].Matricula;
				 alunos[j].Cpf = alunos[j+1].Cpf;
				 alunos[j].CodTurma = alunos[j+1].CodTurma;
				 alunos[j].Telefone = alunos[j+1].Telefone;
				 alunos[j].position = alunos[j+1].position;

				 strcpy(alunos[j+1].NomeAluno, alunos[j].NomeAluno);
				 strcpy(alunos[j+1].Email, alunos[j].Email);
				 strcpy(alunos[j+1].Rua, alunos[j].Rua);
				 strcpy(alunos[j+1].Bairro, alunos[j].Bairro);
				 strcpy(alunos[j+1].Cidade, alunos[j].Cidade);
			 }
			 break;
		}
	}
	
	a--;
}


/* 
 * Funcao responsavel por remover uma turma do vetor turmas. Recebe como argumento
 * o inteiro Compara que eh utilizado para localizar a turma no vetor e o char op
 * que indica com que informacao o Compara esta comparando. Caso op seja igual a 't'
 * a funcao esta localizando a turma pelo seu codigo de curso, caso op seja igual
 * a 't' a funcao esta localizando a turma pelo codigo de turma. Ao remover uma turma
 * os alunos pertencentes a turma tambem sao removidos.
 */

void
remove_turma(int Compara, char op)
{
	int localizado = 0;

	for (int i = 0; i < t; i++)
	{
		if (op == 't')
		{
			if (Compara == turmas[i].CodTurma)
			{
				localizado = 1;
			}
		}
		
		if (op == 'c')
		{
			if (Compara == turmas[i].CodCurso)
			{
				localizado = 1;
			}
		}


		if (localizado == 1)
		{
			 for (int j = i; j < t - 1; j++)
			 {
				 turmas[j].CodTurma = turmas[j+1].CodTurma;
				 turmas[j].Data = turmas[j+1].Data;
				 turmas[j].CodCurso = turmas[j+1].CodCurso;
				 turmas[j].position = turmas[j+1].position;

				 strcpy(turmas[j+1].NomeTurma, turmas[j].NomeTurma);
			 }
			 break;
		}
	}
	
	t--;

	for (int i = 0; i < a; i++)
	{
		if (Compara == alunos[i].CodTurma)
		{ 
			remove_aluno(Compara, 't');
		}
	}
}


/* 
 * Funcao responsavel por remover um curso do vetor cursos. Recebe como argumento
 * o inteiro Compara que eh utilizado para localizar o curso no vetor. Ao remover  
 * um curso as turmas pertencentes ao curso tambem  sao removidas.
 */

void remove_curso(int Compara)
{
	for (int i = 0; i < c; i++)
	{
		if (Compara == cursos[i].CodCurso)
		{
			 for (int j = i; j < c - 1; j++)
			 {
				 cursos[j].CodCurso = cursos[j+1].CodCurso;
				 cursos[j].position = cursos[j+1].position;

				 strcpy(cursos[j+1].NomeCurso, cursos[j].NomeCurso);
			 }
			 break;
		}
	}
	
	c--;

	for (int i = 0; i < t; i++)
	{
		if (Compara == turmas[i].CodCurso)
		{ 
			remove_turma(Compara, 'c');
		}
	}
}


void consulta_aluno(int cod)
{
        system("cls");
	char nome[20];
	int i,pos = -1;
	cout << "Digite o nome completo do aluno a ser encontrado: ";
	fflush(stdin);
	gets_s(nome);
	for(i = 0 ; i < a ; i++)
	{
		if(strcmp(nome,alunos[a].NomeAluno) == 0)
			pos = i;
	}
	if(pos != -1)
	{
		 cout << "\n\nDados do aluno pequisado: ";
         cout << "\n\nNome: " << alunos[a].NomeAluno << "\nCPF: ";
         cout << alunos[a].Cpf << "\nCodigo da turma: " << alunos[a].CodTurma;
         cout << "\nEmail: " <<alunos[a].Email;
         cout << "\n\nRua: " << alunos[a].Rua << "\nBairro: " << alunos[a].Bairro;
         cout << "\nTelefone: " << alunos[a].Telefone;
         cout << " \nCidade: " << alunos[a].Cidade << "\n\n"; 
	}
	else
        {
		cout << "\n\nAluno não cadastrado!!!"; 
        }
}

void consulta_turma(int cod)
{
        system("cls");
	char turma[20];
	int i,pos = -1;
	cout << "Digite o codigo da turma a ser encontrado: ";
	fflush(stdin);
	gets_s(turma);
	for(i = 0 ; i < t ; i++)
	{
		if(strcmp(curso,turmas[i].CodTurma) == 0)
			pos = i;
	}
	if(pos != -1)
	{
                cout << "\n\nDados da turma pequisado: ";
                cout << "\n\nNome da turma: " << turmas[t].NomeTurma << "\nData da criação da turma:";
                cout <<  turmas[t].Data << "\nCodigo do curso: " << turmas[t].CodCurso;
                cout << "\n\n"; 
	}
	else
        {
		cout << "\n\nTurma não cadastrado!!!";
        }
}
void consulta_curso(int cod)

{
        system("cls");
	char curso[20];
	int i,pos = -1;
	cout << "Digite o codigo do curso a ser encontrado: : ";
	fflush(stdin);
	gets_s(curso);
	for(i = 0 ; i < c ; i++)
	{
		if(strcmp(curso,cursos[c].CodCurso) == 0)
			pos = i;
	}
	if(pos != -1)
	{
                 cout << "\n\nDados do curso pequisado: ";
                 cout << "\n\nCodigo do curso: " << cursos[c].CodCurso << "\nNome do curso:";
                 cout << cursos[c].NomeCurso;
                 cout << "\n\n"; 
	}
	else
        {
		cout << "\n\nCurso não cadastrado!!!";
        }
}



void update_turma()
{
	int m;
	int choose;	
	int aux=0;
	system("CLS");
	cout << "Digite o codigo da turma a ser alterada\n";
	cin >> m;
	for(int i=0;i<t;i++)
		if(m==turmas[i].CodTurma)
			aux = 1;
	if(aux == 1){
		do{
			system("CLS");
			cout << "        ESCOLHA QUAL OPCAO QUER ALTERAR \n";
			cout << "\n   [1] Alterar Nome da turma";
			cout << "\n   [2] Alterar Codigo da turma";
			cout << "\n   [3] Alterar data de criacao desta turma (DDMMAAAA)";
			cout << "\n   [4] Alterar Codigo do curso a que esta turma pertence";
			cout << "\n   [5] Voltar ao menu principal\n";
			cin >> choose;
			fflush(stdin); // LIMPAR O CACHE DE ENTRADA;
			switch (choose)
			{
			case 1:  
				system("CLS");	
				cout << "\nDigite o nome da turma para ser alterado: ";
				getline(cin, turmas[m].NomeTurma);
				break;

			case 2:  
				system("CLS");
				cout << "Digite o codigo da turma: ";
				cin >> aux;	
				for(int j=0;j<t;j++){
					if(turmas[j].CodTurma == aux){
						cout << "\nCodigo de turma ja existente!\n";
						system("PAUSE");
						break;
					}
				}
				for(int i=0;i<a;i++) // altera o CodTurma de todos os alunos matriculados nessa turma
					if(alunos[i].CodTurma == turmas[m].CodTurma)
						alunos[i].CodTurma = aux;
				turmas[m].CodTurma = aux;
				break;

			case 3: 
				system("CLS");
				cout << "Novo data de criacao: "<<a<<endl;
				cin >> turmas[m].Data;
				fflush(stdin); // LIMPAR O CACHE DE ENTRADA;
				break;

			case 4: 
				system("CLS");
				cout << "Codigo do curso a que esta turma pertence :";
				cin >> turmas[m].CodCurso;
				fflush(stdin); // LIMPAR O CACHE DE ENTRADA;
				break;

			case 5:  //SAIR
				break;

			default:  //caso a opcao nao exista envia mensagem de erro
				system("CLS");
				cout << "Leia as intrucoes!";
				_getch();
				break;
			}

		}while (choose != 5);
	}
	else {
		cout<<"Turma nao encontrada\n";
		getch();
	}

}

void update_curso()
{
	int m;
	int choose;	
	int aux=0;
	system("CLS");
	cout << "Digite o codigo do curso a ser alterado\n";
	cin >> m;
	for(int i=0;i<c;i++)
		if(m==cursos[i].CodCurso)
			aux = 1;
	if(aux==1){
		do{
			system("CLS");
			cout << "        ESCOLHA QUAL OPCAO QUER ALTERAR \n";
			cout << "\n   [1] Alterar Nome do curso";
			cout << "\n   [2] Alterar Codigo do curso";
			cout << "\n   [3] Voltar ao menu principal\n";
			cin >> choose;
			fflush(stdin); // LIMPAR O CACHE DE ENTRADA;
			switch (choose)
			{
			case 1:  
				system("CLS");	
				cout << "\nDigite o nome do curso para ser alterado: ";
				getline(cin, cursos[m].NomeCurso);
				break;

			case 2:  
				system("CLS");
				cout << "Digite o codigo do curso: ";
				cin >> aux;	
				for(int j=0;j<c;j++){
					if(cursos[j].CodCurso == aux){
						cout << "\nCodigo de curso ja existente!\n";
						system("PAUSE");
						break;
					}
				}
				for (int i =0 ; i< t; i++)  // altera o CodCurso de todas as turmas deste curso
					if(turmas[i].CodCurso == cursos[m].CodCurso)
						turmas[i].CodCurso = aux;
				cursos[m].CodCurso = aux;
				break;		

			case 3:  //SAIR
				break;

			default:  //caso a opcao nao exista envia mensagem de erro
				system("CLS");
				cout << "Leia as intrucoes!";
				_getch();
				break;
			}

		}while (choose != 3);
	}
	else {
		cout << "Curso nao encontrado!\n";
		getch();
	}
}

void update_aluno()
{
	int m;
	int choose;	
	int aux=0;
	system("CLS");
	cout << "Digite a matricula do aluno a ser alterado\n";
	cin >> m;
	for(int i=0;i<a;i++)
		if(m==alunos[i].Matricula)
			aux = 1;
	if(aux == 1){
		do{
			system("CLS");
			cout << "        ESCOLHA QUAL OPCAO QUER ALTERAR \n";
			cout << "\n   [1] Alterar Nome";
			cout << "\n   [2] Alterar CPF";
			cout << "\n   [3] Alterar Matricula";
			cout << "\n   [4] Alterar Email";
			cout << "\n   [5] Alterar Rua";
			cout << "\n   [6] Alterar Bairro";
			cout << "\n   [7] Alterar Cidade";
			cout << "\n   [8] Alterar Telefone";
			cout << "\n   [9] Alterar Turma a qual pertence";
			cout << "\n   [10] Voltar ao menu principal\n";
			cin >> choose;
			fflush(stdin); // LIMPAR O CACHE DE ENTRADA;
			switch (choose)
			{
			case 1:  
				system("CLS");	
				cout << "\nDigite o nome do aluno para ser alterado: ";
				getline(cin, alunos[m].NomeAluno);
				break;

			case 2:  
				system("CLS");
				cout << "Digite o cpf do aluno: ";
				cin >> alunos[m].Cpf;		
				break;

			case 3: 
				system("CLS");
				cout << "Novo numero de matricula do aluno: "<<a<<endl;
				cin >> aux;
				fflush(stdin); // LIMPAR O CACHE DE ENTRADA;
				for(int i = 0; i<a ; i++)
					if (alunos[i].Matricula == aux){
						cout << "\nMatricula ja existente!\n";
						system("PAUSE");
						break;
					}
					alunos[m].Matricula = aux;

				break;

			case 4: 
				system("CLS");
				cout << "Digite o Email: ";
				cin >> alunos[m].Email;
				fflush(stdin); // LIMPAR O CACHE DE ENTRADA;
				break;

			case 5:  
				system("CLS");
				cout << "Digite a rua do aluno: ";
				getline(cin, alunos[m].Rua);
				break;

			case 6: 
				system("CLS");
				cout << "Digite o bairro do aluno: ";
				getline(cin, alunos[m].Bairro);
				break;

			case 7:  
				system("CLS");
				cout << "Digite a cidade do aluno: ";
				getline(cin, alunos[m].Cidade);
				break;

			case 8:  
				system("CLS");
				cout << "Digite o telefone do aluno: ";
				cin >> alunos[m].Telefone;
				break;
		
			case 9 :
				system("CLS");
				cout << "Digite o codigo da turma a ser alterado";
				cin >> alunos[m].CodTurma;
				break;

			case 10:  //SAIR
				break;

			default:  //caso a opcao nao exista envia mensagem de erro
				system("CLS");
				cout << "Leia as intrucoes!";
				_getch();
				break;
			}

		}while (choose != 10);
	}
	else{
		cout<<"Aluno nao encontrado!\n";
		getch();
	}
	
}





void main()
{
	int a=0, t=0, c=0, codigo=0;
	int choose;
	do {
		codigo=0;
		system("CLS");
		cout << "        MENU PRINCIPAL  \n";
		cout << "\n   [1] Inserir novo curso";
		cout << "\n   [2] Inserir nova turma";
		cout << "\n   [3] Inserir novo aluno\n";

		cout << "\n   [4] Remover curso";
		cout << "\n   [5] Remover turma";
		cout << "\n   [6] Remover aluno\n";

		cout << "\n   [7] Pesquisar curso";
		cout << "\n   [8] Pesquisar turma";
		cout << "\n   [9] Pesquisar aluno\n";

		cout << "\n   [10] Atualizar curso";
		cout << "\n   [11] Atualizar turma";
		cout << "\n   [12] Atualizar aluno\n";

		cout << "\n   [0] Sair\n";
		cin>>choose;


		switch (choose)
		{

		case 1:  //Inserir Curso
			system("CLS");
			insert_curso();
			break;

		case 2:  //Inserir turma
			system("CLS");
			insert_turma();
			break;

		case 3:  //Inserir aluno
			system("CLS");
			insert_aluno();
			break;

		case 4:  //remover Curso
			system("CLS");
			remove_curso();
			break;

		case 5:  //remover turma
			system("CLS");
			remove_turma();
			break;

		case 6:  //remover aluno
			system("CLS");
			remove_aluno();
			break;

		case 7:  //consultar Curso
			system("CLS");
			cout<<"Informe o codigo do curso:";
			cin>>codigo;
			consulta_curso(codigo);
			break;

		case 8:  //consultar turma
			system("CLS");
			cout<<"Informe o codigo da turma:";
			cin>>codigo;
			consulta_turma(codigo);
			break;

		case 9:  //Consultar aluno
			system("CLS");
			cout<<"Informe o codigo do aluno:";
			cin>>codigo;
			consulta_aluno(codigo);
			break;

		case 10:  //Atualizar Curso
			system("CLS");
			update_curso();
			break;

		case 11:  //]Atualizar turma
			system("CLS");
			update_turma();
			break;

		case 12:  //Atulizar aluno
			system("CLS");
			update_aluno();
			break;

		case 0:
			break;

		default:  //caso a opcao nao exista envia mensagem de erro
			system("CLS");
			cout << "Leia as intrucoes!";
			_getch();
			break;

		}
	} while (choose != 0);
}
