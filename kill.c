/* kill.c */

#define INCL_DOSPROCESS
#define INCL_DOSERRORS

#include <os2.h>
#include <stdio.h>

int main( int argc, char **argv )
{
   int iScan;
   ULONG ulStat;
   PID pid;

   if( argc <= 1 )
   {
      printf("Usage:\n\tkill <pid>\n\n");
      printf("where <pid> is a valid process ID as given in\nthe ");
      printf("output of the OS/2 utility \"pstat/c\"\n");
      fflush(stdout);
      exit(0);
   }
   else
   {
      iScan = sscanf(argv[1],"%x",&pid);
      if( iScan <= 0 )
      {
	 printf("Invalid PID! Use the OS/2 command \"pstat/c\" to\n");
	 printf("get a list of running processes.\n");
	 fflush(stdout);
	 exit(0);
      }
   }
      
   ulStat = DosKillProcess( EXIT_PROCESS, pid );

   switch( ulStat )
   {
      case NO_ERROR:
         printf("Process successfully killed...\n");
         break;

      case ERROR_INVALID_PROCID:
	 printf("Invalid PID! Use the OS/2 command \"pstat/c\" to\n");
	 printf("get a list of running processes!\n");
	 break;
   }

   fflush(stdout);
   return 0;
   
}
