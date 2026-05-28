#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

#define MAX 5

struct Queue {
    int head = -1;
    int tail = -1;
    string data[MAX];
};

Queue q;

bool isFull() {
    // Antrean penuh jika posisi tail tepat di belakang head secara melingkar
    if ((q.tail + 1) % MAX == q.head) {
        return true;
    }
    return false;
}

bool isEmpty() {
    if (q.head == -1 && q.tail == -1) {
        return true;
    }
    return false;
}

void enqueue(string input) {
    if (isFull()) {
        cout << "Antrean penuh!" << endl;
        return;
    }
    
    // Jika antrean benar-benar kosong, inisialisasi head dan tail ke 0
    if (isEmpty()) {
        q.head = 0;
        q.tail = 0;
        q.data[q.tail] = input;
    } else {
        // Geser tail secara melingkar
        q.tail = (q.tail + 1) % MAX;
        q.data[q.tail] = input;
    }
    cout << "\"" << input << "\" berhasil ditambahkan ke antrean." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrean kosong!" << endl;
        return;
    }
    
    cout << "\"" << q.data[q.head] << "\" berhasil dihapus dari antrean." << endl;
    
    // Jika hanya ada satu elemen tersisa, reset antrean ke kondisi kosong
    if (q.head == q.tail) {
        q.head = -1;
        q.tail = -1;
    } else {
        // Geser head secara melingkar
        q.head = (q.head + 1) % MAX;
    }
}

void clear() {
    // Reset status head dan tail untuk mengosongkan antrean
    q.head = -1;
    q.tail = -1;
    cout << "Antrean berhasil dikosongkan." << endl;
}

void tampilkan() {
    if (isEmpty()) {
        cout << "Antrean kosong!" << endl;
        return;
    }
    
   
