#include <iostream>
using namespace std;

void arr1(){

  // Deklarasi array
  string mahasiswa[5]; 

  // Inisialisasi array cara 1:
  mahasiswa[0] = "Beno";
  mahasiswa[1] = "Felix";
  mahasiswa[2] = "Humam";

  // Deklarasi + inisialisasi array:
  string prodi[5] = {"Ilmu Komputer", "Manajemen", "Ekonomi"};

  // Mengakses elemen array:
  for (int i = 0; i < 5; i++){
    cout << prodi[i] << " ";
  }
  cout << endl;
  cout << "Data Mahasiswa" << endl;
  cout << "Nama \t: " << mahasiswa[0] << endl;
  cout << "Prodi \t: " << prodi[0] << endl;
}

void arr2(){

  // Membuat array 2D
  // Array 2D itu konsepnya sama dengan matriks yang dimana memiliki baris dan kolom

  int no_urut[3][2] = {
    {1, 2},
    {3, 4},
    {5, 6}
  };

  // Mengakses elemen array 2D:
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 2; j++){
      cout << no_urut[i][j] << " ";
    }
    cout << endl;
  }

  string matkul[4][3] = {
    {"Kode", "Nama Matkkul", "Pengajar"},
    {"52001", "Probstat", "Ade Irawan"},
    {"52002", "Alin", "M. Zaky A"},
    {"52003", "ASD", "Meredita"}
  };

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 3; j++){
      cout << matkul[i][j] << " \t";
    }
    cout << endl;
  }
}

void arr3(){

  int id[] =  {1, 2, 3, 4};
  cout << id[3] << endl;

  cout <<  "ID : ";
  for (int i =  0; i < 4; i++){
    cout << id[i] << " ";
  }
  cout << "\n" << endl;

  char abjad[2][3] = {
    {'a', 'b', 'c'},
    {'d', 'e', 'f'}
  };

  for(int i =  0; i < 2; i++){
    for (int j = 0; j < 3; j++){
      cout << abjad[i][j] << " ";
    }
    cout << endl;
  }
}

void arr4(){
  // string anggota[];
  string anggota[] = {"Beno"};
}

void  arr5(){
  float ipk[4] = {3.02, 3.7, 2.8};
  ipk[3] = {3.5};

  cout << ipk[3] << endl;

  for (int i = 0; i < 4; i++){
    cout << ipk[i] << " ";
  }
}


int main(){
  system("cls");
  arr1();
  cout << endl;

  arr2();
  cout << endl;

  arr3();
  cout << endl;

  arr5();
  cout << endl;

  return 0;
}