#include<iostream>
#include<vector>
using namespace std ;

class Heap{
    public :
    int arr[100] ;
    int size = 0 ;

    void insert(int value ){
        size = size + 1;
        int index = size ;
        
        arr[index] = value ;

        while(index > 1 ){
            int parent = index / 2 ;
            if(arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]);
                index = parent ;
            }else{
                return ;
            }
        }
    };

    void pop(){
        if(size == 0 ) return ;
        arr[1] = arr[size] ;
        size -- ;

        int i = 1 ;
        while(i < size ){
            int leftIndex = 2 * i ;
            int rightIndex = 2 * i + 1 ;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i] , arr[leftIndex ]);
                i = leftIndex ;
            }else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i] , arr[rightIndex]) ;
                i = rightIndex ;
            }else{
                return ;
            }
        }
    }

    void print(){
        for(int i = 1 ; i <= size  ; i++){
            cout << arr[i] << " ";
        }
        cout << endl ;
    }
};
int main(){
    Heap h ;
    h.insert(1);
    h.insert(2) ;
    h.insert(3);
    h.print() ;
    h.pop() ;

    h.print() ;
}