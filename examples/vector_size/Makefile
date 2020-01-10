CXX := g++-8
OPT := 0
CXXFLAGS := -O$(OPT)

TARGET := test.out

$(TARGET): test.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

run: $(TARGET)
	./$(TARGET) $(OPT) 1>/dev/null

combine:
	paste f1_O$(OPT)*.txt > f1_O$(OPT).txt
	paste f2_O$(OPT)*.txt > f2_O$(OPT).txt

clean:
	rm -f $(TARGET)

clean-txt:
	rm -f *.txt
