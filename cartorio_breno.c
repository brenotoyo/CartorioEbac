#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registrar() //função responsável por criar novos usuários
{
	system ("cls"); //Limpar sistema
	
	//criação de variáveis
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
	fprintf(file, cpf); //salva o valor da variável 
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

int consultar() //função responsável por consultar usuários
{	
	//criação de variáveis
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
		printf("CPF não localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
}

int deletar() //função responsável por deletar usuários
{
	//criação de variáveis
	char cpf[40];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("Usuário não se encontra no sistema! \n");		
	}
	fclose(file);
	system("pause");
}

int main()
{
	int opcao = 0; //Variável de decisão do usuário
	int menu = 1; //Variável de laço do menu
	
	for(menu = 1; menu == 1;) //Laço do menu
	{
		system("cls"); //Limpar sistema
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("### Cartório da EBAC ### \n\n"); //Início do menu
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n"); //Fim do menu
		
		printf("Escolha a opção desejada do menu: ");
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		system("cls"); //Limpar sistema
		
		switch(opcao) //Escolha do usuário
		{
			case 1:
			registrar(); //Chama a função registrar
			break;
			
			case 2:
			consultar(); //Chama a função consultar
			break;
			
			case 3:
			deletar(); //Chama a função deletar
			break;
			
			default:
			printf("Opção indisponível! \n"); 
			system("pause");
			break;
		}
	
	}
}

