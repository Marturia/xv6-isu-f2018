/*
  Author:   Brody Little

  Purpose:  Gets information about current processes, memory, and cpu number

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
