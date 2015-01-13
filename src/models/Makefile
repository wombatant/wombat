generated.cpp: models/models.cy models.cy
	cat models/models.cy models.cy > all.cy
	cyborgwombat -i all.cy -o generated -n "wombat::models"
	cyborgwombat -v > modelgen_version
	rm -f all.cy
	liccor
clean:
	rm -f all.cy generated.hpp generated.cpp
