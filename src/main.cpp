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

// --- TUGAS ANGGOTA 2 ---
void loadDatabaseRS() {
    daftarJadwal[0] = {"D01", "Dr. Citra", "Anak", "08:00 - 12:00"};
    daftarJadwal[1] = {"D02", "Dr. Budi", "Kandungan", "13:00 - 16:00"};
    daftarJadwal[2] = {"D03", "Dr. Andi", "Penyakit Dalam", "10:00 - 14:00"};
    jumlahJadwal = 3;

    
    cout << "[Sistem] Database awal berhasil dimuat!\n";
}

void tampilJadwalDokter() {
    cout << "\n----- DAFTAR JADWAL DOKTER -----\n";
    if (jumlahJadwal == 0) {
        cout << "Belum ada jadwal dokter tersedia.\n";
        return;
    }
    
    for (int i = 0; i < jumlahJadwal; i++) {
        cout << "[" << daftarJadwal[i].idDokter << "] " 
             << "Nama: " << daftarJadwal[i].namaDokter 
             << " | Spesialis: " << daftarJadwal[i].spesialis 
             << " | Jam: " << daftarJadwal[i].jamPraktik << endl;
    }
}

void cariPasien() {
    cout << "\n----- CARI DATA PASIEN -----\n";
    if (jumlahPasien == 0) {
        cout << "Belum ada data pasien terdaftar.\n";
        return;
    }

    string targetID;
    cout << "Masukkan ID Pasien yang dicari: ";
    cin >> targetID;

    bool ditemukan = false;
    for (int i = 0; i < jumlahPasien; i++) {
        if (daftarPasien[i].idPasien == targetID) {
            cout << "\n>> Data Pasien Ditemukan! <<\n";
            cout << "ID Pasien    : " << daftarPasien[i].idPasien << endl;
            cout << "Nama Pasien  : " << daftarPasien[i].nama << endl;
            cout << "Keluhan      : " << daftarPasien[i].keluhan << endl;
            cout << "Unit/Rujukan : " << daftarPasien[i].unitRujukan << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Pasien dengan ID " << targetID << " tidak ditemukan.\n";
    }
}

void tambahPasien() {
    cout << "\n----- TAMBAH PASIEN BARU -----\n";
    if (jumlahPasien >= MAX_DATA) {
        cout << "Kapasitas data pasien penuh!\n";
        return;
    }

    Pasien pBaru;
    cout << "Masukkan ID Pasien Baru : "; cin >> pBaru.idPasien;
    cin.ignore(); 
    cout << "Masukkan Nama Pasien    : "; getline(cin, pBaru.nama);
    cout << "Masukkan Keluhan        : "; getline(cin, pBaru.keluhan);
    pBaru.unitRujukan = "Pendaftaran/IGD"; 

    daftarPasien[jumlahPasien] = pBaru;
    jumlahPasien++;
    cout << "Pasien berhasil ditambahkan!\n";
}

void hapusPasien() {
    cout << "\n----- HAPUS DATA PASIEN -----\n";
    if (jumlahPasien == 0) {
        cout << "Belum ada data pasien untuk dihapus.\n";
        return;
    }

    string targetID;
    cout << "Masukkan ID Pasien yang akan dihapus: "; cin >> targetID;

    int indeksDitemukan = -1;
    for (int i = 0; i < jumlahPasien; i++) {
        if (daftarPasien[i].idPasien == targetID) {
            indeksDitemukan = i;
            break;
        }
    }

    if (indeksDitemukan != -1) {
        for (int i = indeksDitemukan; i < jumlahPasien - 1; i++) {
            daftarPasien[i] = daftarPasien[i + 1];
        }
        jumlahPasien--;
        cout << "Data pasien dengan ID " << targetID << " berhasil dihapus.\n";
    } else {
        cout << "ID Pasien tidak ditemukan.\n";
    }
}