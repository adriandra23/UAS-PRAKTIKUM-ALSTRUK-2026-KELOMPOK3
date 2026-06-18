#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

struct Pasien {
    int id, usia;
    string nama, jenisKelamin, nomorRekamMedis, diagnosa, unitAsal;
    bool dirujuk;
};
struct JadwalDokter {
    string namaDokter, spesialisasi, hari, jamMulai, jamSelesai, ruangan;
};
struct RiwayatPemeriksaan {
    int idPasien;
    string tanggal, namaDokter, keluhan, hasilPemeriksaan, resepObat;
};

vector<Pasien>             daftarPasien;
vector<JadwalDokter>       daftarJadwal;
vector<RiwayatPemeriksaan> daftarRiwayat;
queue<Pasien>               antrean;
int nextIdPasien = 1;

void garis(char c = '-', int n = 60) { cout << string(n, c) << "\n"; }

// ------------------- MODUL JADWAL DOKTER -------------------
void jadwalDokter() {
    int p; garis('='); cout << "        MODUL JADWAL DOKTER\n"; garis('=');
    cout << "1. Lihat Semua Jadwal\n2. Tambah Jadwal\n0. Kembali\n"; garis();
    cout << "Pilih: "; cin >> p; cin.ignore();
    if (p == 1) {
        garis();
        if (daftarJadwal.empty()) { cout << "[!] Belum ada jadwal dokter.\n"; garis(); return; }
        cout << left << setw(20) << "Dokter" << setw(18) << "Spesialisasi" << setw(10) << "Hari"
             << setw(8) << "Mulai" << setw(8) << "Selesai" << setw(10) << "Ruangan" << "\n";
        garis();
        for (auto& j : daftarJadwal)
            cout << left << setw(20) << j.namaDokter << setw(18) << j.spesialisasi << setw(10) << j.hari
                 << setw(8) << j.jamMulai << setw(8) << j.jamSelesai << setw(10) << j.ruangan << "\n";
        garis();
    } else if (p == 2) {
        JadwalDokter j;
        cout << "Nama Dokter       : "; getline(cin, j.namaDokter);
        cout << "Spesialisasi      : "; getline(cin, j.spesialisasi);
        cout << "Hari              : "; getline(cin, j.hari);
        cout << "Jam Mulai (HH:MM) : "; getline(cin, j.jamMulai);
        cout << "Jam Selesai       : "; getline(cin, j.jamSelesai);
        cout << "Ruangan           : "; getline(cin, j.ruangan);
        daftarJadwal.push_back(j);
        cout << "[OK] Jadwal dokter berhasil ditambahkan.\n";
    } else if (p != 0) cout << "[!] Pilihan tidak valid.\n";
}

// ----------------- MODUL RIWAYAT PEMERIKSAAN -----------------
void riwayatPemeriksaan() {
    int p; garis('='); cout << "      MODUL RIWAYAT PEMERIKSAAN\n"; garis('=');
    cout << "1. Tambah Riwayat\n2. Lihat Riwayat per ID Pasien\n0. Kembali\n"; garis();
    cout << "Pilih: "; cin >> p; cin.ignore();
    if (p == 1) {
        RiwayatPemeriksaan r;
        cout << "ID Pasien          : "; cin >> r.idPasien; cin.ignore();
        bool ada = false;
        for (auto& ps : daftarPasien) if (ps.id == r.idPasien) { ada = true; break; }
        if (!ada) { cout << "[!] ID Pasien tidak ditemukan.\n"; return; }
        cout << "Tanggal (DD/MM/YY) : "; getline(cin, r.tanggal);
        cout << "Nama Dokter        : "; getline(cin, r.namaDokter);
        cout << "Keluhan            : "; getline(cin, r.keluhan);
        cout << "Hasil Pemeriksaan  : "; getline(cin, r.hasilPemeriksaan);
        cout << "Resep Obat         : "; getline(cin, r.resepObat);
        daftarRiwayat.push_back(r);
        for (auto& ps : daftarPasien) if (ps.id == r.idPasien) ps.diagnosa = r.hasilPemeriksaan;
        cout << "[OK] Riwayat pemeriksaan berhasil disimpan.\n";
    } else if (p == 2) {
        int id; cout << "Masukkan ID Pasien: "; cin >> id; cin.ignore();
        garis(); bool ketemu = false;
        for (auto& r : daftarRiwayat) {
            if (r.idPasien != id) continue;
            ketemu = true;
            cout << "Tanggal          : " << r.tanggal << "\n"
                 << "Dokter           : " << r.namaDokter << "\n"
                 << "Keluhan          : " << r.keluhan << "\n"
                 << "Hasil Pemeriksaan: " << r.hasilPemeriksaan << "\n"
                 << "Resep Obat       : " << r.resepObat << "\n";
            garis();
        }
        if (!ketemu) cout << "[!] Tidak ada riwayat untuk ID pasien tersebut.\n";
    }
}

