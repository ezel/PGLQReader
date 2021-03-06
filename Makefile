all: main standalone

main: maclib
	gcc -o build/main.out src/*.c lib/libquirc.a -Ilib -Llib -lrtqr

test: maclib
	gcc -g -o build/test.out src/*.c -Ilib -Llib -lrtqr 

maclib:
	gcc -dynamiclib -o lib/librtqr.dylib lib/*.c lib/libquirc.a -lcrypto -lpng -ljpeg

standalone:
	gcc -o build/pglqread src/*.c lib/*.c lib/libquirc.a -lcrypto -lpng -ljpeg -Ilib

clean:
	rm -rf build/*
	rm -f lib/*.dylib
run:
	build/main.out
runtest:
	lldb build/test.out
