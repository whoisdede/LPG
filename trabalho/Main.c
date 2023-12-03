#include <stdio.h>
#include <stdlib.h>
#include "TipoEvento.c"

int main(int argc, char *argv[]) {
	TipoEvento *e = NULL;
	int n = 0;
	int opcao, i;
	
	FILE *f = fopen( "tipoEvento.txt", "rt" );
	if( f == NULL ){
		printf("Arquivo nao encontrado!\n");
	}
	else{
		fscanf( f, "%d", &n );
		e = malloc( sizeof(TipoEvento) * n );
		for( i = 0 ; i < n ; i++ ){
			fscanf( f, "%d", &e[i].id );
			fscanf( f, " %[^\n]", e[i].descricao );
			fscanf( f, "%[^\n]", e[i].local );
			fscanf( f, "%d %d %d", &e[i].data.ano, &e[i].data.dia, &e[i].data.mes );
			fscanf( f, "%d %d %d", &e[i].horaFim.hora, &e[i].horaFim.minuto, &e[i].horaFim.segundos );
			fscanf( f, "%d %d %d", &e[i].horaInicio.hora, &e[i].horaInicio.minuto, &e[i].horaInicio.segundos );
		}
		fclose( f );
		printf("%d registros foram carregados!\n", n);
		system("pause");
	}
	
	do{	
		printf("1-Cadastrar\n2-Mostrar eventos\n0-Sair\n");
		opcao -1;
		scanf("%d", &opcao);
		switch( opcao ){
			case 1:
				n++;
				e = realloc( e, sizeof(TipoEvento) * n );
				leEvento( &e[n-1] );
				break;
			
			case 2:
				if( n == 0 )
					printf("Cadastro vazio!\n");
				else{
					printf("Eventos cadastrados:\n");
					for( i = 0 ; i < n ; i++ ){
						printf("Evento %d:\n", i+1 );
						mostraEvento( &e[i] );
					}
				}
				system("pause");
				break;
		}
		
	}while( opcao != 0 );
	
	// Salva vetor v no arquivo.
	f = fopen( "tipoEvento.txt", "wt" );
	if( f == NULL ){
		printf("Erro no arquivo da saida!\n");
		return 1;
	}
	fprintf( f, "%d\n", n );
	for( i = 0 ; i < n ; i++ ){
		fprintf( f, "%d\n", e[i].id );
		fprintf( f, "%s\n", e[i].descricao );
		fprintf( f, "%s\n", e[i].local );
		fprintf( f, "%d %d %d\n", e[i].data.ano, e[i].data.dia, e[i].data.mes);
		fprintf( f, "%d %d %d\n", e[i].horaFim.hora, e[i].horaFim.minuto, e[i].horaFim.segundos);
		fprintf( f, "%d %d %d\n", e[i].horaInicio.hora, e[i].horaInicio.minuto, e[i].horaInicio.segundos);
	}
	fclose( f ); // Fundamental!
	
	free( e );
	
	return 0;
}
