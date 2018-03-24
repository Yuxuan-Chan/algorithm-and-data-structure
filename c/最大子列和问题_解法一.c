#include <stdio.h>

int max_sub_seq_sum(int n, int a[]){
	int i, j;
	int this_sum = 0, max_sum = 0;
	for (i = 0; i <= n; i++){
		this_sum = 0;
		for (j = i; j <= n; j++){
			this_sum += a[j];
			if (this_sum > max_sum){
				max_sum = this_sum;
			}
		}
	}
	return max_sum;
}

int main(){
	int k = 6;
	int array[6] = {-2, 11, -4, 13, -5, -2};
	int res = max_sub_seq_sum(6, array);
	printf("%d", res);
	return 0;
}

