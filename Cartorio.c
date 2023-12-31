#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��es de texto por regi�o
#include <string.h> // Biblioteca respons�vel por cuidar das strings

int registrar() // Definindo fun��es
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
  char arquivo[40]; //Definindo as vari�veis 
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

int consultar() // Definindo fun��es
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
		printf("N�o foi poss�vel abrir o arquivo, CPF n�o cadastrado!\n\n");
	}
	
	
	if(file != NULL)
	{
	printf("\nEssas s�o as informa��es do usu�rio:\n\nCPF: ");
	}
	
	
	while(fgets(conteudo, 200, file) != NULL)
	{

		printf("%s", conteudo);
		
	}
	printf("\n\n");
	system("pause");
	fclose(file);
}

int deletar() // Definindo fun��es
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		fclose(file);	
		printf("O CPF digitado n�o foi encontrado!\n");
		system("pause");
	}
	
	if(file != NULL)
	{
		fclose(file);
		printf("O usu�rio foi deletado com sucesso!\n");
		system("pause");
		remove(cpf);
	}
	fclose(file);
}

int main()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("** Cart�rio de Registro da EBAC **\n\n");
	printf("Login de administrador\nDigite a senha: \n\n");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system("cls");
		
		for(laco=1;laco=1;) //Deifindo o la�o de repeti��o
		{
		
		    system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
			printf("** Cart�rio de Registro da EBAC **\n\n"); //In�cio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consutar nomes\n");
			printf("\t3 - Deletar nomes\n");
		    printf("\t4 - Sair do sistema\n\n");
			printf("Op��o:"); //Fim do menu
		
		    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		    
		    system("cls"); 
		    
		    switch(opcao) //In�cio da sele��o
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
		      
		      case 4:
		      printf("Obrigado por utilizar o sistema!\n");
		      return 0;
		      break;
		      
		      default:
		      printf("Esta op��o � inv�lida.\n");
		      system("pause");
		      break;
	
     	    } // Fim da sele��o
    	}  
	}
	
		else
		printf("Senha incorreta, digite novamente.");
}
