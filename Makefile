make:
	make -j8 -C build
preinstall:
	make -j8 -C build preinstall
install:
	make -j8 -C build install
clean:
	make -j8 -C build clean
