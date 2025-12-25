#include "rpg.h"

adrNode newNode(string x) {
    adrNode p = new Node;
    p->info = x;
    p->child = nullptr;
    p->next = nullptr;
    return p;
}

void insertChild(adrNode &parent, adrNode child) {
    if (parent == nullptr) return;

    if (parent->child == nullptr) {
        parent->child = child;
    } else {
        adrNode p = parent->child;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = child;
    }
}

adrNode findNode(adrNode root, string value) {
    if (root == nullptr) return nullptr;

    if (root->info == value) return root;

    adrNode found = findNode(root->child, value);
    if (found != nullptr) return found;

    return findNode(root->next, value);
}

void printTree(adrNode root, int level) {
    if (root == nullptr) return;

    for (int i = 0; i < level; i++) {
        cout << "    ";
    }

    if (level > 0) cout << "|-- ";

    cout << root->info << endl;

    printTree(root->child, level + 1);

    printTree(root->next, level);
}

// Pre-order Traversal: Root -> Child -> Sibling
void preOrder(adrNode root) {
    if (root == nullptr) return;
    
    cout << root->info << " -> ";
    preOrder(root->child);
    preOrder(root->next);
}

// In-order Traversal: Left Child -> Root -> Right Siblings
void inOrder(adrNode root) {
    if (root == nullptr) return;
    
    if (root->child != nullptr) {
        inOrder(root->child);
    }
    
    cout << root->info << " -> ";
    
    if (root->child != nullptr && root->child->next != nullptr) {
        inOrder(root->child->next);
    }
    
    inOrder(root->next);
}

// Post-order Traversal: Child -> Sibling -> Root
void postOrder(adrNode root) {
    if (root == nullptr) return;
    
    postOrder(root->child);
    postOrder(root->next);
    cout << root->info << " -> ";
}

// Menghapus node berdasarkan nama 
bool deleteNode(adrNode &root, string value) {
    if (root == nullptr) return false;
    
    adrNode prev = nullptr;
    adrNode curr = root->child;
    
    while (curr != nullptr) {
        if (curr->info == value) {
            // Hapus curr dari list
            if (prev == nullptr) {
                // curr adalah anak pertama
                root->child = curr->next;
            } else {
                prev->next = curr->next;
            }
            // Hapus semua anak dari curr secara rekursif
            while (curr->child != nullptr) {
                deleteNode(curr, curr->child->info);
            }
            delete curr;
            cout << "Node '" << value << "' berhasil dihapus!" << endl;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    
    // Cari rekursif ke anak-anak
    curr = root->child;
    while (curr != nullptr) {
        if (deleteNode(curr, value)) return true;
        curr = curr->next;
    }
    
    return false;
}

void buildBaseStructure(adrNode &root) {
    // Level 0 - Root
    root = newNode("Game RPG");

    // Level 1
    adrNode map = newNode("Map");
    adrNode quest = newNode("Quest");
    insertChild(root, map);
    insertChild(root, quest);

    // Level 2 - Anak dari Map
    adrNode kotaAwal = newNode("Kota Awal");
    adrNode hutanGelap = newNode("Hutan Gelap");
    adrNode dungeonKuno = newNode("Dungeon Kuno");
    insertChild(map, kotaAwal);
    insertChild(map, hutanGelap);
    insertChild(map, dungeonKuno);

    // Level 2 - Anak dari Quest
    adrNode mainQuest = newNode("Main Quest");
    adrNode sideQuest = newNode("Side Quest");
    insertChild(quest, mainQuest);
    insertChild(quest, sideQuest);

    // Level 3 - Anak dari Kota Awal
    insertChild(kotaAwal, newNode("NPC Pedagang"));
    insertChild(kotaAwal, newNode("NPC Pandai Besi"));
    insertChild(kotaAwal, newNode("Inn"));

    // Level 3 - Anak dari Hutan Gelap
    insertChild(hutanGelap, newNode("Goblin"));
    insertChild(hutanGelap, newNode("Serigala"));
    insertChild(hutanGelap, newNode("Naga Hutan"));

    // Level 3 - Anak dari Dungeon Kuno
    insertChild(dungeonKuno, newNode("Skeleton"));
    insertChild(dungeonKuno, newNode("Boss Lich"));
    insertChild(dungeonKuno, newNode("Treasure Chest"));

    // Level 3 - Anak dari Main Quest
    insertChild(mainQuest, newNode("Kalahkan Naga"));
    insertChild(mainQuest, newNode("Selamatkan Putri"));

    // Level 3 - Anak dari Side Quest
    insertChild(sideQuest, newNode("Kumpulkan 10 Herb"));
    insertChild(sideQuest, newNode("Bunuh 5 Goblin"));
}
