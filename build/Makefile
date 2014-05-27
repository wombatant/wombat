all: gba_build sdl_build sdl_debug_build

gba_build:
	@if [ -d gba ]; then \
		make -j -C gba ${ARGS}; \
	fi

sdl_build:
	@if [ -d sdl ]; then \
		make -j -C sdl ${ARGS}; \
	fi

sdl_debug_build:
	@if [ -d sdl_debug ]; then \
		make -j -C sdl_debug ${ARGS}; \
	fi
