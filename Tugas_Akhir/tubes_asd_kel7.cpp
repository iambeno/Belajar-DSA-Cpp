#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

// Fungsi untuk login
// Fitur login dibuat dengan menyimpan data akun yang didaftarkan kedalam file bernama dataAkun.txt
// info akun yang disimpan berupa nama, username dan password ke file dataAkun.txt

void daftar(){
  string username, password, nama;
  cout << "---------------Daftar akun---------------" << endl;
  cout << "Masukkan nama anda : ";
  getline(cin, nama);

  cout << "Buat username : ";
  cin >> username;

  cin.ignore(); // membersihkan buffer setelah menggunakan cin
  cout << "Buat password : ";
  cin >> password;

  ofstream file("dataAkun.txt", ios::app); // ios::app berfungsi utk membuka file dalam mode append agar bisa memperbarui file (diakhir baris) disetiap kali data ditambahkan ke file

  if(file.is_open()){
    file << "| " << nama << "\t\t| " << username << " \t\t\t\t\t| " << password << " \t\t\t\t\t|"<< endl;

    // Menutup file
    file.close();
  } else{
    cout << "Gagal membuka file" << endl;
  }


  // Menampilkan konfirmasi ke layar
  cout << "\n\nAkun berhasil dibuat" << endl;
  cout << "Nama \t : " << nama << endl;
  cout << "Username : " << username << endl;
  cout << "Password : " << password << endl;
  cout << "\nIngat username dan password anda agar bisa tetap login \n" << endl;

  cout << "Tekan sembarang tombol untuk melanjutkan...";
  getch(); // Menunggu pengguna menekan sembarang tombol sebelum melanjutkan
  cout << "\n"<< endl;
}

void welcome(){
  int pilihan;
  do{
    cout << "==========WELCOME==========" << endl;
    cout << "1. Daftar" << endl;
    cout << "2. Login" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan pilihan [1/2/0] : ";
    cin >> pilihan;
    cin.ignore(); // membersihkan buffer setelah menggunakan cin
    switch (pilihan){
      case 1:
        daftar();
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
  system("cls");
  welcome();

  return 0;
}