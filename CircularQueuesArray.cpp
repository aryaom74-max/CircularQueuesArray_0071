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

