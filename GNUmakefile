sma.ex5: sma.mq5 sma.dll
	-metaeditor64.exe /compile:sma.mq5 /log:log.log
	cat log.log
	rm log.log

sma.dll: sma.c net.o net.h
	clang -Wall -shared -o sma.dll sma.c net.o -lws2_32

net.o: net.c net.h
	clang -Wall -c -o net.o net.c -lws2_32
