#include <iostream>
#include "rpg.h"

using namespace std;

// Fungsi menampilkan menu utama
void tampilkanMenu() {
    cout << "\n========================================" << endl;
    cout << "         MENU GAME RPG TREE            " << endl;
    cout << "========================================" << endl;
    cout << "1. Tampilkan Visualisasi Tree" << endl;
    cout << "2. Traversal Tree (Pre, In, Post Order)" << endl;
    cout << "3. Cari Node" << endl;
    cout << "4. Hapus Node" << endl;
    cout << "5. Reset Tree (Rebuild)" << endl;
    cout << "0. Keluar" << endl;
    cout << "========================================" << endl;
    cout << "Pilih menu [0-5]: ";
}

// Fungsi untuk menampilkan visualisasi tree
void menuVisualisasi(adrNode root) {
    cout << "\n========================================" << endl;
    cout << "       VISUALISASI TREE GAME RPG       " << endl;
    cout << "========================================" << endl;
    printTree(root, 0);
    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.get();
}

// Fungsi untuk menampilkan traversal
void menuTraversal(adrNode root) {
    cout << "\n========================================" << endl;
    cout << "           TRAVERSAL TREE              " << endl;
    cout << "========================================" << endl;

    cout << "\n[Pre-Order Traversal]" << endl;
    cout << "Root -> Child -> Sibling" << endl;
    preOrder(root);
    cout << "END" << endl;

    cout << "\n[In-Order Traversal]" << endl;
    cout << "Left Child -> Root -> Right Siblings" << endl;
    inOrder(root);
    cout << "END" << endl;

    cout << "\n[Post-Order Traversal]" << endl;
    cout << "Child -> Sibling -> Root" << endl;
    postOrder(root);
    cout << "END" << endl;

    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.get();
}

// Fungsi untuk pencarian node
void menuCariNode(adrNode root) {
    cout << "\n========================================" << endl;
    cout << "           PENCARIAN NODE              " << endl;
    cout << "========================================" << endl;

    string searchChoice = "y";
    while (searchChoice == "y" || searchChoice == "Y") {
        string nodeToSearch;
        cout << "Masukkan nama node yang ingin dicari: ";
        getline(cin, nodeToSearch);

        if (!nodeToSearch.empty()) {
            adrNode found = findNode(root, nodeToSearch);
            if (found != nullptr) {
                cout << "Node '" << nodeToSearch << "' DITEMUKAN dalam tree!" << endl;
            } else {
                cout << "Node '" << nodeToSearch << "' TIDAK DITEMUKAN dalam tree!" << endl;
            }
        }

        cout << "\nCari node lain? (y/n): ";
        getline(cin, searchChoice);
    }
}

// Fungsi untuk hapus node
void menuHapusNode(adrNode& root) {
    cout << "\n========================================" << endl;
    cout << "           HAPUS NODE                  " << endl;
    cout << "========================================" << endl;

    // Tampilkan tree terlebih dahulu
    cout << "[Struktur Tree Saat Ini]" << endl;
    printTree(root, 0);
    cout << endl;

    string deleteChoice = "y";
    while (deleteChoice == "y" || deleteChoice == "Y") {
        string nodeToDelete;
        cout << "Masukkan nama node yang ingin dihapus: ";
        getline(cin, nodeToDelete);

        if (!nodeToDelete.empty()) {
            if (!deleteNode(root, nodeToDelete)) {
                cout << "Node '" << nodeToDelete << "' tidak ditemukan!" << endl;
            } else {
                cout << "Node '" << nodeToDelete << "' berhasil dihapus!" << endl;
            }
        }

        cout << "\n[Tree setelah penghapusan]" << endl;
        printTree(root, 0);

        cout << "\nHapus node lain? (y/n): ";
        getline(cin, deleteChoice);
    }
}

int main() {
    adrNode root = nullptr;
    int pilihan;
    string input;

    // Build struktur awal
    buildBaseStructure(root);

    do {
        cout << "\n=== STRUKTUR GAME RPG ===" << endl;
        cout << "Struktur tree telah dibuat." << endl;

        tampilkanMenu();
        getline(cin, input);

        // Validasi input
        if (input.empty() || input.length() > 1 || !isdigit(input[0])) {
            cout << "Input tidak valid! Tekan Enter...";
            cin.get();
            continue;
        }

        pilihan = stoi(input);

        switch (pilihan) {
            case 1:
                menuVisualisasi(root);
                break;
            case 2:
                menuTraversal(root);
                break;
            case 3:
                menuCariNode(root);
                break;
            case 4:
                menuHapusNode(root);
                break;
            case 5:
                // Reset tree
                root = nullptr;
                buildBaseStructure(root);
                cout << "\nTree berhasil di-reset!" << endl;
                cout << "Tekan Enter untuk kembali ke menu...";
                cin.get();
                break;
            case 0:
                cout << "\n========================================" << endl;
                cout << "   TERIMA KASIH TELAH MENGGUNAKAN      " << endl;
                cout << "         PROGRAM GAME RPG TREE         " << endl;
                cout << "========================================" << endl;
                break;
            default:
                cout << "Pilihan tidak valid! Tekan Enter...";
                cin.get();
        }

    } while (pilihan != 0);

    return 0;
}
