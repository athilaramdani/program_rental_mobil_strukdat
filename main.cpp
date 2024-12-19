#include "rental.h"

int main()
{
    //Athila Ramdani Saputra & Arkanzi Suharjanto
    // 103012300132 & 103012300055
    //tubes std
    ListParent listMobil;
    createListParent(listMobil);
    bool show = true;
   // Data dummy add

    // Data Mobil dan Penyewa Dummy
    string nomorPlat[] = {"D 1234 ABC", "B 4321 XYZ", "BK 5678 DEF", "D 7890 GHI", "B 8765 JKL", 
                          "BK 2468 MNO", "D 1357 PQR", "B 9753 STU", "BK 4680 VWX", "D 1029 YZ", 
                          "B 2233 PPL", "DK 4421 LMO", "AB 5671 NOP", "AD 9821 QRS", "E 5512 TUV", 
                          "L 8371 WXY", "N 3092 ZAB", "AA 1123 CDE", "H 9145 FGH", "S 7126 IJK"};

    string namaPenyewa[] = {"Vanessa", "Asep", "Budi", "Putri", "Arkanzi", "Yanto", "Yanti", "Dewi", "Fadli", "Sari", 
                             "Fikri", "Rina", "Adi", "Lina", "Tono", "Dina", "Reza", "Maya", "Joko", "Eka", 
                             "Farah", "Yusuf", "Kiki", "Rico", "Sinta", "Rahman", "Arsyad", "Aldi", "Intan", "Sandi", 
                             "Mila", "Dodi", "Alya", "Sandi", "Rosa", "Lutfi", "Ami", "Bambang", "Nina", "Nisa", 
                             "Caca", "Rafi", "Juli", "Rizki", "Damar", "Tika", "Amir", "Bill", "Athila", "Maming", 
                             };

    string merek[] = {"Toyota", "Honda", "Suzuki", "Mitsubishi", "Nissan", "Daihatsu", "Hyundai", "Kia", "Mazda", "Ford"};
    string tipe[] = {"Avanza", "Civic", "Ertiga", "Pajero", "Grand Livina", "Terios", "Santa Fe", "Seltos", "CX-5", "Ranger"};

    // Generate data dummy
    for (int i = 0; i < 20; ++i) {
        Mobil mobil;
        mobil.nomorPlat = nomorPlat[i];
        mobil.merk = merek[i % 10];
        mobil.tipe = tipe[i % 10];

        adr_parent parent = createParent(mobil);
        insertParent(listMobil, parent);

        int jumlahPenyewa = 2 + (i % 9);
        for (int j = 0; j < jumlahPenyewa; ++j) {
            Penyewa penyewa;
            penyewa.nama = namaPenyewa[(i * jumlahPenyewa + j) % 50];
            penyewa.durasi = 1 + (j % 12); 
            penyewa.transaksi = penyewa.durasi * 50000; 

            adr_child child = createChild(penyewa);
            insertChild(parent, child);
        }
    }

    // Data dummy end

    int pilihanUtama;
    do
    {
        //Menu Utamanya, untuk memilih menu edit, transaction atau keluar
        showMenu();
        cin >> pilihanUtama;
        cin.ignore(); 

        switch (pilihanUtama)
        {
        case 1: 
        {
            int pilihanEditor;
            do
            {
                showMenuEdit(listMobil);
                cin >> pilihanEditor;
                cin.ignore();

                switch (pilihanEditor)
                {
                case 1: // Tambah Mobil
                {
                    Mobil dataMobil;
                    cout << "Masukkan Nomor Plat: ";
                    getline(cin, dataMobil.nomorPlat);
                    cout << "Masukkan Merk Mobil: ";
                    getline(cin, dataMobil.merk);
                    cout << "Masukkan Tipe Mobil: ";
                    getline(cin, dataMobil.tipe);

                    adr_parent newMobil = createParent(dataMobil);
                    insertParent(listMobil, newMobil);
                    cout << "Mobil berhasil ditambahkan!" << endl;
                    break;
                }
                case 2: // Tambah Penyewa
                {
                    Penyewa dataPenyewa;
                    cout << "Masukkan Nama Penyewa: ";
                    getline(cin, dataPenyewa.nama);
                    cout << "Masukkan Durasi Penyewaan (dalam jam): ";
                    cin >> dataPenyewa.durasi;
                    cout << "Masukkan Total Transaksi (dalam Rupiah): ";
                    cin >> dataPenyewa.transaksi;
                    cin.ignore();

                    cout << "Pilih Mobil yang disewa:" << endl;
                    showAll(listMobil);

                    string plat;
                    cout << "Masukkan Nomor Plat Mobil: ";
                    getline(cin, plat);
                    adr_parent P = findMobil(listMobil, plat);

                    if (P != NULL)
                    {
                        adr_child newPenyewa = createChild(dataPenyewa);
                        insertChild(P, newPenyewa);
                        cout << "Penyewa berhasil ditambahkan!" << endl;
                    }
                    else
                    {
                        cout << "Mobil tidak ditemukan!" << endl;
                    }
                    break;
                }
                case 3: // Edit Mobil
                {
                    string nomorPlat;
                    cout << "Masukkan Nomor Plat Mobil yang ingin diubah: ";
                    getline(cin, nomorPlat);

                    adr_parent P = findMobil(listMobil, nomorPlat);
                    if (P != NULL)
                    {
                        updateParent(P);
                        cout << "Data mobil berhasil diubah!" << endl;
                    }
                    else
                    {
                        cout << "Mobil tidak ditemukan!" << endl;
                    }
                    break;
                }
                case 4: // Edit Penyewa
                {
                    string plat, nama;
                    cout << "Masukkan Nomor Plat Mobil: ";
                    getline(cin, plat);

                    adr_parent P = findMobil(listMobil, plat);
                    if (P != NULL)
                    {
                        updateChild(P);
                    }
                    else
                    {
                        cout << "Mobil tidak ditemukan!" << endl;
                    }
                    break;
                }
                case 5: // Hapus Mobil
                {
                    string nomorPlat;
                    cout << "Masukkan Nomor Plat Mobil yang ingin dihapus: ";
                    getline(cin, nomorPlat);
                    deleteParent(listMobil, nomorPlat);
                    break;
                }
                case 6: // Hapus Penyewa
                {
                    string plat, nama;
                    cout << "Masukkan Nomor Plat Mobil: ";
                    getline(cin, plat);

                    adr_parent P = findMobil(listMobil, plat);
                    if (P != NULL)
                    {
                        cout << "Masukkan Nama Penyewa yang ingin dihapus: ";
                        getline(cin, nama);
                        deleteChild(P, nama);
                    }
                    else
                    {
                        cout << "Mobil tidak ditemukan!" << endl;
                    }
                    break;
                }
                case 0: // Keluar
                    cout << "Kembali ke menu utama." << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                    break;
                }
                cout << endl;
            } while (pilihanEditor != 0);
            break;
        }
        case 2: // Data Transaction
        {
            int pilihanTransaksi;
            do
            {
                showMenuTransaction(listMobil, show);
                cin >> pilihanTransaksi;
                cin.ignore();

                switch (pilihanTransaksi)
                {
                case 1: // Tampilkan Semua Data
                {
                    show = !show;
                    break;
                }
                case 2: // Cek Mobil
                {
                   cekMobil(listMobil);
                    break;
                }
                case 3: // Cek Penyewa
                {
                    cekPenyewa(listMobil);
                    break;
                }
                case 4: // Hitung Total Durasi dan Transaksi di rental
                {
                    hitungTotalDurasiTransaksi(listMobil);
                    break;
                }
                case 0: // Keluar
                    cout << "Kembali ke menu utama." << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                    break;
                }
                cout << endl;
            } while (pilihanTransaksi != 0);
            break;
        }
        case 0: // Keluar
            cout << "Terima kasih telah menggunakan sistem rental mobil." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            break;
        }

        cout << endl;
    } while (pilihanUtama != 0);

    return 0;
}
