// tab.c

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "sort.h"

static int str_to_tab(ssize_t **tab, char *str, size_t len, size_t *size)
{
  char *token = NULL;

  str[len] = '\0';
  for (size_t i = 0; i < len; i++)
    if (str[i] == '\n')
      (*size)++;
  if (str[len - 1] != '\n')
    (*size)++;
  *tab = malloc(sizeof(ssize_t) * (*size));
  if (!(*tab))
    return (EXIT_FAILURE);
  token = strtok(str, "\n");
  for (size_t i = 0; token; i++) {
    (*tab)[i] = strtoll(token, NULL, 10);
    token = strtok(NULL, "\n");
  }
  return (EXIT_SUCCESS);
}

int init_tab(ssize_t **tab, const char *file, size_t *size)
{
  int fd;
  char *str;
  struct stat buf;

  fd = open(file, O_RDONLY);
  if (fd == -1 || fstat(fd, &buf) == -1) {
    perror(file);
    return (EXIT_FAILURE);
  }
  str = malloc(sizeof(char) * buf.st_size + 1);
  if (!str
      || read(fd, str, buf.st_size) < 0
      || str_to_tab(tab, str, buf.st_size, size)) {
    perror(file);
    return (EXIT_FAILURE);
  }
  free(str);
  return (EXIT_SUCCESS);
}

void dump_tab(const ssize_t *tab, size_t size)
{
  for (size_t idx = 0; idx < size; idx++)
    printf("%ld\n", tab[idx]);
}
