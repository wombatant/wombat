all: gba_build sdl_build sdl_debug_build

gba_build:
	@if [ -d gba ]; then \
		ninja -C gba ${ARGS}; \
	fi

sdl_build:
	@if [ -d sdl ]; then \
		ninja -C sdl ${ARGS}; \
	fi

sdl_debug_build:
	@if [ -d sdl_debug ]; then \
		ninja -C sdl_debug ${ARGS}; \
	fi
