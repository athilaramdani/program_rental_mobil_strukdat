#include "rental.h"

void createListParent(ListParent &L){
    /* I.S Terdefinisi L sebagai List parent
   F.S first(L) dan last(L) diassign NULL
*/ 
    first(L) = NULL;
    last(L) = NULL;
}

adr_parent createParent(Mobil data){
    /* I.S Terdefinisi data berupa informasi mobil
   F.S Mengembalikan alamat elemen parent baru dengan info data, next, prev, dan first_child diassign NULL
*/
    adr_parent P = new elemenParent;
    info(P) = data;
    first_child(P) = NULL;
    next(P) = NULL;
    prev(P) = NULL; 
    return P;
}

adr_child createChild(Penyewa data){
    /* I.S Terdefinisi data berupa informasi penyewa
   F.S Mengembalikan alamat elemen child baru dengan info data dan next diassign NULL
*/
    adr_child C = new elemenChild;
    info(C) = data;
    next(C) = NULL;
    return C;
}

void insertParent(ListParent &L, adr_parent P){
    /* I.S Terdefinisi L sebagai List parent dan P sebagai elemen parent
   F.S Elemen P ditambahkan ke akhir List L
*/
    //insert last
    if (first(L) == NULL) 
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        next(last(L)) = P; 
        prev(P) = last(L); 
        last(L) = P;
    }
}

void insertChild(adr_parent P, adr_child C) {
    /* I.S Terdefinisi P sebagai parent, dan C sebagai elemen child baru
   F.S Elemen C ditambahkan ke awal daftar anak dari parent P
*/
    //insert First tapi asumsi sudah ada parent awal
    next(C) = first_child(P);
    first_child(P) = C;
}

void showAll(ListParent L){
/* I.S Terdefinisi L sebagai List parent
   F.S Menampilkan seluruh data mobil dan penyewa di setiap mobil
*/
    //menampilkan seluruh mobil sambil menampilkan penyewanya per mobil

    adr_parent P = first(L);
    while (P != NULL)
    {
        cout << "\033[34mNomor Plat: " << info(P).nomorPlat
             << ", Merk: " << info(P).merk
             << ", Tipe: " << info(P).tipe << "\033[0m" <<endl;
        showAllPenyewaPadaMobil(P); 
        P = next(P);
    }
}

void showAllPenyewaPadaMobil(adr_parent P){
    /* I.S Terdefinisi P sebagai parent yaitu mobil
   F.S Menampilkan seluruh penyewa yang terdaftar pada parent P
*/
    adr_child C = first_child(P);
    while (C != NULL)
    {
        cout << "\033[38;2;255;165;0m  Penyewa: " << info(C).nama
             << ", Durasi: " << info(C).durasi
             << " jam, Total Transaksi: Rp " << info(C).transaksi << "\033[0m" <<endl;
        C = next(C);
    }
}

adr_parent findMobil(ListParent L, string nomorPlat){
    /* I.S Terdefinisi L sebagai List parent dan nomorPlat sebagai string untuk pencarian
   F.S Mengembalikan alamat elemen parent jika ditemukan, atau NULL jika tidak ditemukan
*/
    //mencari mobil berdasarkan nommor plat
    adr_parent P = first(L);
    while (P != NULL && info(P).nomorPlat != nomorPlat)
    {
        P = next(P);
    }
    return P;
}

void deleteParent(ListParent &L, string nomorPlat){
    /* I.S Terdefinisi L sebagai List parent dan nomorPlat sebagai string untuk pencarian
   F.S Menghapus elemen parent dengan nomor plat yang sesuai, jika ditemukan, namun child yang bersangkutan tidak didelete but its you know child nya tuh udah ga bisa diakses
*/
    //menghapus mobil berdasarkan nomor plat
    adr_parent P = first(L);
    adr_parent prev = NULL;

    while (P != NULL && info(P).nomorPlat != nomorPlat) {

        prev = P;
        P = next(P);
    }
    if (P != NULL) {
        if (prev == NULL) {
            first(L) = next(P);
            if (first(L) != NULL) {
                prev(first(L)) = NULL; 
            }
        } else {
            next(prev) = next(P);
            if (next(P) != NULL) {
                prev(next(P)) = prev; 
            }
        }
        cout << "Mobil dengan nomor plat " << nomorPlat << " berhasil dihapus." << endl;
    } else {
        cout << "Mobil dengan nomor plat " << nomorPlat << " tidak ditemukan." << endl;
    }
}

void deleteChild(adr_parent P, string nama){
    /* I.S Terdefinisi P sebagai parent, dan nama sebagai string untuk pencarian
   F.S Menghapus elemen child dengan nama yang sesuai dari parent P, jika ditemukan
*/
    //asumsi dia udah punya parentnya
    adr_child C = first_child(P), prev = NULL;

    while (C != NULL && info(C).nama != nama)
    {
        prev = C;
        C = next(C);
    }

    if (C != NULL) 
    {
        if (prev == NULL) 
        {
            first_child(P) = next(C);
        }
        else
        {
            next(prev) = next(C);
        }
        cout << "Penyewa dengan nama " << nama << " berhasil dihapus." << endl;
    }
    else
    {
        cout << "Penyewa dengan nama " << nama << " tidak ditemukan." << endl;
    }
}

