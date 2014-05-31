make:
	make -j -C build
preinstall:
	make -j -C build ARGS="preinstall"
install:
	make -j -C build ARGS="install"
clean:
	make -j -C build ARGS="clean"

sdl:
	./scripts/setup_build

sdl_debug:
	./scripts/setup_build_debug

gba:
	./scripts/setup_build_gba
