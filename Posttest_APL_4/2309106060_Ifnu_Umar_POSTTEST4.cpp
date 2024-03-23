#include <iostream>
using namespace std;

struct Speaker {
    string merk;
    int jumlahProduk;
    int hargaProduk;
};

struct Supplier {
    string nama;
    string alamat;
    string noTelp;
};

struct dataSpeaker{
    Speaker speaker;
    Supplier supplier;
};

dataSpeaker dataBarang[100];
void enter();
void login(dataSpeaker data[], int &jumlahData, int batasLogin);
void managemaentSpeaker(dataSpeaker data[], int &jumlahData);
void lihatMerkSpeaker(dataSpeaker data[], int &jumlahData);
void tambahMerkSpeaker(dataSpeaker data[], int &jumlahData);
void ubahMerkSpeaker(dataSpeaker data[], int &jumlahData);
void hapusMerkSpeaker(dataSpeaker data[], int &jumlahData);
void getline(string prompt, string &input);

int main(int argc, char const *argv[]) {
    int jumlahData = 1;
    int batasLogin = 0;
    dataBarang[0].speaker.merk = "Polytron";
    dataBarang[0].speaker.jumlahProduk = 10;
    dataBarang[0].speaker.hargaProduk = 1000000;
    dataBarang[0].supplier.nama = "PT. Polytron";
    dataBarang[0].supplier.alamat = "Jl. Raya Bandung";
    dataBarang[0].supplier.noTelp = "08123456789";

    system("cls || clear");
    login(dataBarang, jumlahData, batasLogin);
    return 0;
}

void enter() {
    cout << "Tekan Enter untuk melanjutkan...";
    cin.get();
    system("cls || clear");
}

void getline(string prompt, string &input) {
    do{
        cout << prompt;
        getline(cin, input);
        if(input.empty()) cout << "Input tidak boleh kosong\n";
    }while(input.empty());
}

void getInputint(string prompt, int &input) {
    do{
        cout << prompt;
        cin >> input;
        if(cin.fail()|| input <= 0) {
            cin.clear();
            cin.ignore();
            cout << "Input harus angka atau lebih dari 0\n";
        }else{
            break;
        }
    }while(true);
}

void login(dataSpeaker data[], int &jumlahData, int batasLogin) {
    string inputUsername, inputPassword;
    cout << "Halaman Login\n";
    cout << "=============\n";
    getline("Masukan Nama \t: ", inputUsername);
    getline("Masukan NIM \t: ", inputPassword);
    system("cls || clear");

    if(inputUsername == "Ifnu Umar" && inputPassword == "2309106060") {
        cout << "Login Berhasil\n";
        enter();
        system("cls || clear");
        managemaentSpeaker(data, jumlahData);
    }else {
        if(batasLogin == 2) {
            cout << "Anda sudah mencapai batas login\n";
            cout << "Silahkan coba lagi nanti\n";
        } else {
            cout << "Login Gagal\n";
            cout << "Kesempatan Login " << 2 - batasLogin << endl;
            login(data, jumlahData, batasLogin + 1);
        }
    }
}

void managemaentSpeaker(dataSpeaker data[], int &jumlahData) {
    system("cls || clear");
    int pilih;
    cout << "Menu Managemant Speaker\n";
    cout << "=======================\n";
    cout << "1. Melihat Merk Speaker\n";
    cout << "2. Menambah Merk Speaker\n";
    cout << "3. Mengubah Merk Speaker\n";
    cout << "4. Menghapus Merk Speaker\n";
    cout << "5. Keluar\n";
    getInputint("Pilih Menu : ", pilih);
    system("cls || clear");

    switch (pilih) {
        case 1:
            if(jumlahData == 0) {
                cout << "Data tidak ada\n";
                cin.ignore();
                enter();
                break;
            }else{
                lihatMerkSpeaker(data, jumlahData);
                cin.ignore();
                enter();
                break;
            }
        case 2:
            tambahMerkSpeaker(data, jumlahData);
            enter();
            break;
        case 3:
            if(jumlahData == 0) {
                cout << "Data tidak ada\n";
                enter();
                break;
            }else{
                lihatMerkSpeaker(data, jumlahData);
                ubahMerkSpeaker(data, jumlahData);
                enter();
                break;
            }
        case 4:
            if(jumlahData == 0) {
                cout << "Data tidak ada\n";
                cin.ignore();
                enter();
                break;
            }else{
                lihatMerkSpeaker(data, jumlahData);
                hapusMerkSpeaker(data, jumlahData);
                cin.ignore();
                enter();
                break;
            }
        case 5:
            cout << "Terima kasih\n";
            return;
            break;
        default:
            cout << "Menu tidak tersedia\n";
            cin.ignore();
            enter();
            break;
    }
    managemaentSpeaker(data, jumlahData);
}

