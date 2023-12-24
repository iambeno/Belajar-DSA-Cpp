#include <iostream>
#include <string>

using namespace std;

// Struktur data untuk menu
struct Menu {
  string nama;
  string kategori;
  string subKategori;
  string event;
  float harga;
};

// Struktur data untuk bahan baku
struct BahanBaku {
  string nama;
  int stok;
  int minimumStok;
};

// Tree untuk menyimpan data menu
struct Node {
  Menu data;
  Node* left;
  Node* right;
};

// Linked list untuk menyimpan data bahan baku
struct NodeBahanBaku {
  BahanBaku data;
  NodeBahanBaku* next;
};

// Fungsi untuk menampilkan menu
void tampilkanMenu(Node* root) {
  if (root == nullptr) {
    return;
  }

  cout << root->data.nama << " (" << root->data.kategori << ", " << root->data.subKategori << ", " << root->data.event << ") - Rp" << root->data.harga << endl;
  tampilkanMenu(root->left);
  tampilkanMenu(root->right);
}

// Fungsi untuk menambahkan menu baru
void tambahMenu(Node** root, Menu menu) {
  Node* newNode = new Node();
  newNode->data = menu;

  if (*root == nullptr) {
    *root = newNode;
    return;
  }

  Node* current = *root;
  while (current != nullptr) {
    if (menu.kategori < current->data.kategori) {
      if (current->left == nullptr) {
        current->left = newNode;
        return;
      }
      current = current->left;
    } else if (menu.kategori > current->data.kategori) {
      if (current->right == nullptr) {
        current->right = newNode;
        return;
      }
      current = current->right;
    } else if (menu.subKategori < current->data.subKategori) {
      if (current->left == nullptr) {
        current->left = newNode;
        return;
      }
      current = current->left;
    } else if (menu.subKategori > current->data.subKategori) {
      if (current->right == nullptr) {
        current->right = newNode;
        return;
      }
      current = current->right;
    } else if (menu.event < current->data.event) {
      if (current->left == nullptr) {
        current->left = newNode;
        return;
      }
      current = current->left;
    } else if (menu.event > current->data.event) {
      if (current->right == nullptr) {
        current->right = newNode;
        return;
      }
      current = current->right;
    } else {
      cout << "Menu dengan nama " << menu.nama << " sudah ada." << endl;
      return;
    }
  }
}

