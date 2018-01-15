# count-unique
Read lines from standard input and count how often each unique line occurs,
printing an (unordered) list of the form

	 123 line 1
	1000 line 2
	  42 line 3
	   4 line 4

i.e. with the count printed before the line. Note that this programme assumes
that lines are no more than 1024 bytes long. Anything past the 1024th byte will
be silently ignored.

## Motivation
Why on Earth would anyone write a programme like this? Yes, one could just use
`sort | uniq -c`, but that is needlessly slow. In fact, I read [Command-line
Tools can be 235x Faster than your Hadoop
Cluster](https://aadrake.com/command-line-tools-can-be-235x-faster-than-your-hadoop-cluster.html)
and just wanted to see, how hard it would be to beat the parallelized `find` +
`xargs` + `mawk` implementation at the end.

## Compiling
To compile this programme, you will need
[uthash](https://troydhanson.github.io/uthash), a C header-only hash table
implementation. As I don't want to remember how to compile this, it can be built
using [Meson](https://mesonbuild.com):

	meson build
	ninja -C build

which should give you a binary `build/count-unique`. Alternatively, you can
obviously also use your favourite C compiler to build it manually with whatever
flags you like:

	$CC $CFLAGS -o count-unique main.c
