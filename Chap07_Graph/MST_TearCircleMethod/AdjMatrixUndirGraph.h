#pragma once
//STL
#include <vector>
//Current Project
#include "Assistance.h"

// ����ͼ���ڽӾ�����
template <class T>
struct AdjMatrixUndirGraph
{

// �ڽӾ�������ݳ�Ա:
	int vexNum, vexMaxNum, arcNum;			// ������Ŀ������Ķ��������Ŀ�ͱ���
	int **arcs;							    // ��ű���Ϣ�ڽӾ���
	T *vertexes;						// ��Ŷ�����Ϣ������
	mutable Status *tag;					// ��־����


// �ڽӾ������͵ķ�������:
	AdjMatrixUndirGraph(T es[], int vertexNum, int vertexMaxNum = DEFAULT_SIZE);
		// ������es[]Ϊ����,�������ΪvertexNum,����Ķ��������ĿΪvertexMaxNum,����Ϊ0������ͼ
	AdjMatrixUndirGraph(int vertexMaxNum = DEFAULT_SIZE);
		// ��������Ķ��������ĿΪvertexMaxNum,����Ϊ0������ͼ
	~AdjMatrixUndirGraph();					// ��������
	void Clear();			              // ���ͼ
	bool IsEmpty();                 // �ж�����ͼ�Ƿ�Ϊ��
	int GetOrder(T &d) const;// �󶥵�����
	Status GetElem(int v, T &d) const;// �󶥵��Ԫ��ֵ
	Status SetElem(int v, const T &d);// ���ö����Ԫ��ֵ
	int GetVexNum() const;					// ���ض������
	int GetArcNum() const;					// ���ر���
	int FirstAdjVex(int v) const;		// ���ض���v�ĵ�һ���ڽӵ�
	int NextAdjVex(int v1, int v2) const;		 // ���ض���v1�������v2����һ���ڽӵ�
	void InsertVex(const T &d);			 // ����Ԫ��ֵΪd�Ķ���
	void InsertArc(int v1, int v2, int arc[][6]);			     // ���붥��Ϊv1��v2�ı�
	void DeleteVex(const T &d);			 // ɾ��Ԫ��ֵΪd�Ķ���
	void DeleteArc(int v1, int v2);			     // ɾ������Ϊv1��v2�ı�
	Status GetTag(int v) const;			         // ���ض���v�ı�־
	void SetTag(int v, Status val) const;	   // ���ö���v�ı�־Ϊval
	AdjMatrixUndirGraph(const AdjMatrixUndirGraph<T> &g);	// ���ƹ��캯��
	AdjMatrixUndirGraph<T> &operator =(const AdjMatrixUndirGraph<T> &g);
		// ��ֵ�������
    void Display();	                         // ��ʾ�ڽӾ�������ͼ
};

// ����ͼ���ڽӾ������ʵ�ֲ���
template <class T>
AdjMatrixUndirGraph<T>::AdjMatrixUndirGraph(T es[], int vertexNum, int vertexMaxNum)
// �����������������Ԫ��Ϊes[],�������ΪvertexNum,����Ķ��������ĿΪvertexMaxNum,����Ϊ0������ͼ

{
	if (vertexMaxNum < 0)
    	throw Error("����Ķ��������Ŀ����Ϊ��!");        // �׳��쳣

	if (vertexMaxNum < vertexNum)
    	throw Error("������Ŀ���ܴ�������Ķ��������Ŀ!");// �׳��쳣

	vexNum = vertexNum;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;

	vertexes = new T[vexMaxNum];      // �������ɶ�����Ϣ����
	tag = new Status[vexMaxNum];			       // ���ɱ�־����
	arcs = (int **)new int *[vexMaxNum];     // �����ڽӾ���
	for (int v = 0; v < vexMaxNum; v++)
		arcs[v] = new int[vexMaxNum];

	for (int v = 0; v < vexNum; v++) {
		vertexes[v] = es[v];
		tag[v] = UNVISITED;
		for (int u = 0; u < vexNum; u++)
			arcs[v][u] = 0;
	}
}

template <class T>
AdjMatrixUndirGraph<T>::AdjMatrixUndirGraph(int vertexMaxNum)
// �������������������������ĿΪvertexMaxNum�Ŀ�����ͼ
{
	if (vertexMaxNum < 0)
    	throw Error("����Ķ��������Ŀ����Ϊ��!");// �׳��쳣

	vexNum = 0;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;

	vertexes = new T[vexMaxNum];     // �������ɶ�����Ϣ����
	tag = new Status[vexMaxNum];			      // ���ɱ�־����
	arcs = (int **)new int *[vexMaxNum];    // �����ڽӾ���
	for (int v = 0; v < vexMaxNum; v++)
		arcs[v] = new int[vexMaxNum];
 }

template <class T>
void AdjMatrixUndirGraph<T>::Clear()
// ���������������ͼ�Ķ������ͱ�������Ϊ0.
{
    vexNum = 0;
	arcNum = 0;
}

