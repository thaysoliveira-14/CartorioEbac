#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocações de texto por região
#include <string.h> // Biblioteca responsável por cuidar das strings

int registrar() // Definindo funções
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  
  printf("Digite o  CPF a ser cadastrado: ");
  scanf("%s", cpf);
  
  strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
		FILE *file; // cria o arquivo
  		file = fopen(arquivo, "w"); // cria o arquivo
  		fprintf(file,cpf); // salva o valor da variavel
  		fclose(file); // fecha o arquivo

  		file = fopen(arquivo, "a");
  		fprintf(file, "\nNOME: ");
 		fclose(file);
  
  
  printf("Digite o nome a ser cadastrado: ");
  scanf("%s",nome);
  
  		file = fopen(arquivo, "a");
  		fprintf(file,nome);
  		fclose(file);

  		file = fopen(arquivo, "a");
  		fprintf(file, "\nSOBRENOME: ");
  		fclose(file);

  
  printf("Digite o sobrenome a ser cadastrado: ");
  scanf("%s", sobrenome);

  		file = fopen(arquivo, "a");
  		fprintf(file,sobrenome);
  		fclose(file);

  		file = fopen(arquivo, "a");
  		fprintf(file, "\nCARGO: ");
  		fclose(file);
  
  
  printf("Digite o cargo a ser cadastrado: ");
  scanf("%s", cargo);

  		file = fopen(arquivo, "a");
  		fprintf(file, cargo);
  		fclose(file);
  
  printf("\n");
  system("pause");	
  	
}

int consultar() // Definindo funções
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, CPF não cadastrado!\n\n");
	}
	
	
	if(file != NULL)
	{
	printf("\nEssas são as informações do usuário:\n\nCPF: ");
	}
	
	
	while(fgets(conteudo, 200, file) != NULL)
	{

		printf("%s", conteudo);
		
	}
	printf("\n\n");
	system("pause");
	fclose(file);
}

int deletar() // Definindo funções
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		fclose(file);	
		printf("O CPF digitado não foi encontrado!\n");
		system("pause");
	}
	
	if(file != NULL)
	{
		fclose(file);
		printf("O usuário foi deletado com sucesso!\n");
		system("pause");
		remove(cpf);
	}
	fclose(file);
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1; 
	
	for(laco=1;laco=1;) //Deifindo o laço de repetição
	{
	
     system("cls");

	 setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	 printf("** Cartório de Registro da EBAC **\n\n"); //Início do menu
	 printf("Escolha a opção desejada do menu:\n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consutar nomes\n");
	 printf("\t3 - Deletar nomes\n\n");
	 printf("Opção:"); //Fim do menu

     scanf("%d", &opcao); //Armazenando a escolha do usuário
    
     system("cls"); 
    
     switch(opcao) //Início da seleção
     {
	 
      case 1:
      registrar();
      break;
     
      case 2:
      consultar();
      break;
     
      case 3:
      deletar();
      break;
      
      default:
      printf("Esta opção é inválida.\n");
      system("pause");
      break;
	
     } // Fim da seleção
    }  
}
