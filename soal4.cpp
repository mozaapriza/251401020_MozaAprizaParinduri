#include <iostream>
using namespace std;

int main() {
    int N;
    string S;

    cin >> N;
    cin >> S;

    int poinA = 0, poinB = 0;
    int streakA = 0, streakB = 0;

    for (int i = 0; i < N; i++) {

        if (S[i] == 'A') {
            poinA += 3;
            streakA++;
            streakB = 0;

            if (streakA == 3) {
                poinA += 2;
            }
        }
        else if (S[i] == 'B') {
            poinB += 3;
            streakB++;
            streakA = 0;

            if (streakB == 3) {
                poinB += 2;
            }
        }
        else if (S[i] == 'C') {
            poinA += 1;
            poinB += 1;
            streakA = 0;
            streakB = 0;
        }
    }

    //tampilan output
    if (poinA > poinB) {
        cout << "Pemenangnya adalah pemain A" << endl;
    }
    else if (poinB > poinA) {
        cout << "Pemenangnya adalah pemain B" << endl;
    }
    else {
        cout << "Hasil pertandingan seri" << endl;
    }

    cout << "Poin A: " << poinA << endl;
    cout << "Poin B: " << poinB << endl;

    return 0;
}
/*
=== algoritma / logika penyelesaian ===
1. minta input:
2. N = jumlah babak
S = string hasil pertandingan (A, B, atau C)
3. inisialisasi variabel:
poinA = 0, poinB = 0
streakA = 0, streakB = 0
4. lakukan perulangan dari i = 0 sampai N-1:
-jika S[i] == 'A':
poinA += 3
streakA bertambah 1
streakB = 0
jika streakA == 3:
poinA += 2 (bonus)

-jika S[i] == 'B':
poinB += 3
streakB bertambah 1
streakA = 0
jika streakB == 3:
poinB += 2 (bonus)

-jika S[i] == 'C' (seri):
poinA += 1
poinB += 1
streakA = 0
streakB = 0

5. setelah perulangan selesai, tentukan pemenang:
jika poinA > poinB → pemain A menang
jika poinB > poinA → pemain B menang
jika sama → hasil seri

6. tampilkan hasil:
pemenang pertandingan
total poin pemain A
total poin pemain B
*/
