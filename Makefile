main: osxlib
	gcc -o build/main.out src/*.c -Ilib -Llib -lrtqr 

test: osxlib
	gcc -g -o build/main.out src/*.c -Ilib -Llib -lrtqr 

osxlib:
	gcc -dynamiclib -o lib/librtqr.dylib lib/*.c lib/libquirc.a -lcrypto -lpng -ljpeg

clean:
	rm -rf build/*
	rm -f lib/*.dylib
run:
	build/main.out
runtest:
	lldb build/main.out
