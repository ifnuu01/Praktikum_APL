#include <iostream>
using namespace std;


void enter();
void menuManagemantSpeaker(string speaker[], int jumlahProduk[], int hargaProduk[], int jumlahSpeaker);
void lihatMerkSpeaker(string speaker[],int jumlahProduk[],int hargaProduk[], int jumlahSpeaker);
string tambahSpeaker();
int tambahJumlahProduk();
int tambahHargaProduk();
void ubahMerkSpeaker(string speaker[],int jumlahProduk[],int hargaProduk[] ,int jumlahSpeaker);
void hapusMerkSpeaker(string speaker[],int jumlahProduk[],int hargaProduk[], int jumlahSpeaker);
void login(string speaker[], int jumlahProduk[], int hargaProduk[], int jumlahSpeaker, int batasLogin);

int main() {
    string speaker[100] ={
        "JBL", "Sony"
    };
    int jumlahProduk[100]={
        10, 10
    };
    int hargaProduk[100]={
        1000000, 2000000
    };
    int jumlahSpeaker = 2;
    int batasLogin = 0;

    login(speaker, jumlahProduk, hargaProduk, jumlahSpeaker, batasLogin);
    return 0;
}

void enter() {
    cout << "Tekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
    system("cls || clear");
}

void menuManagemantSpeaker(string speaker[], int jumlahProduk[], int hargaProduk[], int jumlahSpeaker) {
    system("cls || clear");
    int pilih;
    cout << "Menu Managemant Speaker\n";
    cout << "=======================\n";
    cout << "1. Melihat Merk Speaker\n";
    cout << "2. Menambah Merk Speaker\n";
    cout << "3. Mengubah Merk Speaker\n";
    cout << "4. Menghapus Merk Speaker\n";
    cout << "5. Keluar\n";
    cout << "Pilih Menu : ";

    cin >> pilih;
    system("cls || clear");

    switch (pilih) {
        case 1:
            lihatMerkSpeaker(speaker, jumlahProduk, hargaProduk, jumlahSpeaker);
            enter();
            break;
        case 2:
            cout << "Menambah Merk Speaker\n";
            speaker[jumlahSpeaker] = tambahSpeaker();
            jumlahProduk[jumlahSpeaker] = tambahJumlahProduk();
            hargaProduk[jumlahSpeaker] = tambahHargaProduk();
            jumlahSpeaker++;
            cout << "Merk Speaker berhasil ditambahkan\n";
            enter();
            break;
        case 3:
            ubahMerkSpeaker(speaker, jumlahProduk, hargaProduk, jumlahSpeaker);
            enter();
            break;
        case 4:
            hapusMerkSpeaker(speaker, jumlahProduk, hargaProduk, jumlahSpeaker);
            jumlahSpeaker--;
            enter();
            break;
        case 5:
            cout << "Terima Kasih\n";
            return;
        default:
            cout << "Menu tidak tersedia\n";
            break;
    }

    menuManagemantSpeaker(speaker, jumlahProduk, hargaProduk, jumlahSpeaker);
}

void lihatMerkSpeaker(string speaker[],int jumlahProduk[],int hargaProduk[], int jumlahSpeaker) {
    cout << "Merk Speaker\n";
    cout << "============\n";
    for (int i = 0; i < jumlahSpeaker; i++) {
        cout << i + 1 << ". "<<"Nama Produk: " << speaker[i] << endl;
        cout <<"Jumlah Produk: " << jumlahProduk[i] << endl;
        cout <<"Harga Produk: " << hargaProduk[i] << endl;
        cout <<"=====================\n";
    }
}

string tambahSpeaker(){
    string speaker;
    cout << "Masukkan Nama Speaker: ";
    cin.ignore();
    getline(cin, speaker);
    return speaker;
}
int tambahJumlahProduk(){
    int jumlahProduk;
    cout << "Masukkan Jumlah Produk: ";
    cin >> jumlahProduk;
    return jumlahProduk;
}

int tambahHargaProduk(){
    int hargaProduk;
    cout << "Masukkan Harga Produk: ";
    cin >> hargaProduk;
    return hargaProduk;
}

void ubahMerkSpeaker(string speaker[],int jumlahProduk[],int hargaProduk[] ,int jumlahSpeaker) {
    int pilih;
    if (jumlahSpeaker == 0){
        cout << "Merk Speaker tidak ditemukan\n";
        return;
    }
    lihatMerkSpeaker(speaker, jumlahProduk, hargaProduk, jumlahSpeaker);
    cout << "Pilih Merk Speaker yang akan diubah: ";
    cin >> pilih;
    cout << "=====================\n";
    if (pilih > jumlahSpeaker or pilih < 1) {
        cout << "Merk Speaker tidak ditemukan\n";
        return;
    }else{
        pilih--;
        speaker[pilih] = tambahSpeaker();
        jumlahProduk[pilih] = tambahJumlahProduk();
        hargaProduk[pilih] = tambahHargaProduk();
        cout << "Merk Speaker berhasil diubah\n";
    }
}

void hapusMerkSpeaker(string speaker[],int jumlahProduk[],int hargaProduk[], int jumlahSpeaker){
    int nomorHapus;
    if (jumlahSpeaker == 0){
        cout << "Merk Speaker tidak ditemukan\n";
        return;
    }
    lihatMerkSpeaker(speaker, jumlahProduk, hargaProduk, jumlahSpeaker);
    cout << "Masukkan nomor merk speaker yang ingin dihapus : ";
    cin >> nomorHapus;
    if (nomorHapus > jumlahSpeaker){
        cout << "Merk Speaker tidak ditemukan\n";
        return;
    }else{
    nomorHapus--;
    for (int i = nomorHapus; i < jumlahSpeaker; i++){
        speaker[i] = speaker[i+1];
        jumlahProduk[i] = jumlahProduk[i+1];
        hargaProduk[i] = hargaProduk[i+1];
    };
    cout << "Merk Speaker berhasil dihapus\n";
    }
}

void login(string speaker[], int jumlahProduk[], int hargaProduk[], int jumlahSpeaker , int batasLogin){
    string inputNama,inputNIM;
    system("cls || clear");
    cout << "Halaman Login \n";
    cout << "=============\n";
    cout << "Masukkan Nama : ";
    getline(cin, inputNama);
    cout << "Masukkan NIM : ";
    getline(cin, inputNIM);
    system("cls || clear");  

    if (inputNama == "Ifnu Umar" && inputNIM == "2309106060"){
        cout << "Login Berhasil\n";
        enter();
        system("cls || clear");
        menuManagemantSpeaker(speaker, jumlahProduk, hargaProduk, jumlahSpeaker);
    } else if (batasLogin == 2){
        cout << "Anda telah mencoba login sebanyak 3 kali, coba lagi lain kali...\n";
        return;
    } else {
        cout << "Login Gagal\n";
        login(speaker, jumlahProduk, hargaProduk, jumlahSpeaker,batasLogin+1);
    };
};
