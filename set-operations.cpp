// Set Operations Project
// Author: M.SUMYUGTHA
// Language: C++
// Concepts: Structures, Arrays, Function Overloading
#include <iostream>
using namespace std;

const int MAX_ELEMENTS = 100;


struct NumSet {
    double values[MAX_ELEMENTS];
    int size;
};

struct NumCollection {
    NumSet sets[20];
    int count;
};


struct StrSet {
    char values[MAX_ELEMENTS][50];
    int size;
};

struct StrCollection {
    StrSet sets[20];
    int count;
};


bool strEqual(const char* s1, const char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return false;
        i++;
    }
    return s1[i] == s2[i];
}


void strCopy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}


void balanceCollections(NumCollection &A, NumCollection &B) {
    if (A.count < B.count) {
        while (A.count < B.count) {
            A.sets[A.count].size = 0;
            A.count++;
        }
    } else if (B.count < A.count) {
        while (B.count < A.count) {
            B.sets[B.count].size = 0;
            B.count++;
        }
    }
}

void balanceCollections(StrCollection &A, StrCollection &B) {
    if (A.count < B.count) {
        while (A.count < B.count) {
            A.sets[A.count].size = 0;
            A.count++;
        }
    } else if (B.count < A.count) {
        while (B.count < A.count) {
            B.sets[B.count].size = 0;
            B.count++;
        }
    }
}


bool isEqual(NumSet s1, NumSet s2) {
    if (s1.size != s2.size) return false;
    for (int i = 0; i < s1.size; i++) {
        if (s1.values[i] != s2.values[i]) return false;
    }
    return true;
}


bool isEqual(StrSet s1, StrSet s2) {
    if (s1.size != s2.size) return false;
    for (int i = 0; i < s1.size; i++) {
        if (!strEqual(s1.values[i], s2.values[i])) return false;
    }
    return true;
}


void inputNumCollection(NumCollection &C, const char* name) {
    cout << "\n--- Input for " << name << " ---\n";
    cout << "Enter number of Sets: ";
    cin >> C.count;
    for (int i = 0; i < C.count; i++) {
        cout << "Enter size of Set " << i+1 << ": ";
        cin >> C.sets[i].size;
        cout << "Enter values: ";
        for (int j = 0; j < C.sets[i].size; j++) {
            cin >> C.sets[i].values[j];
        }
    }
}


void inputStrCollection(StrCollection &C, const char* name) {
    cout << "\n--- Input for " << name << " ---\n";
    cout << "Enter number of Sets: ";
    cin >> C.count;
    for (int i = 0; i < C.count; i++) {
        cout << "Enter size of Set " << i+1 << ": ";
        cin >> C.sets[i].size;
        cout << "Enter strings: ";
        for (int j = 0; j < C.sets[i].size; j++) {
            cin >> C.sets[i].values[j];
        }
    }
}


NumCollection merge(NumCollection A, NumCollection B) {
    NumCollection result;
    result.count = 0;
    for (int i = 0; i < A.count; i++)
        result.sets[result.count++] = A.sets[i];
    for (int i = 0; i < B.count; i++)
        result.sets[result.count++] = B.sets[i];
    return result;
}


StrCollection merge(StrCollection A, StrCollection B) {
    StrCollection result;
    result.count = 0;
    for (int i = 0; i < A.count; i++)
        result.sets[result.count++] = A.sets[i];
    for (int i = 0; i < B.count; i++)
        result.sets[result.count++] = B.sets[i];
    return result;
}


NumCollection setUnion(NumCollection A, NumCollection B) {
    NumCollection result;
    result.count = 0;


    for (int i = 0; i < A.count; i++) {
        bool found = false;
        for (int k = 0; k < result.count; k++) {
            if (isEqual(A.sets[i], result.sets[k])) {
                found = true;
                break;
            }
        }
        if (!found) result.sets[result.count++] = A.sets[i];
    }


    for (int i = 0; i < B.count; i++) {
        bool found = false;
        for (int k = 0; k < result.count; k++) {
            if (isEqual(B.sets[i], result.sets[k])) {
                found = true;
                break;
            }
        }
        if (!found) result.sets[result.count++] = B.sets[i];
    }
    return result;
}