template <class T>
bool AdjMatrixUndirGraph<T>::IsEmpty()
// ����������������ͼΪ�շ���true,���򷵻�false.
{
	return vexNum == 0;
}

template <class T>
AdjMatrixUndirGraph<T>::~AdjMatrixUndirGraph()
// ����������ͷŶ�����ռ�õĿռ�
{
	delete []vertexes;					// �ͷŶ�������
	delete []tag;						    // �ͷű�־

	for (int v = 0; v < vexMaxNum; v++)	// �ͷ��ڽӾ������
		delete []arcs[v];
	delete []arcs;					    // �ͷ��ڽӾ���
}

template <class T>
int AdjMatrixUndirGraph<T>::GetOrder(T &d) const
// ����������󶥵�d�����.�������Ŵ�0��ʼ��ͼ�в����ڶ���dʱ������-1.
{
    for (int v = 0; v < vexNum; v++)
        if (vertexes[v] == d)
		   return v;	    // ����d����,�����������
	return -1;	        // ����d������,����-1
}

template <class T>
Status AdjMatrixUndirGraph<T>::GetElem(int v, T &d) const
// ��������������Ϊv�Ķ���ֵ, v��ȡֵ��ΧΪ0 �� v �� vexNum, v�Ϸ�ʱ����
// ͨ��dȡ�ö���ֵ��������ENTRY_FOUND������������NOT_PRESENT
{
	if (v < 0 || v >= vexNum)
		return NOT_PRESENT;	// v��Χ��,����Ԫ�ز�����
	else	{
		d = vertexes[v];	  // ������v��Ԫ��ֵ����d
		return ENTRY_FOUND;	// ����Ԫ�ش���
	}
}

template <class T>
Status AdjMatrixUndirGraph<T>::SetElem(int v, const T &d)
// ������������ö����Ԫ��ֵv��ȡֵ��ΧΪ0 �� v �� vexNum, v�Ϸ�ʱ��������
//	SUCCESS, ����������RANGE_ERROR
{
	if (v < 0 || v >= vexNum)
		return RANGE_ERROR;	// v��Χ��,����λ�ô�
	else	{
		vertexes[v] = d;		// ������Ԫ�ص�ֵ��Ϊd
		return SUCCESS;		  // �����޸ĳɹ�
	}
}

template <class T>
int AdjMatrixUndirGraph<T>::GetVexNum() const
// ������������ض������
{
	return vexNum;
}

template <class T>
int AdjMatrixUndirGraph<T>::GetArcNum() const
// ������������ر���
{
	return arcNum;
}

template <class T>
int AdjMatrixUndirGraph<T>::FirstAdjVex(int v) const
// ������������ض���v�ĵ�1���ڽӵ�����
{
	if (v < 0 || v >= vexNum)
       throw Error("v���Ϸ�!");// �׳��쳣

	for (int u = 0; u < vexNum; u++)
		if (arcs[v][u] != 0)
       return u;

	return -1;					// ����-1��ʾ���ڽӵ�
}

template <class T>
int AdjMatrixUndirGraph<T>::NextAdjVex(int v1, int v2) const
// ������������ض���v1�������v2����һ���ڽӵ�
{
	if (v1 < 0 || v1 >= vexNum)
       throw Error("v1���Ϸ�!");	// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
       throw Error("v2���Ϸ�!");	// �׳��쳣
	if (v1 == v2) throw
       Error("v1���ܵ���v2!");		// �׳��쳣

	for (int u = v2 + 1; u < vexNum; u++)
		if (arcs[v1][u] != 0)
       return u;

	return -1;						// ����-1��ʾ����һ���ڽӵ�
}

template <class T>
void AdjMatrixUndirGraph<T>::InsertVex(const T &d)
// ������������붥��d
{
	if (vexNum == vexMaxNum)
    throw Error("ͼ�Ķ��������ܳ�������������!");	// �׳��쳣

	vertexes[vexNum] = d;
	tag[vexNum] = UNVISITED;
	for (int v = 0; v <= vexNum; v++) {
		arcs[vexNum][v] = 0;
		arcs[v][vexNum] = 0;
  }
  vexNum++;
}

template <class T>
void AdjMatrixUndirGraph<T>::InsertArc(int v1, int v2, int arc[][6])
// ���������������������v1��v2�ı�
{
	if (v1 < 0 || v1 >= vexNum)
    throw Error("v1���Ϸ�!");	// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
    throw Error("v2���Ϸ�!");	// �׳��쳣
	if (v1 == v2)
    throw Error("v1���ܵ���v2!");// �׳��쳣

	if (arcs[v1][v2] == 0)	{	  // ԭ����ͼ��û�б�(v1, v2)
	   arcNum++;
	   arcs[v1][v2] = arc[v1][v2];
       arcs[v2][v1] = arc[v2][v1];
    }
}

