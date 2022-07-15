#include <windows.h>
#include <stdio.h>


bool patch1,patch2;
char oldsr2[] = "sr2.exe";
char newsr2[] = "sr2_original.exe";
char oldsr2patch[] = "sr2_unpatched.exe";
char newsr2patch[] = "sr2.exe";


int main()
{
	patch1 = rename(oldsr2, newsr2);
	if (patch1 == 0)
	{
		puts("Original executable successfully renamed");
		patch2 = rename(oldsr2patch, newsr2patch);
		if (patch2 == 0)
		{
			puts("Patch was successful!");
		}
		else
		{
			perror("Error renaming patched executable reason");
		}
	}
	else
	{ 
		perror("Error renaming original game executable reason");
	}

	system("pause");

	return 0;
}
