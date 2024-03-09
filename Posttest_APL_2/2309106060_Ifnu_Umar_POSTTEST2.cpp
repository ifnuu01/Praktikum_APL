#include <iostream>
using namespace std;

void enter(){
    cout << "Tekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
    system("cls || clear");
}

void melihatMerkSpeaker(string speaker[], int jumlahSpeaker){
    cout << "Merk Speaker yang tersedia : \n";
    for (int i = 0; i < jumlahSpeaker; i++){
        cout << i+1 << ". " << speaker[i] << endl;
    }cout << "=========================\n";
}

void tambahMerkSpeaker(string speaker[], int jumlahSpeaker){
    cout << "Masukkan Merk Speaker yang ingin ditambahkan : ";
    cin.ignore();
    getline(cin, speaker[jumlahSpeaker]);
    jumlahSpeaker++;
    cout << "Merk Speaker berhasil ditambahkan\n";
}

void ubahMerkSpeaker(string speaker[], int jumlahSpeaker){
    int nomorUbah;
    cout << "Masukkan nomor merk speaker yang ingin diubah : ";
    cin >> nomorUbah;
    cout << "Masukkan merk speaker yang baru : ";
    cin.ignore();
    getline(cin, speaker[nomorUbah-1]);
    cout << "Merk Speaker berhasil diubah\n";
}

void hapusMerkSpeaker(string speaker[], int jumlahSpeaker){
    int nomorHapus;
    cout << "Masukkan nomor merk speaker yang ingin dihapus : ";
    cin >> nomorHapus;
    for (int i = nomorHapus-1; i < jumlahSpeaker; i++){
        speaker[i] = speaker[i+1];
    };
    cout << "Merk Speaker berhasil dihapus\n";
}

int main()
{
    string inputNama,inputNIM;
    string speaker[100] = {"JBL", "Sony", "Bose", "Harman Kardon", "Polytron", "Logitech", "Sonic Gear", "Razer", "Steel Series", "Corsair"};
    int batasLogin,pilih,jumlahSpeaker,nomorUbah;
    jumlahSpeaker = 10;
    batasLogin = 0;
    system("cls || clear");    
    do{
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
            break;
        } else if (batasLogin == 2){
            cout << "Anda telah mencoba login sebanyak 3 kali, coba lagi lain kali...\n";
            return 0;
        } else {
            cout << "Login Gagal\n";
            batasLogin++;
        };
    }while(batasLogin < 3);

    do{
        cout << "Halaman Managemant Merk Speaker\n";
        cout << "==============================\n";
        cout << "1. Melihat Merk Speaker\n";
        cout << "2. Tambah Merk Speaker\n";
        cout << "3. Ubah Merk Speaker\n";
        cout << "4. Hapus Merk Speaker\n";
        cout << "5. Keluar\n";
        cout << "Pilih Menu : ";
        cin >> pilih;
        system("cls || clear");

        switch (pilih)
        {
        case 1:
            melihatMerkSpeaker(speaker, jumlahSpeaker);
            enter();
            break;
        case 2:
            melihatMerkSpeaker(speaker, jumlahSpeaker);
            tambahMerkSpeaker(speaker, jumlahSpeaker);
            jumlahSpeaker++;
            enter();
            break;
        case 3:
            melihatMerkSpeaker(speaker, jumlahSpeaker);
            ubahMerkSpeaker(speaker, jumlahSpeaker);
            enter();
            break;
        case 4:
            melihatMerkSpeaker(speaker, jumlahSpeaker);
            hapusMerkSpeaker(speaker, jumlahSpeaker);
            jumlahSpeaker--;
            enter();
            break;
        case 5:
            cout << "Terima Kasih\n";
            break;
        default:
            cout << "Menu tidak tersedia\n";
            cout << "Silahkan pilih menu yang tersedia\n";
            enter();
            break;
        };
    }while(pilih != 5);

    return 0;
}

