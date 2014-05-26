all: gba_build sdl_build

gba_build:
	make -j`nproc` -C gba ${ARGS}
sdl_build:
	make -j`nproc` -C sdl ${ARGS}
