#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings


int registro() //fun��o registro
{
	//cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das vari�veis
	printf("Digite o cpf a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf); //%s usado para strings
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //"w" siginifica escrever e cria o arquivo
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");//"a" atualiza o arquivo
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta() //fun��o consultar
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" le o arquivo 
	
	if(file == NULL)
	{
		printf("CPF n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //fun��o deletar
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
		
	printf("Digite o CPF que vo�� deseja deletar: \n\n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //se o arquivo for igual a NULL 
	{
		printf("O CPF n�o se encontra no sistema! \n");
		system("pause");
	}
	
	
}

int main()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;){
		
		system("cls"); // respons�vel por limpar a tela 
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cart�rio da EBAC ### \n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar usu�rio\n");
		printf("\t2 - Consultar cadastro\n");
		printf("\t3 - Deletar cadastro\n\n"); 
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");
		
		switch(opcao) // inicio da sele��o do menu
		{
			case 1: //come�o do la�o
			registro(); //chamando a fun��o registro
			break;
			
			case 2:
			consulta(); //chamando a fun��o consulta
			break;
				
			case 3:
			deletar(); //chamando a fun��o deletar
			break;
			
			default:
			printf("Essa op��o n�o esta dispon�vel! \n\n");
			system("pause");
			break; //fim do la�o
		}
	}
}
