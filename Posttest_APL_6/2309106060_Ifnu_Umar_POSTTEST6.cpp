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
void getline(string prompt, string *input);
void getInputint(string prompt, int *input,string message);
void bubbleSortDescending(dataSpeaker data[], int jumlahData);
void selectionSortAscending(dataSpeaker data[], int jumlahData);
void insertionSortAscending(dataSpeaker data[], int jumlahDara);
void urutanData(int jumlahData);
void binarySearchAscending(dataSpeaker data[], int jumlahData, string cari);
void interpolationSearchDescending(dataSpeaker data[], int jumlahData, string cari);
void pencarianData(int jumlahData);


int main() {
    int jumlahData = 4;
    int batasLogin = 0;
    dataBarang[0].speaker.merk = "Polytron";
    dataBarang[0].speaker.jumlahProduk = 10;
    dataBarang[0].speaker.hargaProduk = 1000000;
    dataBarang[0].supplier.nama = "PT. Polytron";
    dataBarang[0].supplier.alamat = "Jl. Raya Bandung";
    dataBarang[0].supplier.noTelp = "08123456789";

    dataBarang[1].speaker.merk = "JBL";
    dataBarang[1].speaker.jumlahProduk = 10;
    dataBarang[1].speaker.hargaProduk = 1000021;
    dataBarang[1].supplier.nama = "PT. JBL";
    dataBarang[1].supplier.alamat = "Jl. Raya Bandung";
    dataBarang[1].supplier.noTelp = "08123456789";
    
    dataBarang[2].speaker.merk = "Sony";
    dataBarang[2].speaker.jumlahProduk = 10;
    dataBarang[2].speaker.hargaProduk = 290000;
    dataBarang[2].supplier.nama = "PT. Sony";
    dataBarang[2].supplier.alamat = "Jl. Raya Bandung";
    dataBarang[2].supplier.noTelp = "08123456789";
    
    dataBarang[3].speaker.merk = "Sharp";
    dataBarang[3].speaker.jumlahProduk = 10;
    dataBarang[3].speaker.hargaProduk = 1500000;
    dataBarang[3].supplier.nama = "PT. Sharp";
    dataBarang[3].supplier.alamat = "Jl. Raya Bandung";
    dataBarang[3].supplier.noTelp = "08123456789";

    system("cls || clear");
    login(dataBarang, jumlahData, batasLogin);
    return 0;
}

void enter() {
    cout << "Tekan Enter untuk melanjutkan...";
    cin.get();
    system("cls || clear");
}

void getlineInput(string prompt, string *input) {
    do{
        cout << prompt;
        getline(cin, *input);
        if(input->empty()) cout << "Input tidak boleh kosong\n";
    }while(input->empty());
}

void getInputint(string prompt, int *input, string message) {
    do{
        cout << prompt;
        cin >> *input;
        if (message == "1"){
            if(cin.fail()|| *input <= 0) {
                cin.clear();
                cin.ignore();
                cout << "Input harus angka atau lebih dari 0\n"; 
            }else{
                break;
            }
        }else if (message == "2"){
            if(cin.fail()|| *input < 0) {
                cin.clear();
                cin.ignore();
                cout << "Input harus angka dan tidak boleh mines\n"; 
            }else{
                break;
            }
        }else{
            break;
        }
    }while(true);
}

