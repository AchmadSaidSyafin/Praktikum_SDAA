#include <iostream>
#include <string>

using namespace std;

const int MAX = 100; 

struct OlehOleh {
    string id;
    string nama;
    int harga;
};

OlehOleh olehOlehList[MAX]; 
int jumlahOlehOleh = 0; 

void tambahOlehOleh() {
    if (jumlahOlehOleh < MAX) {
        OlehOleh* olehOleh = &olehOlehList[jumlahOlehOleh]; 
        olehOleh->id = jumlahOlehOleh + 1;
        cout << "Masukkan nama oleh-oleh: ";
        cin >> olehOleh->nama;
        cout << "Masukkan harga oleh-oleh: ";
        cin >> olehOleh->harga;
        jumlahOlehOleh++;
        cout << "Oleh-oleh berhasil ditambahkan!\n";
    } else {
        cout << "Kapasitas maksimal sudah tercapai!\n";
    }
}


void tampilkanOlehOleh() {
    if (jumlahOlehOleh == 0) {
        cout << "Belum ada data oleh-oleh.\n";
    } else {
        for (int i = 0; i < jumlahOlehOleh; i++) {
            OlehOleh* olehOleh = &olehOlehList[i];
            cout << "ID: " << olehOleh->id << ", Nama: " << olehOleh->nama << ", Harga: " << olehOleh->harga << endl;
        }
    }
}


void updateOlehOleh() {
    int id;
    cout << "Masukkan ID oleh-oleh yang ingin diupdate: ";
    cin >> id;
    if (id > 0 && id <= jumlahOlehOleh) {
        OlehOleh* olehOleh = &olehOlehList[id - 1];
        cout << "Masukkan nama baru oleh-oleh: ";
        cin >> olehOleh->nama;
        cout << "Masukkan harga baru oleh-oleh: ";
        cin >> olehOleh->harga;
        cout << "Data oleh-oleh berhasil diupdate!\n";
    } else {
        cout << "ID tidak ditemukan.\n";
    }
}


void hapusOlehOleh() {
    int id;
    cout << "Masukkan ID oleh-oleh yang ingin dihapus: ";
    cin >> id;
    if (id > 0 && id <= jumlahOlehOleh) {
        for (int i = id - 1; i < jumlahOlehOleh - 1; i++) {
            olehOlehList[i] = olehOlehList[i + 1];
        }
        jumlahOlehOleh--;
        cout << "Data oleh-oleh berhasil dihapus!\n";
    } else {
        cout << "ID tidak ditemukan.\n";
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
        cout << "5. Keluar\n";
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
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}
