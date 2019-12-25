vmtest: vmtest.c
	clang -O0 -o vmtest vmtest.c

run: vmtest
	time ./vmtest 10000000 10000000
	time ./vmtest 10000000 100000000

