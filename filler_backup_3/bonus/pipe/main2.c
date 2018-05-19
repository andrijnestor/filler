#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define die(e) do { fprintf(stderr, "%s\n", e); exit(EXIT_FAILURE); } while (0);

int main() {
  int link[2];
  pid_t pid;
  char foo[8096];
  char	*ff = "../../resources/filler_vm";
  char	*f = "-f";
  char	*map = "../../resources/maps/map00";
  char	*p1 = "-p1";
  char	*p2 = "-p2";
  char	*plr = "../../resources/players/superjeannot.filler";

  if (pipe(link)==-1)
    die("pipe");

  if ((pid = fork()) == -1)
    die("fork");

  if(pid == 0) {

    dup2 (link[1], STDOUT_FILENO);
    close(link[0]);
    close(link[1]);
//    execl("../../resources/filler_vm", "-f", "../../resources/maps/map00", "-p1",
//		   "../../resources/playes/superjeannot.filler", "-p2",
//		   "../../resources/playes/superjeannot.filler", (char *)0);
    execl(ff, ff, f, map, p1, plr, p2, plr, (char *)0);

    die("execl");

  } else {

    close(link[1]);
    int nbytes;
	char	c;
	int ddf = open("file", O_RDWR | O_TRUNC | O_CREAT, 0644);
	while (read(link[0], &c, 1))
	{		
   		dprintf(ddf, "%c", c);
	}
    wait(NULL);

  }
  return 0;
}
