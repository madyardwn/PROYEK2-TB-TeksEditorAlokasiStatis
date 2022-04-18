#ifndef input_h
#define input_h

#define Prev(P) P->prev
#define Info(P) P->info
#define Next(P) P->next
#define Head(L) (L).head
#define Current(L) (L).current
#define Tail(L) (L).tail

typedef struct element_list *address;

typedef struct element_list{
	address prev;
	char info;
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
void normal_input(list *L, address P);
void handling_input(list *L, address P);
void tampil_list(list L);

#endif