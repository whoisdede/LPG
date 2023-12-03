#include <stdio.h>

typedef struct date {
    int ano;
    int mes;
    int dia;
}Data;

typedef struct horario{
    int hora;
    int minuto;
    int segundos;
}Horario;

typedef struct tipoEvento{
    int id;
    Data data;
    Horario horaInicio;
    Horario horaFim;
    char descricao[50];
    char local[50];
}TipoEvento;

void leData( Data *p );
void mostraData( Data *p );
void leHorario( Horario *h);
void mostraHorario( Horario *h);
void mostraEvento( TipoEvento *e );
void leEvento( TipoEvento *e );
TipoEvento leEventoV2();
int buscaEvento( TipoEvento v[], int n, int id );

void mostraData(Data *d){
	printf("%d/%d/%d", d->dia, d->mes, d->ano);
}
void mostraHorario(Horario *h){
	printf("%d:%d:%d", h->hora, h->minuto, h->segundos);
}

void mostraEvento( TipoEvento *e ){
	printf("Id: %d\nDescrição: %s\nLocal: %s\n",
				e->id, e->descricao, e->local);
	printf("Data do evento: ");
	printf("%d/%d/%d", e->data.dia, e->data.mes, e->data.ano);
	printf("\nHorário de início: ");
	printf("%d:%d:%d", e->horaInicio.hora,e->horaInicio.minuto, e->horaInicio.segundos);
	printf("\nHorário do fim: ");
	printf("%d:%d:%d", e->horaFim.hora,e->horaFim.minuto, e->horaFim.segundos);
	printf("\n");
}

void leData(Data *d){
	while((*d).dia > 31 || (*d).dia < 1 ){
		printf("Digite o dia: ");
		scanf("%d", &d->dia);
	}

	printf("Digite o mes: ");
	scanf("%d", &d->mes);
	printf("Digite o ano: ");
	scanf("%d", &d->ano);
}

void leHorario(Horario *h){
	printf("Digite a hora: ");
	scanf("%d", &h->hora);
	printf("Digite o minuto: ");
	scanf("%d", &h->minuto);
	printf("Digite os segundos: ");
	scanf("%d", &h->segundos);
}

void leEvento(TipoEvento *e ){
	printf("\nDigite o id: ");
	scanf("%d", &(*e).id);
	printf("\nDigite a descricao: ");
	scanf(" %[^\n]", e->descricao );
	printf("\nDigite o local: ");
	scanf(" %[^\n]", e->local );
	printf("\nDigite a data:\n");
	leData(&e->data);
	printf("Digite o horário de início:\n");
	leHorario(&e->horaInicio);
	printf("Digite o horário do fim:\n");
	leHorario(&e->horaFim);
}

int buscaEvento( TipoEvento e[], int n, int id ){
	for(int i = 0 ; i < n ; i++ ){
		if( e[i].id == id ){
			return 1;
		}
	}
	return -1;
}