StrCollection setUnion(StrCollection A, StrCollection B) {
    StrCollection result;
    result.count = 0;

    for (int i = 0; i < A.count; i++) {
        bool found = false;
        for (int k = 0; k < result.count; k++) {
            if (isEqual(A.sets[i], result.sets[k])) {
                found = true;
                break;
            }
        }
        if (!found) result.sets[result.count++] = A.sets[i];
    }

    for (int i = 0; i < B.count; i++) {
        bool found = false;
        for (int k = 0; k < result.count; k++) {
            if (isEqual(B.sets[i], result.sets[k])) {
                found = true;
                break;
            }
        }
        if (!found) result.sets[result.count++] = B.sets[i];
    }
    return result;
}


NumCollection setIntersection(NumCollection A, NumCollection B) {
    NumCollection result;
    result.count = 0;
    for (int i = 0; i < A.count; i++) {
        for (int j = 0; j < B.count; j++) {
            if (isEqual(A.sets[i], B.sets[j])) {
                result.sets[result.count++] = A.sets[i];
                break;
            }
        }
    }
    return result;
}

StrCollection setIntersection(StrCollection A, StrCollection B) {
    StrCollection result;
    result.count = 0;
    for (int i = 0; i < A.count; i++) {
        for (int j = 0; j < B.count; j++) {
            if (isEqual(A.sets[i], B.sets[j])) {
                result.sets[result.count++] = A.sets[i];
                break;
            }
        }
    }
    return result;
}


NumCollection setDifference(NumCollection A, NumCollection B) {
    NumCollection result;
    result.count = 0;
    for (int i = 0; i < A.count; i++) {
        bool found = false;
        for (int j = 0; j < B.count; j++) {
            if (isEqual(A.sets[i], B.sets[j])) {
                found = true;
                break;
            }
        }
        if (!found) result.sets[result.count++] = A.sets[i];
    }
    return result;
}


StrCollection setDifference(StrCollection A, StrCollection B) {
    StrCollection result;
    result.count = 0;
    for (int i = 0; i < A.count; i++) {
        bool found = false;
        for (int j = 0; j < B.count; j++) {
            if (isEqual(A.sets[i], B.sets[j])) {
                found = true;
                break;
            }
        }
        if (!found) result.sets[result.count++] = A.sets[i];
    }
    return result;
}


NumCollection oddColumns(NumCollection C) {
    NumCollection result;
    result.count = C.count;
    for (int i = 0; i < C.count; i++) {
        result.sets[i].size = 0;
        for (int j = 0; j < C.sets[i].size; j++) {
            if (j % 2 == 1) {  // Odd index: 1, 3, 5, 7...
                result.sets[i].values[result.sets[i].size++] = C.sets[i].values[j];
            }
        }
    }
    return result;
}


StrCollection oddColumns(StrCollection C) {
    StrCollection result;
    result.count = C.count;
    for (int i = 0; i < C.count; i++) {
        result.sets[i].size = 0;
        for (int j = 0; j < C.sets[i].size; j++) {
            if (j % 2 == 1) {  // Odd index: 1, 3, 5, 7...
                strCopy(result.sets[i].values[result.sets[i].size++], C.sets[i].values[j]);
            }
        }
    }
    return result;
}


NumCollection evenColumns(NumCollection C) {
    NumCollection result;
    result.count = C.count;
    for (int i = 0; i < C.count; i++) {
        result.sets[i].size = 0;
        for (int j = 0; j < C.sets[i].size; j++) {
            if (j % 2 == 0) {  // Even index: 0, 2, 4, 6...
                result.sets[i].values[result.sets[i].size++] = C.sets[i].values[j];
            }
        }
    }
    return result;
}


StrCollection evenColumns(StrCollection C) {
    StrCollection result;
    result.count = C.count;
    for (int i = 0; i < C.count; i++) {
        result.sets[i].size = 0;
        for (int j = 0; j < C.sets[i].size; j++) {
            if (j % 2 == 0) {
                strCopy(result.sets[i].values[result.sets[i].size++], C.sets[i].values[j]);
            }
        }
    }
    return result;
}