void login(dataSpeaker data[], int &jumlahData, int batasLogin) {
    string inputUsername, inputPassword;
    cout << "Halaman Login\n";
    cout << "=============\n";
    getlineInput("Masukan Nama \t: ", &inputUsername);
    getlineInput("Masukan NIM \t: ", &inputPassword);
    system("cls || clear");

    if(inputUsername == "Ifnu umar" && inputPassword == "2309106060") {
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
    cout << "5. Search Merk Speaker\n";
    cout << "6. Keluar\n";
    getInputint("Pilih Menu : ", &pilih, "1");
    system("cls || clear");

    switch (pilih) {
        case 1:
            if(jumlahData == 0) {
                cout << "Data tidak ada\n";
                cin.ignore();
                enter();
                break;
            }else{
                urutanData(jumlahData);
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
                cin.ignore();
                enter();
                break;
            }else{
                urutanData(jumlahData);
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
                urutanData(jumlahData);
                hapusMerkSpeaker(data, jumlahData);
                cin.ignore();
                enter();
                break;
            }
        case 5:
            if(jumlahData == 0){
                cout << "Data tidak ada\n";
                cin.ignore();
                enter();
                break;
            }else{
                pencarianData(jumlahData);
                cin.ignore();
                enter();
                break;
            }
        case 6:
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
    getlineInput("Merk Speaker \t\t: ", &data[jumlahData].speaker.merk);
    getInputint("Jumlah Produk \t\t: ", &data[jumlahData].speaker.jumlahProduk,"1");
    getInputint("Harga Produk \t\t: ", &data[jumlahData].speaker.hargaProduk,"1");
    cin.ignore();
    getlineInput("Nama Supplier \t\t: ", &data[jumlahData].supplier.nama);
    getlineInput("Alamat Supplier \t: ", &data[jumlahData].supplier.alamat);
    getlineInput("No Telp Supplier \t: ", &data[jumlahData].supplier.noTelp);
    jumlahData++;
}

void ubahMerkSpeaker(dataSpeaker data[] , int &jumlahData){
    int pilihData;
    cout << "Ubah Merk Speaker :\n";
    cout << "=================\n";
    getInputint("Pilih Data (Ketik 0 untuk keluar) : ", &pilihData,"2");
    if (pilihData == 0){ 
        managemaentSpeaker(data, jumlahData);
    }else if (pilihData < 1 || pilihData > jumlahData) {
        cout << "Data tidak ada\n";
        cin.ignore();
    }else{
        cin.ignore();
        getlineInput("Merk Speaker \t\t: ", &data[pilihData - 1].speaker.merk);
        getInputint("Jumlah Produk \t\t: ", &data[pilihData - 1].speaker.jumlahProduk,"1");
        getInputint("Harga Produk \t\t: ", &data[pilihData - 1].speaker.hargaProduk,"1");
        cin.ignore();
        getlineInput("Nama Supplier \t\t: ", &data[pilihData - 1].supplier.nama);
        getlineInput("Alamat Supplier \t: ", &data[pilihData - 1].supplier.alamat);
        getlineInput("No Telp Supplier \t: ", &data[pilihData - 1].supplier.noTelp);
        cout << "Data berhasil diubah\n";
    }
}

void hapusMerkSpeaker(dataSpeaker data[], int &jumlahData){
    int pilihData;
    cout << "Hapus Merk Speaker :\n";
    cout << "==================\n";
    getInputint("Pilih Data (Ketik 0 untuk keluar) : ", &pilihData,"2");
    if(pilihData == 0){
        managemaentSpeaker(data, jumlahData);
    }else if (pilihData < 0 || pilihData > jumlahData) {
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

void bubbleSortDescending(dataSpeaker data[], int jumlahData) {
    for(int i = 0; i < jumlahData; i++) {
        for(int j = 0; j < jumlahData - i - 1; j++) {
            if(data[j].speaker.merk < data[j + 1].speaker.merk) {
                dataSpeaker temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void selectionSortAscending(dataSpeaker data[], int jumlahData) {
    for(int i = 0; i < jumlahData; i++){
        int minIndex = i;
        for(int j = i + 1; j < jumlahData; j++){
            if(data[j].speaker.hargaProduk < data[minIndex].speaker.hargaProduk){
                minIndex = j;
            }
        }
        if (minIndex != i){
            dataSpeaker temp = data[i];
            data[i] = data[minIndex];
            data[minIndex] = temp;
        }
    }
}

void insertionSortAscending(dataSpeaker data[], int jumlahDara) {
    for(int i = 1; i < jumlahDara; i++) {
        dataSpeaker temp = data[i];
        int j = i - 1;
        while(j >= 0 && data[j].speaker.merk > temp.speaker.merk) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
}

void urutanData(int jumlahData){
    int pilih;
    cout << "Urutan Data\n";
    cout << "===========\n";
    cout << "1. Nama Merk Z-a\n";
    cout << "2. Harga Merk Kecil Ke Besar\n";
    cout << "3. Nama Merk A-z\n";
    getInputint("Pilih Urutan Data : ", &pilih,"1");
    system("cls || clear");
    switch (pilih) {
        case 1:
            bubbleSortDescending(dataBarang, jumlahData);
            lihatMerkSpeaker(dataBarang, jumlahData);
            break;
        case 2:
            selectionSortAscending(dataBarang, jumlahData);
            lihatMerkSpeaker(dataBarang, jumlahData);
            break;
        case 3:
            insertionSortAscending(dataBarang, jumlahData);
            lihatMerkSpeaker(dataBarang, jumlahData);
            break;
        default:
            cout << "Urutan data tidak ada\n";
            break;
    }
}

void binarySearchAscending(dataSpeaker data[], int jumlahData, string cari) {
    int kiri = 0, kanan = jumlahData - 1;
    bool ketemu = false;
    while(kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if(data[tengah].speaker.merk == cari) {
            ketemu = true;
            cout << "Data ditemukan\n";
            cout << "Merk Speaker \t\t: " << data[tengah].speaker.merk << endl;
            cout << "Jumlah Produk \t\t: " << data[tengah].speaker.jumlahProduk << endl;
            cout << "Harga Produk \t\t: " << data[tengah].speaker.hargaProduk << endl;
            cout << "Nama Supplier \t\t: " << data[tengah].supplier.nama << endl;
            cout << "Alamat Supplier \t: " << data[tengah].supplier.alamat << endl;
            cout << "No Telp Supplier \t: " << data[tengah].supplier.noTelp << endl;
            break;
        }else if(data[tengah].speaker.merk < cari) {
            kiri = tengah + 1;
        }else{
            kanan = tengah - 1;
        }
    }
    if(!ketemu) {
        cout << "Data tidak ditemukan\n";
    }
}

void interpolationSearchDescending(dataSpeaker data[], int jumlahData, string cari) {
    int kiri = 0, kanan = jumlahData - 1;
    bool ketemu = false;
    
    while(kiri <= kanan && cari <= data[kiri].speaker.merk && cari >= data[kanan].speaker.merk) {
        int posisi = kiri + (((double)(kanan - kiri) / (data[kiri].speaker.merk.compare(data[kanan].speaker.merk))) * (data[kiri].speaker.merk.compare(cari)));
        
        if(data[posisi].speaker.merk == cari) {
            ketemu = true;
            cout << "Data ditemukan\n";
            cout << "Merk Speaker \t\t: " << data[posisi].speaker.merk << endl;
            cout << "Jumlah Produk \t\t: " << data[posisi].speaker.jumlahProduk << endl;
            cout << "Harga Produk \t\t: " << data[posisi].speaker.hargaProduk << endl;
            cout << "Nama Supplier \t\t: " << data[posisi].supplier.nama << endl;
            cout << "Alamat Supplier \t: " << data[posisi].supplier.alamat << endl;
            cout << "No Telp Supplier \t: " << data[posisi].supplier.noTelp << endl;
            break;
        } else if(data[posisi].speaker.merk < cari) {
            kanan = posisi - 1; 
        } else {
            kiri = posisi + 1;  
        }
    }
    
    if(!ketemu) {
        cout << "Data tidak ditemukan\n";
    }
}
void pencarianData(int jumlahData){
    int pilih;
    string cari;
    cout << "Pencarian Data\n";
    cout << "==============\n";
    cout << "1. Nama Merk A-z\n";
    cout << "2. Nama Merk z-A\n";
    getInputint("Pilih Pencarian Data : ", &pilih,"1");
    system("cls || clear");
    switch (pilih) {
        case 1:
            insertionSortAscending(dataBarang, jumlahData);
            lihatMerkSpeaker(dataBarang, jumlahData);
            cout << "Cari Merk Speaker :\n";
            cout << "==================\n";
            cin.ignore();
            getlineInput("Merk Speaker : ", &cari);
            binarySearchAscending(dataBarang, jumlahData, cari);
            break;
        case 2:
            bubbleSortDescending(dataBarang, jumlahData);
            lihatMerkSpeaker(dataBarang, jumlahData);
            cout << "Cari Merk Speaker :\n";
            cout << "==================\n";
            cin.ignore();
            getlineInput("Merk Speaker : ", &cari);
            interpolationSearchDescending(dataBarang, jumlahData, cari);
            break;
        default:
            cout << "Pencarian data tidak ada\n";
            break;
    }
}