int totalDurasi(adr_parent P){
/* I.S Terdefinisi P sebagai parent
   F.S Mengembalikan total durasi penyewaan untuk semua anak dari parent P
*/
    //dipanggil dari function cekmobil pada durasi

    int total = 0;
    adr_child C = first_child(P);
    while (C != NULL)
    {
        total += info(C).durasi;
        C = next(C);
    }
    return total;
}

float totalTransaksi(adr_parent P){
/* I.S Terdefinisi P sebagai parent
   F.S Mengembalikan total transaksi penyewaan untuk semua anak dari parent P
*/

    // dipanggil dari function cekmobil pada transaksi
    float total = 0;
    adr_child C = first_child(P);
    while (C != NULL)
    {
        total += info(C).transaksi;
        C = next(C);
    }
    return total;
}


void updateParent(adr_parent &P){
        /* I.S Terdefinisi P sebagai parent
   F.S Data mobil pada parent P diperbarui dengan input baru dari pengguna
*/
    cout << "Mengubah data mobil:" << endl;
    cout << "Masukkan Nomor Plat Baru: ";
    getline(cin, info(P).nomorPlat);
    cout << "Masukkan Merk Mobil Baru: ";
    getline(cin, info(P).merk);
    cout << "Masukkan Tipe Mobil Baru: ";
    getline(cin, info(P).tipe);
}

void updateChild(adr_parent P) {
/* I.S Terdefinisi P sebagai parent
   F.S Data penyewa pada salah satu anak dari parent P diperbarui jika ditemukan
*/
    // Memastikan parent tidak kosong
    if (P == NULL)
    {
        cout << "Parent tidak ditemukan. Tidak ada data yang dapat diperbarui." << endl;
    } else {
        string nama;
        cout << "Masukkan nama penyewa yang ingin diupdate: ";
        getline(cin, nama);

        adr_child C = first_child(P);
        while (C != NULL && info(C).nama != nama)
        {
            C = next(C);
        }

        if (C != NULL)
        {
            cout << "Data penyewa ditemukan, silakan masukkan data baru." << endl;
            cout << "Masukkan Nama Baru: ";
            getline(cin, info(C).nama);
            cout << "Masukkan Durasi Penyewaan Baru (jam): ";
            cin >> info(C).durasi;
            cout << "Masukkan Total Transaksi Baru: Rp ";
            cin >> info(C).transaksi;
            cin.ignore(); // Mengatasi masalah input buffer
            cout << "Data penyewa berhasil diperbarui." << endl;
        }
        else
        {
            cout << "Penyewa dengan nama " << nama << " tidak ditemukan." << endl;
        }
    }

}

void cekPenyewa(ListParent LP){
    /* I.S Terdefinisi LP sebagai list parent (mobil-mobil yang tersedia)
   F.S Menampilkan data penyewa berdasarkan nama yang dicari, 
        termasuk total durasi dan transaksi penyewa jika ditemukan
*/
    string nama;
    cout << "Masukkan Nama Penyewa: ";
    getline(cin, nama);

    bool found = false;
    int totalDurasiPenyewa = 0;
    float totalTransaksiPenyewa = 0;

    adr_parent P = first(LP);

    while (P != NULL) {
        adr_child C = first_child(P);
        while (C != NULL) {
            if (info(C).nama == nama) {
                if (!found) {
                    cout << "\033[36mData Penyewa Ditemukan:\033[0m\n";
                }
                found = true;

                cout << "\033[34mMobil yang Disewa:\033[0m\n";
                cout << "Nomor Plat: " << info(P).nomorPlat
                     << ", Merk: " << info(P).merk
                     << ", Tipe: " << info(P).tipe << endl;
                cout << "Durasi: " << info(C).durasi << " jam, Total Transaksi: Rp " << info(C).transaksi << endl;

                totalDurasiPenyewa += info(C).durasi;
                totalTransaksiPenyewa += info(C).transaksi;
            }
            C = next(C);
        }
        P = next(P);
    }

    // Menampilkan hasil akhir
    if (found) {
        cout << "\033[32mTotal Durasi Penyewaan: " << totalDurasiPenyewa << " jam\033[0m" << endl;
        cout << "\033[32mTotal Transaksi Penyewaan: Rp " << totalTransaksiPenyewa << "\033[0m" << endl;
    } else {
        cout << "Penyewa dengan nama " << nama << " tidak ditemukan." << endl;
    }
    cout << "=====================================" << endl;

    // Memberikan waktu kepada pengguna sebelum kembali ke menu
    cout << "Ketik apapun untuk melanjutkan: ";
    string keluar;
    cin >> keluar;
}

