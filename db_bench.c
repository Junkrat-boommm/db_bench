#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "db.h"

#include "util/Slice.h"



static const char* FLAGS_benchmarks =
    "fillseq,"
    "fillsync,"
    "fillrandom,"
    "overwrite,"
    "readrandom,"
    "readrandom,"  // Extra run to allow previous compactions to quiesce
    "readseq,"
    "readreverse,"
    "compact,"
    "readrandom,"
    "readseq,"
    "readreverse,"
    "fill100K,"
    "crc32c,"
    "snappycomp,"
    "snappyuncomp,";


// Number of key/values to place in database
static int FLAGS_num = 1000000;

// Number of read operations to do.  If negative, do FLAGS_num reads.
static int FLAGS_reads = -1;

// Number of concurrent threads to run.
static int FLAGS_threads = 1;

// Size of each value
static int FLAGS_value_size = 100;

// Number of key/values to place in database
static int FLAGS_num = 1000000;

// Number of read operations to do.  If negative, do FLAGS_num reads.
static int FLAGS_reads = -1;

// Number of concurrent threads to run.
static int FLAGS_threads = 1;

// Size of each value
static int FLAGS_value_size = 100;

// size of map file
static int FLAGS_file_size = 4 * 1024 * 1024 * 1024;

// 


// Use the db with the following name.
static const char* FLAGS_db = NULL;

struct Benchmark {
	int num_;
};

void BenchmarkInitial(struct Benchmark *bench) {
	bench->num_ = FLAGS_num;
}

void PrintEnvironment() {
    fprintf(stderr, "DB:    version %d.%d\n", kMajorVersion,
                 kMinorVersion);

// #if defined(__linux) 
//     time_t now = time(NULL);
//     fprintf(stderr, "Date:       %s",
//                  ctime(&now));  // ctime() adds newline
//     FILE* cpuinfo = fopen("/proc/cpuinfo", "r");
//     if (cpuinfo != NULL) {
//       char line[1000];
//       int num_cpus = 0;
//       char* cpu_type;
//       char* cache_size;
//       while (fgets(line, sizeof(line), cpuinfo) != NULL) {
//         const char* sep = strchr(line, ':');
//         if (sep == NULL) {
//           continue;
//         }
//         Slice key = TrimSpace(Slice(line, sep - 1 - line));
//         Slice val = TrimSpace(Slice(sep + 1));
//         if (key == "model name") {
//           ++num_cpus;
//           cpu_type = val.ToString();
//         } else if (key == "cache size") {
//           cache_size = val.ToString();
//         }
//       }
//       fclose(cpuinfo);
//       fprintf(stderr, "CPU:        %d * %s\n", num_cpus, cpu_type);
//       fprintf(stderr, "CPUCache:   %s\n", cache_size);
//     }
// #endif
}

void PrintHeader(struct Benchmark *bench) {
	PrintEnvironment();

}

void Run(struct Benchmark benchmark) {
	
}

int main (int argc, char** argv) {
	// set options as default

	// get options from shell
	for (int i = 1; i < argc; i++) {
		double d;
		int n;
		char junk;
		struct Slice s;
		SliceInitial(&s, strlen(argv[i]), argv[i]);
		if(SliceStartWith(s, "--benchmarks=", strlen("--benchmarks"))) {
			FLAGS_benchmarks = argv[i] + strlen("--benchmarks");
		} else if (sscanf(argv[i], "flie_size", &n, &junk) == 1) {
			FLAGS_file_size = n;
		} else {
			fprintf(stderr, "Invalid flag '%s'\n", argv[i]);
			exit(1);
		}
	}

	struct Benchmark benchmark;
	BenchmarkInitial(&benchmark);
	Run(benchmark);
}