template <class T>
void AdjMatrixUndirGraph<T>::DeleteVex(const T &d)
// ���������ɾ��Ԫ��Ϊd�Ķ���
{
   int v;
   for (v = 0; v < vexNum; v++)
     if	(vertexes[v] == d)
        break;
   if (v == vexNum)
      throw Error("ͼ�в�����Ҫɾ���Ķ���!");	// �׳��쳣

   for (int u = 0; u < vexNum; u++)             // ɾ���붥��d������ı�
	  if (arcs[v][u] == 1) {
		arcNum--;
	    arcs[v][u] = 0;
        arcs[u][v] = 0;
    }

   vexNum--;
   if (v < vexNum) {
      vertexes[v] = vertexes[vexNum];
	  tag[v] = tag[vexNum];
	  for (int u = 0; u <= vexNum; u++)
		 arcs[v][u] = arcs[vexNum][u];
	  for (int u = 0; u <= vexNum; u++)
         arcs[u][v] = arcs[u][vexNum];
   }
}

template <class T>
void AdjMatrixUndirGraph<T>::DeleteArc(int v1, int v2)
// ���������ɾ����������v1��v2�ı�
{
	if (v1 < 0 || v1 >= vexNum)
    throw Error("v1���Ϸ�!");	// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
    throw Error("v2���Ϸ�!");	// �׳��쳣
	if (v1 == v2)
    throw Error("v1���ܵ���v2!");// �׳��쳣

	if (arcs[v1][v2] != 0)	{	// ԭ����ͼ���ڱ�(v1, v2)
		arcNum--;
	    arcs[v1][v2] = 0;
        arcs[v2][v1] = 0;
    }
}

template <class T>
Status AdjMatrixUndirGraph<T>::GetTag(int v) const
// ������������ض���v�ı�־
{
	if (v < 0 || v >= vexNum)
    throw Error("v���Ϸ�!");	// �׳��쳣

	return tag[v];
}

template <class T>
void AdjMatrixUndirGraph<T>::SetTag(int v, Status val) const
// ������������ö���v�ı�־Ϊval
{
	if (v < 0 || v >= vexNum)
    throw Error("v���Ϸ�!");	// �׳��쳣

	tag[v] = val;
}

template <class T>
AdjMatrixUndirGraph<T>::AdjMatrixUndirGraph(const AdjMatrixUndirGraph<T> &g)
// ���������������ͼ���ڽӾ���g����������ͼ���ڽӾ���g�������ƹ��캯��
{
	vexNum = g.vexNum;
	vexMaxNum = g.vexMaxNum;
	arcNum = g.arcNum;

	vertexes = new T[vexMaxNum];		// ���ɶ�����������
	tag = new Status[vexMaxNum];			// ���ɱ�־����
	arcs = (int **)new int *[vexMaxNum];	// �����ڽӾ���
	for (int v = 0; v < vexMaxNum; v++)
		arcs[v] = new int[vexMaxNum];

	for (int v = 0; v < vexNum; v++)	{	// ���ƶ�����������
		vertexes[v] = g.vertexes[v];
		tag[v] = g.tag[v];
		for (int u = 0; u < vexNum; u++)
			arcs[v][u] = g.arcs[v][u];
	}
}

template <class T>
AdjMatrixUndirGraph<T> &AdjMatrixUndirGraph<T>::operator =(const AdjMatrixUndirGraph<T> &g)
// ���������������ͼ���ڽӾ���g��ֵ����ǰ����ͼ���ڽӾ��󡪡���ֵ�������
{
	if (&g != this)	{
	  delete []vertexes;				// �ͷŶ�������
	  delete []tag;						  // �ͷű�־

	  for (int v = 0; v < vexMaxNum; v++)	// �ͷ��ڽӾ������
       delete []arcs[v];
    delete []arcs;					  // �ͷ��ڽӾ���
	  vexNum = g.vexNum;
    vexMaxNum = g.vexMaxNum;
	  arcNum = g.arcNum;

	  vertexes = new T[vexMaxNum];	 // ���ɶ�����������
	  tag = new Status[vexMaxNum];			   // ���ɱ�־����
	  arcs = (int **)new int *[vexMaxNum]; // �����ڽӾ���
	  for (int v = 0; v < vexMaxNum; v++)
		  arcs[v] = new int[vexMaxNum];

	  for (int v = 0; v < vexNum; v++)	{	 // ���ƶ�����������
		  vertexes[v] = g.vertexes[v];
		  tag[v] = g.tag[v];
		  for (int u = 0; u < vexNum; u++)
		    arcs[v][u] = g.arcs[v][u];
	  }
	}
	return *this;
}

template <class T>
void AdjMatrixUndirGraph<T>::Display()
// �������: ��ʾ�ڽӾ�������ͼ
{
	for (int v = 0; v < vexNum; v++)
 		cout << "\t" << vertexes[v];
	cout << endl;

	for (int v = 0; v < vexNum; v++)	{
		cout << vertexes[v];
		for (int u = 0; u < vexNum; u++)
 			cout << "\t" << arcs[v][u];
		cout << endl;
	}
}
