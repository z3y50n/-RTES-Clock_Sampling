# RTES-Clock_Sampling
## 2 simple programs to sample the CPU clock
### Author: Papageorgiou Dimitrios
\--------------------------------------------------------------------------

#### Installation
In download folder type:
>make

#### Description
First program runs without using the timestamps from gettimeofday()

Second program improves the error by taking advantage of the timestamps.

diagram.py creates a diagram of the intervals between the timestamps and calculates
some statistics.

#### Usage
Just enter total time and dt and the program will execute. At the end it will ask if 
the user would like to store the data.
