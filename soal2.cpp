#include <iostream>
#include <string>
using namespace std;

int main() {
    string kode, lokasi, nama;
    int jenis;
    int jamKeluarInput, jamMasuk, menitMasuk, jamKeluar, menitKeluar;
    int durasi, biaya;

    cout << "Masukkan kode parkir digital (10 digit): ";
    cin >> kode;

    cout << "Masukkan jam keluar (format HHMM): ";
    cin >> jamKeluarInput;

    jenis = kode[0] - '0';

    int waktuMasuk = stoi(kode.substr(2,4)); 
    lokasi = kode.substr(6,4);

    jamMasuk = waktuMasuk / 100;
    menitMasuk = waktuMasuk % 100;

    jamKeluar = jamKeluarInput / 100;
    menitKeluar = jamKeluarInput % 100;

    durasi = jamKeluar - jamMasuk;

    //hitung biaya
    if (jenis == 1) {
        nama = "Mobil";
        biaya = 5000 + (durasi - 1) * 3000;
    } 
    else if (jenis == 2) {
        nama = "Motor";
        biaya = 3000 + (durasi - 1) * 2000;
    } 
    else if (jenis == 3) {
        nama = "Bus";
        biaya = 10000 + (durasi - 1) * 7000;
    } 
    else {
        nama = "Tidak diketahui";
        biaya = 0;
    }

    //tampilan output
    cout << "\n--- Ringkasan Parkir ---\n";
    cout << "Jenis kendaraan: " << nama << endl;

    cout << "Waktu masuk: ";
    if (jamMasuk < 10) cout << "0";
    cout << jamMasuk << ":";
    if (menitMasuk < 10) cout << "0";
    cout << menitMasuk << endl;

    cout << "Waktu keluar: ";
    if (jamKeluar < 10) cout << "0";
    cout << jamKeluar << ":";
    if (menitKeluar < 10) cout << "0";
    cout << menitKeluar << endl;

    cout << "Durasi parkir: " << durasi << " jam" << endl;
    cout << "Lokasi parkir: " << lokasi << endl;
    cout << "Total biaya: Rp " << biaya << endl;

    return 0;
}

/*
=== algoritma/logika penyelesaian:===
1. minta user input kode parkir (10 digit) dan jam keluar (format HHMM).
2. ambil informasi dari kode:
   - digit pertama = jenis kendaraan
   - digit ke-3 sampai ke-6 = waktu masuk (HHMM)
   - digit ke-7 sampai ke-10 = lokasi parkir
3. pisahkan waktu masuk:
   - jamMasuk = HHMM / 100
   - menitMasuk = HHMM % 100
4. pisahkan waktu keluar:
   - jamKeluar = HHMM / 100
   - menitKeluar = HHMM % 100
5. hitung durasi parkir:
   - durasi = jamKeluar - jamMasuk
6. tentukan jenis kendaraan dan tarif:
   - mobil = 5000 + (durasi - 1) × 3000
   - motor = 3000 + (durasi - 1) × 2000
   - bus   = 10000 + (durasi - 1) × 7000
7. tampilkan hasil:
   - jenis kendaraan
   - waktu masuk dan keluar
   - durasi parkir
   - lokasi parkir
   - total biaya
*/
