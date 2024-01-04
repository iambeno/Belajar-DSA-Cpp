// Fungsi untuk menghapus item menu dan menghapusnya dari sistem
void deleteItem(MenuNode* node, const string& category, const string& subcategory, const string& itemName) {
    for (auto it = node->items.begin(); it != node->items.end(); ++it) {
        if (it->name == itemName) {
            // Hapus item dari vektor items
            node->items.erase(it);
            
            // Hapus harga dari sistem
            cout << "Item " << itemName << " dihapus dari sistem.\n";
            return;
        }
    }

    // Cari di anak-anak node
    for (auto& child : node->children) {
        deleteItem(child, category, subcategory, itemName);
    }
}