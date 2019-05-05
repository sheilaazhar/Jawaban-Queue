/* 
Nama		: Sheila Azhar Almufarida & Putri Nabila
NPM			: 140810180001 & 140810180007
deksripsi	: Mencetak nama penyetor untuk donatur bantuan penyenbuhan kanker dalam queue (No. 2)
*/

#include <iostream>
using namespace std;

#include<iostream>
using namespace std;

struct ElementQueue{
 	char nama[100];
 	int setoran;
 	ElementQueue* next;
};
typedef ElementQueue* pointer;

struct Queue{
 	pointer head;
	pointer tail;
}Q;

void createElement(pointer& pBaru, int& antrian){
 	pBaru = new ElementQueue; 
 	cout << "penyetor ke-" << antrian << endl;
 	cout << "Nama\t: "; cin >> pBaru->nama;
    cout << "donasi(Rp)\t: "; cin >> pBaru->setoran;
 	pBaru->next = NULL;
    antrian++;
}

void insertQueue(pointer pBaru){
    if (Q.head == NULL && Q.tail == NULL){
        Q.head = pBaru;
        Q.tail = pBaru;
    }
else {
        Q.tail->next = pBaru;
        Q.tail = pBaru;
    }
}

void cetakSetor(pointer pBantu){
    pBantu = Q.head;
    cout << " Nama Penyetor dan Jumlahnya " << endl;
    do{
        cout << "Nama: " << pBantu->nama << "\t\t|| " << "donasi: " << pBantu->setoran << endl;
        pBantu = pBantu->next;
    }while (pBantu != NULL);
}
void jumlahSetor (pointer pBantu, int& total){
    pBantu = Q.head;
    total = 0;
    do{
        total += pBantu->setoran;
        pBantu = pBantu->next;
    }while (pBantu != NULL);
}
int main(){
    pointer kantor;
    int antrian = 1, month = 1, pilihan;
    int total = 0, n;

    do{
        system("cls");
         cout<<"================================================="<<  endl ;
        cout << "Bantuan Untuk Pengobatan Kanker Putri Nabila " << endl;
        cout<<"================================================="<<  endl ;
        
        cout << "Bulan ke-" << month << endl;
        cout << "Total uang masuk(Rp): " << total << endl;
		cout << "[1] Masukkan Data Penyetor" << endl;
        cout << "[2] Cetak data setoran" << endl;
        cout << "[3] Selesai" << endl;
        cout << "Masukan Pilihan: "; cin >> pilihan;
        switch(pilihan){
            case 1:
                cout << "Berapa banyak penyetor : "; cin >> n;
                for (int i = 0; i < n; i++){
                    createElement(kantor, antrian);
                    insertQueue(kantor);
                }
                month++;
                jumlahSetor(kantor, total);
                system("PAUSE");
                break;

            case 2:
            	int Setor;
                cetakSetor(kantor);
                system("PAUSE");
                break;
                
                 if (Setor < 0){
                    cout << "Dana belum cukup terkumpul!" << endl;
                    system("PAUSE");
                }

            else {
                    system("cls");
                   
                    cout << "Total uang masuk(Rp): " << total << endl;
                    cout << "Jumlah Penyetor: " << antrian-1 << " orang\n" << endl;
                    cetakSetor(kantor);
                    return(0);
                }
                break;
        }
    }while (pilihan != 0);
}

