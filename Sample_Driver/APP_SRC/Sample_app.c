#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define WR_DATA  _IOW('1','2',int32_t*)
#define RD_DATA  _IOR('1','3',int32_t*)


int8_t write_buf[1024];
int8_t read_buf[1024];

int main()
{
        int fd;
        char option;

        fd = open("/dev/Sample_device", O_RDWR);
        if(fd < 0) {
                printf("Cannot open device file...\n");
                return 0;
        }

        while(1) 
        {
                printf("\n\t-------------------------------");
                printf("\n\t|        1. Write             |");
                printf("\n\t|        2. Read              |");
                printf("\n\t|        3. Exit              |");
                printf("\n\t-------------------------------");
                printf("\n\t Enter the Option :");
                scanf(" %c", &option);
                //                printf("Your Option = %c\n", option);

                switch(option) {
                        case '1':
                                {
                                        printf("Enter the string to write into driver :");
                                        scanf("  %[^\t\n]s", write_buf);
                                        //write(fd, write_buf, strlen(write_buf)+1);
                                        ioctl(fd,WR_DATA,(char *)&write_buf);
                                }
                                break;
                        case '2':
                                {
                                        // read(fd, read_buf, 1024);
                                        ioctl(fd,RD_DATA,(char *)&read_buf);
                                        printf("Data = %s\n\n", read_buf);
                                }
                                break;
                        case '3':
                                {
                                        close(fd);
                                        exit(1);
                                }
                                break;
                        default:
                                printf("Enter Valid option = %c\n",option);
                                break;
                }
        }
        close(fd);
}
