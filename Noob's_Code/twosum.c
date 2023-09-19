#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 50

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	for (int i = 0; i < numsSize; ++i)
	{
		for (int j = i + 1; j < numsSize; ++j)
		{
			if (nums[i] + nums[j] == target)
			{
				int *ret = malloc(2 * sizeof(int));
				ret[0] = i, ret[1] = j;
				*returnSize = 2;
				return ret;
			}
		}
	}
	*returnSize = 0;
	return NULL;
}

int main()
{
	int target ,numsSize, returnSize, num = 0, count = 0, sign = 1;
	char ch[LEN];
	int nums[LEN];
	gets(ch);
	for (int i = 0; ch[i] != '\0'; i++)
	{
		if (ch[i] >= '0' && ch[i] <= '9')
		{
			num = num*10 + (ch[i] - '0');
			sign = 0;
		}
		else
		{
			if (!sign)
			{	nums[count] = num;
				count++;
			}
			num = 0;
			sign = 1;
		}
	}
	numsSize = count;
	
	num = 0;
	strcpy(ch, "");
	gets(ch);
	for (int i = 0; ch[i] != '\0'; i++)
	{
		if (ch[i] >= '0' && ch[i] <= '9')
		{
			num = num * 10 + (ch[i] - '0');
		}
	}
	target = num;
	int *ret = twoSum(nums, numsSize, target, &returnSize);
	if (returnSize == 0)
		printf("输入的数组无法得出目标数\n");
	else
		printf("[%d, %d]", ret[0], ret[1]);
	
	free(ret);
	
	return 0;
}
