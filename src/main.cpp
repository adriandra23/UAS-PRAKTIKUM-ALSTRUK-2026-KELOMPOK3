#include <iostream>
#include <string>
using namespace std;

struct Pasien {
    string idPasien;
    string nama;
    string keluhan;
    string unitRujukan;
};

struct JadwalDokter {
    string idDokter;
    string namaDokter;
    string spesialis;
    string jamPraktik;
};

const int MAX_DATA = 100;
Pasien daftarPasien[MAX_DATA];
int jumlahPasien = 0;

JadwalDokter daftarJadwal[MAX_DATA];
int jumlahJadwal = 0;

string antreanPelayanan[MAX_DATA];
int jumlahAntrean = 0;

string riwayatPemeriksaan[MAX_DATA];
int jumlahRiwayat = 0;


// --- TUGAS ANGGOTA 2  Aditnya ---
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


// --- TUGAS ANGGOTA 3  Igna ---
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

// --- TUGAS ANGGOTA 4 Reva ---
  
void inputRiwayatPemeriksaan() {
    cout << "\n----- INPUT RIWAYAT PEMERIKSAAN -----\n";
    if (jumlahRiwayat >= MAX_DATA) {
        cout << "Log riwayat pemeriksaan penuh!\n";
        return;
    }

    string logMedis;
    cout << "Format [ID Pasien - Diagnosis - Obat]\n";
    cout << "Masukkan log pemeriksaan: ";
    cin.ignore();
    getline(cin, logMedis);

    riwayatPemeriksaan[jumlahRiwayat] = logMedis;
    jumlahRiwayat++;
    cout << "Data rekam medis berhasil dicatat.\n";
}

void tampilRiwayatLog() {
    cout << "\n----- LOG RIWAYAT & REKAM MEDIS PASIEN -----\n";
    if (jumlahRiwayat == 0) {
        cout << "Belum ada riwayat pemeriksaan terdokumentasi.\n";
        return;
    }

    for (int i = 0; i < jumlahRiwayat; i++) {
        cout << i + 1 << ". " << riwayatPemeriksaan[i] << endl;
    }
}

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
