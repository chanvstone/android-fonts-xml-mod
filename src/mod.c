//
// Created by sio2 on 3/23/22.
//

#include "../include/mod.h"
#include "../include/fonts.h"
#include <stdio.h>
#include <string.h>

void findAndReplace(FILE *dest, FILE *src, char *search, void writeConfig(FILE *)) {
  char buffer[512];
  while (fgets(buffer, 512, src) == buffer) {
    if (strstr(buffer, search) == NULL) {
      fputs(buffer, dest);

    } else {
      while (fgets(buffer, 512, src) == buffer) {
        if (strstr(buffer, "</family>") != NULL) {
          break;
        }
      }
      writeConfig(dest);
      return;
    }
  }
}

void sansSerif(FILE *dest, FILE *src) {
  findAndReplace(dest, src, "<family name=\"sans-serif\">", robotoSansSerif);
  findAndReplace(dest, src, "<family name=\"sans-serif-condensed\">", robotoSansSerifCondensed);
}

void serif(FILE *dest, FILE *src) {
  findAndReplace(dest, src, "<family name=\"serif\">", notoSerif);
  notoSerifCondensed(dest);
}

void monospace(FILE *dest, FILE *src) {
  findAndReplace(dest, src, "<family name=\"monospace\">", notoSansMonospace);
}

void cjk(FILE *dest, FILE *src) {
  findAndReplace(dest, src, "<family lang=\"zh-Hans\">", notoSansCjkSc);
  findAndReplace(dest, src, "<family lang=\"zh-Hant,zh-Bopo\">", notoSansCjkTc);
  findAndReplace(dest, src, "<family lang=\"ja\">", notoSansCjkJa);
  findAndReplace(dest, src, "<family lang=\"ko\">", notoSansCjkKo);
}

void mod(FILE *dest, FILE *src) {
  sansSerif(dest, src);
  serif(dest, src);
  monospace(dest, src);
  cjk(dest, src);
  char buffer[512];
  while (fgets(buffer, 512, src) == buffer) {
    fputs(buffer, dest);
  }
}

