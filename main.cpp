#include <iostream>
#include "rpg.h"

using namespace std;

int main() {
    adrNode root = nullptr;

    buildBaseStructure(root);

    cout << "=== STRUKTUR GAME RPG ===" << endl;
    cout << "Struktur tree telah dibuat secara statis." << endl;
    cout << "==========================" << endl;

    cout << "\n\n========================================" << endl;
    cout << "       VISUALISASI TREE GAME RPG        " << endl;
    cout << "========================================" << endl;
    printTree(root, 0);

    cout << "\n\n========================================" << endl;
    cout << "           TRAVERSAL TREE               " << endl;
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

    cout << "\n\n========================================" << endl;
    cout << "           HAPUS NODE                   " << endl;
    cout << "========================================" << endl;

    string deleteChoice;
    cout << "Apakah Anda ingin menghapus node? (y/n): ";
    getline(cin, deleteChoice);

    while (deleteChoice == "y" || deleteChoice == "Y") {
        string nodeToDelete;
        cout << "Masukkan nama node yang ingin dihapus: ";
        getline(cin, nodeToDelete);

        if (!nodeToDelete.empty()) {
            if (!deleteNode(root, nodeToDelete)) {
                cout << "Node '" << nodeToDelete << "' tidak ditemukan!" << endl;
            }
        }

        cout << "\n[Tree setelah penghapusan]" << endl;
        printTree(root, 0);

        cout << "\nHapus node lain? (y/n): ";
        getline(cin, deleteChoice);
    }

    cout << "\n\n========================================" << endl;
    cout << "           PENCARIAN NODE               " << endl;
    cout << "========================================" << endl;

    string searchChoice;
    cout << "Apakah Anda ingin mencari node? (y/n): ";
    getline(cin, searchChoice);

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

    cout << "\n\n========================================" << endl;
    cout << "       PROGRAM SELESAI - TERIMA KASIH   " << endl;
    cout << "========================================" << endl;

    return 0;
}
