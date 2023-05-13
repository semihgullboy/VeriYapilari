#include <iostream>
#include <queue>
#include <list>
#include "Stack.h" 
#include "Queue.h"

using namespace std;

// Her birinin i�leminin 30 saniye ile 300 sn. aras�nda random bir zaman ald��� fonksiyon

void randomzaman(int kisiSayisi, int randomsure[]) {
    int randomislemsuresi;

    srand(time(0));

    for (int i = 0; i < kisiSayisi; i++) {
        randomislemsuresi = 30 + rand() % 270;
        randomsure[i] = randomislemsuresi;
    }
}

int main() {
    setlocale(LC_ALL, "Turkish"); //T�rk�e karakter

    int kisiSayisi;
    int toplamislem = 0;
    cout << "Kuyruktaki ki�i say�s� : ";
    cin >> kisiSayisi;

    int* randomsure = new int[kisiSayisi];
    randomzaman(kisiSayisi, randomsure);

    Queue kuyruk;
    for (int i = 0; i < kisiSayisi; i++)
    {
        kuyruk.enqueue(i);
        cout << i + 1 << " nolu ki�inin i�lem s�resi : " << randomsure[i];
        cout << " " << endl;
        kuyruk.dequeue();
        toplamislem += randomsure[i];
        cout << i + 1 << " numaral� ki�inin toplam i�lem tamamlama s�resi : " << toplamislem << endl;
    }


    cout << endl;
    cout << "Ortalama i�lem s�resi : " << toplamislem / kisiSayisi << endl;
    cout << endl;




}