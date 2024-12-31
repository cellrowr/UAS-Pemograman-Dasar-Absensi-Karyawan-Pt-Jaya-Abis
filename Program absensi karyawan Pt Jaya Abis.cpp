#include <iostream>
#include <string>
#include <vector>
#include <limits> 

using namespace std;

struct Karyawan {
    int id;
    string nama;
    string tanggal_absen;
};

void tambahKaryawan(vector<Karyawan>& karyawan_list) {
    Karyawan karyawan;
    cout << "Masukkan ID Karyawan Pt Jaya Abis: ";
    while (!(cin >> karyawan.id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input data tidak valid. Masukkan angka untuk ID Karyawan Pt Jaya Abis: ";
    }
    cin.ignore(); 
    cout << "Masukkan Nama Lengkap Karyawan: ";
    getline(cin, karyawan.nama);
    cout << "Masukkan Tanggal Absen (tanggal-bulan-tahun): ";
    getline(cin, karyawan.tanggal_absen);

    karyawan_list.push_back(karyawan);
    cout << "Data absensi karyawan telah berhasil ditambahkan!" << endl;
}

void lihatKaryawan(const vector<Karyawan>& karyawan_list) {
    if (karyawan_list.empty()) {
        cout << "Tidak ada data absensi karyawan." << endl;
        return;
    }
    for (size_t i = 0; i < karyawan_list.size(); ++i) {
        cout << "ID: " << karyawan_list[i].id
             << ", Nama: " << karyawan_list[i].nama
             << ", Tanggal Absen: " << karyawan_list[i].tanggal_absen << endl;
    }
}

void hapusKaryawan(vector<Karyawan>& karyawan_list, int id) {
    for (size_t i = 0; i < karyawan_list.size(); ++i) {
        if (karyawan_list[i].id == id) {
            karyawan_list.erase(karyawan_list.begin() + i);
            cout << "Data absensi karyawan berhasil untuk dihapus!" << endl;
            return;
        }
    }
    cout << "ID karyawan tidak valid." << endl;
}

int main() {
    vector<Karyawan> karyawan_list;
    int pilihan;

    do {
        cout << "\nMenu Absensi Karyawan Pt Jaya Abis:\n";
        cout << "1. Tambah Absensi Karyawan\n";
        cout << "2. Lihat Absensi Karyawan\n";
        cout << "3. Hapus Absensi Karyawan\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        while (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Masukkan angka antara 1 hingga 4: ";
        }

        switch (pilihan) {
            case 1:
                tambahKaryawan(karyawan_list);
                break;
            case 2:
                lihatKaryawan(karyawan_list);
                break;
            case 3: {
                int id;
                cout << "Masukkan ID Karyawan yang ingin dihilangkan: ";
                while (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input tidak valid. Masukkan angka untuk ID: ";
                }
                hapusKaryawan(karyawan_list, id);
                break;
            }
            case 4:
                cout << "Terima kasih sudah menggunakan program absensi karyawan Pt Jaya Abis." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);

    return 0;
}
