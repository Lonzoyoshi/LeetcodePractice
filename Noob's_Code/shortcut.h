int *get_num_ar(char *ch, int *nums,int *numsSize)
{
	int num = 0, sign = 1, count = 0;
	for (int i = 0; ch[i] != '\0'; i++)
	{
		if (ch[i] >= '0' && ch[i] <= '9')
		{
			num = num*10 + (ch[i] - '0');
			sign = 0;
		}
		else 
		{
			if(!sign)
			{
				nums[count] = num;
				count++;
			}
			num = 0;
			sign = 0;
		}	
	}
	*numsSize = count;
	return nums;
}
