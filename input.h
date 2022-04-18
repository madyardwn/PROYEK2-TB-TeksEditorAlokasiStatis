#ifndef input_h
#define input_h

#define Prev(P) P->prev
#define Info(P) P->info
#define Baris(P) P->baris
#define Kolom(P) P->kolom
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
	int baris;
	int kolom;
	address next;	
}element_input;

typedef struct{
	address head;
	address current;
	address tail;
}list;

address Alokasi(char ch, int baris, int kolom);
void create_text_editor(list *L);
void input_keyboard(list *L);
bool cek_input(char ch);
void normal_input(list *L, address P, int *baris, int *kolom);
void handling_input(list *L, char ch, int *baris, int *kolom);
void arrows(list *L, char ch, int *baris, int *kolom);
void tampil_list(list L);

#endif