void cekMobil(ListParent LP){
    /* I.S Terdefinisi LP sebagai list parent (mobil-mobil yang tersedia)
   F.S Menampilkan detail mobil berdasarkan nomor plat, termasuk data penyewa, total durasi, dan total transaksi untuk mobil tersebut
*/
    string nomorPlat;
    cout << "Masukkan Nomor Plat Mobil: ";
    getline(cin, nomorPlat);

    adr_parent mobil = findMobil(LP, nomorPlat);
    if (mobil != NULL)
    {
        cout << "Mobil ditemukan: \n"
             << "========= DETAIL MOBIL =========\n"
             << "Nomor Plat: " << info(mobil).nomorPlat << endl
             << "Merk: " << info(mobil).merk << endl
             << "Tipe: " << info(mobil).tipe << endl;

        // Menampilkan data penyewa pada mobil
        adr_child penyewa = first_child(mobil);
        while (penyewa != NULL)
        {
            cout << "Penyewa: " << info(penyewa).nama << endl
                 << "Durasi: " << info(penyewa).durasi << " jam" << endl
                 << "Total Transaksi: Rp " << info(penyewa).transaksi << endl;
            penyewa = next(penyewa);
        }

        // Memanggil fungsi totalDurasi dan totalTransaksi
        int totalDurasiMobil = totalDurasi(mobil);
        float totalTransaksiMobil = totalTransaksi(mobil);

        cout << "\033[32mTotal Durasi Penyewaan pada mobil: " << totalDurasiMobil << " jam\033[0m" << endl;
        cout << "\033[32mTotal Transaksi Penyewaan pada mobil: Rp " << totalTransaksiMobil << "\033[0m" << endl;

    }
    else
    {
        cout << "Mobil dengan nomor plat " << nomorPlat << " tidak ditemukan!" << endl;
    }
    cout << "=====================================" << endl;
    string keluar;
    cout << "ketik apapun untuk melanjutkan: ";
    cin >> keluar;
}
void hitungTotalDurasiTransaksi(ListParent LP){
    /* I.S Terdefinisi LP sebagai list parent (mobil-mobil yang tersedia)
   F.S Menghitung dan menampilkan total durasi dan total transaksi dari semua mobil dalam rental
*/
    int totalDurasi = 0;
    double totalTransaksi = 0.0;

    adr_parent P = first(LP);
    while (P != NULL)
    {
        adr_child C = first_child(P);
        while (C != NULL)
        {
            totalDurasi += info(C).durasi;
            totalTransaksi += info(C).transaksi;
            C = next(C);
        }
        P = next(P);
    }
    cout << "Total Durasi Penyewaan di rental: " << totalDurasi << " jam" << endl;
    cout << "Total Transaksi Penyewaan di rental: Rp " << totalTransaksi << endl;
}


void showMenu(){
    /* I.S Tidak ada
   F.S Menampilkan menu utama pada sistem rental mobil
*/
    cout << "============================================" << endl;
    cout << "    SISTEM RENTAL MOBIL Athdanz X Kenzi                  " << endl;
    cout << "============================================" << endl;
    cout << "1. Data Editor" << endl;
    cout << "2. Data Transaction" << endl;
    cout << "0. Keluar" << endl;
    cout << "============================================" << endl;
    cout << "Masukkan pilihan: ";
}

void showMenuEdit(ListParent LP){
    /* I.S Terdefinisi LP sebagai list parent (mobil-mobil yang tersedia)
   F.S Menampilkan menu editor untuk pengelolaan data mobil dan penyewa
*/
    cout << "============================================" << endl;
    cout << "      DATA EDITOR" << endl;
    cout << "============================================" << endl;
    showAll(LP);
    cout << "1. Tambah Mobil" << endl;
    cout << "2. Tambah Penyewa" << endl;
    cout << "3. Edit Mobil" << endl;
    cout << "4. Edit Penyewa" << endl;
    cout << "5. Hapus Mobil" << endl;
    cout << "6. Hapus Penyewa" << endl;
    cout << "0. Keluar" << endl;
    cout << "============================================" << endl;
    cout << "Masukkan pilihan: ";
}

void showMenuTransaction(ListParent LP, bool show) {
    /* I.S Terdefinisi LP sebagai list parent (mobil-mobil yang tersedia) dan status show untuk menampilkan data
   F.S Menampilkan menu transaksi dan data sesuai status show (ON/OFF)
*/
    cout << "============================================" << endl;
    cout << "      TRANSACTION MENU" << endl;
    cout << "============================================" << endl;
    if (show) {
        showAll(LP);
        cout << "\033[32m1. TOGGLE Tampilkan Semua Data = ON\033[0m" << endl;
    } else {
        cout << "\033[31m1. TOGGLE Tampilkan Semua Data = OFF\033[0m" << endl;
    }
    cout << "2. cek Mobil" << endl;
    cout << "3. cek Penyewa" << endl;
    cout << "4. Hitung Total Durasi dan Transaksi Penyewaan Rental" << endl;
    cout << "0. Keluar" << endl;
    cout << "============================================" << endl;
    cout << "Masukkan pilihan: ";
}


