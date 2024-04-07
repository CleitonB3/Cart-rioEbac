#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings


int registro() //função registro
{
	//criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das variáveis
	printf("Digite o cpf a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf); //%s usado para strings
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //"w" siginifica escrever e cria o arquivo
	fprintf(file,cpf); //salva o valor da variável
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

int consulta() //função consultar
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
		printf("CPF não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //função deletar
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
		
	printf("Digite o CPF que voçê deseja deletar: \n\n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //se o arquivo for igual a NULL 
	{
		printf("O CPF não se encontra no sistema! \n");
		system("pause");
	}
	
	
}

int main()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;){
		
		system("cls"); // responsável por limpar a tela 
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ### \n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar usuário\n");
		printf("\t2 - Consultar cadastro\n");
		printf("\t3 - Deletar cadastro\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");
		
		switch(opcao) // inicio da seleção do menu
		{
			case 1: //começo do laço
			registro(); //chamando a função registro
			break;
			
			case 2:
			consulta(); //chamando a função consulta
			break;
				
			case 3:
			deletar(); //chamando a função deletar
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!"); 
			return 0;
			break;
			
			default:
			printf("Essa opção não esta disponível! \n");
			system("pause");
			break; //fim do laço
		}
	}
}
