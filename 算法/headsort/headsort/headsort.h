class HeapSort 
{

public:
	void Sort(int* dataArr, int size);
	void build_heap(int* dataArr,int size);
	void max_heap(int* dataArr,int curIndex,int size);

	int get_parent(int curIndex);
	int get_left(int curIndex);
	int get_right(int curIndex);

	void swap(int* dataArr,int aIndex,int bIndex);

	void show(int* dataArr,int size);

};
