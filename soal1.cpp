#include <iostream>
#include <string>
using namespace std;

int main() {
    string nomor;
    cout << "Masukkan nomor kartu digital: ";
    cin >> nomor;

    int n = nomor.length();

    //menentukan jenis kartu
    string jenis = "";

    if (n == 14 && nomor[0] == '6' && nomor[1] == '5') {
        jenis = "NUSANTARA";}
    else if (n == 16 && nomor[0] == '7' && (nomor[1] == '7' || nomor[1] == '8')) {
        jenis = "GARUDA";} 
    else if (n == 15 && nomor[0] == '9' && nomor[1] == '1') {
        jenis = "MERDEKA";}

    //proses validasi angka
    int total = 0;
    bool dikali = true;

    for (int i = n - 2; i >= 0; i--) {
        int digit = nomor[i] - '0';

        if (dikali) {
            digit = digit * 2;

            if (digit > 9) {
                digit = (digit / 10) + (digit % 10);
            }
        }
        total += digit;
        dikali = !dikali;
    }

    total += nomor[n - 1] - '0';

    //tampilan hasil
    if (jenis == "") {
        cout << "Tipe kartu: TIDAK DIKENAL" << endl;
        cout << "Nomor kartu TIDAK VALID." << endl;
    } 
    else {
        cout << "Tipe kartu: " << jenis << endl;

        if (total % 10 == 0) {
            cout << "Nomor kartu VALID." << endl;
        } 
        else {
            cout << "Nomor kartu TIDAK VALID." << endl;
        }
    }

    return 0;
}

// === algoritma/logika penyelesaian: ===
// 1. program dimulai dengan meminta user input nomor kartu digital.
// 2. hitung panjang nomor kartu dengan fungsi length(), dan simpan ke variabel n.
// 3. tentukan jenis kartu berdasarkan panjang dan awalan:
//    - jika panjang 14 dan diawali "65", maka jenis=NUSANTARA
//    - jika panjang 16 dan diawali "77" atau "78", maka jenis=GARUDA
//    - jika panjang 15 dan diawali "91", maka jenis= MERDEKA
//    - jika tidak memenuhi → jenis kartu tidak dikenal (string jenis akan kosong)
// 4. jika jenis kartu tidak dikenal, tampilkan tipe kartu tidak dikenal, tampilkan kartu tidak valid,
//    dan program selesai.
// 5. jika jenis kartu dikenal, 
//     - inisialisasi total=0, dan dikali=true (untuk nentuin digit dikali atau tidak).
//     - lakukan perulangan dari digit ke 2 dari belakang, 
//       - ambil digit dengan cara nomor[i]-'0', 
//       - jika dikali=true, maka digit dikalikan 2, dan jika hasil>9, jumlahkan digitnya.
//       - tambahkan digit ke total 
//       - balik nilai dikali agar nilai jadi false untuk digit selanjutnya.
//     - setelah perulangan selesai, tambahkan digit terakhir (yang ga dikali) ke total.
// 6. buat pengecekan akhir
//    - jika total%10 == 0, maka kartu valid 
//    - jika tidak, maka kartu tidak valid 
// 7. tampilkan hasil 
//     - jenis kartu
//     - status validasi kartu
