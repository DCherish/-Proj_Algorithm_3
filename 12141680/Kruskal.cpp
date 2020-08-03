#include <iostream>
#include <stack>
#include <vec>
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

bool isCycle(vector <vector <int>> connect, int N) // Cycle �˻�
{
	stack <int> store ; // stack �̿�

	for( int i = 0 ; i < N ; i++ )
	{
		vector <bool> visited(N, false) ; // false �ʱ�ȭ

		if( connect[i].size() != 0 )
		{
			store.push(i) ; // stack�� ����

			while( !store.empty() )
			{
				int visit = store.top() ;

				store.pop() ; // �� �� �� pop

				if( visited[visit] == false ) // �湮�� ���� ���ٸ�
				{
					visited[visit] = true ; // �湮�ߴٰ� ǥ��

					for( int j = 0 ; j < connect[visit].size() ; j++ )
					{
						if( visited[connect[visit][j]] == false ) // ���� �湮�� ���� ���ٸ�
						{
							store.push(connect[visit][j]) ; // stack�� ����
						}
					}
				}else // �湮�� ���� �ִٸ�
				{
					return true ; // ����Ŭ�� ����
				}
			}
		}
	}

	return false ; // ����Ŭ�� ����
}

void kruskal(priority_queue <Path> &pathk, int N)
{
	vector <vector <int>> connect(N) ; // connect ; 2d array

	vector <Path> result ; // result ; array

	while( !pathk.empty() )
	{
		Path temp ; // struct
		temp = pathk.top() ; // PQ �� �� ��
		pathk.pop() ; // PQ �� �� �� pop

		connect[temp.node1].push_back(temp.node2) ; // node1 - node2 ����Ǿ� �ִٸ�
		connect[temp.node2].push_back(temp.node1) ; // node2 - node1 ���� ����Ǿ� ����

		if( !isCycle(connect, N) ) // cycle ���� �˻�, kruskal �ٽ�
		{
			result.push_back(temp) ; // ����Ŭ�� ���ٸ� result�� ����
		}else // ����Ŭ�� �ִٸ�
		{
			connect[temp.node1].pop_back() ;
			connect[temp.node2].pop_back() ; // �� ���� ����
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
	cout << "12141680 Kruskal" << endl << endl ;

	int N, L ;
	cin >> N >> L ; // ��� ����, ���� ���� �Է�

	priority_queue <Path> pathk ; // path ; struct PQ

	vector <vector <int> > graph(N) ; // graph ; 2d array 
	vector <bool> visited(N) ; // visited ; array

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
		pathk.push(temp) ;
	}
	
	cout << endl ;

	kruskal(pathk, N) ; // Kruskal

	return 0 ;
}