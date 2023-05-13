#include <iostream>
#include <queue>
#include <list>
#include "Stack.h" 
#include "Queue.h"

using namespace std;

// Her birinin iþleminin 30 saniye ile 300 sn. arasýnda random bir zaman aldýðý fonksiyon

void randomzaman(int kisiSayisi, int randomsure[]) {
    int randomislemsuresi;

    srand(time(0));

    for (int i = 0; i < kisiSayisi; i++) {
        randomislemsuresi = 30 + rand() % 270;
        randomsure[i] = randomislemsuresi;
    }
}

int main() {
    setlocale(LC_ALL, "Turkish"); //Türkçe karakter

    int kisiSayisi;
    int toplamislem = 0;
    cout << "Kuyruktaki kiþi sayýsý : ";
    cin >> kisiSayisi;

    int* randomsure = new int[kisiSayisi];
    randomzaman(kisiSayisi, randomsure);

    Queue kuyruk;
    for (int i = 0; i < kisiSayisi; i++)
    {
        kuyruk.enqueue(i);
        cout << i + 1 << " nolu kiþinin iþlem süresi : " << randomsure[i];
        cout << " " << endl;
        kuyruk.dequeue();
        toplamislem += randomsure[i];
        cout << i + 1 << " numaralý kiþinin toplam iþlem tamamlama süresi : " << toplamislem << endl;
    }


    cout << endl;
    cout << "Ortalama iþlem süresi : " << toplamislem / kisiSayisi << endl;
    cout << endl;




}