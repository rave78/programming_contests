SOLUTIONS := $(subst uva, solution, $(wildcard uva*))

.PHONY: all

all: $(SOLUTIONS)
	@echo 'Done'

solution%:  
	g++ $(subst solution, uva, $@)/$@.cpp -o $@ 


clean:
	@rm -v $(SOLUTIONS)
