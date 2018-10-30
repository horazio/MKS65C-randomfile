#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int * rando_gen(int size){
  int fd = open("/dev/random", O_RDONLY);
  int * nums = malloc(size * 4);
  read(fd, nums, size * 4);
  close(fd);
  return nums;
}

char * rando_write(int * nums, int size){
  char * path = malloc(20);
  sprintf(path, "./%d.txt", nums[0]);
  int fd = open(path,  O_WRONLY | O_CREAT, 0770);
  if( write(fd, nums, size)){
    printf("\n--the file is written with no errors--\n");
  }
  close(fd);

  return path;
}

int main(){
  int size = 10;
  int * nums = rando_gen(size);

  int i;
  for(i = 0; i < size; i++){
    printf("nums[%d] = %d\n",i, nums[i]);
  }

  char * path =rando_write(nums, size * 4);

  int * nums2 = malloc(4 * size);
  int fd = open(path, O_RDONLY);

  if (read(fd, nums2, size * 4)){
    printf("\n--the file is read with no errors--\n");
  }
  close(fd);
  printf("The next array copied back from the file is: \n");

  for(i = 0; i < size; i++){
    printf("nums2[%d] = %d\n",i, nums2[i]);
  }


  printf("\n\n");
  free(nums);
  free(nums2);
  return 0;
}