NumCollection oddRows(NumCollection C) {
    NumCollection result;
    result.count = 0;
    for (int i = 0; i < C.count; i++) {
        if (i % 2 == 1) {
            result.sets[result.count++] = C.sets[i];
        }
    }
    return result;
}


StrCollection oddRows(StrCollection C) {
    StrCollection result;
    result.count = 0;
    for (int i = 0; i < C.count; i++) {
        if (i % 2 == 1) {
            result.sets[result.count++] = C.sets[i];
        }
    }
    return result;
}


NumCollection evenRows(NumCollection C) {
    NumCollection result;
    result.count = 0;
    for (int i = 0; i < C.count; i++) {
        if (i % 2 == 0) {
            result.sets[result.count++] = C.sets[i];
        }
    }
    return result;
}


StrCollection evenRows(StrCollection C) {
    StrCollection result;
    result.count = 0;
    for (int i = 0; i < C.count; i++) {
        if (i % 2 == 0) {
            result.sets[result.count++] = C.sets[i];
        }
    }
    return result;
}


void print(NumCollection C) {
    cout << "{ ";
    for (int i = 0; i < C.count; i++) {
        cout << "{ ";
        for (int j = 0; j < C.sets[i].size; j++) {
            cout << C.sets[i].values[j];
            if (j < C.sets[i].size - 1) cout << ", ";
        }
        cout << " }";
        if (i < C.count - 1) cout << ", ";
    }
    cout << " }\n";
}


void print(StrCollection C) {
    cout << "{ ";
    for (int i = 0; i < C.count; i++) {
        cout << "{ ";
        for (int j = 0; j < C.sets[i].size; j++) {
            cout << C.sets[i].values[j];
            if (j < C.sets[i].size - 1) cout << ", ";
        }
        cout << " }";
        if (i < C.count - 1) cout << ", ";
    }
    cout << " }\n";
}

int main() {
    int choice;
    cout << "Select Data Type:\n";
    cout << "1. Numbers (Integer/Float/Double)\n";
    cout << "2. Strings\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1) {
        NumCollection A, B, C;
        inputNumCollection(A, "Collection A");
        inputNumCollection(B, "Collection B");

        cout << "\n--- Balancing ---\n";
        balanceCollections(A, B);

        C = merge(A, B);
        cout << "\n1. Merge: ";
        print(C);

        C = setUnion(A, B);
        cout << "2. Union: ";
        print(C);

        C = setIntersection(A, B);
        cout << "3. Intersection: ";
        print(C);

        C = setDifference(A, B);
        cout << "4. Difference (A - B): ";
        print(C);

        // NEW: 4 Additional Operations on Union
        NumCollection unionResult = setUnion(A, B);

        C = oddColumns(unionResult);
        cout << "5. Odd Columns from Union: ";
        print(C);

        C = evenColumns(unionResult);
        cout << "6. Even Columns from Union: ";
        print(C);

        C = oddRows(unionResult);
        cout << "7. Odd Rows from Union: ";
        print(C);

        C = evenRows(unionResult);
        cout << "8. Even Rows from Union: ";
        print(C);

    } else if (choice == 2) {
        StrCollection SA, SB, SC;
        inputStrCollection(SA, "Collection A");
        inputStrCollection(SB, "Collection B");

        cout << "\n--- Balancing ---\n";
        balanceCollections(SA, SB);

        SC = merge(SA, SB);
        cout << "\n1. Merge: ";
        print(SC);

        SC = setUnion(SA, SB);
        cout << "2. Union: ";
        print(SC);

        SC = setIntersection(SA, SB);
        cout << "3. Intersection: ";
        print(SC);

        SC = setDifference(SA, SB);
        cout << "4. Difference (A - B): ";
        print(SC);

        // NEW: 4 Additional Operations on Union
        StrCollection unionResult = setUnion(SA, SB);

        SC = oddColumns(unionResult);
        cout << "5. Odd Columns from Union: ";
        print(SC);

        SC = evenColumns(unionResult);
        cout << "6. Even Columns from Union: ";
        print(SC);

        SC = oddRows(unionResult);
        cout << "7. Odd Rows from Union: ";
        print(SC);

        SC = evenRows(unionResult);
        cout << "8. Even Rows from Union: ";
        print(SC);
    }

    return 0;
}



