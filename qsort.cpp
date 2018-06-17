void swap(int input[], int i, int j)
{
  int temp = input[i];
  input[i] = input[j];
  input[j] = temp;
}

void quickSort(int input[], int size) {
  // Here, we partition the given array and use recursion
  if(size<=1) return;
  int count=0;  // count represent no of elements less than input[0]
  for(int i=1;i<size;i++)
    if(input[i]<input[0])
      count++;
  if(count==0)
  {
    quickSort(input+1, size-1);
    return;
  }
  else if(count==size-1)
  {
    swap(input,0,count);
    quickSort(input, size-1);
    return;
  }
  swap(input,0,count);
  int left=0, right=size-1;
  while(left<right)
  {
    while(left<right && input[left]<=input[count]) left++;
    while(left<right && input[right]>=input[count]) right--;
    // if left < right, something to swap
    if(left<right)
      swap(input,left,right);
  }
  // Now that arrays is partitioned, we use recursion
  quickSort(input,count-1);
  quickSort(input+count+1,size-count-1);
}
