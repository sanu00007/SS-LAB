#include <stdio.h>

#include <stdlib.h>

#include <string.h>

FILE * obj;
struct mod {
  char op[10];
  int reloc[10];
  int flag[10];
}
r;
char prog_name[10], record[100], locn[6], instr[2], objcode[9], cnt[2], relocn[6];
int i, j, k = 0, flag = 0, rec_len, start, ind, new_loc, load_addr, count = 0, mod_count = 3, minstr;
int rel_addr;
int main() {
  obj = fopen("obj3.txt", "r");
  fscanf(obj, "%s", record);
  for (i = 0; i < strlen(prog_name); i++) {
    if (record[i + 2] == prog_name[i]) {
      flag = 0;
    } else {
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    printf("Invalid program name!\n");
  } else {
    printf("\nEnter the load address: ");
    scanf("%x", & load_addr);
    rewind(obj);
    fscanf(obj, "%s", record);
    printf("\nAddress Object Code");
    while (record[0] != 'E') {
      if (record[0] == 'T') {
        for (j = 4, k = 0; j < 8, k < 4; k++, j++) {
          locn[k] = record[j];
        }
        sscanf(locn, "%x", & start);  //store value in start as decimal 
        new_loc = start;
        new_loc += load_addr;
        for (i = 9, k = 0; i < 11, k < 2; i++, k++) {
          cnt[k] = record[i];
        }
        sscanf(cnt, "%x", & count);
        count = count / 3;
        ind = 12;
        for (i = 0; i < 10; i++) {
          while (count > 0) {
            objcode[0] = '\0';
            for (j = 0, k = ind; j < 6, k < ind + 6; j++, k++) {
              objcode[j] = record[k];
            }
            ind += 6;
            if (record[ind] == '^' || record[ind] == '\0') {
              ind++;
              objcode[j] = '\0';
            } else {
              while (record[ind] != '^') {
                if (record[ind] == '\0') {
                  break;
                }
                objcode[j] = record[ind];
                ind++;
                j++;
              }
              ind++;
            }
            objcode[j] == '\0'; // setting the end of the string
            sscanf(objcode, "%x", & minstr);
            for (i = 0; i < mod_count; i++) {
              if (r.reloc[i] > new_loc && r.reloc[i] < new_loc + 4 && r.flag[i] != 1) {
                if (r.op[i] == '+') {
                  minstr += load_addr;
                } else {
                  minstr -= load_addr;
                }
                r.flag[i] = 1;
                break;
              }
            }
            printf("\n %x %x", new_loc, minstr);
            new_loc += strlen(objcode) / 2; // add number of half bytes in object code to new_locn
            count--;
          }
        }
      }
      fscanf(obj, "%s", record);
    }
  }
  return 0;
}
