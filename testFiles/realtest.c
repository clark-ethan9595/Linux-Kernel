/*
 *Created by: Mitch Stark (mjs73), Kyle Reitsma (kr29), Ethan Clark (elc3)
 *Date: 4/27/17
 *Runs the system call on the Linux Kernel
 */
#include <tasktree.h>
#include <taskinfo.h>
#include <stdio.h>
#include <stdlib.h>

//Main function to test run the system call

int main(void) {
	//system call puts process info into this pointer
	struct taskinfo *processes;
		
	//number of processes to look at
	int nr = 100;
	
	//allocate process memory
	processes = malloc(nr*sizeof(struct taskinfo));
			
	//run system call
	int num = syscall(327, processes, nr, 1);
		
	printf("Number of related processes found: %i\n", num);

	//setup for loop
	int i;
	int j;

	//iterate through all processes
	for ( i = 0; i < nr; i++ )
	{  
		for( j = 0; j < processes[i].level; j++ ) {
			printf( "\t" ) ; 
		}
		printf( "pid %i, parent_pid %i, first_child %i, state %lu, uid %lu name %s\n", processes[i].pid, processes[i].parent_pid, processes[i].first_child_pid, processes[i].state, processes[i].uid, processes[i].comm);
	}
	
	//free memory
	free(processes);
	return 0;
}