// Fungsi untuk menghapus menu
void hapusMenu(Node** root, string namaMenu) {
  if (*root == nullptr) {
    return;
  }

  Node* current = *root;
  Node* parent = nullptr;

  while (current != nullptr && current->data.nama != namaMenu) {
    parent = current;
    if (namaMenu < current->data.nama) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  if (current == nullptr) {
    cout << "Menu dengan nama " << namaMenu << " tidak ditemukan." << endl;
    return;
  }

  // Menu ditemukan
  if (current->left == nullptr && current->right == nullptr) {
    // Menu tidak memiliki child
    if (parent == nullptr) {
      *root = nullptr;
    } else if (parent->left == current) {
      parent->left = nullptr;
    } else {
      parent->right = nullptr;
    }
    delete current;
  } else if (current->left == nullptr) {
    // Menu hanya memiliki child kanan
    if (parent == nullptr) {
      *root = current->right;
    } else if (parent->left == current) {
      parent->left = current->right;
    } else {
      parent->right = current->right;
    }
    delete current;
  } else if (current->right == nullptr) {
    // Menu hanya memiliki child kiri
    if (parent == nullptr) {
      *root = current->left;
    } else if (parent->left == current) {
      parent->left = current->left;
    } else {
      parent->right = current->left;
    }
    delete current;
  } else {
    // Menu memiliki dua child
    Node* successorParent = current;
    Node* successor = current->right;

    while (successor->left != nullptr) {
      successorParent = successor;
      successor = successor->left;
    }

    // Ganti data current dengan data successor
    current->data = successor->data;

    // Hapus successor
    if (successorParent->left == successor) {
      successorParent->left = successor->right;
    } else {
      successorParent->right = successor->right;
    }
    delete successor;
  }
}

// Fungsi untuk menampilkan bahan baku
void tampilkanBahanBaku(NodeBahanBaku* head) {
  if (head == nullptr) {
    return;
  }

  cout << head->data.nama << " - " << head->data.stok << " - " << head->data.minimumStok << endl;
  tampilkanBahanBaku(head->next);
}

// Fungsi untuk menambahkan bahan baku baru
void tambahBahanBaku(NodeBahanBaku** head, BahanBaku bahanBaku) {
  NodeBahanBaku* newNode = new NodeBahanBaku();
  newNode->data = bahanBaku;
  newNode->next = nullptr;

  if (*head == nullptr) {
    *head = newNode;
    return;
  }

  NodeBahanBaku* current = *head;
  while (current->next != nullptr) {
    current = current->next;
  }

  current->next = newNode;
}

// Fungsi untuk mengurangi stok bahan baku
void kurangiStokBahanBaku(NodeBahanBaku** head, string namaBahanBaku, int jumlah) {
  if (*head == nullptr) {
    return;
  }

  NodeBahanBaku* current = *head;
  while (current != nullptr) {
    if (current->data.nama == namaBahanBaku) {
      current->data.stok -= jumlah;
      if (current->data.stok < current->data.minimumStok) {
        // Kirim notifikasi
      }
      return;
    }
    current = current->next;
  }
}

// Fungsi utama
int main() {
  // Inisialisasi data menu
  Menu menu1 = {"Croissant", "Roti dan Kue", "Viennoiseries", "Breakfast", 15000};
  Menu menu2 = {"Pain au Chocolate", "Roti dan Kue", "Viennoiseries", "Breakfast", 20000};
  Menu menu3 = {"Brioche", "Roti dan Kue", "Viennoiseries", "Breakfast", 25000};
  Menu menu4 = {"Éclair", "Roti dan Kue", "Pastry", "Breakfast", 30000};
  Menu menu5 = {"Mille-feuille", "Roti dan Kue", "Pastry", "Breakfast", 35000};
  Menu menu6 = {"Tarte Tatin", "Roti dan Kue", "Pastry", "Breakfast", 40000};
  Menu menu7 = {"Tarlet", "Roti dan Kue", "Pastry", "Breakfast", 45000};
  Menu menu8 = {"Bagel", "Roti dan Kue", "Bread", "Breakfast", 50000};
  Menu menu9 = {"Burger", "Roti dan Kue", "Bread", "Breakfast", 55000};
  Menu menu10 = {"Hotdog", "Roti dan Kue", "Bread", "Breakfast", 60000};

  // Inisialisasi data bahan baku
  BahanBaku bahanBaku1 = {"Tepung terigu", 100, 50};
  BahanBaku bahanBaku2 = {"Baking powder", 50, 25};
  BahanBaku bahanBaku3 = {"Gula pasir", 250, 125};
  BahanBaku bahanBaku4 = {"Telur", 100, 50};

  // Buat tree menu
  Node* root = nullptr;
  tambahMenu(&root, menu1);
  tambahMenu(&root, menu2);
  tambahMenu(&root, menu3);
  tambahMenu(&root, menu4);
  tambahMenu(&root, menu5);
  tambahMenu(&root, menu6);
  tambahMenu(&root, menu7);
  tambahMenu(&root, menu8);
  tambahMenu(&root, menu9);
  tambahMenu(&root, menu10);

  // Buat linked list bahan baku
  NodeBahanBaku* head = nullptr;
  tambahBahanBaku(&head, bahanBaku1);
  tambahBahanBaku(&head, bahanBaku2);
  tambahBahanBaku(&head, bahanBaku3);
  tambahBahanBaku(&head, bahanBaku4);

  // Buat menu pilihan
  int pilihan;
  do {
    cout << "Pilihan menu:" << endl;
    cout << "1. Tampilkan menu" << endl;
    cout << "2. Tambah menu" << endl;
    cout << "3. Hapus menu" << endl;
    cout << "4. Tampilkan bahan baku" << endl;
    cout << "5. Tambah bahan baku" << endl;
    cout << "6. Kurangi stok bahan baku" << endl;
    cout << "7. Keluar" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> pilihan;

    switch (pilihan) {
      case 1:
        // Tampilkan menu
        tampilkanMenu(root);
        break;
      case 2:
        // Tambah menu
        // Masukkan data menu
        Menu menu;
        cout << "Masukkan nama menu: ";
        cin >> menu.nama;
        cout << "Masukkan kategori menu: ";
        cin >> menu.kategori;
        cout << "Masukkan sub kategori menu: ";
        cin >> menu.subKategori;
        cout << "Masukkan event menu: ";
        cin >> menu.event;
        cout << "Masukkan harga menu: ";
        cin >> menu.harga;

        // Tambah menu ke tree
        tambahMenu(&root, menu);
        break;
      case 3:
        // Hapus menu
        // Masukkan nama menu yang akan dihapus
        string namaMenu;
        cout << "Masukkan nama menu yang akan dihapus: ";
        cin >> namaMenu;

        // Hapus menu dari tree
        hapusMenu(&root, namaMenu);
        break;
      case 4:
        // Tampilkan bahan baku
        tampilkanBahanBaku(head);
        break;
      case 5:
        // Tambah bahan baku
        // Masukkan data bahan baku
        BahanBaku bahanBaku;
        cout << "Masukkan nama bahan baku: ";
        cin >> bahanBaku.nama;
        cout << "Masukkan stok bahan baku: ";
        cin >> bahanBaku.stok;
        cout << "Masukkan minimum stok bahan baku: ";
        cin >> bahanBaku.minimumStok;

        // Tambah bahan baku ke linked list
        tambahBahanBaku(&head, bahanBaku);
        break;
      case 6:
        // Kurangi stok bahan baku
        // Masukkan nama bahan baku dan jumlah stok yang akan dikurangi
        string namaBahanBaku;
        int jumlah;
        cout << "Masukkan nama bahan baku: ";
        cin >> namaBahanBaku;
        cout << "Masukkan jumlah stok yang akan dikurangi: ";
        cin >> jumlah;

        // Kurangi stok bahan baku dari linked list
        kurangiStokBahanBaku(&head, namaBahanBaku, jumlah);
        break;
    }
  } while (pilihan != 7);

  return 0;
}
