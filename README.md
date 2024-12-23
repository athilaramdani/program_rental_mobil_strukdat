# Rental Mobil Athdanz X Kenzi
## [![Typing SVG](https://readme-typing-svg.demolab.com/?lines=Hello+gengs+!;Ini+AthdanzXkenzi😎)](https://git.io/typing-svg)
Sistem ini dirancang untuk mengelola data rental mobil, mencakup pencatatan data mobil, data penyewa, transaksi, dan berbagai fitur lain yang mendukung pengelolaan rental mobil secara efisien.

## Fitur Utama

### 1. **Manajemen Data Mobil**
- **Tambah Mobil**: Menambahkan data mobil baru ke dalam sistem.
- **Edit Mobil**: Mengubah data mobil yang sudah ada, seperti nomor plat, merk, dan tipe.
- **Hapus Mobil**: Menghapus data mobil dari sistem.
- **Tampilkan Semua Mobil**: Melihat daftar mobil beserta detailnya.

### 2. **Manajemen Data Penyewa**
- **Tambah Penyewa**: Menambahkan data penyewa baru pada mobil tertentu.
- **Edit Penyewa**: Mengubah data penyewa yang sudah ada, seperti nama, durasi, dan transaksi.
- **Hapus Penyewa**: Menghapus data penyewa dari mobil tertentu.
- **Tampilkan Semua Penyewa**: Melihat daftar penyewa yang terhubung pada setiap mobil.

### 3. **Pencarian Data**
- **Cari Mobil Berdasarkan Nomor Plat**: Menemukan mobil berdasarkan nomor platnya.
- **Cari Penyewa Berdasarkan Nama**: Menemukan data penyewa tertentu, termasuk total durasi dan transaksi penyewa tersebut.

### 4. **Transaksi**
- **Hitung Total Durasi dan Transaksi**:
  - Menampilkan total durasi penyewaan dan total transaksi untuk setiap mobil.
  - Menampilkan total durasi dan transaksi keseluruhan dari semua mobil dalam sistem.

### 5. **Laporan dan Tampilan Data**
- **Tampilkan Data Mobil dan Penyewa**:
  - Menampilkan data mobil, penyewa yang terhubung dengan mobil tersebut, serta detail transaksi.
- **Tampilkan Total Durasi dan Transaksi untuk Setiap Mobil**: Memberikan laporan khusus per mobil.

### 6. **Menu Utama**
- **Data Editor**:
  - Akses menu untuk pengelolaan data mobil dan penyewa.
- **Data Transaction**:
  - Akses menu transaksi untuk melihat dan menghitung total durasi serta transaksi.

## Teknologi yang Digunakan
- **Bahasa Pemrograman**: C++
- **Struktur Data**: 
  - *Doubly Linked List* untuk menyimpan data mobil.
  - *Single Linked List* untuk menyimpan data penyewa yang terkait dengan mobil tertentu.

## Struktur Program
### Header File: `rental.h`
Berisi definisi struktur data, tipe elemen, dan deklarasi fungsi/prosedur yang digunakan dalam sistem ini.

### File Implementasi: `rental.cpp`
Berisi implementasi fungsi/prosedur seperti:
- **`createListParent`**: Inisialisasi daftar mobil.
- **`createParent` dan `createChild`**: Membuat elemen baru untuk mobil dan penyewa.
- **`insertParent` dan `insertChild`**: Menambahkan elemen baru ke dalam daftar mobil atau daftar penyewa.
- **`showAll` dan `showAllPenyewaPadaMobil`**: Menampilkan data mobil dan penyewa.
- **`findMobil`**: Mencari mobil berdasarkan nomor plat.
- **`deleteParent` dan `deleteChild`**: Menghapus data mobil atau penyewa.
- **`updateParent` dan `updateChild`**: Memperbarui data mobil atau penyewa.
- **`cekPenyewa` dan `cekMobil`**: Mencari data spesifik untuk penyewa atau mobil tertentu.
- **`hitungTotalDurasiTransaksi`**: Menghitung total durasi dan transaksi untuk semua mobil.

## Cara Menggunakan
1. **Kompilasi Program**:
   ```bash
   g++ rental.cpp -o rental
   ```
2. **Jalankan Program**:
   ```bash
   ./rental
   ```
3. Pilih menu sesuai kebutuhan:
   - Gunakan **Data Editor** untuk mengelola data.
   - Gunakan **Data Transaction** untuk melihat laporan data.