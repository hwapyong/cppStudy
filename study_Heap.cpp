#include <iostream>
using namespace std;
/* Heap DataStructure

    1. Heap 은 complete Binary Tree 형태를 가진다.
    2. Complete Binary Tree 구현은 Array 를 사용하여 일반적으로 구현한다.
     --> 즉, Heap 은 Array 로 구현하는 것이 편하다.

    참고, 
            Binary Tree          : children 이 {0,1,2}개인 Tree 구조.

            Full Binary Tree     : children 이 {0,  2}개인 Tree 구조.
                                   Full Binary Tree 는 leaf 노드들을 제외한 모든 노드들이 2개의 children 을 가지는 Binary Tree 라고도 할 수 있다
                                   Full Binary Tree 에서 모든 leaf 노드의 개수는 internal node 의 개수 + 1 이다

            Perfect Binary Tree  : 모든 internal node 가 두개의 children 을 가지고 있고, 
                                   모든 leaf 노드가 같은 level 에 있으면 Perfect Binary Tree 라고 한다.
                                   Height 가 h 인 Perfect Binary Tree 는 2^h - 1 개의 노드를 가진다

            Complete Binary Tree : 마지막 level 을 제외한 나머지 level 에 node 들이 가득 차있고, 
                                   마지막 level 에서 node 는 가장 왼쪽 부터 채워지는 형태가 Complete Binary Tree 이다.

                                   Complete Binary Tree 구조를 그대로 사용하여 Binary Heap 이라는 데이터 구조를 만들 수 있는데, 이놈이 Heap 이다.
                                    
  < 중요 Concept >
  1. Insertion  :  O(log n)
  2. Creation   :  O(nlog n)
  3. Deletion   :  O(log n)
  4. Heap Sort  :  Max or Min Heap 을 1. Creation 하고 2. Deletion 하면, 자연스럽게 Sorting 된다. -> O (nlog n)
  5. Priority Queue : Max or Min Heap 에서 Deletion 하는 것 자체가 Priority Queue
  6. Heapify : Creation 할 때, 순서를 left to right 가 아니라, right to left 로 하면, 시간 복잡도가 감소.
                * left to right : nlog n
                * right to left : log n
*/
void swap(int* numb1, int* numb2) {
    int tmp = *numb1;
    *numb1 = *numb2;
    *numb2 = tmp;
}

void insert(int H[], int n) {
    int i = n;
    while (i!=1) {
        if ( H[i] > H[i/2] ) {
            swap(&H[i], &H[i / 2]);
            i = i / 2;
        }
        else {
            break;
        }
    }
}

// 틀림 수정요함.
int deleteHeap(int H[], int n) {
    int tmp = H[1];
    H[1] = H[n];
    int i = 1;
    int j;
    while (i<n) {
        j = 2 * i;
        if (H[j] < H[j + 1])
            j = j + 1;
        swap(&H[j], &H[i]);
        i = j;
    }
    return tmp;
}

void createHeap(int H[], int n) {
    for (int i = 1; i <= n; i++) {
        insert(H, i);
    }
}

int main()
{
    int H[] = { 0, 10, 50, 20, 30, 40, 70, 60 }; // Array size 는 8 이지만, 맨 앞의 0 은 Dummy.
                                                 // 1 부터 ordering 하기 위해서..

    int sizeOfArray = sizeof(H) / sizeof(int) - 1; // 0 번째 element =  Dummy.
    createHeap(H, sizeOfArray);
    for (int i = 1; i < 8; i++)
        printf("%d ", H[i]);
    printf("\n");
    // 70, 40, 60, 10, 30, 20, 50
    cout << "Delete Heap " << endl;
    for (int i = sizeOfArray; i > 0; i--) {
        cout << deleteHeap(H, i) << " ";
    }
    cout << endl;

}
