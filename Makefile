make:
	make -j -C build
preinstall:
	make -j -C build ARGS="preinstall"
install:
	make -j -C build ARGS="install"
clean:
	make -j -C build ARGS="clean"

sdl: build/sdl
build/sdl:
	./scripts/setup_build

sdl_debug: build/sdl_debug
build/sdl_debug:
	./scripts/setup_build_debug

gba: build/gba
build/gba:
	./scripts/setup_build_gba
