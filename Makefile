as=/usr/bin/as
cc=/usr/bin/g++
ld=/usr/bin/ld

sources=
basic_source=fl_device_info.cpp
objects=$(sources:.cpp=.o)
basic_objects=$(basic_source:.cpp=.o)

app=$(sources:.cpp=)
src_headers= 
basic_app=$(basic_source:.cpp=)
cflags=-std=c++11
gtkcflags=`pkg-config --cflags --libs gtk+-2.0`
mysqlcflags=$(mysql_config --cflags --libs)
fltkflags=`fltk-config --cxxflags` `fltk-config --ldflags` 
fltkother=`fltk-config --use-images --ldflags`
wxflags=`wx-config --cxxflags --libs`
sfmlflags=-lsfml-graphics -lsfml-window -lsfml-system
basic_app:
	$(cc) -c $(basic_source) $(fltkother) 
	$(cc)  -o $(basic_app) $(basic_objects) $(fltkother)
clean:
	rm $(basic_app)
