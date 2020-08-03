#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std ;

void NodeBFS(vector <vector <int> > graph, vector <bool> visited) // BFS �湮 ���
{
	for( int i = 0 ; i < visited.size() ; i++ ) // �ʱ�ȭ
	{
		visited[i] = false ;
	}

	queue <int> store ; // queue �̿�

	int index = 0 ;

	store.push(index) ; // �ʱ� �� queue�� ����

	cout << "BFSNode : " ;

	while( !store.empty() )
	{
		int visit = store.front() ;

		store.pop() ; // �� �� �� pop

		if( visited[visit] == false ) // ���� �湮�� ���� ���ٸ�
		{
			visited[visit] = true ; // �湮�ߴٰ� ǥ��

			cout << visit+1 << " " ; // �湮 ��� ���
			
			for( int i = 0 ; i < graph[visit].size() ; i++ ) // BFS
			{
				if( visited[graph[visit][i]] == false ) // ���� �湮�� ���� ���ٸ�
				{
					store.push(graph[visit][i]) ; // queue�� ����
				}
			}
		}
	}
	cout << endl << endl ;
}

void LineBFS(vector <vector <int> > graph, vector <bool> visited) // BFS ���� ���
{
	for( int i = 0 ; i < visited.size() ; i++ ) // �ʱ�ȭ
	{
		visited[i] = false ;
	}

	queue <int> store ; // queue �̿�

	int index = 0 ;

	store.push(index) ; // �ʱ� �� queue�� ����

	cout << "-> BFSLine :" << endl ;

	while( !store.empty() )
	{
		int visit = store.front() ;

		store.pop() ; // �� �� �� pop (Queue -> �� �� pop)

		visited[visit] = true ; // �� �� �� �湮�ߴٰ� ǥ��

		for( int i = 0 ; i < graph[visit].size() ; i++ ) // BFS
		{
			if( visited[graph[visit][i]] == false ) // ���� �湮�� ���� ���ٸ�
			{
				visited[graph[visit][i]] = true ; // �湮�ߴٰ� ǥ��
				store.push(graph[visit][i]) ; // queue�� ����
				cout << "(" << visit+1 << ") - (" << graph[visit][i]+1 << ")" << endl ; // ������ ���
			}
		}
	}
	cout << endl ;
}

void NodeDFS(vector <vector <int> > graph, vector <bool> visited) // DFS �湮 ���
{
	for( int i = 0 ; i < visited.size() ; i++ ) // �ʱ�ȭ
	{
		visited[i] = false ;
	}

	stack <int> store ; // stack �̿�

	int index = 0 ;

	store.push(index) ; // �ʱ� �� stack�� ����

	cout << "DFSNode : " ;

	while( !store.empty() )
	{
		int visit = store.top() ;

		store.pop() ; // �� �� �� pop

		if( visited[visit] == false ) // ���� �湮�� ���� ���ٸ�
		{
			visited[visit] = true ; // �湮�ߴٰ� ǥ��

			cout << visit+1 << " " ; // �湮 ��� ���

			for( int i = 1 ; i < graph[visit].size() ; i++ )
			{
				if( visited[graph[visit][i]] == false ) // ���� �湮�� ���� ���ٸ�
				{
					store.push(graph[visit][i]) ; // stack�� ����
				}
			}
		}
	}
	cout << endl << endl ;
}

void LineDFS(vector <vector <int> > graph, vector <bool> visited) // DFS ���� ���
{
	for( int i = 0 ; i < visited.size() ; i++ ) // �ʱ�ȭ
	{
		visited[i] = false ;
	}

	stack <int> store ; // stack �̿�

	int index = 0 ;

	store.push(index) ;
	store.push(index) ; // �ʱ� �� stack ����

	cout << "-> DFSLine :" << endl ;

	while( !store.empty() )
	{
		int visit = store.top() ; // ���� ��

		store.pop() ; // ���� �� pop
		store.pop() ; // ���� ���̶� ����� ��� pop

		if( visited[visit] == false ) // ���� �湮�� ���� ���ٸ�
		{
			visited[visit] = true ; // �湮�ߴٰ� ǥ��

			for( int i = 0 ; i < graph[visit].size() ; i++ )
			{
				store.push(visit) ; // ���� ���̶� ����� ��� ����
				store.push(graph[visit][i]) ; // ���� �� ����
			}

			if( !store.empty() ) // ���� stack�� ������� �ʴٸ�
			{
				while( visited[store.top()] == true ) // ���� �湮�ߴ� ���� �ִٸ�
				{
					store.pop() ; // ���� �� pop
					store.pop() ; // ���� ���̶� ����� ��� pop
					if( store.empty() ) break ; // pop ����, stack�� empty�ϴٸ� ����
				}

				if( store.empty() ) break ; // stack�� ����ִٸ� ����
				
				int k2 = store.top() ; // ���� ��
				store.pop() ; // ���� �� pop

				int k1 = store.top() ; // ���� ���̶� ����� ���
				
				cout << "(" << k1+1 << ") - (" << k2+1 << ")" << endl ; // ���� ���
				store.push(k2) ; // �ٽ� ���� ���� ����
			}
		}
	}
	cout << endl ;
}

int main()
{
	cout << "12141680 BFSDFS" << endl << endl ;

	int N, L ;
	cin >> N >> L ; // ��� ����, ���� ���� �Է�

	vector <vector <int> > graph(N) ; // graph ; 2d array
	vector <bool> visited(N) ; // visited ; array

	for( int i = 0 ; i < L ; i++ )
	{
		int h ;
		int t ;
		cin >> h >> t ; // ���� ���� ���, �� ��� ����
		graph[h-1].push_back(t-1) ; // ex) 1 - 3 �� ����Ǿ� �ִٸ�
		graph[t-1].push_back(h-1) ; // ex) 3 - 1 ���� ����Ǿ� ����
	}

	cout << endl ;

	NodeBFS(graph, visited) ; // BFS �湮 ���
	LineBFS(graph, visited) ; // BFS ���� ���
	NodeDFS(graph, visited) ; // DFS �湮 ���
	LineDFS(graph, visited) ; // DFS ���� ���

	return 0 ;
}