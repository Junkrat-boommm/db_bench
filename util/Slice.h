#pragma once

#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct Slice {
	/* data */
	uint64_t size;
	char *data;
	int is_owner;
};


int SliceStartWith(struct Slice s1, char *c, int len) {
	return ((s1.size >= len) && (memcpy(s1.data, c, len) == 0));
}

int SliceCompare(struct Slice* s1, struct Slice* s2) {
	if (s1->size == s2->size) {
		return memcmp(s1->data, s2->data, s2->size);
	}
	else if(s1->size > s2->size) {
		int res = memcmp(s1->data, s2->data, s2->size);
		return (res == 0) ? 1 : res;
	}
	else {
		int res = memcmp(s1->data, s2->data, s1->size);
		return (res == 0) ? -1 : res;
	}
}

struct Slice *SliceCreate(uint64_t len, char* data, int is_owner) {
	struct Slice *slice = (struct Slice *)malloc(sizeof(struct Slice));
	if(is_owner) {
		slice->data = (char*)malloc(len);
		int _ = memcpy(slice->data, data, len);
	} else {
		slice->data = data;
	}
	slice->size = len;
	slice->is_owner = is_owner;
	return slice;
}

void SliceDestroy(struct Slice* slice) {
	if(NULL == slice)
		return;
	if (slice->is_owner && NULL != slice->data)
	{
		free(slice->data);
	}
	free(slice);
}

void SliceInitial(struct Slice *slice, uint64_t len, char* data) {
	if(slice == NULL)
		assert(0);
	slice->size = len;
	slice->data = data;
	slice->is_owner = 0;
	return;
}