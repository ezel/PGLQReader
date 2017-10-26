main: osxlib
	gcc -o build/main.out src/*.c -Ilib -Llib -lrtqr 

test: osxlib
	gcc -g -o build/main.out src/*.c -Ilib -Llib -lrtqr 

osxlib:
	gcc -dynamiclib -o lib/librtqr.dylib lib/*.c -lcrypto

bwl: lib/libmeme.dylib
	gcc -o build/main.out src/*.c -Ilib -Llib -L. -lrtqr

wnl:
	gcc -o build/main.out src/*.c -Ilib lib/*.c
clean:
	rm -f build/*
	rm -f lib/*.dylib
run:
	build/main.out
runtest:
	lldb build/main.out
