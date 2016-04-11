#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_cpu_usage () {
	FILE *stat;
	static unsigned long long old_user, old_nuser, old_system, old_idle;
	unsigned long long user = 0, nuser = 0, system = 0, idle = 0;

	if ((stat = fopen ("/proc/stat", "r")) == NULL) {
		fprintf (stderr, "Error opening /proc/stat.\n");
		return -1;
	}

	/**
	 * %*s      %llu         %llu          %llu            %llu
	 * ---    user mode    nice user    system mode     idle state
	 * cpu     1714278       9555          953821       1344256388
	 */
	fscanf (stat, "%*s %llu %llu %llu %llu",
		&user, &nuser, &system, &idle);

	old_user = user;
	old_nuser = nuser;
	old_system = system;
	old_idle = idle;

	fclose (stat);
}
