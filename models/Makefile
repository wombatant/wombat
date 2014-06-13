generated.cpp: models/models.cy models.cy
	cat models/models.cy models.cy > all.cy
	cyborgbear -i all.cy -o generated
	rm -f all.cy
	liccor
clean:
	rm -f all.cy generated.hpp generated.cpp
