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