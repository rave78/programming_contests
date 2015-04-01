all: uva100 uva272 uva394 uva483 uva573

uva100: 
	    g++ Uva100/solution100.cpp -o solution100

uva272: 
	    g++ Uva272/solution272.cpp -o solution272
	    
uva394: 
	    g++ Uva394/solution394.cpp -o solution394

uva483: 
	    g++ Uva483/solution483.cpp -o solution483

uva573: 
	    g++ Uva573/solution573.cpp -o solution573

clean:
		rm solution*