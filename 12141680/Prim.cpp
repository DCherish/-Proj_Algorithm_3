#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std ;

typedef struct Path
{
	int node1 ;
	int node2 ;
	int cost ;

	bool operator<(const Path &o) const  // operation overloading
	{
		return cost > o.cost ;
	}
} Path ;

void prim(vector <vector <Path> > pathp, int N)
{
	vector <Path> result ;
	vector <bool> visited(N, false) ; // false �ʱ�ȭ
	priority_queue <Path> PQ ;

	int i = 0 ;

	visited[i] = true ; // �� �� �� �湮�ߴٰ� ǥ��

	for( int j = 0 ; j < pathp[i].size() ; j++ )
	{
		if( visited[pathp[i][j].node2] == false ) // �湮�� ���� ���ٸ�
		{
			PQ.push(pathp[i][j]) ; // PQ�� ����
		}
	}

	while( !PQ.empty() )
	{
		Path temp = PQ.top() ; // PQ �� �� ��
		PQ.pop() ; // PQ �� �� �� pop

		i = temp.node2 ;

		if( visited[i] == false ) // �湮�� ���� ���ٸ�
		{
			result.push_back(temp) ; // result�� ����

			visited[temp.node2] = true ; // �湮�ߴٰ� ǥ��

			for( int j = 0 ; j < pathp[i].size() ; j++ )
			{
				if( visited[pathp[i][j].node2] == false ) // �湮�� ���� ���ٸ�
				{
					PQ.push(pathp[i][j]) ; // PQ�� ����
				}
			}
		}
	}

	for( int i = 0 ; i < result.size() ; i++ ) // operation overloading
	{
		cout << result[i].node1+1 << " " << result[i].node2+1 << " " << result[i].cost << endl ;
	} // ����Ŭ�� ���� �ּ� ��� ���� ���

	cout << endl ;
}

int main()
{
	cout << "12141680 Prim" << endl << endl ;

	int N, L ;
	cin >> N >> L ; // ��� ����, ���� ���� �Է�

	vector < vector <Path> > pathp(N) ; // pathp ; 2d struct array 

	for( int i = 0 ; i < L ; i++ )
	{
		int h ;
		int t ;
		int cost ;
		Path temp ;
		cin >> h >> t >> cost ; // ���� ���� ���, �� ���, ���� ���� cost ����
		temp.node1 = h - 1 ; // ���� ��� tempnode1
		temp.node2 = t - 1 ; // �� ��� tempnode2
		temp.cost = cost ; // ���� ���� cost
		pathp[h-1].push_back(temp) ;// node1 - node2 ����Ǿ� �ִٸ�
		temp.node1 = t - 1 ;
		temp.node2 = h - 1 ;
		pathp[t-1].push_back(temp) ;// node2 - node1 ���� ����Ǿ� ����
	}

	cout << endl ;

	prim(pathp, N) ; // Prim

	return 0 ;
}
