final: UtPodDriver.o UtPod.o Song.o
	g++ -otest  UtPodDriver.o UtPod.o Song.o
driver.o: UtPodDriver.cpp UtPod.h Song.h
	g++ -c UtPodDriver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ -c UtPod.cpp
song.o: Song.cpp Song.h
	g++ -c Song.cpp
