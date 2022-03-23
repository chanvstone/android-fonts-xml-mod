//
// Created by sio2 on 3/23/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "mod.h"

int main(int argv, char **args) {
//  if (argv != 2) {
//    return 1;
//  }
//  FILE *src = fopen(args[0], "r");
//  if (src == NULL) {
//    return 1;
//  }
//  FILE *dest = fopen(args[1], "w");
//  if (dest == NULL) {
//    return 1;
//  }
//  mod(dest, src);
  if (system("adb pull /system/etc/fonts.xml ./fonts.xml") != 0) {
    return 1;
  }
  FILE *src = fopen("./fonts.xml", "r");
  if (src == NULL) {
    return 1;
  }
  FILE *dest = fopen("./moded.xml", "w");
  if (dest == NULL) {
    return 1;
  }
  mod(dest, src);
  if (system("adb push ./moded.xml /system/etc/fonts.xml") != 0) {
    printf("push fonts.xml failed\n");
    return 1;
  }
  if (system("adb push ./fonts/* /system/fonts/") != 0) {
    printf("push fonts file failed\n");
    return 1;
  }

  return 0;
}