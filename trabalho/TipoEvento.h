
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
