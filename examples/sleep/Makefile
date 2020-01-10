CXX := g++-8
CXXFLAGS := -Wall

TARGET := sleep.out

$(TARGET): sleep.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
