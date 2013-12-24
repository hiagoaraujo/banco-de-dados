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



void remove_aluno(int m) // m é a matricula do aluno 
{ 
	int aux; 
	aux = find_aluno(m); //aux é a posição no vetor do aluno de matricula m 
	alunos[aux].Matricula = -1; 
}

void remove_turma(int m)// m é o codigo da turma 
{ 
	int aux; 
	aux = find_turma(m); //aux é a posição no vetor da turma de codigo m 
	turmas[aux].CodTurma = -1; 
	for(int i=0;i<a;i++) 
		if(alunos[i].CodTurma == m) 
			remove_aluno(alunos[i].CodTurma); 
}

void remove_curso(int m) // m é o codigo do curso a ser excluido 
{ 
	int aux; 
	aux = find_curso(m); // aux é a posição do vetor do curso de codigo m 
	cursos[aux].CodCurso = -1; 
	for(int i=0;i<t;i++){ // exlcui todas as turmas desse curso 
		if(turmas[i].CodCurso == m) 
			remove_turma(turmas[i].CodTurma); 
	} 
}


void consulta_aluno(int cod)
{
    system("cls");
int student = find_aluno(cod);

	if(student== -1)
	{
		cout<<"Aluno nao encontrado "<<endl;
		_getch();
	}
	else
	{
	cout <<"\nNome: "<<alunos[student].NomeAluno;
	cout <<"\nMatricula:"<<alunos[student].Matricula;
	cout <<"\nCPF:"<<alunos[student].Cpf;
	cout <<"\nEndereco: \nRua:"<<alunos[student].Rua;
	cout <<"\nBairro"<<alunos[student].Bairro;
	cout <<"\nCidade"<<alunos[student].Cidade;
	cout <<"\nE-mail"<<alunos[student].Email;
	cout <<"\nTelefone:"<<alunos[student].Telefone;
	cout <<"\nTurma: "<<turmas[find_turma(alunos[student].CodTurma)].NomeTurma;
	_getch();
	}
}

void consulta_turma(int cod)
{
    system("cls");
	int classe = find_turma(cod);
	if(classe==-1)
	{
		cout<<"Turma nao encontrada "<<endl;
			cout<<endl;
		system("pause");
	}
	else
	{

	cout <<"\nNome da turma:"<<turmas[classe].NomeTurma;
	cout <<"\nCodigo da turma:"<<turmas[classe].CodTurma;
	cout <<"\nCurso :"<<cursos[find_curso(turmas[classe].CodCurso)].NomeCurso;
			cout<<endl;
	system("pause");
	}
}
void consulta_curso(int cod)

{
    system("cls");
	int curse = find_curso(cod);
	if(curse==-1)
	{
		cout<<"Curso nao encontrado "<<endl;
		system("pause");
	}
	else
	{
	cout <<"\nNome do curso:"<<cursos[curse].NomeCurso;
	cout <<"\nCodigo do curso:"<<cursos[curse].CodCurso;
		cout<<endl;
		system("pause");
	}
}



void update_turma()
{
	int m;
	int choose;	
	int aux;
	system("CLS");
	cout << "Digite o codigo da turma a ser alterada\n";
	cin >> m;
	do{
		system("CLS");
		cout << "        ESCOLHA QUAL OPCAO QUER ALTERAR \n";
		cout << "\n   [1] Alterar Nome da turma";
		cout << "\n   [2] Alterar Codigo da turma";
		cout << "\n   [3] Alterar data de criacao desta turma (DDMMAAAA)";
		cout << "\n   [4] Alterar Codigo do curso a que esta turma pertence";
		cout << "\n   [5] Voltar ao menu principal\n";
		cin >> choose;
		switch (choose)
		{
		case 
			1:  
			system("CLS");	
			cout << "\nDigite o nome da turma para ser alterado: ";
			fflush(stdin);
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

void update_curso()
{
	int m;
	int choose;	
	int aux;
	system("CLS");
	cout << "Digite o codigo da turma a ser alterada\n";
	cin >> m;
	do{
		system("CLS");
		cout << "        ESCOLHA QUAL OPCAO QUER ALTERAR \n";
		cout << "\n   [1] Alterar Nome do curso";
		cout << "\n   [2] Alterar Codigo do curso";
		cout << "\n   [3] Voltar ao menu principal\n";
		cin >> choose;
		switch (choose)
		{
		case 1:  
			system("CLS");	
			cout << "\nDigite o nome do curso para ser alterado: ";
			fflush(stdin);
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

void update_aluno()
{
	int m;
	int choose;	
	int aux;
	system("CLS");
	cout << "Digite a matricula do aluno a ser alterado\n";
	cin >> m;
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
		switch (choose)
		{
		case 1:  
			system("CLS");	
			cout << "\nDigite o nome do aluno para ser alterado: ";
			fflush(stdin);
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
			fflush(stdin);
			cin >> alunos[m].Email;
			fflush(stdin); // LIMPAR O CACHE DE ENTRADA;
			break;

		case 5:  
			system("CLS");
			cout << "Digite a rua do aluno: ";
			fflush(stdin);
			getline(cin, alunos[m].Rua);
			break;

		case 6: 
			system("CLS");
			cout << "Digite o bairro do aluno: ";
			fflush(stdin);
			getline(cin, alunos[m].Bairro);
			break;

		case 7:  
			system("CLS");
			cout << "Digite a cidade do aluno: ";
			fflush(stdin);
			getline(cin, alunos[m].Cidade);
			break;

		case 8:  
			system("CLS");
			cout << "Digite o telefone do aluno: ";
			cin >> alunos[m].Telefone;
			break;
		
		case 9:
			system("CLS");
			cout << "Digite o codigo da turma a ser alterado";
			cin >> alunos[m].CodTurma;

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

		case 4: //remover Curso 
			system("CLS"); 
			cout<<"Informe o codigo do curso:"; 
			cin>>codigo; 
			remove_curso(codigo);
			break;

		case 5: //remover turma 
			system("CLS"); 
			cout<<"Informe o codigo da turma:"; 
			cin>>codigo; 
			remove_turma(codigo); 
			break;

		case 6: //remover aluno 
			system("CLS"); 
			cout<<"Informe o codigo do aluno:"; 
			cin>>codigo; 
			remove_aluno(codigo);
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
