//
//  tvector.h
//  OOPsummer
//
//  Created by Shuqing Li on 6/26/19.
//  Copyright © 2019 Shuqing Li. All rights reserved.
//

#ifndef tvector_h
#define tvector_h

const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;
using namespace std;

template <typename T>
class MyVec {
public:
    MyVec() : sz(0) {
        capacity = DEF_CAPACITY;
        data = new T[DEF_CAPACITY];
    }
    
    MyVec(int sz, T val) : sz(sz) {
        capacity=sz;
        data=new T[sz];
        for (int i=0;i<sz;++i) {
            data[i]=val;
        }
    }
    
    // copy control:
    MyVec(const MyVec<T>& v2) {
        copy(v2);
    }
    ~MyVec() {delete [] data;}
    MyVec<T>& operator=(const MyVec<T> & v2){
        if (this != &v2) {
            delete [] data;
            copy(v2);
        }
        return *this;
    }
    
    void push_back(T val){
        sz++;
        if (sz > capacity) {
            cout << "Increasing capacity\n";
            int* old_data = data;
            data = new T[capacity * CAPACITY_MULT];
            for (int i = 0; i < sz; i++) {
                data[i] = old_data[i];
            }
            capacity *= CAPACITY_MULT;
            delete [] old_data;
        }
        data[sz - 1] = val;
    }
    
    int size() const { return sz; }
    /*
     * this [] is for reading items from the MyVec:
     * It returns the i-th element.
     * */
    T operator[](int i) const {
        return data[i];
    }
    
    /*
     * this [] allows write access to items in the MyVec:
     * It returns a reference to the i-th element.
     * */
    T& operator[](int i) {
        return data[i];
    }

private:
    void copy(const MyVec<T>& v2) {
        sz = v2.sz;
        capacity = v2.capacity;
        data = new T[capacity];
        for (int i = 0; i < sz; i++) {
            data[i] = v2.data[i];
        }
    }
    T* data;
    int sz;
    int capacity;
};


template <typename T>
bool operator==(MyVec<T>& v1, MyVec<T>& v2) {
    if (v1.size()!=v2.size()) return false;
    else {
        for(int i=0;i<v1.size();i++){
            if (v1[i]!=v2[i]) {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
void print_vector(const MyVec<T>& v) {
    for (int i=0;i<v.size();i++) cout << v[i] << " ";
    cout << endl;
    
}

#endif /* tvector_h */
