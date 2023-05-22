#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

class Storage {
    int* arr;
    int size;
    static int usedMemory; // Общий обьём всей занятой памяти (байт)
public:
    Storage(int usize) { // Выделить память + рандомно заполнить + сказать сколько занято под него и все хранилища
        size = usize;
        Storage::usedMemory += 4*size;
        arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100;
        }

    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    /*void setMem(int mem) {
        Storage::usedMemory += mem;
        cout << "Выделено больше памяти.\n";
    }*/

    static int getMemory() {
        return Storage::usedMemory;
    }

    ~Storage()
    {
        if (arr)
        {
            delete[]arr;
        }
        Storage::usedMemory -= size * 4;

        cout << "Очищено " << 4*size << " байт памяти\n";
        
        cout << "Осталось "<< getMemory()<<" байт памяти. "  << endl << endl;
    }
    
};

int Storage::usedMemory{ 0 };

void main() {

    setlocale(0, "");
    srand(time(NULL));

    Storage box{ 10 };
    cout << "Box:\n";
    box.print();
    cout << "Память: " << box.getMemory()<<" Байт" << endl;

    Storage shop{ 20 };
    cout << "\nShop:\n";
    shop.print();
    cout << "Память: " << shop.getMemory() << " Байт" << endl << endl;



}
