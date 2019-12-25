# vmtest
Demonstrate that virtual memory is cheap.

## Usage:

`$ time ./vmtest 10000000 10000000`

`$ time ./vmtest 10000000 100000000`

Note: both take the same amount of time, same amount of RAM.
The latter just takes more virtual memory space.

