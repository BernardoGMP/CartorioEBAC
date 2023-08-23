#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca resposável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{

//Criamos as variáveis que iremos utilizar como strings que podem ter no máximo 40 caracteres (valor arbitrário)
	char cpf[40];
	char nome[40];
	char sobrenome[40]; 
	char cargo[40]; 
	char nomedoarquivo[40]; //criado apenas para salvar momentaneamente o valor do CPF.
	
//SOLICITAÇÃO DO CPF + CRIAÇÃO DO ARQUIVO

	//Solicitação ao usuário
		printf("Digite o CPF a ser cadastrado: ");
		scanf("%s",cpf);
	
	//Copiamos o valor que o cliente inseriu para usá-la para nomear o arquivo
		strcpy(nomedoarquivo, cpf);
	
	//Criamos um arquivo para armazenar as informações e inserimos o CPF nele como primeira informação
		FILE *file; //Chamamos a estrutura FILE da biblioteca stdio e declaramos a variável ponteiro "file" para ela.
		file = fopen(nomedoarquivo, "w"); //Criamos o arquivo para escrever ("w") nele.
		fprintf(file,cpf); //Escrevemos o CPF dentro do arquivo que foi aberto
		fprintf(file,","); //Botamos uma vírgula para separar os elementos
		fclose(file); //Fechamos o arquivo

//SOLICITAÇÃO DO NOME
	
	//Solicitação ao usuário
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);
	
	//Registramos o nome do cliente + adicionamos uma vírgula
		file = fopen(nomedoarquivo,"a");
		fprintf(file,nome);
		fprintf(file,",");
		fclose(file);	

//SOLICITAÇÃO DO SOBRENOME

	//Solicitação ao usuário
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s",sobrenome);
	
	//Registramos o sobrenome do cliente + adicionamos uma vírgula
		file = fopen(nomedoarquivo,"a");
		fprintf(file,sobrenome);
		fprintf(file,",");
		fclose(file);	
		
//SOLICITAÇÃO DO CARGO

	//Solicitação ao usuário
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s",cargo);
	
	//Registramos o sobrenome do cliente
		file = fopen(nomedoarquivo,"a");
		fprintf(file,cargo);
		fclose(file);
		
//MENSAGEM DE SUCESSO

		system("cls");
		printf("Registro criado com sucesso!\n\n");
		
//Não botei o systempause aqui porque ele já botei no final do código main antes de fechar o loop
		
}


int consulta() //Função responsável por consultar os usuários no sistema
{

//Definimos a linguagem para poder botar acento na interação com cliente
	setlocale(LC_ALL, "Portuguese");
	
//Criamos as variáveis que iremos utilizar dentro dessa função
	char cpf[40];
	char conteudo[100];

//Solicitação ao usuário
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
//Consultamos o arquivo
	FILE *file;
	file = fopen(cpf,"r");
	
	//Caso não haja o arquivo procurado
	if (file ==NULL) 
	{
		printf("\nEste CPF não foi encontrado.\n\n");
	}
	
	//Caso haja o arquivo, retornarmos para ele o conteúdo
	while (fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
}

int deletar() //Função responsável por deletar os usuários do sistema
{
	
//Criamos as variáveis que iremos utilizar dentro dessa função
	char cpf[40];
	
//Solicitação ao usuário
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);

remove(cpf); //Função do stdio.h para deletar um arquivo

//Fazemos uma validação se o usuário existe no sistema
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file==NULL) 
	{
		printf("O usuário não se encontra no sistema.\n");
	}

}


int main ()
{
	int opcao=0; //Antes de tudo criamos a nossa variável e setamos o valor "0" para que a variável não fique com um valor variável de memória
	int laco=1; //Essa variável será necessária para utilizarmos o "for" que manterá o programa aberto
	
	
	//Início do loop
	for (laco=1;laco=1;) //O programa ficará aberto enquanto a variável laco=1
	{ 
	
		setlocale(LC_ALL, "Portuguese"); //Definimos a linguagem

		//Início do menu
		printf("### Cartório da EBAC ###\n\n"); 
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1) Registrar nomes\n");
		printf("\t2) Consultar nomes\n");
		printf("\t3) Deletar nomes\n");
		printf("\t4) Sair do sistema\n\n");
		printf("Opção:");
		//Final do menu
	
		scanf("%d", &opcao); //Recebe o caracter do usuário
	
		system("cls"); //Limpa a tela
	
		//Início da seleção e chamada de funções
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
			printf("Essa opção não está disponível\n");
		} 
		//Fim da seleção
		
		system("pause"); //Pausa a tela para o usuário visualizar o que está escrito (fiz diferente do prof)
		system("cls"); //Limpa a tela depois que o usuário "despausa" para voltar ao início (fiz diferente do prof)
		
	}
	//Fim do loop
}






