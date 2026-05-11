#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <new>
#include <utility>
#include <algorithm>
#include <memory>
#include <initializer_list>
#include<limits>
using namespace std;

template <typename T>
class Myvector {
private:
    T* arr;
    size_t size;
    size_t capacity;

    void resize();

public:
    Myvector();
    ~Myvector();
    Myvector(const Myvector& other);
    Myvector(Myvector&& other) noexcept;
    Myvector& operator=(const Myvector& other);
    Myvector& operator=(Myvector&& other) noexcept;

    void push_back(const T& element);
    void pop_back();
    void erase(size_t index);
    size_t get_size() const;
    size_t get_capacity() const;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    T* begin() { return arr; }
    T* end() { return arr + size; }
};

template <typename T>
Myvector<T>::Myvector() : arr(new T[1]), size(0), capacity(1) {}

template <typename T>
Myvector<T>::~Myvector() {
    delete[] arr;
}

template <typename T>
void Myvector<T>::resize() {
    capacity *= 2;
    T* newArr = new T[capacity];
    for (size_t i = 0; i < size; ++i)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
}

template <typename T>
Myvector<T>::Myvector(const Myvector& other)
    : arr(new T[other.capacity]), size(other.size), capacity(other.capacity) {
    for (size_t i = 0; i < size; i++)
        arr[i] = other.arr[i];
}

template <typename T>
Myvector<T>& Myvector<T>::operator=(const Myvector& other) {
    if (this == &other) return *this;
    delete[] arr;
    size = other.size;
    capacity = other.capacity;
    arr = new T[capacity];
    for (size_t i = 0; i < size; i++)
        arr[i] = other.arr[i];
    return *this;
}

template <typename T>
Myvector<T>::Myvector(Myvector&& other) noexcept
    : arr(other.arr), size(other.size), capacity(other.capacity) {
    other.arr = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template <typename T>
Myvector<T>& Myvector<T>::operator=(Myvector&& other) noexcept {
    if (this == &other) return *this;
    delete[] arr;
    arr = other.arr;
    size = other.size;
    capacity = other.capacity;
    other.arr = nullptr;
    other.size = 0;
    other.capacity = 0;
    return *this;
}

template <typename T>
void Myvector<T>::push_back(const T& element) {
    if (size == capacity) resize();
    arr[size++] = element;
}

template <typename T>
void Myvector<T>::pop_back() {
    if (size > 0) --size;
}

template <typename T>
size_t Myvector<T>::get_size() const { return size; }

template <typename T>
size_t Myvector<T>::get_capacity() const { return capacity; }

template <typename T>
T& Myvector<T>::operator[](size_t index) {
    if (index >= size) throw out_of_range("Index out of range");
    return arr[index];
}

template <typename T>
const T& Myvector<T>::operator[](size_t index) const {
    if (index >= size) throw out_of_range("Index out of range");
    return arr[index];
}
template <typename T>
void Myvector<T>::erase(size_t index) {
    if (index >= size) {
        throw out_of_range("Index out of range in erase");
    }
    for (size_t i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    --size;
}

class SinhVien{
    private:
       string msv, hoten, lop;
       double gpa;
    public:
       SinhVien(){
        msv = hoten = lop = "";
        gpa = 0;
       }
       SinhVien(string msv, string hoten, string lop, double gpa){
        this->msv = msv;
        this->hoten = hoten;
        this->lop = lop;
        this->gpa = gpa;
       }
       void nhap(){
        cout << "Nhap ma sinh vien: ";
        cin >> msv;
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin,hoten);
        cout << "Nhap lop: ";
        cin >> lop;
        cout << "Nhap diem tb: ";
        cin >> gpa;
       }
       void xuat(){
        cout << msv << " " << hoten << " " << lop << " " << gpa << endl;
       }
       double getGpa(){
        return gpa;
       }
       string getMsv(){
        return msv;
       }
       string getName(){
        return hoten;
       }
};
void findName(SinhVien a, string s){
        if(a.getName() == s){
            a.xuat();
    }
}
void eraseSV(Myvector<SinhVien> &a, string s){
    for(int i = 0; i < a.get_size(); i++){
        if(a[i].getMsv() == s){
            a.erase(i);
        }
    }
}
void xuatds(Myvector<SinhVien> a){
    for(int i = 0; i < a.get_size(); i++){
        cout << i + 1 << ". ";
        a[i].xuat();
    }
}
int menu(){
    system("cls");
    cout << "1.Them sinh vien." << endl;
    cout << "2.Xoa sinh vien theo ma." << endl;
    cout << "3.Sua thong tin sinh vien." << endl;
    cout << "4.Sap xep theo diem trung binh." << endl;
    cout << "5.Tim kiem theo ten." << endl;
    cout << "6.Hien thi danh sach." << endl;
    cout << "7.Thoat." << endl;
    int select;
    cin >> select;
    if(select > 0 && select <= 7) {
        return select;
    }
    return menu();
}
bool tang(SinhVien a, SinhVien b){
    return a.getGpa() < b.getGpa();
}
bool giam(SinhVien a, SinhVien b){
    return a.getGpa() > b.getGpa();
}
int main() {
    Myvector<SinhVien> sv;
    do{
        int t = menu();
        switch(t){
            case 1: {
               SinhVien a;
               a.nhap();
               sv.push_back(a);
               break;
            }
            case 2:{
               string s;
               cout << "Nhap ma sinh vien can xoa: ";
               cin.ignore();
               cin >> s;
               eraseSV(sv,s);
               break;
            }
            case 3:{
               int idx;
               cout << "Nhap vi tri sinh vien can sua thong tin: ";
               cin >> idx;
               if(idx < 1 || idx > sv.get_size()){
                cout << "Vi tri khong hop le!";
                break;
               }
               cout << "Nhap lai thong tin: ";
               SinhVien a;
               a.nhap();
               sv[idx - 1] = a;
               break;
            }
            case 4:{
               cout << "Nhap thu tu muon sap xep:" << endl;
               cout << "1.Tang" << endl;
               cout << "2.Giam" << endl;
               int tmp;
               cin >> tmp;
               if(tmp != 1 && tmp != 2){
                cout << "Lua chon khong hop le" << endl;
                break;
               }else if(tmp == 1){
                sort(sv.begin(),sv.end(),tang);
                break;
               }else if(tmp == 2){
                sort(sv.begin(),sv.end(),giam);
                break;
               }
            }
            case 5:{
               cout << "Nhap ten can tim: ";
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               string s;
               getline(cin,s);
               for(int i = 0; i < sv.get_size(); i++){
                findName(sv[i], s);
               }
               break;
            }
            case 6:
               cout << "-Danh sach sinh vien-" << endl;
               xuatds(sv);
               break;
            default: return 0;;
        }
        cout << "\n\n";
        system("pause");
    } while(true);
}
