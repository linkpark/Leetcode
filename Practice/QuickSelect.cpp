#include <iostream>
#include <vector>

using namespace std;

int median3( int i, int j, int k ) {
  if( (j >=i && j <= k) || ( j >=k && j <= i ) ) return j;
  if( (i >=j && i <= k) || ( i >=k && i <= j) ) return i;
  if( (k >=i && k <= j) || ( k >=j && k <= i) ) return k;

  return i;
}

void QuikSelect( int S[], int k, int left, int right ) {
  int i, j;
  int pivot;

  if( left < right ) {
    pivot = median3(S,left, right );
  }
}

