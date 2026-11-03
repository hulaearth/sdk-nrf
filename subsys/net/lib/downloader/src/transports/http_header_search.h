/* SPDX-License-Identifier: LicenseRef-Nordic-5-Clause */
#ifndef DOWNLOADER_HTTP_HEADER_SEARCH_H_
#define DOWNLOADER_HTTP_HEADER_SEARCH_H_

#include <stddef.h>
#include <string.h>

/* HTTP delimiters are short. Keep the search bounded and stop at the first NUL. */
static inline char *http_header_find(const char *text, const char *needle, size_t size)
{
	const size_t needle_size = strlen(needle);
	if (needle_size == 0) {
		return (char *)text;
	}
	size_t text_size = 0;
	while (text_size < size && text[text_size] != '\0') {
		++text_size;
	}
	if (needle_size > text_size) {
		return NULL;
	}
	for (size_t i = 0; i <= text_size - needle_size; ++i) {
		if (memcmp(text + i, needle, needle_size) == 0) {
			return (char *)text + i;
		}
	}
	return NULL;
}
#endif
