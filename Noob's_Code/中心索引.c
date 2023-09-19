#include <stdio.h>
#include "shortcut.h"
#define LEN 50

int pivotIndex(int* nums, int numsSize){
	int Rsum=0;
	int Lsum=0;
	for(int i=1;i<numsSize;i++){
		Rsum+=nums[i];
	}						// 右侧往左加的全部和
	for(int i=0;i<numsSize;i++){
		if(Rsum==Lsum)
			return i;
		else{
			if(i!=numsSize-1){
				Rsum -= nums[i+1];		// 右侧递减
				Lsum += nums[i];		// 左侧递加
			}else
				return Rsum==Lsum?numsSize-1:-1;
		}
	}
	return -1;
}

int main()
{
	printf("Please enter a integer array:\n");
	char ch[LEN];
	gets(ch);
	int numsSize;
	int ret[LEN];
	get_num_ar(ch, ret,&numsSize);
	printf("%d", pivotIndex(ret, numsSize));
	
	return 0;
}
