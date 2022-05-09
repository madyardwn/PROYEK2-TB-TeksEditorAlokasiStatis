#ifndef input_h
#define input_h

#include <stdbool.h>

#define Prev(P) P->prev
#define Info(P) P->info
#define First(P) P->first
#define Last(P) P->last
#define Next(P) P->next
#define Head(L) (L).head
#define Current(L) (L).current
#define Tail(L) (L).tail

#define MAX_ROWS 5
#define MAX_COLUMNS 5

typedef struct element_list *address;

typedef struct element_list{
	address prev;
	char info;
	bool first;
	bool last;
	address next;	
}element_input;

typedef struct{
	address head;
	address current;
	address tail;
}list;

address Alokasi(char ch);
void create_text_editor(list *L);
void input_keyboard(list *L);
bool cek_input(char ch);
void normal_input(list *L, address P, address *Q, int *baris, int *kolom);
void handling_input(list *L, char ch, int *baris, int *kolom);
void arrows(list *L, char ch, int *baris, int *kolom);
void enter(list *L, char ch, int *baris, int *kolom);
void tampil_list(list L);
void tab(List L);

#endif
