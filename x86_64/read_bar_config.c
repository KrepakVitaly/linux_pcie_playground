/*

 *  */

#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <getopt.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include <errno.h>


#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>



#define DEVICE_NAME_DEFAULT "/dev/xdma0_c2h_0"
#define SIZE_DEFAULT (32)
#define COUNT_DEFAULT (1)


static int test_read_bar_config(char *devname, uint64_t addr, uint64_t size,
		    uint64_t offset, uint64_t count, char *ofname)
{

    int fpga_fd = open(devname, O_RDWR | O_NONBLOCK);


	if (fpga_fd < 0) {
                fprintf(stderr, "unable to open device %s, %d.\n",
                        devname, fpga_fd);
		perror("open device");
                return -EINVAL;
        }
        else
        {
         fprintf(stderr, "success opened device %s, %d.\n",
                        devname, fpga_fd);
        }

    close(fpga_fd);
    fprintf(stdout, "closed device %d\n", fpga_fd);
    return 0;
}


int main(int argc, char *argv[])
{

    char *device = DEVICE_NAME_DEFAULT;
    uint64_t address = 0;
    uint64_t size = SIZE_DEFAULT;
    uint64_t offset = 0;
    uint64_t count = COUNT_DEFAULT;
    char *ofname = NULL; //output filename

    fprintf(stdout,
                "dev %s, addr 0x%lx, size 0x%lx, offset 0x%lx, count %lu\n",
		device, address, size, offset, count);

    test_read_bar_config(device, address, size, offset, count, ofname);

    return 0;
}


