#include <iostream>
using namespace std;

// Struct : adalah tipe data yang dapat menyimpan sejumlah elemen dengan tipe data berbeda

// Berikut ini adalah berbagai jenis dan cara yang saya praktekkan untuk mengimplementasikan konsep struct (record) dalam berbagai case

void data_mahasiswa(){

  // Deklarasi struct
  struct identitas{
    string nama;
    string nim;
  };

  identitas mahasiswa;
  cout << "Data Mahasiswa " << endl;
  cout << "Nama \t: ";
  getline(cin, mahasiswa.nama);
  cout << "NIM \t: ";
  cin >> mahasiswa.nim;
}

int main(){
  system("cls");

  data_mahasiswa();

  return 0;
}