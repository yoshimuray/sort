#include <stdio.h>

//フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
  int i, j, k, pivot;

  if(n <= 1) return;

// 先頭の要素をピボットとする
  pivot = A[0];
  for(i = j = k = 1; i < n; i++){
    if(A[i] < pivot){
      int z = A[j];
      A[j] = A[i];
      A[i] = A[k];
      A[k] = z;
      j++;
      k++;
    }else if(A[i] == pivot){
      int z = A[k];
      A[k] = A[i];
      A[i] = z;
      k++;
    }
  }

  A[0] = A[j-1];
  A[j-1] = pivot;

  quick_sort(A, j);
  quick_sort(A+k, n-k+1);
  return;
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 3; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
