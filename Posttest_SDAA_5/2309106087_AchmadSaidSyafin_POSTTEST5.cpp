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

// Quick Sort Function for ascending order
OlehOleh* partition(OlehOleh* low, OlehOleh* high) {
    int pivot = high->harga;
    OlehOleh* i = low->next;

    for (OlehOleh* j = low; j != high; j = j->next) {
        if (j->harga < pivot) {
            swap(i->harga, j->harga);
            swap(i->nama, j->nama);
            swap(i->id, j->id);
            i = (i == nullptr) ? low : i->next;
        }
    }
    swap(i->harga, high->harga);
    swap(i->nama, high->nama);
    swap(i->id, high->id);
    return i;
}

void quickSort(OlehOleh* low, OlehOleh* high) {
    if (high != nullptr && low != high && low != high->next) {
        OlehOleh* pivot = partition(low, high);
        quickSort(low, pivot->next);
        quickSort(pivot->next, high);
    }
}

void sortAscending() {
    if (head == nullptr) return;

    // Find the last node
    OlehOleh* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    quickSort(head, current);
    cout << "Oleh-oleh berhasil diurutkan dalam urutan ascending berdasarkan harga.\n";
}

// Shell Sort Function for descending order
void shellSort() {
    if (head == nullptr) return;

    // Count the number of nodes
    int n = 0;
    OlehOleh* current = head;
    while (current != nullptr) {
        n++;
        current = current->next;
    }

    // Shell sort algorithm
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            current = head;
            // Move current to the ith node
            for (int j = 0; j < i; j++) {
                current = current->next;
            }

            OlehOleh* temp = current;
            int temp_harga = temp->harga;
            string temp_nama = temp->nama;
            string temp_id = temp->id;

            int j;
            for (j = i; j >= gap; j -= gap) {
                OlehOleh* temp_current = head;
                for (int k = 0; k < j - gap; k++) {
                    temp_current = temp_current->next;
                }

                if (temp_harga > temp_current->harga) {
                    temp_current->harga = temp->harga;
                    temp_current->nama = temp->nama;
                    temp_current->id = temp->id;
                } else {
                    break;
                }
            }

            OlehOleh* temp_current = head;
            for (int k = 0; k < j; k++) {
                temp_current = temp_current->next;
            }
            temp_current->harga = temp_harga;
            temp_current->nama = temp_nama;
            temp_current->id = temp_id;
        }
    }
    cout << "Oleh-oleh berhasil diurutkan dalam urutan descending berdasarkan harga.\n";
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
        cout << "7. Urutkan oleh-oleh (Ascending)\n";
        cout << "8. Urutkan oleh-oleh (Descending)\n";
        cout << "9. Keluar\n";
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
            sortAscending();
            break;
        case 8:
            shellSort();
            break;
        case 9:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 9);

    while (head != nullptr) {
        OlehOleh* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
