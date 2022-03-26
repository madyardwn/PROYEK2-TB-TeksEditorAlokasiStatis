#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct element{ //membuat var struct
	int slide;
	char ch;
};

struct element* createTable(char* find){
	int i;
	int j;
	
	struct element *Table;
	Table=(struct element*)malloc(sizeof(struct element)*(strlen(find)-1));
	
	for(i=0;i<strlen(find)-1;i++){//256 karakterlik bir dizi a?mak yerine 5 tane structure kulland?m;
		Table[i].ch=find[i];
		Table[i].slide=strlen(find)-i-1;
		for(j=0;j<i;j++){
			if(find[i]==Table[j].ch){//harf ?nceden kullan?ld?ysa slide de?eri g?ncelleniyor
				Table[j].slide=strlen(find)-i-1;
			}
		}
	}
	return Table;
}

int getSlide(struct element* Table,char cur,char* find){//Table'dan slide miktar?n? g?nderiyor
	if(strlen(find)==1){
		return 1;
	}
	int i=0;
	for(i=0;i<strlen(find)-1;i++){
		if(cur==Table[i].ch){
			return Table[i].slide;
		}
	}
	return strlen(find);
}

int sensitive(char* text,char* find,char* replace,struct element* Table){
	int initial=strlen(text);
	int i;
	int j;
	int counter=0;
	int z=0;
	int k;
	int flag=0;
	int shifter=0;
	for(i=strlen(find)-1;i<strlen(text);i){
		flag=0;
		z=0;
		for(j=0;j<strlen(find) && flag==0;j++){
			if(text[i-j]!=find[strlen(find)-1-j]){//bulunmas? gereken stringe kadar gidiliyor
				flag=1;//e?er farkl? bir harf bulunursa for d?ng?s?ne ve a?a??daki if statementlar?n i?ine girmiyor ve i'yi slide de?eri kadar ilerletiyor
				i+=getSlide(Table,text[i],find);
				}
			}
			if(flag==0){
				counter++;
				if(strlen(replace)>strlen(find)){//eklenecek s?zc?k bulunacak olandan fazlaysa bulunan s?zc???n son harfinden itibaren aradaki fark kadar kayd?r?l?yor
					shifter=strlen(replace)-strlen(find);
					for(k=initial+shifter;k>i+shifter;k--){
						text[k]=text[k-shifter];
					}
					for(k=0;k<strlen(replace);k++){
						text[k+i-j+1]=replace[k];
					}
					initial=initial+shifter;
					i=i+shifter;
				}
				else if(strlen(replace)==strlen(find)){//eklenecek s?zc?k bulunacak s?zc?k direkt de?i?im yap?l?yor
					for(k=0;k<strlen(find);k++){
						text[k+i-j+1]=replace[k];
					}
					i=i+shifter;
				}
				else{//eklenecek s?zc?k bulunan s?zc?kten k?saysa her ?ey aradaki fark kadar geri kayd?r?l?yor
					shifter=strlen(find)-strlen(replace);//her ?eyi shifter kadar geri al

					for(k=0;k<strlen(replace);k++){
						text[k+i-j+1]=replace[k];
					}
					for(k=i-shifter+1;k<initial;k++){
						text[k]=text[k+shifter];
					}
					initial=initial+shifter;
					i=i-1;
				}
			}
		}
	return counter;	
}


