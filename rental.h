#ifndef RENTAL_H_INCLUDED
#define RENTAL_H_INCLUDED

#include <iostream>
#include <string>

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define first_child(P) P->first_child

using namespace std;

// Struct untuk Parent (Mobil)
struct Mobil
{
    string nomorPlat;
    string merk;
    string tipe;
};

// Struct untuk Child (Penyewa)
struct Penyewa
{
    string nama;
    int durasi;      // dalam jam
    float transaksi; // dalam rupiah
};

// Elemen Parent
typedef struct elemenParent *adr_parent;
// Elemen Child
typedef struct elemenChild *adr_child;

struct elemenParent // type dll
{
    Mobil info;
    adr_parent next;
    adr_parent prev;    
    adr_child first_child; 
};

struct elemenChild // SLL
{
    Penyewa info;
    adr_child next;
};

// List Parent
struct ListParent
{
    adr_parent first;
    adr_parent last;
};

// Prosedur dan Fungsi
void createListParent(ListParent &L);
adr_parent createParent(Mobil data);
adr_child createChild(Penyewa data);

void insertParent(ListParent &L, adr_parent P);
void insertChild(adr_parent P, adr_child C);

void showAll(ListParent L);
void showAllPenyewaPadaMobil(adr_parent P);

adr_parent findMobil(ListParent L, string nomorPlat);
void deleteParent(ListParent &L, string nomorPlat);
void deleteChild(adr_parent P, string nama);

int totalDurasi(adr_parent P);
float totalTransaksi(adr_parent P);

void updateParent(adr_parent &P);
void updateChild(adr_parent P);
void cekPenyewa(ListParent LP);
void cekMobil(ListParent LP);
void hitungTotalDurasiTransaksi(ListParent LP);

void showMenu();
void showMenuTransaction(ListParent LP, bool show);
void showMenuEdit(ListParent LP);

#endif