// ------------------- MODUL ANTREAN PELAYANAN -------------------
void antreanPelayanan() {
    int p; garis('='); cout << "       MODUL ANTREAN PELAYANAN\n"; garis('=');
    cout << "1. Daftarkan Pasien Baru\n2. Panggil Pasien Berikutnya\n3. Lihat Seluruh Antrean\n0. Kembali\n"; garis();
    cout << "Pilih: "; cin >> p; cin.ignore();
    if (p == 1) {
        Pasien ps; ps.id = nextIdPasien++; ps.dirujuk = false;
        cout << "Nama Pasien        : "; getline(cin, ps.nama);
        cout << "Usia               : "; cin >> ps.usia; cin.ignore();
        cout << "Jenis Kelamin (L/P): "; getline(cin, ps.jenisKelamin);
        cout << "Unit Tujuan        : "; getline(cin, ps.unitAsal);
        ps.nomorRekamMedis = "RM-" + to_string(1000 + ps.id);
        ps.diagnosa = "-";
        daftarPasien.push_back(ps); antrean.push(ps);
        cout << "[OK] Pasien terdaftar. No. RM: " << ps.nomorRekamMedis
             << " | Nomor Antrean: " << ps.id << "\n";
    } else if (p == 2) {
        if (antrean.empty()) { cout << "[!] Antrean kosong.\n"; return; }
        Pasien ps = antrean.front(); antrean.pop();
        cout << "[>>] Memanggil pasien:\n     Nama   : " << ps.nama
             << "\n     No. RM : " << ps.nomorRekamMedis
             << "\n     Unit   : " << ps.unitAsal
             << "\nSisa antrean: " << antrean.size() << " orang.\n";
    } else if (p == 3) {
        if (antrean.empty()) { cout << "[!] Antrean kosong.\n"; return; }
        queue<Pasien> salinan = antrean; int no = 1;
        garis();
        cout << left << setw(5) << "No." << setw(20) << "Nama" << setw(14) << "No. RM" << setw(20) << "Unit" << "\n";
        garis();
        while (!salinan.empty()) {
            Pasien ps = salinan.front(); salinan.pop();
            cout << left << setw(5) << no++ << setw(20) << ps.nama
                 << setw(14) << ps.nomorRekamMedis << setw(20) << ps.unitAsal << "\n";
        }
        garis();
    }
}

