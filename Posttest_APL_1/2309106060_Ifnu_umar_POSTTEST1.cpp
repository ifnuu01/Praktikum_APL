#include <iostream>
using namespace std;

void clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void enter()
{
    cout << "Tekan Enter untuk melanjutkan";
    cin.ignore();
    cin.get();
    clear();
}

int main()
{
    string nama = "ifnu umar";
    string nim = "2309106060";
    string inputNama, inputNim;
    int count = 0;
    int pilih, pilihHasil;
    double km, m, cm, mil;

    clear();
    while (count < 3)
    {
        cout << "Halaman Login \n";
        cout << "Masukkan Nama : ";
        getline(cin, inputNama);
        cout << "Masukkan NIM : ";
        getline(cin, inputNim);
        clear();
        if (inputNama == nama && inputNim == nim)
        {
            cout << "Login Berhasil "
                 << "\n\n";
            break;
        }
        else
        {
            if (count == 2)
            {
                cout << "Anda sudah mencoba 3 kali, Silahkan coba lagi nanti \n";
                return 0;
            }
            else
            {
                cout << "Login Gagal ke " << count + 1 << "\n\n";
                count++;
            }
        }
    }

    do
    {
        cout << "Menu Konversi Kecepatan \n";
        cout << "=========================\n\n";
        cout << "1. Konversi Kilometer/jam \n";
        cout << "2. Konversi Meter/detik \n";
        cout << "3. Konversi centimeter/detik \n";
        cout << "4. Konversi Mil/jam \n";
        cout << "5. Keluar dari program \n";

        cout << "Pilih Menu : ";
        cin >> pilih;
        clear();
        switch (pilih)
        {
        case 1:
            cout << "Masukkan Nilai Kilometer/jam : ";
            cin >> km;
            clear();
            cout << "Menu Konversi Kilometer/jam\ndengan nilai : " << km << " km/jam di konversi ke\n\n";
            cout << "1. Konversi ke Meter/detik \n";
            cout << "2. Konversi ke centimeter/detik \n";
            cout << "3. Konversi ke Mil/jam \n";
            cout << "Pilih Menu : ";
            cin >> pilihHasil;
            clear();
            switch (pilihHasil)
            {
            case 1:
                m = km * 1000 / 3600;
                cout << "Hasil Konversi dari : " << km << " km/jam"
                     << " menjadi " << m << " m/detik" << endl;
                break;
            case 2:
                cm = km * 100000 / 3600;
                cout << "Hasil Konversi dari : " << km << " km/jam"
                     << " menjadi " << cm << " cm/detik" << endl;
                enter();
                break;
            case 3:
                mil = km / 1.609;
                cout << "Hasil Konversi dari : " << km << " km/jam"
                     << " menjadi " << mil << " mil/jam" << endl;
                enter();
                break;
            default:
                cout << "Pilih anda tidak ada pada menu Silahkan ulangi dari awal\n";
                enter();
                break;
            }
            break;
        case 2:
            cout << "Masukkan Nilai Meter/detik : ";
            cin >> m;
            clear();
            cout << "Menu Konversi Meter/detik\ndengan nilai : " << m << "m/detik di konversi ke\n\n";
            cout << "1. Konversi ke Kilometer/jam \n";
            cout << "2. Konversi ke centimeter/detik \n";
            cout << "3. Konversi ke Mil/jam \n";
            cout << "Pilih Menu : ";
            cin >> pilihHasil;
            clear();
            switch (pilihHasil)
            {
            case 1:
                km = m * 3.6 / 1000;
                cout << "Hasil Konversi dari : " << m << " m/detik"
                     << " menjadi " << km << " km/jam" << endl;
                enter();
                break;
            case 2:
                cm = m * 100;
                cout << "Hasil konversi dari : " << m << " m/detik"
                     << " menjadi " << cm << " cm/detik" << endl;
                enter();
                break;
            case 3:
                mil = m * 2.237 / 1000;
                cout << "Hasil Konversi dari : " << m << " m/detik"
                     << " menjadi " << mil << " mil/jam" << endl;
                enter();
                break;
            default:
                cout << "Pilih anda tidak ada pada menu Silahkan ulangi dari awal\n";
                enter();
                break;
            }
            break;
        case 3:
            cout << "Masukkan Nilai centimeter/detik : ";
            cin >> cm;
            clear();
            cout << "Menu Konversi centimeter/detik\ndengan nilai : " << cm << "cm/detik di konversi ke\n\n";
            cout << "1. Konversi ke Kilometer/jam \n";
            cout << "2. Konversi ke Meter/detik \n";
            cout << "3. Konversi ke Mil/jam \n";
            cout << "Pilih Menu : ";
            cin >> pilihHasil;
            clear();
            switch (pilihHasil)
            {
            case 1:
                km = cm * 3600 / 100000;
                cout << "Hasil konversi dari : " << cm << " cm/detik"
                     << " menjadi " << km << " km/jam" << endl;
                enter();
                break;
            case 2:
                m = cm / 100;
                cout << "Hasil konversi dari : " << cm << " cm/detik"
                     << " menjadi " << m << " m/detik" << endl;
                enter();
                break;
            case 3:
                mil = cm * 0.02237;
                cout << "Hasil konversi dari : " << cm << " cm/detik"
                     << " menjadi " << mil << " mil/jam" << endl;
                enter();
                break;
            default:
                cout << "Pilih anda tidak ada pada menu Silahkan ulangi dari awal\n";
                enter();
                break;
            }
            break;
        case 4:
            cout << "Masukkan Nilai Mil/jam : ";
            cin >> mil;
            clear();
            cout << "Menu Konversi Mil/jam\ndengan nilai : " << mil << "mil/jam di konversi ke\n\n";
            cout << "1. Konversi ke Kilometer/jam \n";
            cout << "2. Konversi ke Meter/detik \n";
            cout << "3. Konversi ke centimeter/detik \n";
            cout << "Pilih Menu : ";
            cin >> pilihHasil;
            clear();
            switch (pilihHasil)
            {
            case 1:
                km = mil * 1.609;
                cout << "Hasil Konversi dari : " << mil << " mil/jam"
                     << " menjadi " << km << " km/jam" << endl;
                enter();
                break;
            case 2:
                m = mil * 1609 / 3600;
                cout << "Hasil Konversi dari : " << mil << " mil/jam"
                     << " menjadi " << m << " m/detik" << endl;
                enter();
                break;
            case 3:
                cm = mil * 160900 / 3600;
                cout << "Hasil Konversi dari : " << mil << " mil/jam"
                     << " menjadi " << cm << " cm/detik" << endl;
                enter();
                break;
            default:
                cout << "Pilih anda tidak ada pada menu Silahkan ulangi dari awal\n";
                enter();
                break;
            }
            break;
        case 5:
            cout << "Terima Kasih \n";
            break;
        default:
            cout << "Pilih anda tidak ada pada menu \n";
            enter();
            break;
        }
    } while (pilih != 5);

    return 0;
}
