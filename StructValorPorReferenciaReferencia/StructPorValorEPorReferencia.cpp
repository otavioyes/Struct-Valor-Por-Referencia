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

/*Neste caso criamos uma função sobrecarregada da função AlteraDados. Agora nessa ASSISNATURA função AlteraDados
é recebido como parametros um ponteiro capaz de apontar para uma vaariavel (objeto) do tipo struct Aluno
Todo PONTEIRO recebe um endereço de memória

Se dado é um ponteiro, ele pode ter dentro dele um endereço de memória. Logo ao chamar a função
AlteraDados() com ponteiros, deve-se enviar um endereço de objeto.
*/


int main() 
{
	setlocale(LC_ALL, "PORTUGUESE");

	Aluno Aluno01 = { 101, "Otavio", "Engenharia da Computação", 8, 150.63 };
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

/*O QUE SERÁ ENVIADO PARA A FUNÇÃO Dados É UMA CÓPIA DA STRUCT QUE SERÁ PASSADO PARA O PARAMETROS Dados, OU SEJA, 
Dados não conseguem alterar os valores de Aluno01 porque é uma simples cópia, isso é chamado de:
PASSAGEM POR VALOR*/

/*O aluno01 será o argumento que será colocado no parametro da função Dados*/

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

/*Sem utilizar a &Referencia, não é possivel alterar o valor de Aluno01, pois sem a &Referencia o valor é
apenas uma cópia*/
void AlterarDados(Aluno& AlteraDados) 
{
	AlteraDados.NomeDoAluno = "Alex";
	AlteraDados.Curso = "Gastronomia";
	AlteraDados.Matricula = 888;
	AlteraDados.Semestre = 2;
	AlteraDados.Mensalidade = 299.56;
}