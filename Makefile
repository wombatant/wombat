make:
	make -j8 -C build
preinstall:
	make -j8 -C build preinstall
install:
	make -j8 -C build install
clean:
	make -j8 -C build clean
build: release
release:
	./scripts/setup_build
debug:
	./scripts/setup_build_debug
