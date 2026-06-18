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

// --- TUGAS ANGGOTA 3 IGNA ---
void masukAntrean() {
    cout << "\n----- DAFTARKAN ANTREAN PELAYANAN -----\n";
    if (jumlahAntrean >= MAX_DATA) {
        cout << "Antrean hari ini sudah penuh!\n";
        return;
    }

    string idAtauNama;
    cout << "Masukkan Nama Pasien untuk masuk antrean: ";
    cin.ignore();
    getline(cin, idAtauNama);

    antreanPelayanan[jumlahAntrean] = idAtauNama;
    jumlahAntrean++;
    cout << "Pasien \"" << idAtauNama << "\" berhasil masuk antrean nomor: " << jumlahAntrean << endl;
}

void prosesRujukan() {
    cout << "\n----- PROSES RUJUKAN ANTAR UNIT -----\n";
    if (jumlahPasien == 0) {
        cout << "Belum ada data pasien.\n";
        return;
    }

    string targetID;
    cout << "Masukkan ID Pasien yang akan dirujuk: "; cin >> targetID;

    for (int i = 0; i < jumlahPasien; i++) {
        if (daftarPasien[i].idPasien == targetID) {
            cout << "Unit Saat Ini: " << daftarPasien[i].unitRujukan << endl;
            cout << "Masukkan Unit Rujukan Baru (Poli Gigi / Rawat Inap / Laboratorium): ";
            cin.ignore();
            getline(cin, daftarPasien[i].unitRujukan);
            cout << "Rujukan berhasil diperbarui ke unit: " << daftarPasien[i].unitRujukan << endl;
            return;
        }
    }
    cout << "ID Pasien tidak ditemukan.\n";
}
void sortingJadwalDokter() {
    cout << "\n----- SORTING JADWAL DOKTER (A-Z) -----\n";
    if (jumlahJadwal <= 1) {
        cout << "Jadwal terlalu sedikit untuk diurutkan.\n";
        return;
    }

    for (int i = 0; i < jumlahJadwal - 1; i++) {
        for (int j = 0; j < jumlahJadwal - i - 1; j++) {
            if (daftarJadwal[j].namaDokter > daftarJadwal[j + 1].namaDokter) {
                JadwalDokter temp = daftarJadwal[j];
                daftarJadwal[j] = daftarJadwal[j + 1];
                daftarJadwal[j + 1] = temp;
            }
        }
    }
    cout << "Jadwal dokter berhasil diurutkan berdasarkan alfabet nama.\n";
    tampilJadwalDokter(); 
}
