/*
  Author:   Brody Little

  Purpose:  Gets information about current processes, memory, and cpu number

  Struct for system_info, defined in proc.h:
  struct system_info {
    int uvm_used;
    int num_procs;
    int num_cpus;
  };

 */
#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"
#include "param.h"
#include "proc.h"

#define K 1000
#define M 1000000
#define G 1000000000


int main(int argc, char *argv[]) {
  struct system_info c;
  system_load(&c);
  
  //Checks for '-h' option and then checks which memory value to convert to 
  if(strcmp(argv[1], "-h") == 0){
    printf(2,"#procs: %d", c.num_procs);
    if(c.uvm_used > (2*G)){
      printf(2,", size(uvm): %dGB", c.uvm_used/G);\
    } else if(c.uvm_used> (2*M)){
      printf(2,", size(uvm): %dMB", c.uvm_used/M);
    } else if(c.uvm_used > (2*K)){
      printf(2,", size(uvm): %dKB", c.uvm_used/K);
    }
    printf(2,", ncpu %d\n", c.num_cpus);
  } else{ 
    printf(2,"#procs: %d, size(uvm): %d, ncpu %d\n", c.num_procs, c.uvm_used, c.num_cpus);
  }
  exit();
}
