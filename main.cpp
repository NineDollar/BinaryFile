#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

typedef struct Student {
    char name[10];
    char id[10];
    int score;
} student;

#define LEN sizeof(student)

int main() {
    char fileName[20] = "student.dat";
    student st;
    fstream file(fileName, ios::out | ios::binary);
    if (!file) {
        cerr << "Can not open output file: " << fileName;
        exit(1);
    }
    cout << "Please input name:";
    cin >> st.name;
    cin.get();//
    while (strcmp(st.name, "#") != 0) {
        cout << "please input id and score:";
        cin >> st.id >> st.score;
        file.write((char *) &st, LEN);
        cout << "Please input name:";
        cin >> st.name;
    }
    file.close();
    student sts[100];
    int i = 0;
    file.open(fileName, ios::in | ios::binary);
    if(!file){
        cerr << "Can not open input file: " << fileName;
        exit(2);
    }
    while (file.read((char *)(sts+i),LEN)){
        i++;
    }
    for (int j = 0; j < i; ++j) {
        cout << sts[j].name << '\t' << sts[j].id << '\t' << sts[j].score << endl;
    }
    file.close();
    return 0;
}
