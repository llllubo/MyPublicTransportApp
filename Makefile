# 			ICP | FIT VUT
# PROJECT: DISPLAY AND MONITORING OF PUBLIC TRANSPORT
# VERSION: 1.0
# DATE:    17.05.2020
# AUTHORS: Lubos Bever | Samuel Gajdos

all:
	@cd src && qmake -o Makefile && make

run:
	./src/icp

doxygen:
	doxygen src/doxyfile

pack: clean
	zip -r xgajdo26-xvajco00.zip src doc Makefile README.txt examples

clean:
	rm -rfv src/*.o
	rm -rfv src/moc_*
	rm -rfv doc/*
	rm -rfv xgajdo26-xvajco00.zip
	rm -rfv src/icp
