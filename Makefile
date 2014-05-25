make:
	./scripts/runmake 
preinstall:
	./scripts/runmake preinstall
install:
	./scripts/runmake install
clean:
	./scripts/runmake clean
build: release
release:
	./scripts/setup_build
debug:
	./scripts/setup_build_debug
