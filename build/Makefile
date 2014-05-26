all: gba_build sdl_build sdl_debug_build

gba_build:
	@if [ -d gba ]; then \
		make -j`nproc` -C gba ${ARGS}; \
	fi

sdl_build:
	@if [ -d sdl ]; then \
		make -j`nproc` -C sdl ${ARGS}; \
	fi

sdl_debug_build:
	@if [ -d sdl_debug ]; then \
		make -j`nproc` -C sdl_debug ${ARGS}; \
	fi
