#ifndef RPG_H_INCLUDED
#define RPG_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

typedef struct Node* adrNode;

struct Node {
    string info;
    adrNode child;
    adrNode next;
};

adrNode newNode(string x);
void insertChild(adrNode &parent, adrNode child);
adrNode findNode(adrNode root, string value);
void printTree(adrNode root, int level);

void preOrder(adrNode root);
void inOrder(adrNode root);
void postOrder(adrNode root);

bool deleteNode(adrNode &root, string value);
void buildBaseStructure(adrNode &root);
bool printPath(adrNode root, string target);
bool findPath(adrNode root, string target, string &path);
bool updateNode(adrNode root, string oldValue, string newValue);

#endif