// -------------- MODUL RUJUKAN ANTAR UNIT PELAYANAN --------------
void prosesRujukan() {
    garis('='); cout << "    MODUL RUJUKAN ANTAR UNIT PELAYANAN\n"; garis('=');
    if (daftarPasien.empty()) { cout << "[!] Belum ada data pasien.\n"; return; }
    cout << left << setw(6) << "ID" << setw(22) << "Nama" << setw(14) << "No. RM"
         << setw(20) << "Unit Sekarang" << setw(10) << "Dirujuk" << "\n";
    garis();
    for (auto& ps : daftarPasien)
        cout << left << setw(6) << ps.id << setw(22) << ps.nama << setw(14) << ps.nomorRekamMedis
             << setw(20) << ps.unitAsal << setw(10) << (ps.dirujuk ? "Ya" : "Tidak") << "\n";
    garis();
    int id; cout << "ID Pasien yang dirujuk (0=batal): "; cin >> id; cin.ignore();
    if (id == 0) return;
    for (auto& ps : daftarPasien) {
        if (ps.id != id) continue;
        string tujuan, alasan;
        cout << "Unit Asal           : " << ps.unitAsal << "\n";
        cout << "Unit Tujuan Rujukan : "; getline(cin, tujuan);
        cout << "Alasan Rujukan      : "; getline(cin, alasan);
        RiwayatPemeriksaan r{ps.id, "RUJUKAN", "Sistem", alasan, "Dirujuk ke unit: " + tujuan, "-"};
        daftarRiwayat.push_back(r);
        string unitLama = ps.unitAsal;
        ps.unitAsal = tujuan; ps.dirujuk = true;
        cout << "\n  ===== SURAT RUJUKAN INTERNAL =====\n"
             << "  Pasien  : " << ps.nama << "\n"
             << "  No. RM  : " << ps.nomorRekamMedis << "\n"
             << "  Dari    : " << unitLama << "\n"
             << "  Ke      : " << tujuan << "\n"
             << "  Alasan  : " << alasan << "\n"
             << "  ===================================\n"
             << "[OK] Rujukan berhasil diproses.\n";
        return;
    }
    cout << "[!] ID Pasien tidak ditemukan.\n";
}

// ------------------------- MENU UTAMA -------------------------
void menuUtama() {
    garis('='); cout << "   SISTEM INFORMASI RUMAH SAKIT DIGITAL\n"; garis('=');
    cout << "1. Jadwal Dokter\n2. Riwayat Pemeriksaan\n3. Antrean Pelayanan\n"
         << "4. Proses Rujukan Antar Unit\n5. Lihat Semua Data Pasien\n0. Keluar\n";
    garis(); cout << "Pilih menu: ";
}

// ----------------------------- MAIN -----------------------------
int main() {
    daftarJadwal = {
        {"Dr. Andi Prasetyo", "Penyakit Dalam", "Senin",  "08:00", "12:00", "Poli 1"},
        {"Dr. Sari Dewi",     "Anak",           "Selasa", "09:00", "13:00", "Poli 2"},
        {"Dr. Budi Santoso",  "Bedah",          "Rabu",   "07:00", "11:00", "Poli 3"},
        {"Dr. Lina Kusuma",   "Kardiologi",     "Kamis",  "10:00", "14:00", "Poli 4"}
    };
    int pilihan;
    do {
        menuUtama(); cin >> pilihan; cin.ignore(); cout << "\n";
        switch (pilihan) {
            case 1: jadwalDokter(); break;
            case 2: riwayatPemeriksaan(); break;
            case 3: antreanPelayanan(); break;
            case 4: prosesRujukan(); break;
            case 5:
                garis('='); cout << "        DAFTAR SELURUH PASIEN\n"; garis('=');
                if (daftarPasien.empty()) { cout << "[!] Belum ada pasien terdaftar.\n"; break; }
                cout << left << setw(5) << "ID" << setw(22) << "Nama" << setw(6) << "Usia" << setw(5) << "JK"
                     << setw(14) << "No. RM" << setw(20) << "Unit" << setw(30) << "Diagnosa" << "\n";
                garis('-', 100);
                for (auto& ps : daftarPasien)
                    cout << left << setw(5) << ps.id << setw(22) << ps.nama << setw(6) << ps.usia
                         << setw(5) << ps.jenisKelamin << setw(14) << ps.nomorRekamMedis
                         << setw(20) << ps.unitAsal << setw(30) << ps.diagnosa << "\n";
                garis('-', 100);
                break;
            case 0: cout << "  Terima kasih. Sistem ditutup.\n"; break;
            default: cout << "[!] Pilihan tidak valid.\n";
        }
        cout << "\n";
    } while (pilihan != 0);
    return 0;
}

