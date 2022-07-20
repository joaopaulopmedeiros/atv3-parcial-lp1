app: msg dist build

msg: 
	@echo Hello, we're getting things ready for ya...

dist: 
	mkdir dist

build:
	g++ -c src/main.cpp -o dist/main.o
	g++ -o dist/main dist/main.o

reload: app	