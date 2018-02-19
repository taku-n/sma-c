sma.ex5: sma.mq5 sma.dll
	-metaeditor64.exe /compile:sma.mq5 /log:log.log
	cat log.log
	rm log.log

sma.dll: sma.c
	clang -Wall -shared -o sma.dll sma.c
