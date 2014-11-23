rbt: main.o RedBlackTree.o
	clang++ main.o RedBlackTree.o -o rbt

RedBlackTree.o: RedBlackTree.cpp
	clang++ -c RedBlackTree.cpp -std=c++1y -stdlib=libc++

main.o: main.cpp
	clang++ -c main.cpp -std=c++1y -stdlib=libc++

clean:
	rm *.o
