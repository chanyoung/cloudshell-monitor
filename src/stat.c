#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_cpu_usage () {
	FILE *stat;
	static unsigned long long old_user, old_nuser, old_system, old_idle;
	unsigned long long user = 0, nuser = 0, system = 0, idle = 0;
	unsigned int idle_usage;

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

	/**
	 * Calculate cpu idle jiffies.
	 *
	 *                            idle jiffies
	 *  -----------------------------------------------------------------
	 *   user jiffies + nice user jiffies + system jiffies + idle jiffies
	 *
	 */
	idle_usage = (((idle - old_idle) * 100) / ((user - old_user) + (nuser - old_nuser) + (system - old_system) + (idle - old_idle)));

	/**
	 * Save current jiffies into old values.
	 */
	old_user = user;
	old_nuser = nuser;
	old_system = system;
	old_idle = idle;

	fclose (stat);

	/**
	 * Cpu usage = 100 - idle usage.
	 */
	return (100 - idle_usage);
}

int get_cpu_heat () {
	FILE *heat;
	unsigned int temperature;

	if ((heat = fopen ("/sys/class/thermal/thermal_zone0/temp", "r")) == NULL) {
		fprintf (stderr, "Error opening /sys/class/thermal/thermal_zone0/temp.\n");
		return -1;
	}

	fscanf (heat, "%u", &temperature);
	fclose (heat);

	return (temperature / 1000);
}

int get_mem_usage () {
	FILE *file;
	unsigned int total, free;

	if ((file = fopen ("/proc/meminfo", "r")) == NULL) {
		fprintf (stderr, "Error opening /proc/meminfo.\n");
		return -1;
	}

	fscanf (file, "%*s %u %*s\n%*s %u", &total, &free);

	fclose (file);

	return (100 - (((float) free / total) * 100));
}
