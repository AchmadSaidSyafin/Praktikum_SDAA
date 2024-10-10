#include <iostream>
#include <string>

using namespace std;

struct OlehOleh {
    string id;
    string nama;
    int harga;
    OlehOleh* next; 
};

OlehOleh* head = nullptr; 
int jumlahOlehOleh = 0; 

struct Stack {
    OlehOleh* top;
    
    Stack() : top(nullptr) {}
    
    void push(OlehOleh* newOlehOleh) {
        newOlehOleh->next = top;
        top = newOlehOleh;
    }
    
    OlehOleh* pop() {
        if (top == nullptr) return nullptr;
        OlehOleh* temp = top;
        top = top->next;
        return temp;
    }
};

struct Queue {
    OlehOleh* front;
    OlehOleh* rear;
    
    Queue() : front(nullptr), rear(nullptr) {}
    
    void enqueue(OlehOleh* newOlehOleh) {
        newOlehOleh->next = nullptr;
        if (rear) {
            rear->next = newOlehOleh;
        } else {
            front = newOlehOleh;
        }
        rear = newOlehOleh;
    }
    
    OlehOleh* dequeue() {
        if (front == nullptr) return nullptr;
        OlehOleh* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        return temp;
    }
};

Stack stack;
Queue queue;

void tambahOlehOleh() {
    OlehOleh* newOlehOleh = new OlehOleh; 
    newOlehOleh->id = to_string(++jumlahOlehOleh);
    cout << "Masukkan nama oleh-oleh: ";
    cin >> newOlehOleh->nama;
    cout << "Masukkan harga oleh-oleh: ";
    cin >> newOlehOleh->harga;

    newOlehOleh->next = head; 
    head = newOlehOleh; 
    
    stack.push(newOlehOleh);
    queue.enqueue(newOlehOleh);
    
    cout << "Oleh-oleh berhasil ditambahkan!\n";
}

void tampilkanOlehOleh() {
    if (head == nullptr) {
        cout << "Belum ada data oleh-oleh.\n";
    } else {
        OlehOleh* current = head;
        while (current != nullptr) {
            cout << "ID: " << current->id << ", Nama: " << current->nama << ", Harga: " << current->harga << endl;
            current = current->next; 
        }
    }
}

void updateOlehOleh() {
    string id;
    cout << "Masukkan ID oleh-oleh yang ingin diupdate: ";
    cin >> id;

    OlehOleh* current = head;
    while (current != nullptr) {
        if (current->id == id) {
            cout << "Masukkan nama baru oleh-oleh: ";
            cin >> current->nama;
            cout << "Masukkan harga baru oleh-oleh: ";
            cin >> current->harga;
            cout << "Data oleh-oleh berhasil diupdate!\n";
            return;
        }
        current = current->next; 
    }
    cout << "ID tidak ditemukan.\n";
}

void hapusOlehOleh() {
    string id;
    cout << "Masukkan ID oleh-oleh yang ingin dihapus: ";
    cin >> id;

    OlehOleh* current = head;
    OlehOleh* previous = nullptr;

    while (current != nullptr) {
        if (current->id == id) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next; 
            }
            delete current; 
            jumlahOlehOleh--;
            cout << "Data oleh-oleh berhasil dihapus!\n";
            return;
        }
        previous = current;
        current = current->next; 
    }
    cout << "ID tidak ditemukan.\n";
}

void tampilkanStack() {
    if (stack.top == nullptr) {
        cout << "Stack kosong.\n";
        return;
    }
    cout << "Isi Stack:\n";
    OlehOleh* current = stack.top;
    while (current != nullptr) {
        cout << "ID: " << current->id << ", Nama: " << current->nama << ", Harga: " << current->harga << endl;
        current = current->next; 
    }
}

void tampilkanQueue() {
    if (queue.front == nullptr) {
        cout << "Queue kosong.\n";
        return;
    }
    cout << "Isi Queue:\n";
    OlehOleh* current = queue.front;
    while (current != nullptr) {
        cout << "ID: " << current->id << ", Nama: " << current->nama << ", Harga: " << current->harga << endl;
        current = current->next; 
    }
}

int main() {
    int pilihan;

    do {
        cout << "\nMenu Manajemen Oleh-Oleh Khas Bali:\n";
        cout << "1. Tambah oleh-oleh\n";
        cout << "2. Tampilkan oleh-oleh\n";
        cout << "3. Update oleh-oleh\n";
        cout << "4. Hapus oleh-oleh\n";
        cout << "5. Tampilkan Stack\n";
        cout << "6. Tampilkan Queue\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahOlehOleh();
            break;
        case 2:
            tampilkanOlehOleh();
            break;
        case 3:
            updateOlehOleh();
            break;
        case 4:
            hapusOlehOleh();
            break;
        case 5:
            tampilkanStack();
            break;
        case 6:
            tampilkanQueue();
            break;
        case 7:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 7);

    while (head != nullptr) {
        OlehOleh* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
