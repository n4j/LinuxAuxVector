#include "hwcap.h"

void print_info(Elf64_auxv_t *val) {
	uint64_t a_val = val->a_un.a_val;

	switch(val->a_type) {
		case AT_PHDR:
			printf("AT_PHDR=[%ld]\r\n", a_val);
			break;
		case AT_PHENT:
			printf("AT_PHENT\r\n");
			break;
		case AT_PHNUM:
			printf("AT_PHNUM\r\n");
			break;
		case AT_PAGESZ:
			printf("AT_PAGESZ=[%ld]\r\n", a_val);
			break;
		case AT_BASE:
			printf("AT_BASE\r\n");
			break;
		case AT_ENTRY:
			printf("AT_ENTRY\r\n");
			break;
		case AT_RANDOM:
			printf("AT_RANDOM\r\n");
			break;
		case AT_SYSINFO_EHDR:
			printf("AT_SYSINFO_EHDR\r\n");
			break;
		case AT_HWCAP:
			printf("AT_HWCAP\r\n");
			break;
		case AT_HWCAP2:
			printf("AT_HWCAP2\r\n");
		        print_cpu_cap(a_val);	
			break;
		case AT_SECURE:
			printf("AT_SECURE\r\n");
			break;
		case AT_PLATFORM:
			printf("AT_PLATFORM\r\n");
			break;
		case AT_EXECFN:
			printf("AT_EXECFN\r\n");
			break;
		default:
			printf("Unknown attribute [%ld]\r\n", val->a_type);
	}
}

int main() {
	int auxv_fd = open("/proc/self/auxv", O_RDONLY);
	if(0 > auxv_fd) {
		perror("fopen ");
		return errno;
	}

	int auxv_sz = sizeof(Elf64_auxv_t);

	Elf64_auxv_t* auxv = (Elf64_auxv_t*)malloc(auxv_sz);

	while(read(auxv_fd, (void*)auxv, auxv_sz) > 0)
		print_info(auxv);

	return 0;
}


