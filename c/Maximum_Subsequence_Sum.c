#include <stdio.h>

struct Tuple {
	int start;
	int end;
	int max_sum;
};

struct Tuple max_sub_seq_sum(int k, int array[]){
	int this_sum = 0, max_sum = 0;
	int i;
	int start = 0, end = 0;
	int flag = 0;
	for (i = 0; i < k; i++){
		if (array[i] > 0){
			flag = 1;
		}
		this_sum += array[i];
		if (this_sum > max_sum){
			max_sum = this_sum;
			end = i; /*possible exit index*/
		}
		else if (this_sum < 0){
			this_sum = 0;
		}
	}
	if (flag == 0){ /*all negatives*/
		struct Tuple res = {0, k-1, 0};  // start, end, max_sum
		return res;
	}
	else{
		int temp_sum = 0;
		int temp_index = end;
		while(temp_sum < max_sum){
			temp_sum += array[temp_index];
			temp_index -= 1;
		}
		start = temp_index + 1;
//		printf("%d", start);
		struct Tuple res = {start, end, max_sum};
		return res;
	}
}


int main(){
	int k = 10;
	int array[k] = {-10, 1, 2, 3, 4, -5, -23, 3, 7, -21};
	struct Tuple res = max_sub_seq_sum(k, array);
	printf("%d\n", res.start);
	printf("%d\n", res.end);
	printf("%d\n", res.max_sum);
	return 0;
}


