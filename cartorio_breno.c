#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registrar() //fun��o respons�vel por criar novos usu�rios
{
	system ("cls"); //Limpar sistema
	
	//cria��o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];

	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //copia os valores de cpf em arquivo
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e entra em "escrever"
	fprintf(file, cpf); //salva o valor da vari�vel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ", "); //insere uma "," no arquivo
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, nome); //insere o nome no arquivo
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ", "); 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, sobrenome); //insere o sobrenome no arquivo
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ", "); 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, cargo); //insere o cargo no arquivo
	fclose(file);
	
	system("pause");
}

int consultar() //fun��o respons�vel por consultar usu�rios
{	
	//cria��o de vari�veis
	char cpf[40];
	char conteudo[200];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	system ("cls");
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF n�o localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
}

int deletar() //fun��o respons�vel por deletar usu�rios
{
	//cria��o de vari�veis
	char cpf[40];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("Usu�rio n�o se encontra no sistema! \n");		
	}
	fclose(file);
	system("pause");
}

int main()
{
	int opcao = 0; //Vari�vel de decis�o do usu�rio
	int menu = 1; //Vari�vel de la�o do menu
	
	for(menu = 1; menu == 1;) //La�o do menu
	{
		system("cls"); //Limpar sistema
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("### Cart�rio da EBAC ### \n\n"); //In�cio do menu
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n"); //Fim do menu
		
		printf("Escolha a op��o desejada do menu: ");
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls"); //Limpar sistema
		
		switch(opcao) //Escolha do usu�rio
		{
			case 1:
			registrar(); //Chama a fun��o registrar
			break;
			
			case 2:
			consultar(); //Chama a fun��o consultar
			break;
			
			case 3:
			deletar(); //Chama a fun��o deletar
			break;
			
			default:
			printf("Op��o indispon�vel! \n"); 
			system("pause");
			break;
		}
	
	}
}

