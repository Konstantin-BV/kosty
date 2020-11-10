class MyList
{
	MyList();
	void push_back(int); // add to the end of the list
	void push_front(int); // add to the top of the list
	void pop_back(); // deleting the last element
	void pop_front();  // deleting the first element
	void insert(int, size_t);// adding an item by index
	int at(size_t);// getting an item by index
	void remove(size_t); // deleting an item by index
	size_t get_size();// getting the list size
	void print_to_console();// output list items to the console using a separator, do not use at
	void clear();// delete all list items
	void set(size_t, int);// replacing an element by index with the passed element
	bool isEmpty(); // checking if the list is empty
	void reverse(); // changes the order of items in the list
};