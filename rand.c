#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int * rando_gen(int size){
  int fd = open("/dev/random", O_RDONLY);
  int * nums = malloc(size * 4);
  read(fd, nums, size * 4);
  return nums;
}

void rando_write(int * nums, int size){
  char path[20];
  strcpy(path, "./");
  strcpy(path, (char) nums[0]);
  strcpy(path, ".txt");
  printf("%s", path);
  open(path,  O_WRONLY);
  //write()

}

int main(){
  int size = 10;
  int * nums = rando_gen(size);

  int i;
  for(i = 0; i < size; i++){
    printf("nums[%d] = %d\n",i, nums[i]);
  }

  printf("\n\n");
  free(nums);
  return 0;
}
