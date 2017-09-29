#include<iostream>
using namespace std;
const int MaxSize = 100;
class SeqList {
private:
	int data[MaxSize];
	int length;
public:
	SeqList() { length = 0; }
	SeqList(int a[], int n);
	~SeqList() {};
	int Length() { return length; }
	int Get(int i);
	int Locate(int x);
	void Insert(int i, int x);
	int Delete(int i);
	void PrintList();
};
void main()
{
	int array[] = { 123,426,654,2,6,56,7,3 };
	SeqList S(array,8);
	cout << "以下是默认输出:" << endl;
	S.PrintList();
	cout << "进行顺序表的按位查找操作,请输入要查找的位：";
	int wei;
	cin >> wei;
	S.Get(wei);
	cout << "下面进行按值查找，请输入你要查找的值:";
	int value;
	cin >> value;
	cout<<"你查找的位置："<<S.Locate(value)<<endl;
	cout << "下面进行插入值操作，请输入插入的位置，插入的数值,中间以空格隔开;" << endl;
	int x, y;
	cin >> x;
	cin >> y;
	cout << "你插入的位置是:" << x << ";你插入数值为:" << y << endl;
	S.Insert(x, y);
	S.PrintList();
	cout << "下面进行删除操作，请输入删除的位置，删除成功返回删除的元素";
	int del;
	cin >> del;
	cout<<S.Delete(del)<<endl;
	S.PrintList();
	system("pause");
}

SeqList::SeqList(int a[], int n)
{
	if (n > MaxSize)throw"非法参数";
	for (int i = 0; i < n; i++)
	{
		data[i] = a[i];
	}
	length = n;
}

int SeqList::Get(int i)
{
	if (i<1 && i>length)throw"输入的序列不再其中！";
	else
	{
		cout << "查到的值为：" << data[i - 1]<<endl;
		return data[i - 1];
	}
}
int SeqList::Locate(int x)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == x) { return i+1; }
	}
	return 0;
}
void SeqList::Insert(int i, int x)
{
	if (i < 1 && i>length)throw"插入顺序错误！";
	else if (length >= MaxSize)throw"储存空间已满！";
	else {
		for (int j = length; j>i; j--)
		{
			data[length] = data[length - 1];
		}
		data[i - 1] = x;
		length++;
	}
}
int SeqList::Delete(int i)
{
	if (i <= 0 && i > length)throw"删除位置错误！";
	int result = data[i-1];
	for (int j = i; j <length; j++)
	{
		data[j - 1] = data[j];
	}
	length--;
	return result;
}
void SeqList::PrintList()
{
	for (int j = 0; j < length-1; j++)
	{
		cout << data[j] << "--";
	}
	cout << data[length - 1] << endl;
}


