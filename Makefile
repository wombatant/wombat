make:
	make -j`nproc` -C build ARGS="" 
preinstall:
	make -j`nproc` -C build ARGS="preinstall"
install:
	make -j`nproc` -C build ARGS="install"
clean:
	make -j`nproc` -C build ARGS="clean"
sdl: build/sdl
build/sdl:
	./scripts/setup_build
gba: build/gba
build/gba:
	./scripts/setup_build_debug
