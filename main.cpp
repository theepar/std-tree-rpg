#include <iostream>
#include "rpg.h"

using namespace std;

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
    cout << "7. Navigasi (GPS / Jejak Leluhur)" << endl;
    cout << "8. Update Nama Node" << endl;
    cout << "0. Keluar" << endl;
    cout << "========================================" << endl;
    cout << "Pilih menu [0-8]: ";
}

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

void menuVisualisasi(adrNode root) {
    cout << "\n========================================" << endl;
    cout << "       VISUALISASI TREE GAME RPG       " << endl;
    cout << "========================================" << endl;
    printTree(root, 0);
    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.get();
}

void menuPreOrderTraversal(adrNode root) {
    cout << "\n[Pre-Order Traversal]" << endl;
    cout << "Root -> Child -> Sibling" << endl;
    preOrder(root);
    cout << "END" << endl;

    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.get();
}

void menuInOrderTraversal(adrNode root) {
    cout << "\n[In-Order Traversal]" << endl;
    cout << "Left Child -> Root -> Right Siblings" << endl;
    inOrder(root);
    cout << "END" << endl;

    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.get();
}

void menuPostOrderTraversal(adrNode root) {
    cout << "\n[Post-Order Traversal]" << endl;
    cout << "Child -> Sibling -> Root" << endl;
    postOrder(root);
    cout << "END" << endl;

    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.get();
}

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

void menuHapusNode(adrNode& root) {
    cout << "\n========================================" << endl;
    cout << "           HAPUS NODE                  " << endl;
    cout << "========================================" << endl;

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

    buildBaseStructure(root);

    do {
        cout << "\n=== STRUKTUR GAME RPG ===" << endl;
        cout << "Struktur tree telah dibuat." << endl;

        tampilkanMenu();
        getline(cin, input);

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
                deleteTree(root);
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
            case 7: {
                cout << "\n========================================" << endl;
                cout << "     NAVIGASI (JEJAK NODE)    " << endl;
                cout << "========================================" << endl;
                cout << "[Struktur Tree Saat Ini]" << endl;
                printTree(root, 0);
                cout << endl;

                string navChoice = "y";
                while (navChoice == "y" || navChoice == "Y") {
                    string targetNode;
                    cout << "Masukkan nama node tujuan: ";
                    getline(cin, targetNode);

                    if (!targetNode.empty()) {
                        string path = "";
                        
                        if (findPath(root, targetNode, path)) {
                            cout << "\n[PATH DITEMUKAN]" << endl;
                            cout << "Jejak Node: " << path << endl;
                        } else {
                            cout << "\nNode '" << targetNode << "' TIDAK DITEMUKAN dalam tree!" << endl;
                        }
                    }

                    cout << "\nCari path lain? (y/n): ";
                    getline(cin, navChoice);
                }
                break;
            }
            case 8: {
                // Menu Update Nama Node
                cout << "\n========================================" << endl;
                cout << "          UPDATE NAMA NODE             " << endl;
                cout << "========================================" << endl;
                cout << "[Struktur Tree Saat Ini]" << endl;
                printTree(root, 0);
                cout << endl;

                string updateChoice = "y";
                while (updateChoice == "y" || updateChoice == "Y") {
                    string oldName, newName;
                    cout << "Masukkan nama node yang ingin diubah: ";
                    getline(cin, oldName);

                    if (!oldName.empty()) {
                        adrNode checkNode = findNode(root, oldName);
                        if (checkNode != nullptr) {
                            cout << "Masukkan nama baru: ";
                            getline(cin, newName);

                            if (!newName.empty()) {
                                if (updateNode(root, oldName, newName)) {
                                    cout << "\nBerhasil mengubah '" << oldName << "' menjadi '" << newName << "'!" << endl;
                                    cout << "\n[Tree setelah update]" << endl;
                                    printTree(root, 0);
                                }
                            } else {
                                cout << "Nama baru tidak boleh kosong!" << endl;
                            }
                        } else {
                            cout << "Node '" << oldName << "' tidak ditemukan!" << endl;
                        }
                    }

                    cout << "\nUpdate node lain? (y/n): ";
                    getline(cin, updateChoice);
                }
                break;
            }
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
