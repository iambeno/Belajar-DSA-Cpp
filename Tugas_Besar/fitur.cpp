#include <iostream>
#include <conio.h>
using namespace std;

int pilihan;

void fiturDaftarMenu(){
  cout << "\nFitur daftar menu" << endl;
  do{
    cout << "9. Kembali" << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilihan;
    if (pilihan == 9){
      break;
    }
    else
      cout << "Pilihan tidak tersedia, coba lagi" << endl;
  }while(true);
}

void menuUtama_pil(int input){
  switch(input){
    case 1: 
      cout << "\nDaftar menu" << endl;
      fiturDaftarMenu();
      cout << "\nLanjutkan...";
      getch();
      cout << endl;
      break;
    case 2:
      cout << "\nTambah menu" << endl;
      cout << "\nLanjutkan...";
      getch();
      cout << endl;
      break;
    case 3:
      cout << "\nHapus menu" << endl;
      cout << "\nLanjutkan...";
      getch();
      cout << endl;
      break;
    case 4:
      cout << "\nTambah bahan baku" << endl;
      cout << "\nLanjutkan...";
      getch();
      cout << endl;
      break;
    case 5:
      cout << "\nUpdate harga" << endl;
      cout << "\nLanjutkan...";
      getch();
      cout << endl;
      break;
    case 6:
      cout << "\nLaporan pembelian" << endl;
      cout << "\nLanjutkan...";
      getch();
      cout << endl;
      break;
    case 0:
      cout << "\nTerima kasih, sampai jumpa!\n" << endl;
      exit(0);
      break;
    default:
      cout << "\nPilihan tidak tersedia, coba lagi" << endl;
      break;
  }
}

void menuUtama(){
  do{
    cout << "===============WELCOME===============" << endl;
    cout << "1. Daftar menu\n";
    cout << "2. Tambah menu\n";
    cout << "3. Hapus menu\n";
    cout << "4. Tambah bahan baku\n";
    cout << "5. Update harga\n";
    cout << "6. Buat laporan pembelian\n";
    cout << "0. Tutup\n";
    cout << "Masukkan pilihan [1/2/3/4/5/6/0] : ";
    cin >> pilihan;
    menuUtama_pil(pilihan);
  } while(true);
}

int main(){
  system("cls");

  menuUtama();

  return 0;
}