
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

typedef struct      s_header_bmpfile
{
	unsigned char   signature[2];
	unsigned int    size;
	unsigned short	reserved1;
	unsigned short	reserved2;
	unsigned int    offset;
}                   t_FileHeader;

typedef struct      s_header_bmpimg
{
	unsigned int    headersize;
	unsigned int    w;
	unsigned int    h;
	unsigned short  planes;
	unsigned short  bpp;
	unsigned int    compression;
	unsigned int    size;
	unsigned int    horizontalres;
	unsigned int    verticalres;
	unsigned int    colornb;
	unsigned int    importantcolors;
}                   t_InfoHeader;

int		ft_error(const char *str)
{
	write(1, str, strlen(str));
	return(-1);
}

int					main(int ac, char **av)
{
	t_FileHeader	file;
	t_InfoHeader	info;
	char			buf[10];
	int				fd;

	if (ac != 2)
		return (ft_error("Give a filename, dumb !\n"));
	if ((fd = open(av[1], O_RDWR)) <= 0)
		return (ft_error("Sorry, open failure !\n"));
	buf[0] = 0;
	//FILEHEADER
	read(fd, &(file.signature[0]), 2);
	read(fd, &(file.size), 4);
	read(fd, &(file.reserved1), 2);
	read(fd, &(file.reserved2), 2);
	read(fd, &(file.offset), 4);
	printf("1\t\tsignature 1 :\t\t|%c|\n", *((char*)&(file.signature[0])));
	printf("2\t\tsignature 2 :\t\t|%c|\n", *((char*)&(file.signature[1])));
	printf("3,4,5,6\t\tsize :\t\t\t|%u|\n", *((unsigned int*)&(file.size)));
	printf("7,8\t\treserved1 :\t\t|%hd|\n", *((unsigned short*)&(file.reserved1)));
	printf("9,10\t\treserved2 :\t\t|%hd|\n", *((unsigned short*)&(file.reserved2)));
	printf("11,12,13,14\toffset :\t\t|%u|\n", *((unsigned int*)&(file.offset)));
	fflush(stdout);
	//INFOHEADER
	read(fd, &(info.headersize), 4);
	read(fd, &(info.w), 4);
	read(fd, &(info.h), 4);
	read(fd, &(info.planes), 2);
	read(fd, &(info.bpp), 2);
	read(fd, &(info.compression), 4);
	read(fd, &(info.size), 4);
	read(fd, &(info.horizontalres), 4);
	read(fd, &(info.verticalres), 4);
	read(fd, &(info.colornb), 4);
	read(fd, &(info.importantcolors), 4);
	printf("\n1,2,3,4\t\tinfoheadersize :\t|%u|\n", *((unsigned int*)&(info.headersize)));
	printf("5,6,7,8\t\twidth :\t\t\t|%u|\n", *((unsigned int*)&(info.w)));
	printf("9,10,11,12\theight :\t\t|%u|\n", *((unsigned int*)&(info.h)));
	printf("13,14\t\tplanes :\t\t|%hd|\n", *((unsigned short*)&(info.planes)));
	printf("15,16\t\tbpp :\t\t\t|%hd|\n", *((unsigned short*)&(info.bpp)));
	printf("17,18,19,20\tcompression :\t\t|%u|\n", *((unsigned int*)&(info.compression)));
	printf("21,22,23,24\tsize :\t\t\t|%u|\n", *((unsigned int*)&(info.size)));
	printf("25,26,27,28\thoriz res :\t\t|%u|\n", *((unsigned int*)&(info.horizontalres)));
	printf("29,30,31,32\tvertic res :\t\t|%u|\n", *((unsigned int*)&(info.verticalres)));
	printf("33,34,35,36\tcolornb :\t\t|%u|\n", *((unsigned int*)&(info.colornb)));
	printf("37,38,39,40\timportant color :\t|%u|\n", *((unsigned int*)&(info.importantcolors)));
	fflush(stdout);
	close(fd);
	return(0);
}
