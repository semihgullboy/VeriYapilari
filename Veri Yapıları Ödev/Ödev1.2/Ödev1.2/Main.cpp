#include <iostream>
#include <algorithm>
#include "Stack.h"
#include  "Queue.h"


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

    int kisisayisi;
    int toplamislem = 0;
    int toplamislem2 = 0;

    cout << "Kuyruktaki ki�i say�s� : ";
    cin >> kisisayisi;

    int* randomsure = new int[kisisayisi];
    randomzaman(kisisayisi, randomsure);

    int* beklemesuresikuyruk1 = new int[kisisayisi];
    int* beklemesuresikuyruk2 = new int[kisisayisi];
    int* templ = new int[kisisayisi];


    cout << endl;
    cout << "------------------FIFO KUYRU�UNA G�RE ��LEM �EKL�------------------ - " << endl;
    cout << endl;

    Queue kuyruk;
    for (int i = 0; i < kisisayisi; i++)
    {
        kuyruk.enqueue(i);
        cout << " nolu ki�inin s�resi : " << randomsure[i] << endl;
        toplamislem2 += randomsure[i];
        beklemesuresikuyruk1[i] = toplamislem2 - randomsure[i];
        kuyruk.dequeue();
        cout << " nolu ki�inin i�lemi bitti. " << endl;
        cout << i + 1 << " nolu ki�inin  i�lem  tamamlama s�resi : " << toplamislem2 << endl;
    }

    cout << endl;
    cout << "------------------��LEM S�RES� �NCEL���NE G�RE ��LEM �EKL� ------------------ - " << endl;
    cout << endl;

    for (int i = 0; i < kisisayisi; i++)
    {
        templ[i] = randomsure[i];
    }

    sort(templ, templ + kisisayisi);

    Queue kuyruk2;

    for (int i = 0; i < kisisayisi; i++)
    {
        for (int j = 0; j < kisisayisi; j++)
        {
            if (templ[i] == randomsure[j]) {
                kuyruk2.enqueue(j);
                cout << " nolu kisinin suresi : " << randomsure[j] << endl;
                kuyruk2.dequeue();
                cout << " nolu kisinin islemi bitti. " << endl;
                toplamislem += randomsure[j];
                beklemesuresikuyruk2[j] = toplamislem - randomsure[j];
                cout << j + 1 << " nolu kisinin  islem  tamamlama suresi : " << toplamislem << endl;
            }
        }

    }

    cout << endl;
    cout << "Ortalama islem suresi : " << toplamislem / kisisayisi << endl;
    cout << endl;

    for (int i = 0; i < kisisayisi; i++)
    {
        int beklemesuresi = beklemesuresikuyruk2[i] - beklemesuresikuyruk1[i];
        cout << i + 1 << " nolu ki�inin f�fo kuyru�una g�re bekleme s�resi :" << beklemesuresi << endl;
    }




}