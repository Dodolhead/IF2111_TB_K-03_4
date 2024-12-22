#include "map.h"
#include "../../../utilities.h"
#include <stdio.h>

/* *** Konstruktor/Kreator *** */
void CreateMapEmpty(Map *M) {
    M->Count = NilMap;
}

/* *** Predikat Untuk Test Keadaan KOLEKSI *** */
boolean IsMapEmpty(Map *M) {
    return M->Count == NilMap;
}

boolean IsMapFull(Map *M) {
    return M->Count == MaxEl;
}

/* *** Operator Dasar Map *** */
valuetype Value(Map *M, keytype k) {
    for (int i = 0; i < M->Count; i++) {
        if (stringEquals(M->Elements[i].Key, k)) {
            return M->Elements[i].Value;
        }
    }
    return Undefined;
}


void Insert(Map *M, keytype k, valuetype v) {
    // Pastikan kita tidak melebihi kapasitas dan key belum ada
    if (!IsMapFull(M) && !IsMember(M, k)) {
        // Menyalin kunci ke dalam array menggunakan copyString
        copyString(M->Elements[M->Count].Key, k);  // Salin kunci ke M->Elements[M->Count].Key
        
        // Menetapkan nilai ke elemen yang sesuai
        M->Elements[M->Count].Value = v;
        
        // Menambah jumlah elemen
        M->Count++;
    }
}


        // Increment the count
void Delete(Map *M, keytype k) {
    if (!IsMapEmpty(M)) {
        int idx = -1;
        for (int i = 0; i < M->Count; i++) {
            if (stringEquals(M->Elements[i].Key, k)) {
                idx = i;
                break;
            }
        }
        if (idx != -1) {
            for (int j = idx; j < M->Count - 1; j++) {
                M->Elements[j] = M->Elements[j + 1];
            }
            M->Count--;
        }
    }
}

boolean IsMember(Map *M, keytype k) {
    for (int i = 0; i < M->Count; i++) {
        if (stringEquals(M->Elements[i].Key, k)) {
            return true;
        }
    }
    return false;
}
