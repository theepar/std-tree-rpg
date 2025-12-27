#include <iostream>
#include "rpg.h"

using namespace std;

// Fungsi menampilkan menu utama
void tampilkanMenu() {
    cout << "\n========================================" << endl;
    cout << "         MENU GAME RPG TREE            " << endl;
    cout << "========================================" << endl;
    cout << "1. Tampilkan Tree saat ini" << endl;
    cout << "2. Traversal Tree (Pre, In, Post Order)" << endl;
    cout << "3. Cari Node" << endl;
    cout << "4. Hapus Node" << endl;
    cout << "5. Reset Tree (Rebuild)" << endl;
    cout << "6. Insert Data" << endl;
    cout << "0. Keluar" << endl;
    cout << "========================================" << endl;
    cout << "Pilih menu [0-6]: ";
}

//Fungsi menampilkan menu traversal
void tampilkanMenuTraversal(){
    cout << "\n========================================" << endl;
    cout << "           PILIH TRAVERSAL         " << endl;
    cout << "========================================" << endl;
    cout << "1. Pre Order" << endl;
    cout << "2. In Order" << endl;
    cout << "3. Post Order" << endl;
    cout << "========================================" << endl;
    cout << "Nomer: ";
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

// Fungsi untuk menampilkan pre order traversal
void menuPreOrderTraversal(adrNode root) {
    cout << "\n[Pre-Order Traversal]" << endl;
    cout << "Root -> Child -> Sibling" << endl;
    preOrder(root);
    cout << "END" << endl;

    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.get();
}

// Fungsi untuk menampilkan in order traversal
void menuInOrderTraversal(adrNode root) {
    cout << "\n[In-Order Traversal]" << endl;
    cout << "Left Child -> Root -> Right Siblings" << endl;
    inOrder(root);
    cout << "END" << endl;

    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.get();
}

// Fungsi untuk menampilkan post order traversal
void menuPostOrderTraversal(adrNode root) {
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
    adrNode cPointer, pPointer;
    int pilihan;
    string input, parent, child;

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
                tampilkanMenuTraversal();
                getline(cin, input);
                pilihan = stoi(input);
                switch(pilihan){
                    case 1:
                        menuPreOrderTraversal(root);
                        break;

                    case 2:
                        menuInOrderTraversal(root);
                        break;

                    case 3:
                        menuPostOrderTraversal(root);
                        break;
                    default:
                        cout << "Pilihan tidak valid! Tekan Enter...";
                        cin.get();
                }
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
            case 6:
                cout << "Masukan parent yang ingin di input: ";
                getline(cin, parent);
                pPointer = findNode(root,parent);

                if (pPointer != nullptr) {
                    cout << "Masukkan nama Child yang ingin di input: ";
                    getline(cin, child);

                    cPointer = newNode(child);

                    insertChild(pPointer, cPointer);

                    cout << "\nBerhasil menambahkan " << child << " sebagai child dari " << parent << endl;
                } else {
                    cout << "\nError: " << parent << " tidak ditemukan dalam tree!" << endl;
                    cout << "Gunakan menu 1 untuk melihat struktur tree yang tersedia." << endl;
                }

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
