#include <stdio.h>
#include <errno.h>
#include <linux/unistd.h>
#include <linux/kernel.h> /* for struct sysinfo */
#include <sys/sysinfo.h>

long get_uptime(void)
{
	struct sysinfo s_info;
	int rc;

	rc = sysinfo(&s_info);
	if (rc != 0) {
		printf("Error code: %d\n", rc);
	}
	return s_info.uptime;
}

int main(void)
{
	printf("%ld\n", get_uptime());
	return 0;
}