void lihatMerkSpeaker(dataSpeaker data[], int &jumlahData) {
    cout << "Merk Speaker :\n";
    cout << "===============================================\n";
    for(int i = 0; i < jumlahData; i++) {
        cout << "Data ke \t\t: " << i + 1 << endl;
        cout << "Merk Speaker \t\t: " << data[i].speaker.merk << endl;
        cout << "Jumlah Produk \t\t: " << data[i].speaker.jumlahProduk << endl;
        cout << "Harga Produk \t\t: " << data[i].speaker.hargaProduk << endl;
        cout << "Nama Supplier \t\t: " << data[i].supplier.nama << endl;
        cout << "Alamat Supplier \t: " << data[i].supplier.alamat << endl;
        cout << "No Telp Supplier \t: " << data[i].supplier.noTelp << endl;
        cout << "===============================================\n";
    }
}

void tambahMerkSpeaker(dataSpeaker data[], int &jumlahData) {
    cout << "Tambah Merk Speaker :\n";
    cout << "===================\n";
    cin.ignore();
    getline("Merk Speaker \t\t: ", data[jumlahData].speaker.merk);
    getInputint("Jumlah Produk \t\t: ", data[jumlahData].speaker.jumlahProduk);
    getInputint("Harga Produk \t\t: ", data[jumlahData].speaker.hargaProduk);
    cin.ignore();
    getline("Nama Supplier \t\t: ", data[jumlahData].supplier.nama);
    getline("Alamat Supplier \t: ", data[jumlahData].supplier.alamat);
    getline("No Telp Supplier \t: ", data[jumlahData].supplier.noTelp);
    jumlahData++;
}

void ubahMerkSpeaker(dataSpeaker data[] , int &jumlahData){
    int pilihData;
    cout << "Ubah Merk Speaker :\n";
    cout << "=================\n";
    getInputint("Pilih Data : ", pilihData);
    if (pilihData < 1 || pilihData > jumlahData) {
        cout << "Data tidak ada\n";
        cin.ignore();
    }else{
        cin.ignore();
        getline("Merk Speaker \t\t: ", data[pilihData - 1].speaker.merk);
        getInputint("Jumlah Produk \t\t: ", data[pilihData - 1].speaker.jumlahProduk);
        getInputint("Harga Produk \t\t: ", data[pilihData - 1].speaker.hargaProduk);
        cin.ignore();
        getline("Nama Supplier \t\t: ", data[pilihData - 1].supplier.nama);
        getline("Alamat Supplier \t: ", data[pilihData - 1].supplier.alamat);
        getline("No Telp Supplier \t: ", data[pilihData - 1].supplier.noTelp);
        cout << "Data berhasil diubah\n";
    }
}

void hapusMerkSpeaker(dataSpeaker data[], int &jumlahData){
    int pilihData;
    cout << "Hapus Merk Speaker :\n";
    cout << "==================\n";
    getInputint("Pilih Data : ", pilihData);
    if (pilihData < 1 || pilihData > jumlahData) {
        cout << "Data tidak ada\n";
        cin.ignore();
    }else {
        for (int i = pilihData - 1; i < jumlahData; i++) {
            data[i] = data[i + 1];
        }
        jumlahData--;
        cout << "Data berhasil dihapus\n";
    }
}