#include <unistd.h>
#include <sys/types.h>
struct taskinfo {
	pid_t pid;
	pid_t parent_pid;
	pid_t first_child_pid;
	long state;
	long uid;
	char comm[64];
	int level;
};