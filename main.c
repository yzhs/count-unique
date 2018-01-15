#define _POSIX_C_SOURCE 200809L

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

#include <uthash.h>

#define LINE_MAX 1024

struct line {
	char content[LINE_MAX];
	int count;
	UT_hash_handle hh;
};

int
main(void)
{
	struct line *lines = NULL, *s = NULL;

	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, stdin)) != -1) {
		HASH_FIND_STR(lines, line, s);
		if (s) {
			s->count += 1;
			continue;
		}

		s = malloc(sizeof(struct line));
		if (!s) {
			err(1, "malloc");
		}
		strncpy(s->content, line, LINE_MAX);
		s->count = 1;
		HASH_ADD_STR(lines, content, s);
	}
	free(line);
	line = NULL;

	struct line *tmp;
	HASH_ITER(hh, lines, s, tmp) {
		HASH_DEL(lines, s);
		printf("%8d %s", s->count, s->content);
		free(s);
	}

	return 0;
}
