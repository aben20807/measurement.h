CXX := g++
CXXFLAGS := -Wall

TARGET := sleep.out

$(TARGET): sleep.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
