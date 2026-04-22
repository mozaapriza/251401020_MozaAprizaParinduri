#include <iostream>
using namespace std;

int main() {
    string kode;

    cout << "Masukkan kode transaksi (8 digit): ";
    cin >> kode;

    if (kode.length() != 8) {
        cout << "Kode tidak valid (harus 8 digit)" << endl;
        return 0;
    }

    //ambil data dari kode
    int kodeHari = stoi(kode.substr(0,2));
    int kodeLoyal = stoi(kode.substr(2,2));
    int jumlah = stoi(kode.substr(4,4)); // dalam kelipatan 100rb

    //tentukan jenis hari
    string hari;
    if (kodeHari == 1) hari = "Hari kerja";
    else if (kodeHari == 2) hari = "Akhir pekan";
    else if (kodeHari == 3) hari = "Hari libur nasional";
    else {
        cout << "Kode hari tidak valid!" << endl;
        return 0;
    }

    //tentukan jenis pelanggan
    string pelanggan;
    if (kodeLoyal == 1) pelanggan = "Biasa";
    else if (kodeLoyal == 2) pelanggan = "Silver";
    else if (kodeLoyal == 3) pelanggan = "Gold";
    else {
        cout << "Kode loyalitas tidak valid!" << endl;
        return 0;
    }

    //hitung poin
    int poin = 0;

    if (kodeHari == 1) { // hari kerja
        if (kodeLoyal == 1) poin = 1;
        else if (kodeLoyal == 2) poin = 2;
        else if (kodeLoyal == 3) poin = 3;
    }
    else if (kodeHari == 2) { // akhir pekan
        if (kodeLoyal == 1) poin = 2;
        else if (kodeLoyal == 2) poin = 3;
        else if (kodeLoyal == 3) poin = 5;
    }
    else if (kodeHari == 3) { // libur nasional
        if (kodeLoyal == 1) poin = 3;
        else if (kodeLoyal == 2) poin = 5;
        else if (kodeLoyal == 3) poin = 7;
    }

    int totalPoin = jumlah * poin;

    long long totalBelanja = jumlah * 100000;

    //tampilan output
    cout << "Jenis hari: " << hari << endl;
    cout << "Jenis pelanggan: " << pelanggan << endl;
    cout << "Jumlah belanja: Rp " << totalBelanja << endl;
    cout << "Total poin: " << totalPoin << endl;

    return 0;
}

// === algoritma / logika penyelesaian ===
// 1. minta user input kode transaksi (8 digit).
// 2. cek apakah panjang kode = 8 digit:
// jika tidak, tampilkan pesan "kode tidak valid" lalu program selesai.
// 3. ambil informasi dari kode:
// digit ke-1 dan ke-2 = kode hari
// digit ke-3 dan ke-4 = kode loyalitas pelanggan
// digit ke-5 sampai ke-8 = jumlah belanja (dalam kelipatan 100.000)
// 4. konversi data:
// kodeHari = substring(0,2)
// kodeLoyal = substring(2,2)
// jumlah = substring(4,4)
// 5. tentukan jenis hari:
// 01 → hari kerja
// 02 → akhir pekan
// 03 → hari libur nasional
// selain itu → kode tidak valid, program selesai
// 5. tentukan jenis pelanggan:
// 01 → biasa
// 02 → silver
// 03 → gold
// selain itu → kode tidak valid, program selesai
// 6. tentukan poin per 100.000 berdasarkan jenis hari dan pelanggan:
// hari kerja:
// biasa = 1
// silver = 2
// gold = 3
// akhir pekan:
// biasa = 2
// silver = 3
// gold = 5
// hari libur nasional:
// biasa = 3
// silver = 5
// gold = 7
// 7. hitung total poin:
// totalPoin = jumlah * poin
// hitung total belanja:
// totalBelanja = jumlah * 100.000
// 8. tampilkan hasil:
// jenis hari
// jenis pelanggan
// jumlah belanja
// total poin
