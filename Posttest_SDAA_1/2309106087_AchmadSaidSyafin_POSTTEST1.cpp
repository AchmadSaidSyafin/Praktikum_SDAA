#include <iostream>
using namespace std;
void menara(int n, char asal, char tujuan, char sementara) {
    if (n == 1) {
        cout << "Pindahkan piringan 1 dari " << asal << " ke " << tujuan << endl;
    } else {
        menara(n - 1, asal, sementara, tujuan);
        cout << "Pindahkan piringan " << n << " dari " << asal << " ke " << tujuan << endl;
        
        menara(n - 1, sementara, tujuan, asal);
    }
}

int main() {
    int jumlah_piringan = 3; 
    menara(jumlah_piringan, 'A', 'C', 'B');
    return 0;
}
