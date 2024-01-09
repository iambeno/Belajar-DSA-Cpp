// // Fungsi untuk menghapus item menu dan menghapusnya dari sistem
// void deleteItem(MenuNode* node, const string& category, const string& subcategory, const string& itemName) {
//     for (auto it = node->items.begin(); it != node->items.end(); ++it) {
//         if (it->name == itemName) {
//             // Hapus item dari vektor items
//             node->items.erase(it);
            
//             // Hapus harga dari sistem
//             cout << "Item " << itemName << " dihapus dari sistem.\n";
//             return;
//         }
//     }

//     // Cari di anak-anak node
//     for (auto& child : node->children) {
//         deleteItem(child, category, subcategory, itemName);
//     }
// }

#include <iostream>
#include <map>
#include <string>

struct Menu {
    std::string name;
    int price;
    int availability;
    std::string subCategory;
};

std::map<std::string, Menu> upperEastMenu;
std::map<std::string, int> upperEastStock;

void addMenu(const std::string &name, int price, int availability, const std::string &subCategory) {
    Menu newMenu;
    newMenu.name = name;
    newMenu.price = price;
    newMenu.availability = availability;
    newMenu.subCategory = subCategory;

    upperEastMenu.insert(std::make_pair(name, newMenu));
    upperEastStock.insert(std::make_pair(name, availability));
}

void updatePrice(const std::string &name, int newPrice) {
    upperEastMenu[name].price = newPrice;
}

void updateStock(const std::string &name, int newStock) {
    upperEastStock[name] = newStock;
}

void checkStock() {
    for (const auto &menu : upperEastMenu) {
        if (upperEastStock[menu.first] < 5) {
            std::cout << "Stock untuk menu " << menu.first << " kurang dari 5!" << std::endl;
        }
    }
}

int main() {
    addMenu("Capuchino", 2000, 10, "Kopi");
    addMenu("Cappucino", 2500, 8, "Kopi");
    addMenu("Latte", 2300, 12, "Kopi");

    updatePrice("Capuchino", 2200);
    updateStock("Capuchino", 50);

    checkStock();

    return 0;
}