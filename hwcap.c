#include "hwcap.h"

void print_cpu_cap(uint64_t mask) {
	#if defined(__aarch64__) || defined(_M_ARM64)
		print_cpu_cap_aarch64(mask);
	#elif 
		print_cpu_cap_noop(mask);
	#endif
}

void print_cpu_cap_aarch64(uint64_t features) {
	int total_caps = sizeof(AARCH_CPU_FEATURES)/sizeof(AARCH_CPU_FEATURES[0]);
	uint64_t mask = 1;

	printf("CPU features: \r\n");
	for(int i=0; i<total_caps; i++) {
		if(features && mask) {
			printf("\t%s\r\n", AARCH_CPU_FEATURES[i]);
		}
		mask <<= 1;
	}
}

void print_cpu_cap_noop(uint64_t) {
	printf("UCP: Unidentified CPU Platform\r\n");
}
