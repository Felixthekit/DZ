#include <iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;
class AbstractContainer {
public:
    virtual int Size() const = 0;
    virtual bool Empty() const = 0;
};
class AbstractStack : public AbstractContainer {
public:
    virtual void Push(int value) = 0;
    virtual void Pop() = 0;
    virtual int Top() = 0;

};
//class AbstractList : public AbstractContainer {
//public:
//    virtual void PushFront(int value) = 0;
//    virtual void PushBack(int value) = 0;
//    virtual void PopBack() = 0;
//    virtual void PopFront() = 0;
//    virtual int Front() = 0;
//    virtual int Back() = 0;
//
//};
//class LimitedList : public AbstractList {
//public:
//    LimitedList(int limit) : a_(nullptr), size_(0), limit_size_(limit) {}
//    LimitedList(LimitedList& lst) {
//        limit_size_ = lst.limit_size_;
//        a_ = new int[lst.size_];
//        this->size_ = lst.size_;
//        for (int i = 0; i < this->size_; i++) {
//            this->a_[i] = lst.a_[i];
//        }
//
//    }
//    LimitedList& operator= (LimitedList& lst) {
//        if (this->a_ == lst.a_) {
//            return*this;
//        }
//        delete[]a_;
//        this->size_ = lst.size_;
//        this->a_ = lst.a_;
//        return*this;
//    }
//    bool Empty() const {
//        return size_ == 0;
//    }
//    int Size() const {
//        return size_;
//    }
//    int Front() {
//        return a_[size_ - 1];
//    }
//    int Back() {
//        return a_[0];
//    }
//    void PushFront(int value) {
//        int* tmp = new int[size_ + 1];
//        for (int i = 0; i < size_; i++) {
//            tmp[i] = a_[i];
//        }
//        size_++;
//        tmp[size_ - 1] = value;
//        delete[] a_;
//        a_ = tmp;
//    }
//    void PushBack(int value) {
//        int* tmp = new int[size_ + 1];
//        tmp[0] = value;
//        for (int i = 0; i < size_; i++) {
//            tmp[i + 1] = a_[i];
//        }
//        size_++;
//        delete[] a_;
//        a_ = tmp;
//    }
//    void PopFront() {
//        if (size_ == 0) {
//            throw runtime_error("Out of Range");
//        }
//        else if (size_ == 1) {
//            a_ = nullptr;
//            size_ = 0;
//        }
//        else {
//            size_--;
//            int* tmp = new int[size_];
//            for (int i = 0; i < size_; i++) {
//                tmp[i] = a_[i];
//            }
//            delete[] a_;
//            a_ = tmp;
//        }
//    }
//    void PopBack() {
//        if (size_ == 0) {
//            throw runtime_error("Out of Range");
//        }
//        else if (size_ == 1) {
//            a_ = nullptr;
//            size_ = 0;
//        }
//        else {
//            size_--;
//            int* tmp = new int[size_];
//            for (int i = 0; i < size_; i++) {
//                tmp[i] = a_[i + 1];
//            }
//            delete[] a_;
//            a_ = tmp;
//        }
//    }
//
//
//private:
//    int* a_;
//    int size_;
//    int limit_size_;
//};
//class UnlimitedList : public AbstractList {
//public:
//    UnlimitedList() : a_(nullptr), size_(0){}
//    UnlimitedList(UnlimitedList& lst) {
//        a_ = new int[lst.size_];
//        this->size_ = lst.size_;
//        for (int i = 0; i < this->size_; i++) {
//            this->a_[i] = lst.a_[i];
//        }
//
//    }
//
//    UnlimitedList& operator= (UnlimitedList& lst) {
//        if (this->a_ == lst.a_) {
//            return*this;
//        }
//        delete[]a_;
//        this->size_ = lst.size_;
//        this->a_ = lst.a_;
//        return*this;
//    }
//    bool Empty() const {
//        return size_ == 0;
//    }
//    int Size() const {
//        return size_;
//    }
//    int Front() {
//        return a_[size_ - 1];
//    }
//    int Back() {
//        return a_[0];
//    }
//    void PushFront(int value) {
//        int* tmp = new int[size_ + 1]; 
//        for (int i = 0; i < size_; i++) {
//            tmp[i] = a_[i];
//        }
//        size_++;
//        tmp[size_ - 1] = value;
//        delete[] a_;
//        a_ = tmp;
//    }
//    void PushBack(int value) {
//        int* tmp = new int[size_ + 1];
//        tmp[0] = value;
//        for (int i = 0; i < size_; i++) {
//            tmp[i + 1] = a_[i];
//        }
//        size_++;
//        delete[] a_;
//        a_ = tmp;
//    }
//    void PopFront() {
//        if (size_ == 0) {
//            throw runtime_error("Out of Range");
//        }
//        else if (size_ == 1) {
//            a_ = nullptr;
//            size_ = 0;
//        }
//        else {
//            size_--;
//            int* tmp = new int[size_];
//            for (int i = 0; i < size_; i++) {
//                tmp[i] = a_[i];
//            }
//            delete[] a_;
//            a_ = tmp;
//        }
//    }
//    void PopBack() {
//        if (size_ == 0) {
//            throw runtime_error("Out of Range");
//        }
//        else if (size_ == 1) {
//            a_ = nullptr;
//            size_ = 0;
//        }
//        else {
//            size_--;
//            int* tmp = new int[size_];
//            for (int i = 0; i < size_; i++) {
//                tmp[i] = a_[i + 1];
//            }
//            delete[] a_;
//            a_ = tmp;
//        }
//    }
//    
//
//private:
//    int* a_;
//    int size_;
//};
class UnlimitedStack : public AbstractStack {
public:
    UnlimitedStack() : a_(nullptr), size_(0) {

    }
    UnlimitedStack(const UnlimitedStack& l) {
        a_ = new int[l.size_];
        this->size_ = l.size_;
        for (int i = 0; i < size_; i++) {
            a_[i] = l.a_[i];
        }
    }
    int Size() const {
        return size_;
    }
    bool Empty() const{
        return size_ == 0;
    }
    int Top() {
        if (size_ == 0) {
            throw runtime_error("Empty Array");
        }
        return a_[size_ - 1];
    }
    void Push(int value) {
        int* tmp = new int[size_ + 1];
        for (int i = 0; i < size_; i++) {
            tmp[i] = a_[i];
        }
        delete[] a_;
        tmp[size_] = value;
        size_++;
        a_ = tmp;
    }
    UnlimitedStack& operator=(const UnlimitedStack& ls) {
        if (this->a_ == ls.a_) {
            return*this;
        }
        delete[] this->a_;
        this->size_ = ls.size_;
        this->a_ = ls.a_;
        return*this;
    }
    void Pop() {
        if (size_ == 1) {
            size_--;
            a_ = nullptr;
        }
        else if (size_ == 0) {
            throw runtime_error("Out of range");
        }
        else {
            int* other = new int[size_ - 1];
            size_--;
            for (int i = 0; i < size_; i++) {
                other[i] = a_[i];
            }
            delete[] a_;
            a_ = other;
        }
    }
private:
    int* a_;
    int size_;
};
class ListedStack : public AbstractStack {
public:
    ListedStack() {
        size_ = 0;
    }
    ~ListedStack() {
        lst_.clear();
    }
    ListedStack(const ListedStack& lst) {
        lst_ = lst.lst_;
        size_ = lst.size_;
    }
    virtual bool Empty() const override {
        return size_ == 0;
    }
    virtual int Size() const override {
        return size_;
    }
    virtual void Push(int value) override
    {
        lst_.push_front(value);
        size_++;
    }
    virtual void Pop() override {
        lst_.pop_front();
        size_--;
    }
    virtual int Top() override {
        return lst_.front();
    }
    list<int> lst_;
    int size_;
};
class LimitedStack : public AbstractStack {
public:
    LimitedStack(int limit) : a_(new int [limit]), size_(0), limit_size_(limit) {

    }
    LimitedStack(const LimitedStack& l) {
        a_ = new int [l.size_];
        this->size_ = l.size_;
        for (int i = 0; i < size_; i++) {
            a_[i] = l.a_[i];
        }
    }
    int Top() {
        if (size_ == 0) {
            throw runtime_error("Empty Array");
        }
        return a_[size_ - 1];
    }
    int Size() const {
        return size_;
    }
    bool Empty() const {
        return size_== 0;
    }
    void Push(int value) {
        if (size_ >= limit_size_) {
            throw runtime_error("wrong size");
        }
        int* tmp = new int[size_ + 1];
        for (int i = 0; i < size_; i++) {
            tmp[i] = a_[i];
        }
        delete[] a_;
        tmp[size_] = value;
        size_++;
        a_ = tmp;
    }
    void Pop() {
        if (size_ == 1) {
            size_--;
            a_ = nullptr;
        }
        else if (size_ == 0) {
            throw runtime_error("Out of range");
        }
        else {
            int* other_a_ = new int(size_ - 1);
            size_--;
            for (int i = 0; i < size_; i++) {
                other_a_[i] = a_[i];
            }
            delete[] a_;
            a_ = other_a_;
        }
    }

    LimitedStack& operator=(const LimitedStack& ls) {
        if (this->a_ == ls.a_) {
            return* this;
        }
        delete[] this->a_;
        this->limit_size_ = ls.limit_size_;
        this->size_ = ls.size_;
        this->a_ = ls.a_;
        return*this;
    }
private:
    int* a_;
    int size_;
    int limit_size_;
};

int main()
{

}
