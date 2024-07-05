#include <iostream>
#include <string>
#include <locale>
#include <iomanip>

struct Aluno 
{
	long int Matricula;
	std::string NomeDoAluno;
	std::string Curso;
	int Semestre;
	double Mensalidade;
};

void MostrarDados(Aluno Dados);
void MostrarDados(Aluno* Dados); // ERRO ESTA AQUI 
void AlterarDados(Aluno& AlteraDados);
void AlterarDados(Aluno* Dados);

/*Neste caso criamos uma fun��o sobrecarregada da fun��o AlteraDados. Agora nessa ASSISNATURA fun��o AlteraDados
� recebido como parametros um ponteiro capaz de apontar para uma vaariavel (objeto) do tipo struct Aluno
Todo PONTEIRO recebe um endere�o de mem�ria

Se dado � um ponteiro, ele pode ter dentro dele um endere�o de mem�ria. Logo ao chamar a fun��o
AlteraDados() com ponteiros, deve-se enviar um endere�o de objeto.
*/


int main() 
{
	setlocale(LC_ALL, "PORTUGUESE");

	Aluno Aluno01 = { 101, "Otavio", "Engenharia da Computa��o", 8, 150.63 };
	Aluno* Aluno02 = new Aluno;
	Aluno Aluno03;

	
	system("CLS");	
	std::cout << "\nANTES DE MODIFICAR\n";
	AlterarDados(&Aluno03);
	MostrarDados(&Aluno03);
	MostrarDados(Aluno01);
	AlterarDados(Aluno01);
	std::cout << "\nDEPOIS DE MODIFICAR \n";
	MostrarDados(Aluno01);
	std::cout << "\nANTES DE MODIFICAR COM PONTEIROS\n";
	AlterarDados(Aluno02);
	std::cout << "\nDEPOIS DE MODIFICAR COM PONTEIROS \n";
	MostrarDados(Aluno02);
	
	return 0;
}

/*O QUE SER� ENVIADO PARA A FUN��O Dados � UMA C�PIA DA STRUCT QUE SER� PASSADO PARA O PARAMETROS Dados, OU SEJA, 
Dados n�o conseguem alterar os valores de Aluno01 porque � uma simples c�pia, isso � chamado de:
PASSAGEM POR VALOR*/

/*O aluno01 ser� o argumento que ser� colocado no parametro da fun��o Dados*/

void MostrarDados(Aluno Dados) 
{
	std::cout << "************Dados do Aluno************\n\n";
	std::cout << "\t NOME: " << Dados.NomeDoAluno << '\n';
	std::cout << "\t CURSO: " << Dados.Curso << '\n';
	std::cout << "\t MATRICULA: " << Dados.Matricula << '\n';
	std::cout << "\t SEMESTRE: " << Dados.Semestre << '\n';
	std::cout << "\t VALOR DA MENSALIDADE R$ " << std::fixed << std::setprecision(2) << Dados.Mensalidade << '\n';
	std::cout << "*************************************************************************\n\n";
}

void MostrarDados(Aluno* Dados)
{
	std::cout << "************Dados do Aluno************\n\n";
	std::cout << "\t NOME: " << Dados->NomeDoAluno << '\n';
	std::cout << "\t CURSO: " << Dados->Curso << '\n';
	std::cout << "\t MATRICULA: " << Dados->Matricula << '\n';
	std::cout << "\t SEMESTRE: " << Dados->Semestre << '\n';
	std::cout << "\t VALOR DA MENSALIDADE R$ " << std::fixed << std::setprecision(2) << Dados->Mensalidade << '\n';

	std::cout << "*************************************************************************\n\n";
}

void AlterarDados(Aluno* Dados) 
{
	Dados->NomeDoAluno = "Aldair";
	Dados->Curso = "Logistica";
	Dados->Matricula = 911;
	Dados->Semestre = 11;
	Dados->Mensalidade = 469.99	;
}

/*Sem utilizar a &Referencia, n�o � possivel alterar o valor de Aluno01, pois sem a &Referencia o valor �
apenas uma c�pia*/
void AlterarDados(Aluno& AlteraDados) 
{
	AlteraDados.NomeDoAluno = "Alex";
	AlteraDados.Curso = "Gastronomia";
	AlteraDados.Matricula = 888;
	AlteraDados.Semestre = 2;
	AlteraDados.Mensalidade = 299.56;
}