all: gba_build sdl_build sdl_debug_build

gba_build:
	make -j`nproc` -C gba ${ARGS}
sdl_build:
	make -j`nproc` -C sdl ${ARGS}
sdl_debug_build:
	make -j`nproc` -C sdl_debug ${ARGS}
