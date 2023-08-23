#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respos�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{

//Criamos as vari�veis que iremos utilizar como strings que podem ter no m�ximo 40 caracteres (valor arbitr�rio)
	char cpf[40];
	char nome[40];
	char sobrenome[40]; 
	char cargo[40]; 
	char nomedoarquivo[40]; //criado apenas para salvar momentaneamente o valor do CPF.
	
//SOLICITA��O DO CPF + CRIA��O DO ARQUIVO

	//Solicita��o ao usu�rio
		printf("Digite o CPF a ser cadastrado: ");
		scanf("%s",cpf);
	
	//Copiamos o valor que o cliente inseriu para us�-la para nomear o arquivo
		strcpy(nomedoarquivo, cpf);
	
	//Criamos um arquivo para armazenar as informa��es e inserimos o CPF nele como primeira informa��o
		FILE *file; //Chamamos a estrutura FILE da biblioteca stdio e declaramos a vari�vel ponteiro "file" para ela.
		file = fopen(nomedoarquivo, "w"); //Criamos o arquivo para escrever ("w") nele.
		fprintf(file,cpf); //Escrevemos o CPF dentro do arquivo que foi aberto
		fprintf(file,","); //Botamos uma v�rgula para separar os elementos
		fclose(file); //Fechamos o arquivo

//SOLICITA��O DO NOME
	
	//Solicita��o ao usu�rio
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);
	
	//Registramos o nome do cliente + adicionamos uma v�rgula
		file = fopen(nomedoarquivo,"a");
		fprintf(file,nome);
		fprintf(file,",");
		fclose(file);	

//SOLICITA��O DO SOBRENOME

	//Solicita��o ao usu�rio
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s",sobrenome);
	
	//Registramos o sobrenome do cliente + adicionamos uma v�rgula
		file = fopen(nomedoarquivo,"a");
		fprintf(file,sobrenome);
		fprintf(file,",");
		fclose(file);	
		
//SOLICITA��O DO CARGO

	//Solicita��o ao usu�rio
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s",cargo);
	
	//Registramos o sobrenome do cliente
		file = fopen(nomedoarquivo,"a");
		fprintf(file,cargo);
		fclose(file);
		
//MENSAGEM DE SUCESSO

		system("cls");
		printf("Registro criado com sucesso!\n\n");
		
//N�o botei o systempause aqui porque ele j� botei no final do c�digo main antes de fechar o loop
		
}


int consulta() //Fun��o respons�vel por consultar os usu�rios no sistema
{

//Definimos a linguagem para poder botar acento na intera��o com cliente
	setlocale(LC_ALL, "Portuguese");
	
//Criamos as vari�veis que iremos utilizar dentro dessa fun��o
	char cpf[40];
	char conteudo[100];

//Solicita��o ao usu�rio
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
//Consultamos o arquivo
	FILE *file;
	file = fopen(cpf,"r");
	
	//Caso n�o haja o arquivo procurado
	if (file ==NULL) 
	{
		printf("\nEste CPF n�o foi encontrado.\n\n");
	}
	
	//Caso haja o arquivo, retornarmos para ele o conte�do
	while (fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
}

int deletar() //Fun��o respons�vel por deletar os usu�rios do sistema
{
	
//Criamos as vari�veis que iremos utilizar dentro dessa fun��o
	char cpf[40];
	
//Solicita��o ao usu�rio
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);

remove(cpf); //Fun��o do stdio.h para deletar um arquivo

//Fazemos uma valida��o se o usu�rio existe no sistema
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file==NULL) 
	{
		printf("O usu�rio n�o se encontra no sistema.\n");
	}

}


int main ()
{
	int opcao=0; //Antes de tudo criamos a nossa vari�vel e setamos o valor "0" para que a vari�vel n�o fique com um valor vari�vel de mem�ria
	int laco=1; //Essa vari�vel ser� necess�ria para utilizarmos o "for" que manter� o programa aberto
	
	
	//In�cio do loop
	for (laco=1;laco=1;) //O programa ficar� aberto enquanto a vari�vel laco=1
	{ 
	
		setlocale(LC_ALL, "Portuguese"); //Definimos a linguagem

		//In�cio do menu
		printf("### Cart�rio da EBAC ###\n\n"); 
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1) Registrar nomes\n");
		printf("\t2) Consultar nomes\n");
		printf("\t3) Deletar nomes\n");
		printf("\t4) Sair do sistema\n\n");
		printf("Op��o:");
		//Final do menu
	
		scanf("%d", &opcao); //Recebe o caracter do usu�rio
	
		system("cls"); //Limpa a tela
	
		//In�cio da sele��o e chamada de fun��es
		switch (opcao) 
		{
		case 1:
			registro();
			break;
		
		case 2:
			consulta();
			break;
		
		case 3:
			deletar();
			break;
			
		case 4:
			printf("Agradecemos por utilizar o sistema.\n");
			return 0;
			break;
		
		default:
			printf("Essa op��o n�o est� dispon�vel\n");
		} 
		//Fim da sele��o
		
		system("pause"); //Pausa a tela para o usu�rio visualizar o que est� escrito (fiz diferente do prof)
		system("cls"); //Limpa a tela depois que o usu�rio "despausa" para voltar ao in�cio (fiz diferente do prof)
		
	}
	//Fim do loop
}






