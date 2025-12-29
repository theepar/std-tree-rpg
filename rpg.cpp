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

    inOrder(root->child);
    cout << root->info << " -> ";
    inOrder(root->next);
}

// Post-order Traversal: Child -> Sibling -> Root
void postOrder(adrNode root) {
    if (root == nullptr) return;

    postOrder(root->child);
    postOrder(root->next);
    cout << root->info << " -> ";
}

bool deleteNode(adrNode &root, string value) {
    if (root == nullptr) return false;

    adrNode prev = nullptr;
    adrNode curr = root->child;

    while (curr != nullptr) {
        if (curr->info == value) {
            if (prev == nullptr) {
                root->child = curr->next;
            } else {
                prev->next = curr->next;
            }
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

    curr = root->child;
    while (curr != nullptr) {
        if (deleteNode(curr, value)) return true;
        curr = curr->next;
    }

    return false;
}

void buildBaseStructure(adrNode &root){
    root = newNode("Game RPG");

    adrNode map = newNode("Map");
    adrNode quest = newNode("Quest");
    insertChild(root, map);
    insertChild(root, quest);

    adrNode kotaAwal = newNode("Kota Awal");
    adrNode hutanGelap = newNode("Hutan Gelap");
    adrNode dungeonKuno = newNode("Dungeon Kuno");
    insertChild(map, kotaAwal);
    insertChild(map, hutanGelap);
    insertChild(map, dungeonKuno);

    adrNode mainQuest = newNode("Main Quest");
    adrNode sideQuest = newNode("Side Quest");
    insertChild(quest, mainQuest);
    insertChild(quest, sideQuest);

    insertChild(kotaAwal, newNode("NPC Pedagang"));
    insertChild(kotaAwal, newNode("NPC Pandai Besi"));

    insertChild(hutanGelap, newNode("Goblin"));
    insertChild(hutanGelap, newNode("Serigala"));
    insertChild(hutanGelap, newNode("Naga Hutan"));

    insertChild(dungeonKuno, newNode("Skeleton"));
    insertChild(dungeonKuno, newNode("Boss Lich"));
    insertChild(dungeonKuno, newNode("Treasure Chest"));

    insertChild(mainQuest, newNode("Kalahkan Naga"));
    insertChild(mainQuest, newNode("Selamatkan Putri"));

    insertChild(sideQuest, newNode("Kumpulkan 10 Herb"));
    insertChild(sideQuest, newNode("Bunuh 5 Goblin"));
}

// Mencetak path dari root menuju node target
bool printPath(adrNode root, string target) {
    if (root == nullptr) return false;

    if (root->info == target) {
        cout << root->info;
        return true;
    }

    adrNode child = root->child;
    while (child != nullptr) {
        if (printPath(child, target)) {
            return true;
        }
        child = child->next;
    }

    return false;
}

// Helper untuk printPath
bool findPath(adrNode root, string target, string &path) {
    if (root == nullptr) return false;

    if (root->info == target) {
        path = root->info;
        return true;
    }

    adrNode child = root->child;
    while (child != nullptr) {
        if (findPath(child, target, path)) {
            path = root->info + " -> " + path;
            return true;
        }
        child = child->next;
    }

    return false;
}

// Fitur Update Node
bool updateNode(adrNode root, string oldValue, string newValue) {
    if (root == nullptr) return false;

    adrNode target = findNode(root, oldValue);

    if (target != nullptr) {
        target->info = newValue;
        return true;
    }

    return false;
}
