#ifndef finrep_h
#define finrep_h

struct element{ //membuat var struct
	int slide;
	char ch;
};

int finrep();
struct element* createTable(char* find);
int sensitive(char* text,char* find,char* replace,struct element* Table);
int notSensitive(char* text,char* find,char* replace,struct element* Table);

#endif