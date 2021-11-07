#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
}*first;

void displayLL(struct Node* p) {
    cout << "Reading Linked List ...  by DisplayLL" << endl;
    while (p) {
        cout << p->data << "  " ;    
        p = p->next;
    }
    cout << "\nClear" << endl;
}

void rDisplayLL(struct Node* p)
{
    if(p)
    {
        cout << p->data << "  ";
        p = p->next;
        rDisplayLL(p);
    }
}

void createLL(int A[], int num) {
    struct Node* last = nullptr;
    struct Node* temp = nullptr;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (int i = 1; i < num; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}

int countLL(struct Node* p) {
    int count = 0;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}

int sumLL(struct Node* p) {
    int sum=0;
    while (p) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int rCountLL(struct Node* p) {
    if (p) {
        return rCountLL(p->next) + 1;
    }
    else {
        return 0;
    }
}

int rSumLL(struct Node* p) {
    if (p) {
        return rSumLL(p->next) + p->data;
    }
    else {
        return 0;
    }
}

int maxLL(struct Node* p) {
    int max = p->data; // 초기 max 값을 첫번째 데이터로 선정
    while (p) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int rMaxLL(struct Node* p) {
    if (p->next == nullptr) return p->data;
    int rmax = rMaxLL(p->next);
    return p->data > rmax ? p->data : rmax;
}

struct Node* searchLL(struct Node* p, int key) {
    struct Node* q=NULL;
    while (p) {
        if (p->data == key) {
            if (q) {
                q->next = p->next;
                p->next = first;
                first = p;
            }
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

struct Node* rSearchLL(struct Node* p, int key) {
    if (!p) return NULL;
    if (p->data == key) return p;
    return rSearchLL(p->next, key);
}

int main()
{
    int A[] = { 1, 2, 13, 4, 5, 26, 7, 8, 39, 10 };
    createLL(A, 10);
    displayLL(first);
    cout << "total count is  " << countLL(first) << endl;
    cout << "total sum    is  " << sumLL(first) << endl;
    cout << "total count is  " << rCountLL(first) << endl;
    cout << "total sum    is  " << rSumLL(first) << endl;
    cout << "max number is " << maxLL(first) << endl;
    cout << "rmax number is " << rMaxLL(first) << endl;
    searchLL(first, 26);
    displayLL(first);
    cout << rSearchLL(first, 26)->data << endl;;
    displayLL(first);
}
