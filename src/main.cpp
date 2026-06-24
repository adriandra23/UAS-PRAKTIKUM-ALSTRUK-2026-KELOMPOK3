#include <iostream>
#include <string>

using namespace std;

// Struktur Data Utama
struct Pasien {
    string idPasien;
    string nama;
    string keluhan;
    string unitRujukan; // Menyimpan info perpindahan/rujukan antar unit
};

struct JadwalDokter {
    string idDokter;
    string namaDokter;
    string spesialis;
    string jamPraktik;
};

// Global Variable Koleksi Data
const int MAX_DATA = 100;
Pasien daftarPasien[MAX_DATA];
int jumlahPasien = 0;

JadwalDokter daftarJadwal[MAX_DATA];
int jumlahJadwal = 0;

string antreanPelayanan[MAX_DATA];
int jumlahAntrean = 0;

string riwayatPemeriksaan[MAX_DATA];
int jumlahRiwayat = 0;


// --- TUGAS ANGGOTA 2 Adit Haikal---
void loadDatabaseRS() {
    // Tulis data awal bawaan (master data dokter/pasien) di sini
    cout << "\n-----Fitur Data Base Rumah Sakit-----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}

void tampilJadwalDokter() {
    // Tulis logika menampilkan jadwal dokter di sini
     cout << "\n-----Fitur Tampil Jadwal Dokter-----" << endl;
     cout << "Fitur ini masih dalam pengembangan...\n";
}

void cariPasien() {
    // Tulis logika pencarian data pasien di sini
    cout << "\n-----Fitur Cari Data Pasien----" << endl;
     cout << "Fitur ini masih dalam pengembangan...\n";
}

void tambahPasien() {
    // Tulis logika tambah data pasien baru di sini
    cout << "\n-----Fitur Tambah Pasien Baru----" << endl;
     cout << "Fitur ini masih dalam pengembangan...\n";
}

void hapusPasien() {
    // Tulis logika hapus data pasien di sini
     cout << "\n-----Fitur Hapus Data Pasien----" << endl;
     cout << "Fitur ini masih dalam pengembangan...\n";
}


// --- TUGAS ANGGOTA 3 Igna ---
void masukAntrean() {
    // Tulis logika pendaftaran antrean pelayanan di sini
     cout << "\n-----Fitur Masuk Antrean Pelayanan----" << endl;
     cout << "Fitur ini masih dalam pengembangan...\n";
}

void prosesRujukan() {
    // Tulis logika proses rujukan antar unit pelayanan di sini
     cout << "\n-----Fitur Proses Rujukan Antar Unit----" << endl;
     cout << "Fitur ini masih dalam pengembangan...\n";

void sortingJadwalDokter() {
    // Tulis logika urutkan jadwal dokter di sini
     cout << "\n-----Fitur Sorting Jadwal Dokter----" << endl;
     cout << "Fitur ini masih dalam pengembangan...\n";
}

void inputRiwayatPemeriksaan() {
    // Tulis logika pengisian riwayat medis pasien di sini
     cout << "\n-----Fitur Input Riwayat Pemeriksaan----" << endl;
     cout << "Fitur ini masih dalam pengembangan...\n";
}

// --- TUGAS ANGGOTA 4 Reva ---

void tampilRiwayatLog() {
    // Tulis logika untuk melihat log riwayat pemeriksaan di sini
     cout << "\n-----Fitur Tampil Log Riwayat Pemeriksaan----" << endl;
     cout << "Fitur ini masih dalam pengembangan...\n";
}


// --- MENU UTAMA ---
int main() {
    loadDatabaseRS(); 
    int pilihan;

    do {
        cout << "\n========================================\n";
        cout << "       SISTEM RUMAH SAKIT DIGITAL       \n";
        cout << "========================================\n";
        cout << " [1] Tampilkan Jadwal Dokter\n";
        cout << " [2] Cari Data Pasien\n";
        cout << " [3] Tambah Pasien Baru\n";
        cout << " [4] Hapus Data Pasien\n";
        cout << " [5] Daftarkan Antrean Pelayanan\n";
        cout << " [6] Proses Rujukan Antar Unit\n";
        cout << " [7] Urutkan Jadwal Dokter (A-Z)\n";
        cout << " [8] Riwayat & Rekam Medis Pemeriksaan\n";
        cout << " [9] Keluar Sistem\n";
        cout << "========================================\n";
        cout << " Pilih menu (1-9): "; cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilJadwalDokter();
                break;

            case 2:
                cariPasien();
                break;

            case 3:
                tambahPasien();
                break;

            case 4:
                hapusPasien();
                break;

            case 5:
                masukAntrean();
                break;

            case 6:
                prosesRujukan();
                break;

            case 7:
                sortingJadwalDokter();
                break;

            case 8:
                inputRiwayatPemeriksaan();
                tampilRiwayatLog();
                break;

            case 9:
                cout << "\n>> Keluar dari sistem rumah sakit. Terima kasih!\n";
                break;

            default:
                cout << "\n[Peringatan] Pilihan tidak valid! Masukkan angka 1-9.\n";
                break;
        }
    } while (pilihan != 9);

    return 0;
}