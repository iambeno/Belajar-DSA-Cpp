#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Fungsi untuk login
// Simpan info login berupa username dan pw ke file datalogin.txt

void login(){
  ofstream datalogin;
  string username, password;


}

void welcome(){
  int pilihan;
  cout << "==========WELCOME==========" << endl;
  do{
    cout << "1. Daftar" << endl;
    cout << "2. Login" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan pilihan [1/2/0] : ";
    cin >> pilihan;
    switch (pilihan){
      case 1:
        cout << "Daftar" << endl;
        break;
      case 2: 
        cout << "Login" << endl;
        break;
      case 0:
        cout << "Exit" << endl;
        exit(1);
        break;
      default:
        cout << "Pilihan tidak tersedia, coba lagi" << endl;
    }
  } while(true);

}

int main(){
  welcome();

  return 0;
}