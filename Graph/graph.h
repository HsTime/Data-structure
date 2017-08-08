#pragma once
#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<string>
#include<assert.h>

template<class V, class W, size_t N, bool IsDirector = false>
class GraphMartix
{
public:
	GraphMartix(V* vertexs)
	{
		for (size_t i = 0; i < N; i++)
		{
			_vectexs[i] = vertexs[i];
		}


		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				_martix[i][j] = W();
			}
		}
	}

	size_t GetVertexIndex(const V& v)
	{
		for (size_t i = 0; i < N; i++)
		{
			if (_vectexs[i] == v)
				return i;
		}
		assert(false);
		return 0;
	}

	void AddEdge(const V& src, const V& dst, const W& w)
	{
		size_t srcIndex = GetVertexIndex(src);
		size_t dstIndex = GetVertexIndex(dst);

		_martix[srcIndex][dstIndex] = w;
		if (IsDirector == false)
		{
			_martix[dstIndex][srcIndex] = w;
		}
	}

protected:
	V _vectexs[N];//���㼯��
	W _martix[N][N];//�ߵļ���
};

void TestGraphMartix()
{
	string address[] = { "�ƴ�ͼ���", "�ƴ���Ӿ��", "����", "������", "����" };
	GraphMartix<string, size_t, sizeof(address) / sizeof(address[0])> gm(address);
	gm.AddEdge("�ƴ�ͼ���", "�ƴ���Ӿ��", 1000);
	gm.AddEdge("����", "������", 1500);
	gm.AddEdge("����", "�ƴ���Ӿ��", 100);
}


template<class W>
struct LinkEdge
{
	W _w;//Ȩֵ
	size_t _src;
	size_t _dst;
	LinkEdge<W>* _next;

	LinkEdge(size_t src, size_t dst, const W& w)
		:_src(src)
		, _dst(dst)
		, _w(w)
		, _next(NULL)
	{}
};


template<class V, class W, size_t N, bool IsDirector = false>
class GreaphLink
{
	typedef LinkEdge<W> Edge;
public:
	GreaphLink(V* vertexs)
	{
		for (size_t i = 0; i < N; i++)
		{
			_vertexs.push_back(vertexs[i]);
		}

		LinkTable.resize(N, NULL);
	}
	size_t GetVertexIndex(const V& v)
	{
		for (size_t i = 0; i < N; i++)
		{
			if (_vertexs[i] == v)
				return i;
		}
		assert(false);
		return 0;
	}

	/*void AddEdge(const V& src, const V& dst, const W& w)
	{
		size_t srcIndex = GetVertexIndex(src);
		size_t dstIndex = GetVertexIndex(dst);
		if (LinkTable[srcIndex] == NULL)
			LinkTable[srcIndex] = new Edge(srcIndex, dstIndex, W());
		Edge* cur = LinkTable[srcIndex];
		Edge* ptr = new Edge(dstIndex, srcIndex, w);
		while (cur->_next != NULL)
			cur = cur->_next;
			cur->_next = ptr;

		if (IsDirector == false)
		{
			if (LinkTable[dstIndex] == NULL)
				LinkTable[dstIndex] = new Edge(dstIndex, srcIndex, W());

			Edge* cur = LinkTable[dstIndex];
			Edge* ptr = new Edge(srcIndex, dstIndex, w);
			while (cur->_next != NULL)
				cur = cur->_next;
				cur->_next = ptr;
		}

	}*/

	void DFS()
	{

	}
	void BFS(const V& src)
	{
		queue<size_t> q;
		q.push(GetVertexIndex(src));
		vector<bool> visited;
		visited.resize(N, false);
		while (!q.empty())
		{
			size_t first = q.front();
			q.pop();
			if (!visited[first])
			{
				Edge* cur = LinkTable[first];
				cout << _vertexs[first] << " ";
				visited[first] = true;
				while (cur)
				{
					if (visited[cur->_dst] == false)
					{
						q.push(cur->_dst);
					}
					cur = cur->_next;
				}
			}

		}
		cout << endl;
	}

protected:
	vector<V> _vertexs;       //���㼯��
	vector<Edge*> LinkTable;  //�ߵļ���
};

void TestGraph()
{
	string address[] = { "�ƴ�ͼ���", "�ƴ���Ӿ��", "����", "������", "����" };
	GreaphLink<string, size_t, sizeof(address) / sizeof(address[0])> gm(address);
	gm.AddEdge("�ƴ�ͼ���", "�ƴ���Ӿ��", 1000);
	gm.AddEdge("����", "������", 1500);
	gm.AddEdge("����", "�ƴ���Ӿ��", 100);
	gm.BFS("�ƴ�ͼ���");
}