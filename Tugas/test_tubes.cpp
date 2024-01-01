#include <iostream>
using namespace std;

// Struktur data untuk menu
struct Menu{
  string namaMenu;
  string kategori;
  string subKategori;
  string event;
  float harga;
  int stok;
};

// Tree untuk menyimpan data menu
struct Node{
  Menu data;
  Node* left;
  Node* right;
};

int main(){

  return 0;
}