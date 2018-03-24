#include <stdio.h>


int max_sub_seq_sum(int left, int right, int a[]){
	if (left == right){
		return a[left];
	}
	
	int mid;
	mid = (left + right) / 2;
	
	int max_left_sum;
	max_sub_seq_sum(left, mid, a);
	
	int max_right_sum;
	max_sub_seq_sum(mid+1, right, a);
	
	int max_left_border_sum = a[mid];
	int left_border_sum = a[mid];
	int i;
	for (i = mid - 1; i > left ; i--){
		left_border_sum += a[i];
		if (left_border_sum > max_left_border_sum){
			max_left_border_sum = left_border_sum;
		}
	}
	
	int max_right_border_sum = a[mid+1];
	int right_border_sum = a[mid+1];
	int j;
	for (j = mid + 2; j < right; j++){
		right_border_sum += a[j];
		if (right_border_sum > max_right_border_sum){
			max_right_border_sum = right_border_sum;
		}
	}
	
	return max_three(max_left_sum, max_right_sum, max_left_border_sum + max_right_border_sum);
}


int max_three(int a, int b, int c){
	int max;
	if (a > b){
		if (a > c){
			max = a;
		}
		else{
			max = c;
		}
	}
	else{
		if (b > c){
			max = b;
		}
		else{
			max = c;
		}
	}
	
	return max;
}


int main(){
	int array[6] = {-2, 11, -4, 13, -5, -2};
	int res;
	res = max_sub_seq_sum(0, 5, array);
	printf("%d", res);
	return 0;
}