int notSensitive(char* text,char* find,char* replace,struct element* Table){
	int initial=strlen(text);
	int i;
	int j;
	int counter=0;
	int z=0;
	int k;
	int flag=0;
	int shifter=0;
	for(i=strlen(find)-1;i<strlen(text);i){
		flag=0;
		z=0;
		for(j=0;j<strlen(find) && flag==0;j++){
			if(text[i-j]!=find[strlen(find)-1-j] && text[i-j]+32!=find[strlen(find)-1-j]){//Not sensitive k?sm?nda, bulunacak s?zc?k ?nceden k???lt?ld??? i?in+++
				flag=1;                                                                   //+++ sadece text'teki s?zc???n harflerinin b?y?k veya ayn? olmas?na bak?l?yor+++ 
				if(text[i]>64 && text[i]<91){											  //+++ text'in harfinin k???k find'?n harfinin b?y?k olmas?na bakmaya gerek kalm?yor
				i+=getSlide(Table,text[i]+32,find);
			}
				else{
					i+=getSlide(Table,text[i],find);
				}
				}
			}
			if(flag==0){
				counter++;
				if(strlen(replace)>strlen(find)){//eklenecek s?zc?k bulunacak olandan fazlaysa bulunan s?zc???n son harfinden itibaren aradaki fark kadar kayd?r?l?yor
					shifter=strlen(replace)-strlen(find);
					for(k=initial+shifter;k>i+shifter;k--){
						text[k]=text[k-shifter];
					}
					for(k=0;k<strlen(replace);k++){
						text[k+i-j+1]=replace[k];
					}
					initial=initial+shifter;
					i=i+shifter;
				}
				else if(strlen(replace)==strlen(find)){//eklenecek s?zc?k bulunacak s?zc?k direkt de?i?im yap?l?yor
					for(k=0;k<strlen(find);k++){
						text[k+i-j+1]=replace[k];
					}
					i++;
				}
				else{//eklenecek s?zc?k bulunan s?zc?kten k?saysa her ?ey aradaki fark kadar geri kayd?r?l?yor
					shifter=strlen(find)-strlen(replace);

					for(k=0;k<strlen(replace);k++){
						text[k+i-j+1]=replace[k];
					}
					for(k=i-shifter+1;k<initial;k++){
						text[k]=text[k+shifter];
					}
					initial=initial+shifter;//yeni s?zc?k eskisinden b?y?k oldu?unda i daha ?nce traverse edilmemi? bir yeri g?steriyor+++
					i=i-1;//+++Bu durum kelime veya harf ka??rmaya neden olabilir.
				}
			}
		}
	return counter;	
}

int main(){
	char find[100];
	char replace[100];
	char text[2000];	//E?er text 1500den b?y?kse text array inin b?y?kl???n? artt?r?n.
	FILE *fp;
	char filename[100];
	clock_t start,end;
	
	printf("Masukkan Nama File :");
	gets(filename);
	fp=fopen(filename,"rb+");
	if(fp==NULL){
		printf("File yang dipilih tidak ada!!");
		return 1;
	}
	
	int i=0;

	while(!feof(fp) ){
		text[i]=fgetc(fp);
		i++;
	}
	text[i-1]='\0';
	
	printf("\nIsi Teks Original :%s",text);
	
	printf("\n\nKata yang ingin dicari :");
	gets(find);
	
	printf("\nReplace :");
	gets(replace);
	
	struct element *Table1;
	Table1=createTable(find);
	
	struct element *Table2;
	
	
	printf("If you would like a case sensitive search enter '1', \nIf you dont want a case sensitive search enter anything else:\n");
	char state;
	scanf("%c",&state);
	int counter;
	
	 start = clock();//Zaman ba?lang?c? inputlar al?nd?ktan sonra yap?l?yor
	
	switch(state){
		case '1':
			counter=sensitive(text,find,replace,Table1);
			fclose(fp);
			
			fp=fopen(filename,"w");
			for(i=0;i<strlen(text);i++){//Carriage return  ('\r') fazladan 1 sat?r daha atlamas?na neden oluyor.+++
				if(text[i]=='\r')//+++bunun olmamas? i?in yerine bo?luk ekliyorum
				text[i]=' ';//Kod bu olaydan dolay? sat?r atlamal? caselerde de ?al???yor
			}
			fputs(text,fp);
			printf("%s",text);
			fclose(fp);
			
			printf("\n Found and Replaced:%d",counter);
			printf("\nCheck the file to see the differences");
			break;
			
		default:
			for(i=0;i<strlen(find);i++){//Zaten Not case sensitive se?ildi?i i?in find s?zc???n?n harflerinin b?y?k ya da k???k olmas?n? de?i?tirmek+++
				if(find[i]<91 && find[i]>64){//+++ bir sorun yaratmayacakt?r
					find[i]=find[i]+32;
				}
			}
			
			Table2=createTable(find);			
			counter=notSensitive(text,find,replace,Table2);
			
			fclose(fp);
			fp=fopen(filename,"w");
			for(i=0;i<strlen(text);i++){//Carriage return -> '\r' fazladan 1 sat?r daha atlamas?na neden oluyor.+++
				if(text[i]=='\r')//+++bunun olmamas? i?in yerine bo?luk ekliyorum
				text[i]=' ';//Kod bu olaydan dolay? sat?r atlamal? caselerde de ?al???yor
			}
			fputs(text,fp);
			printf("%s",text);
			fclose(fp);
			
			printf("\n Found and Replaced:%d",counter);
			printf("\nCheck the file to see the differences");			
	}
	end=clock();
	 printf("\nRunning Time: %f ms",(double)((double)end-(double)start)/CLOCKS_PER_SEC);
	return 0;
}
