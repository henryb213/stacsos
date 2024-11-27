#include <stacsos/console.h>
#include <stacsos/memops.h>

using namespace stacsos;

int main(const char *cmdline)
{   

    if (!cmdline || memops::strlen(cmdline) == 0) {
		console::get().write("error: usage: ls [-l] <directory>\n");
		return 1;
	}

    bool longListing = false; 
    
    if (cmdline[0] == '-' && cmdline[1] == 'l'){
        longListing = true;
        console::get().write("Long listing\n");
        
        // assume next argument will be after a space. 
        cmdline = cmdline + 3;
    }

    const char *dir = cmdline;
    console::get().writef("Showing: %s\n", dir);  

	return 0;
}