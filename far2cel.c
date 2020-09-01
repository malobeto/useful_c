#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
  {
  if(argc == 0)
    {
      printf("You need to enter a temperature.");
    }
  if(argc >= 1)
    {
      int i;
      for(i = 1; i < argc; i++)
      {
        char *p;
        int far = strtol(argv[i], &p, 10);
        int cel = (far - 30)/1.8;
        printf("%d Farenheit is %d Celcius.\n", far, cel);
      }
    }
  return 0;
  }
