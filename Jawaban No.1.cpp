/*
Nama		: Sheila Azhar Almufarida & Putri Nabila
NPM			: 140810180001 & 140810180007
Nama Program: Antrian RS (No. 1)
*/

#include<iostream>
using namespace std;
 
struct data{
	char nama[20];
	char jk[1]; 
	int no;
};

struct elementQueue{
	data info;
	elementQueue* next;
	elementQueue* prev;
};

typedef elementQueue* pointer;

struct Queue{
 pointer Head;
 pointer Tail;
};

void createQueue(Queue& Q);
void createElement(Queue& pBaru);
void insertQueue(Queue& Q);
void deleteQueue(Queue& Q, pointer& pHapus);
void traversal(Queue Q);

main(){
 Queue Q;
 pointer pBaru, pHapus;
 int pilih;
 createQueue(Q);
 do{
  menu:
  system("cls");
  cout<<"========================================"<<endl;
  cout<<"    Program Antrian RSU. Jatinangor"<<endl;
  cout<<"========================================\n"<<endl;
  cout<<" 1. Tambah Antrian Pasien"<<endl;
  cout<<" 2. Panggil Antrian Pasien"<<endl;
  cout<<" 3. Tampilkan Antrian Pasien"<<endl;
  cout<<" 0. Exit"<<endl;
  cout<<"\n========================================"<<endl;
  cout<<"Pilih : ";
  cin>>pilih;
  switch(pilih){
  case 1:
   system("cls");
   cout<<"======================================"<<endl;
   cout<<"\tInput Antrian Pasien"<<endl;
   cout<<"======================================"<<endl;
   insertQueue(Q);
   system("pause");
   break;
  case 2:
   deleteQueue(Q,pHapus);
   system("cls");
   cout<<"======================================"<<endl;
   cout<<"\tAntrian Pasien"<<endl;
   cout<<"======================================"<<endl;
   traversal(Q);
   system("pause");
   break;
  case 3:
   system("cls");
   cout<<"======================================"<<endl;
   cout<<"\tAntrian Pasien"<<endl;
   traversal(Q);
   system("pause");
   break;
  case 0:
   system("cls");
   cout<<"\n\n\t\t\t\tTERIMAKASIH"<<endl<<endl;
   system("pause");
   break;
  default:
   cout<<"\n\tMenu Belum Tersedia\n\n";
   system("pause");
   goto menu;
  }
 }while(pilih != 0);
}

void createQueue(Queue& Q){
 Q.Head = NULL;
 Q.Tail = NULL;
}

void createElement(pointer& pBaru){
 pBaru = new elementQueue;
 char tmp[10];
 cout<<"Nama Pasien\t: ";
 cin>>pBaru->info.nama;
 cout<<"Jenis Kelamin(P/L): ";
 cin>>pBaru->info.jk;
 cout<<"Nomor Antrian\t: ";
 cin>>pBaru->info.no;
 
 pBaru->next = NULL;
 pBaru->prev = NULL;
}

void insertQueue(Queue& Q){
 pointer pBaru, pBantu;
 int ketemu = 0;
 createElement(pBaru);
 if(Q.Head == NULL){
  Q.Head = pBaru;
  Q.Tail = pBaru;
 }
 else{
 	pBantu = Q.Head;
  		if(Q.Head->info.no > pBaru->info.no){
  		pBaru->next = Q.Head;
		Q.Head->prev = pBaru;
		Q.Head = pBaru;
  		}
  		else{
   			while(ketemu == 0 && pBantu != NULL){
    			if(pBantu->info.no > pBaru->info.no){
     			ketemu = 1;
     			pBaru->next = pBantu;
     			pBaru->prev = pBantu->prev;
     			pBaru->next->prev = pBaru;
     			pBaru->prev->next = pBaru;
    			}
    			else
     			pBantu = pBantu->next;
   			}
   		if(ketemu == 0){
    		Q.Tail->next = pBaru;
    		pBaru->prev = Q.Tail;
    		Q.Tail = pBaru;
   		}
  		}
}	 
 cout<<endl<<pBaru->info.nama<<" Sudah Masuk Dalam Antrian"<<endl<<endl;
}

void deleteQueue(Queue& Q, pointer& pHapus){
 if(Q.Head == NULL){
  pHapus = NULL;
  cout<<"Antrian kosong";
 }
 else if(Q.Head == Q.Tail){
  pHapus = Q.Head;
  Q.Head = NULL;
  Q.Tail = NULL;
 }
 else{
  pHapus = Q.Head;
  Q.Head = Q.Head->next;
  Q.Head->prev = NULL;
  pHapus->next = NULL;
 }
}

void traversal(Queue Q){
 pointer pBantu;
 int no=1;
 pBantu = Q.Head; 
 if(Q.Head == NULL){
  cout<<"Antrian kosong";
 }
 else{
  cout<<"======================================"<<endl;
  cout<<"No\tNama\t\tJK\tNo.Antrian"<<endl;
  cout<<"======================================"<<endl;
  while(pBantu != NULL){
   cout<<no<<"\t"<<pBantu->info.nama<<"\t\t"<<pBantu->info.jk<<"\t"<<pBantu->info.no<<endl;
   pBantu = pBantu->next;
   no++;
  }
  cout<<"======================================"<<endl;
 }
 cout<<endl;
}
