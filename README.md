# Game RPG - General Tree Implementation

## Deskripsi Proyek
Implementasi **General Tree** (N-ary Tree) menggunakan representasi **Left-Child Right-Sibling (LCRS)** untuk studi kasus sistem struktur Game RPG.

---

## Struktur Node

```cpp
struct Node {
    string info;      // Data/nama node
    adrNode child;    // Pointer ke anak pertama
    adrNode next;     // Pointer ke saudara (sibling)
};
```

### Visualisasi Pointer
```
child → untuk turun ke ANAK (level bawah)
next  → untuk ke SAUDARA (level yang sama)
```

---

## Struktur Tree Game RPG

```
Game RPG
├── Map
│   ├── Kota Awal
│   │   ├── NPC Pedagang
│   │   ├── NPC Pandai Besi
│   │   └── Inn
│   ├── Hutan Gelap
│   │   ├── Goblin
│   │   ├── Serigala
│   │   └── Naga Hutan
│   └── Dungeon Kuno
│       ├── Skeleton
│       ├── Boss Lich
│       └── Treasure Chest
└── Quest
    ├── Main Quest
    │   ├── Kalahkan Naga
    │   └── Selamatkan Putri
    └── Side Quest
        ├── Kumpulkan 10 Herb
        └── Bunuh 5 Goblin
```

---

## Daftar Fungsi

### 1. Primitives

| Fungsi | Deskripsi |
|--------|-----------|
| `adrNode newNode(string x)` | Membuat node baru dengan info = x |
| `void insertChild(adrNode &parent, adrNode child)` | Menambahkan anak ke parent (insert last) |
| `adrNode findNode(adrNode root, string value)` | Mencari node berdasarkan nama (rekursif) |
| `void printTree(adrNode root, int level)` | Menampilkan tree dengan indentasi |

### 2. Traversal

| Fungsi | Urutan Kunjungan |
|--------|------------------|
| `void preOrder(adrNode root)` | Root → Child → Sibling |
| `void inOrder(adrNode root)` | First Child → Root → Other Children |
| `void postOrder(adrNode root)` | Child → Sibling → Root |

### 3. Operasi Lainnya

| Fungsi | Deskripsi |
|--------|-----------|
| `bool deleteNode(adrNode &root, string value)` | Menghapus node beserta semua anaknya |
| `void buildBaseStructure(adrNode &root)` | Membangun struktur tree statis |

---

## File Program

| File | Deskripsi |
|------|-----------|
| `rpg.h` | Header file - deklarasi struct dan fungsi |
| `rpg.cpp` | Implementasi semua fungsi |
| `main.cpp` | Program utama - demo semua fitur |

---

## Cara Kompilasi & Menjalankan

### Menggunakan g++
```bash
g++ -o rpg main.cpp rpg.cpp
./rpg
```

### Menggunakan Code::Blocks
1. Buka project `rpg.cbp`
2. Klik Build & Run (F9)

---

## Fitur Program

1. **Visualisasi Tree** - Menampilkan struktur tree dengan indentasi
2. **Traversal** - Pre-order, In-order, Post-order
3. **Hapus Node** - Input nama node untuk dihapus
4. **Cari Node** - Input nama node untuk dicari

---

## Contoh Output

```
=== STRUKTUR GAME RPG ===
Struktur tree telah dibuat secara statis.
==========================

========================================
       VISUALISASI TREE GAME RPG        
========================================
Game RPG
    |-- Map
        |-- Kota Awal
            |-- NPC Pedagang
            |-- NPC Pandai Besi
            |-- Inn
        |-- Hutan Gelap
            |-- Goblin
            ...

========================================
           TRAVERSAL TREE               
========================================

[Pre-Order Traversal]
Root -> Child -> Sibling
Game RPG -> Map -> Kota Awal -> NPC Pedagang -> ... -> END
```

---

## Catatan

- Ini adalah **General Tree**, bukan Binary Tree
- Representasi menggunakan **Left-Child Right-Sibling (LCRS)**
- Setiap node bisa memiliki jumlah anak yang tidak terbatas
- Semua operasi traversal menggunakan **rekursi**
