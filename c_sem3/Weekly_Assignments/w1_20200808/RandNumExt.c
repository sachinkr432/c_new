#include <stdio.h>
int main (void)
{
int nums[1000]; //up to 1000 element int array
FILE *fp1; //file pointer
int i,n;
//****************** code logic starts here ***************
for(i=0;i<n;i++) //initialize array elements with 0
nums[i]=0;
i=0; //re-initialize the array index at i=0
if ((fp1=fopen("random_numbers.txt","r"))==NULL) //Checks if the file exists
{
printf("random_numbers.txt failed to open\n");
return 1;
}
else
{
while((fscanf(fp1,"%d",&nums[i]))!=EOF) //scanf, check and continue untill EOF
i++;
n = i;
for(i=0;i<n;i++)
{
printf("nums[%d] is %d\n",i,nums[i]);
}
}
return 0;
}