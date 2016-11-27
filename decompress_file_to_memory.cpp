#include <stdio.h>
#include <iostream>
#include <sstream>
#include "zlib.h"

#define BUFFER_LENGTH 1024

/**
 * This function opens given file and uses zlib to
 * to uncompress it. Result is saved into string stream
 * for future usage within the program.
 *
 * \param[in] filename Name of the compressed file
 */
int decompress_one_file_to_memory(char *infilename)
{
   gzFile file = gzopen(infilename, "rb");

   char buffer[BUFFER_LENGTH];
   int num_read = 0;

   std::ostringstream oss;
      
   while ((num_read = gzread(file, buffer, sizeof(buffer))) > 0) {
     // Add null char to end
     buffer[BUFFER_LENGTH] = '\0';
     oss << buffer;
   }
   // print decompressed file contents
   std::cout << oss.str();
   
   gzclose(infile);
}

int main(int argc, char **argv)
{ 
   decompress_one_file_to_memory(argv[1]);
}
