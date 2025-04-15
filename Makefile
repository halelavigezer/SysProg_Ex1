# קובץ Makefile
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# קבצי קוד מקור
SRC = main.cpp Algorithms.cpp Graph.cpp Node_V.cpp Queue.cpp PriorityQueue.cpp myunionfind.cpp test_Algorithms.cpp

# קבצי אובייקטים
OBJ = $(SRC:.cpp=.o)

# קובץ הביצוע
EXEC = runApp

# יעד ברירת מחדל (יצירת הביצוע)
all: $(EXEC)

# יצירת האובייקטים
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# יצירת קובץ הריצה
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

# מטרת הריצה של הטסטים
runTests: $(OBJ)
	$(CXX) $(CXXFLAGS) -o runTests $(OBJ)
	./runTests

# מטרת ניקוי
clean:
	rm -f $(OBJ) $(EXEC) runTests
