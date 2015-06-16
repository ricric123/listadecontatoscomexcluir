#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 5
#include <string.h>

struct tipo_contato{
	char nome[80], email[80], num[8];
	int id;
};

//variáveis globais
struct tipo_contato vet[TAM];
int cont;
//protótipo de função e procedimento
void addContato(int id, char *nome, char *num, char *email);
int getContato(int id);
void removeContato(int id);
void listar();
void mostraContato(int pos);

main(){
	setlocale(LC_ALL, "");
	//variáveis locais
	int op, i, pos, id;
	cont=0;
	char nome[80], email[80], num[8];
	
	
	do{
		// apresentar as opções do menu
		system("cls");
		printf("# Agenda de contatos #\n\n");
		printf("1-inserir contato\n");
		printf("2-Consultar contato\n");
		printf("3-Excluir contato\n");
		printf("4-Listar todos\n");
		printf("5-Sair\n\n");
		printf("Opção: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:		
				printf("ID: ");
				scanf("%d", &id);
				printf("Nome: ");
				fflush(stdin);
				gets(nome);
				printf("Telefone: ");
				fflush(stdin);
				gets(num);
				printf("Email: ");
				fflush(stdin);
				gets(email);
				// CHAMADA DE PROCEDIMENTO addContato
				addContato(id, nome, email, num);
				break;
			case 2:
				printf("Informe um id: ");
				fflush(stdin);
				gets(id);
				pos=getContato(id);
				
				if(pos==-1){
					printf("Nome nao cadastrado.\n\n");
				}else {
					mostraContato(pos);
				}
				break;
			case 3:
				printf("Informe o id\n");
				scanf("%d", &id);
				removeContato(id);
				break;
			case 4:
				listar();
				break;
			case 5:
				break;
			default:
				printf("Opção invalida. Tente novamente.\n\n");							
		}
		
		getch();
		
	}while(op!=5);
}

//copiar os parâmetros de entrada para um posição específica do vetor
void addContato(int id, char*nome, char*email, char*num){
	//copiar o campo nome
	if(cont<TAM){
		strcpy(vet[cont].nome, nome);
		strcpy(vet[cont].email, email);
		strcpy(vet[cont].num, num);
		vet[cont].id=id;
		cont++;
	}
}

void listar(){
	int i;
	
	for(i=0;i<cont;i++){
		printf("Nome: %s\n", vet[i].nome);
		printf("Telefone: %s\n\n", vet[i].num);
	}
}

int getContato(int id){
	int i;
	for(i=0;i<cont;i++){
		if(vet[i].id==id){
			return i;
		}
	}
	return -1;
}

void mostraContato(int pos){
	printf("Id:%d nome: Tel: %s email: %s\n", vet[pos].id, vet[pos].nome, vet[pos].num, vet[pos].email);
}

void removeContato(int id){
	int i, pos;
	pos=getContato(id);
	if(pos !=-1){
		cont--;
		for(i=pos;i<cont;i++){
			vet[i]=vet[i+1];
		}
	}
}
