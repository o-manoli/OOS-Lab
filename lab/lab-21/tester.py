"""
   Passes input files onto an executable to be run as a test cases.

   Won't do any fancy error handling!
   Just prints to the terminal.

   Parameters:
      1. Path to the executable file
      ... as many input files as you want

      There should be at least one input file.
         Otherwise there is nothing execute.

   Author:
      @O-Manoli

"""

import sys
import os


if len(sys.argv) < 2:
   print(__doc__)
   raise ValueError("\n\nNot Enough arguments !!!")

exe, *input_files = sys.argv[1], *sys.argv[2:]

for stdin in input_files:
   print(f"\n\tTesting: {stdin}\n\n")
   os.system(f"{exe} < {stdin}")
   print(2*"\n" + ' '.join(12*'-') + 2*"\n")

