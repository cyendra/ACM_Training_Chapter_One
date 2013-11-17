#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#define MAX_SIZE 2000
using namespace std;

vector<int>list[MAX_SIZE];
stack<int>stk;

bool dfs(int x);

bool visit[MAX_SIZE];
int X[MAX_SIZE];
int Y[MAX_SIZE];

int size_x;
int size_y;

bool dfs(int x)
{
    vector<int>::iterator it;
	stk.push(x);
	for (it = list[x].begin(); it<list[x].end(); it++)
	{
		if (visit[ *it ]==false)
		{
			visit[ *it ] = true;
			stk.push( *it );
			if (Y[ *it ]==0 || dfs(Y[ *it ])==true)
				return true;
			else
				stk.pop();
		}
	}
	stk.pop();
	return false;

}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF && n!=0)
    {
        scanf("%d%d",&size_x,&size_y);

        //init
        for (int i=1; i<=size_x; i++)
        {
            list[i].clear();
        }

        memset(X,0,sizeof(X));
        memset(Y,0,sizeof(Y));

        //input
        int x,y;
        for (int i=1; i<=n; i++)
        {
            scanf("%d%d",&x,&y);
            list[x].push_back(y);
        }

        //solve
        int top;
        for (int i=1; i<=size_x; i++)
        {
            while ( !stk.empty() ) stk.pop();
            memset(visit,false,sizeof(visit));
            if (dfs(i)==true)
            {
                while ( !stk.empty() )
                {
                    top=stk.top();
                    stk.pop();
                    Y[top]=stk.top();
                    X[stk.top()]=top;
                    stk.pop();
                }
            }
        }

        //output
        int ans=0;
        for (int i=1; i<=size_x; i++)
        {
            if ( X[i]>0 ) ans++;
        }
        printf("%d\n",ans);

        while ( !stk.empty() ) stk.pop();
    }
    return 0;
}

/*
#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef struct node
{
    int ord;
    node * next;
} Node;

const int size = 512 + 1;

Node list[size];
int	X[size];
int	Y[size];
bool visit[size];
int	size_x;
int	size_y;
stack<int>stk;

bool dfs(int x)
{
    Node*	p;

    stk.push(x);
    for (p = list[x].next; p; p = p->next)
    {
        if (!visit[p->ord])
        {
            visit[p->ord] = true;
            stk.push(p->ord);
            if (!Y[p->ord] || dfs(Y[p->ord]))
                return true;
            else
                stk.pop();
        }
    }
    stk.pop();

    return false;
}

int main(void)
{
    int	n;

    while (scanf("%d", &n), n)
    {
        scanf("%d%d", &size_x, &size_y);

        for (int i = 1; i <= size_x; i++) list[i].next = NULL;
        memset(X, 0, (size_x + 1) * sizeof(int));
        memset(Y, 0, (size_y + 1) * sizeof(int));

        int	x;
        int	y;
        Node*	p;

        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            p = new Node;
            p->ord = y;
            p->next = list[x].next;
            list[x].next = p;
        }


        int	top;

        for (int i = 1; i <= size_x; i++)
        {
            while (!stk.empty()) stk.pop();
            memset(visit, false, size_y + 1);
            if (dfs(i))
            {
                while (!stk.empty())
                {
                    top = stk.top();
                    stk.pop();
                    Y[top] = stk.top();
                    X[stk.top()] = top;
                    stk.pop();
                }
            }
        }

        int	count = 0;

        for (int i = 1; i <= size_x; i++)
        {
            if (X[i]) count++;
            while (p = list[i].next)
            {
                list[i].next = p->next;
                delete p;
            }
        }

        cout << count << endl;
        while (!stk.empty()) stk.pop();
    }

    return 0;
}
*/

