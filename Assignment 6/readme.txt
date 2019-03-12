Kathy Daniels
404887687
Assignment 6
After-action Report
--------------------

I encountered a few problems while trying to implement this
multithreaded program. I first struggled to figure out how
to correctly link the -lpthread library using correct syntax,
but I easily fixed that by researching documentation.

The first time I tried to execute my program, I encountered
the error: "make: *** [check] Error 1" which I couldn't quite
determine the source for, but after re-examining the code
and fixing minor errors in the code logic, I was able to get
my program to run correctly.

My overall approach in this assignment was to split up the
work with "n" amount of threads, running "n" calculations
in parallel to determine each pixel color. When running the
make clean check, I got the following performance results:

1-test.ppm			2-test.ppm

real	0m41.203s		real	0m21.582s
user	0m41.194s		user    0m43.106s
sys	0m0.000s		sys     0m0.001s

4-test.ppm			8-test.ppm

real	0m11.182s		real	0m5.769s
user	0m44.421s		user	0m44.677s
sys	0m0.001s		sys	0m0.006s

As we can see, my implementation of SRT improved the original
performance after all. As the number of threads is doubled,
the time decreases by around half of the previous time.
Therefore, we can see that we can gain a much better
performance using multithreading!
